#pragma once

/**

	@file SceneBase.h
	@brief シーンベース
	@author 木村憂哉
	@date 2019/11/02

*/

#include		"Transition.h"
#include		"Game.h"

class CSceneBase {

protected:

	//! テクスチャのポインタ
	CTexture*		m_pTexture;

	//! 遷移
	CTransition*	m_Transition;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CSceneBase(const std::vector<int>* nextScene) : m_pTexture(nullptr), m_Transition(new CTransition(nextScene)) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CSceneBase(void) {

				if (m_Transition) { delete m_Transition; m_Transition = nullptr; }

	}

#pragma endregion
						
#pragma region 関数

	/**
		@brief Load
		@param なし
		@return bool true 成功 false 失敗
		@details シーンの読み込み
	*/
	virtual		bool		Load(void) = 0;
	/**
		@brief Initialize
		@param なし
		@return なし
		@details シーンの初期化を行う
	*/
	virtual		void		Initialize(void) = 0;
	/**
		@brief Update
		@param なし
		@return なし
		@details シーンの更新を行う
	*/
	virtual		void		Update(void) = 0;
	/**
		@brief Render
		@param なし
		@return なし
		@details シーンの描画を行う
	*/
	virtual		void		Render(void) = 0;
	/**
		@brief Release
		@param なし
		@return なし
		@details シーンの解放を行う
	*/
	virtual		void		Release(void) = 0;
	/**
		@brief Operation
		@param なし
		@return なし
		@details シーンの操作を行う
	*/
	virtual		void		Operation(CGameObject* pGameObject) {

		//入力コマンドの取得
		const CDynamicArray<int>* inputCommand = CGame::GetInstance()->GetController()->Input();

		//コマンドを取得
		CCommand** command = CGame::GetInstance()->GetController()->GetCommand();

		for (int i = 0; i < inputCommand->GetArrayCount(); i++) {

			//設定されているコマンドを実行
			if (command[inputCommand->GetData(i)] != nullptr) {

				command[inputCommand->GetData(i)]->Execute(pGameObject);

			}

		}

	}

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetTransition
		@param なし
		@return CTransition* 遷移
		@details 遷移オブジェクトを取得する
	*/
	CTransition*	GetTransition(void) { return m_Transition; }

#pragma endregion

};