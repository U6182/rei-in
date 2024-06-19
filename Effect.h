#pragma once

/**

	@file Effect.h
	@brief エフェクト
	@author 木村憂哉
	@date 2019/11/23

*/

#include		"GameElement.h"

class CEffect {

private:

	//! テクスチャのポインタ
	CTexture*					m_pTexture;

	//! モーション
	CSpriteMotionController*	m_pMotion;

	//! 矩形
	CRectangle					m_StrRect;

	//! 座標
	Vector2						m_Pos;

	//! サイズ
	Vector2						m_Size;

	//! 表示フラグ
	bool						m_bShow;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CEffect(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CEffect(void);

#pragma endregion
			
#pragma region 関数

	/**
		@brief Initialize
		@param[in] type エフェクトの種類
		@return なし
		@details エフェクトの初期化を行う
	*/
	void	Initialize(const int type);
	/**
		@brief Update
		@param なし
		@return なし
		@details エフェクトの更新を行う
	*/
	void	Update(void);
	/**
		@brief Render
		@param[in] scrooll スクロール値
		@return なし
		@details エフェクトの描画を行う
	*/
	void	Render(const Vector2& scrooll);
	/**
		@brief Start
		@param[in] pos エフェクトの座標
		@return なし
		@details 指定した位置にエフェクトの表示を行う
	*/
	void	Start(const Vector2& pos);

#pragma endregion

#pragma region セッター

	/**
		@brief SetTexture
		@param[in] pTexture エフェクトのテクスチャポインタ
		@return なし
		@details エフェクトのテクスチャの設定を行う
	*/
	void	SetTexture(CTexture* pTexture) { m_pTexture = pTexture; }

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param なし
		@return CRectangle 矩形
		@details 矩形を取得する
	*/
				CRectangle		GetRect() { return CRectangle(m_Pos.x, m_Pos.y, m_Pos.x + m_Size.x, m_Pos.y + m_Size.y); }
	/**
		@brief GetSize
		@param なし
		@return Vector2 エフェクトのサイズ
		@details エフェクトのサイズを取得する
	*/
	const		Vector2&		GetSize(void) { return m_Size; }
	/**
		@brief IsShow
		@param なし
		@return なし
		@details エフェクトの表示フラグを取得する
	*/
				bool			IsShow(void) { return m_bShow; }

#pragma endregion
	
};