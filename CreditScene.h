#pragma once

/**

	@file CreditScene.h
	@brief クレジットシーン
	@author 木村憂哉
	@date 2019/11/20

*/

#include		"SceneBase.h"
#include		"Stage.h"

class CCreditScene : public CSceneBase {

private:

	//! プレイヤー
			CPlayer*						m_Player;

	//! クリアゴースト
			std::vector<CItem*>				m_ClearGhost;

	//! 敵
			std::vector<CEnemy*>			m_EnemyArray;

	//! ステージ
			CStage*							m_Stage;

	//! クレジット
			std::vector<char*>				m_Credit;

	//! クレジットの座標
			Vector2*						m_CreditPos;

	//! クレジットの色
			MofU32*							m_CreditColor;

	//! クリアゴースト発見フラグ
			bool							m_bGhostFind;

	//! 待機インターバル
			float							m_WaitInterval;

	//! 待機インターバルタイム
	const	float							m_WAITINTERVALTIME = 4.0f;

	//! 次のシーン
	const	std::vector<int>				m_NextSceneList = { CGameElement::SCENENO_GAMECLEAR };

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CCreditScene(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CCreditScene(void);

#pragma endregion		

#pragma region 関数

	/**
		@brief Load
		@param なし
		@return bool true 成功 false 失敗
		@details クレジットシーンの読み込み
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param なし
		@return なし
		@details クレジットシーンの初期化を行う
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param なし
		@return なし
		@details クレジットシーンの更新を行う
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param なし
		@return なし
		@details クレジットシーンの描画を行う
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param なし
		@return なし
		@details クレジットシーンの解放を行う
	*/
	void	Release(void) override;

#pragma endregion

};