#pragma once

/**

	@file GameScene.h
	@brief ゲームシーン
	@author 木村憂哉
	@date 2019/11/20

*/

#include		"SceneBase.h"
#include		"Player.h"
#include		"Enemy.h"
#include		"Item.h"
#include		"Stage.h"
#include		"WorldTimeLimit.h"

class CGameScene : public CSceneBase {

private:

	//! 時間制限
			CWorldTimeLimit*			m_WorldTimeLimit;

	//! プレイヤー
			CPlayer*					m_Player;

	//! ステージ
			CStage*						m_Stage;

	//! 敵
			std::vector<CEnemy*>		m_EnemyArray;

	//! アイテム
			std::vector<CItem*>			m_ItemArray;

	//! 振動フラグ
			bool						m_bVibration;

	//! コントローラの状態
			int							m_ControllerState;

	//! ゲームの状態
			int							m_GameState;

	//! 次のシーン
	const	std::vector<int>			m_NextSceneList = { CGameElement::SCENENO_GAMEOVER, CGameElement::SCENENO_CREDIT };

	//! プレイヤー攻撃時の停止時間
			float						m_BreakTime;

#pragma region 関数

	/**
		@brief PlayerUpdate
		@param なし
		@return なし
		@details プレイヤーの更新を行う
	*/
	void			PlayerUpdate(void);
	/**
		@brief EnemyUpdate
		@param なし
		@return なし
		@details 敵の更新を行う
	*/
	void			EnemyUpdate(void);
	/**
		@brief ItemUpdate
		@param なし
		@return なし
		@details アイテムの更新を行う
	*/
	void			ItemUpdate(void);
	/**
		@brief ControllerUpdate
		@param なし
		@return なし
		@details コントローラーの更新を行う
	*/
	void			ControllerUpdate(void);
	/**
		@brief SoundUpdate
		@param なし
		@return なし
		@details サウンドの更新を行う
	*/
	void			SoundUpdate(void);
	/**
		@brief WorldTimeLimitUpdate
		@param なし
		@return なし
		@details 時間制限の更新を行う
	*/
	void			WorldTimeLimitUpdate(void);
	/**
		@brief CommandTransition
		@param なし
		@return なし
		@details コマンド遷移を行う
	*/
	void			CommandTransition(void);
	/**
		@brief GameState
		@param なし
		@return CGameObject* ゲームオブジェクト
		@details ゲームの状態に合わせたオブジェクトを取得する
	*/
	CGameObject*	GameState(void);
	/**
		@brief EnemyAppear
		@param なし
		@return なし
		@details 敵の出現処理を行う
	*/
	void			EnemyAppear(void);
	/**
		@brief ItemAppear
		@param なし
		@return なし
		@details アイテムの出現処理を行う
	*/
	void			ItemAppear(void);
	/**
		@brief AnimeCollision
		@param なし
		@return なし
		@details キャラクターの衝突処理を行う
	*/
	void			AnimeCollision(void);
	/**
		@brief ItemCollision
		@param なし
		@return なし
		@details アイテムの衝突処理を行う
	*/
	void			ItemCollision(void);
	/**
		@brief GameTransition
		@param なし
		@return なし
		@details ゲームの遷移処理を行う
	*/
	void			GameTransition(void);
	/**
		@brief TypeItemFind
		@param[in] type　種類
		@return なし
		@details 指定した種類のオブジェクトの識別番号の取得処理を行う
	*/
	CItem*		TypeItemFind(std::vector<CItem*> pItem, const int type) {

		CItem* pFindItem = nullptr;

		for (CItem* pGameItem : pItem) {

			if (pGameItem->GetType() == type) {

				pFindItem = pGameItem;

			}

		}

		return pFindItem;

	};

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CGameScene(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CGameScene(void);

#pragma endregion		

#pragma region 関数

	/**
		@brief Load
		@param なし
		@return bool true 成功 false 失敗
		@details ゲームシーンの読み込み
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param なし
		@return なし
		@details ゲームシーンの初期化を行う
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param なし
		@return なし
		@details ゲームシーンの更新を行う
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param なし
		@return なし
		@details ゲームシーンの描画を行う
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param なし
		@return なし
		@details ゲームシーンの解放を行う
	*/
	void	Release(void) override;

#pragma endregion

};