#pragma once

/**

	@file WorldTimeLimit.h
	@brief タイムリミット
	@author 木村憂哉
	@date 2019/11/24

*/

#include	"GameObject.h"

class CWorldTimeLimit : public CGameObject {

private:

	//! タイムリミットのテクスチャ
			CTexture*	m_pNumberTexture;

	//! タイムリミットフレームのテクスチャ
			CTexture*	m_pNumberFrameTexture;

	//! マイナス記号のテクスチャ
			CTexture*	m_pNegativeSymbolTexture;

	//! リミット加速フラグ
			bool		m_bTimeFaster;

	//! 削られた時間
			int			m_LessTime;

	//! 透明度
			int			m_LessTimeAlpha;

	//! タイムリミット
			float		m_TimeLimit;

	//! 描画時間定数
	const	float		m_LESSRENDERTIME = 3.0f;

	//! 描画時間
			float		m_LessTimeRenderTime;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CWorldTimeLimit(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CWorldTimeLimit(void) { ; }

#pragma endregion

#pragma region 関数

	/**
		@brief Update
		@param なし
		@return なし
		@details タイムリミットの更新を行う
	*/
	void		Update(void);
	/**
		@brief Render
		@param なし
		@return なし
		@details タイムリミットの描画を行う
	*/
	void		Render(void);
	/**
		@brief LessTime
		@param[in] lessTime 削られた時間
		@return なし
		@details 残り時間を減らす処理を行う
	*/
	void		LessTime(const int lessTime) {
	
		m_TimeLimit -= lessTime;

		m_LessTime = lessTime;

		m_LessTimeAlpha = 255;

		m_LessTimeRenderTime = m_LESSRENDERTIME;

	}

#pragma endregion

#pragma region セッター

	/**
		@brief SetTimeFaster
		@param[in] bFaster タイム加速フラグ
		@return なし
		@details タイム加速フラグの設定を行う
	*/
	void	SetTimeFaster(bool bFaster) { m_bTimeFaster = bFaster; }

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetTimeLimit
		@param なし
		@return int タイムリミット
		@details タイムリミットの取得を行う
	*/
	int		GetTimeLimit(void) { return m_TimeLimit; }

#pragma endregion

};