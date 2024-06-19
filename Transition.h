#pragma once

/**

	@file Transition.h
	@brief 遷移
	@author 木村憂哉
	@date 2020/10/23

*/

#include		"GameObject.h"

class CTransition : public CGameObject {

private:

	//! シーン終了フラグ
			bool				m_bEnd;

	//! フェードフラグ
			bool				m_bAlpha;

	//! 現在のシーン
			int					m_NowScene;

	//! 次に遷移するシーン
	const	std::vector<int>*	m_NextScene;

	//! フェード値
			int					m_Alpha;

	//! 選択番号
			int					m_SelectNo;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CTransition(const std::vector<int>* nextScene) : m_NextScene(nextScene) { m_bEnd = false, m_bAlpha = false, m_NowScene = NULL, m_SelectNo = 0, m_Alpha = 0; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CTransition(void) { ; }

#pragma endregion

#pragma region 関数

	/**
		@brief Initialize
		@param なし
		@return なし
		@details 遷移の初期化を行う
	*/
	void		Initialize(void) { m_Alpha = 255; };
	/**
		@brief Update
		@param なし
		@return なし
		@details 遷移の更新を行う
	*/
	void		Update(void);
	/**
		@brief Render
		@param なし
		@return なし
		@details 遷移の描画を行う
	*/
	void		Render(void);
	/**
		@brief Transition
		@param なし
		@return なし
		@details 遷移を行う
	*/
	void		Transition(void) { 
		
		if ((*m_NextScene)[m_SelectNo] == CGameElement::SCENENO_EXIT) {

			//終了関数
			PostQuitMessage(0);

			return;

		}

		m_bAlpha = true; 
	
	};
	/**
		@brief SelectDownAndRight
		@param なし
		@return なし
		@details セレクトを行う
	*/
	void		SelectDownAndRight(void) {

		m_SelectNo++;

		if (m_SelectNo > m_NextScene->size() - 1) {

			m_SelectNo = m_NextScene->size() - 1;

		}

	}
	/**
		@brief SelectUpAndLeft
		@param なし
		@return なし
		@details セレクトを行う
	*/
	void		SelectUpAndLeft(void) {

		m_SelectNo--;

		if (m_SelectNo < 0) {

			m_SelectNo = 0;

		}

	}

#pragma endregion

#pragma region セッター

	/**
		@brief SetSelectNo
		@param[in] selectNo
		@return なし
		@details セレクト番号の設定を行う
	*/
	void		SetSelectNo(const int selectNo) { m_SelectNo = selectNo; }

#pragma endregion

#pragma region ゲッター

	/**
		@brief IsEnd
		@param なし
		@return bool true シーン終了 false シーン継続
		@details シーンの終了フラグを取得する
	*/
	bool		IsEnd(void) { return m_bEnd; }
	/**
		@brief GetNowScene
		@param なし
		@return int 現在のシーン
		@details 現在のシーンを取得する
	*/
	int			GetNowScene(void) { return m_NowScene; }
	/**
		@brief GetNextScene
		@param なし
		@return int 次に遷移するシーン
		@details 次に遷移するシーンを取得する
	*/
	int			GetNextScene(void) { return (*m_NextScene)[m_SelectNo]; }
	/**
		@brief GetSelectNo
		@param なし
		@return int 選択番号
		@details 選択番号を取得する
	*/
	int			GetSelectNo(void) { return m_SelectNo; }

#pragma endregion

};
