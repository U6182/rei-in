#pragma once

/**

	@file DynamicGameObject.h
	@brief キャラクターやアイテムのベース
	@author 木村憂哉
	@date 2019/11/24

*/

#include		"GameObject.h"
#include		"MotionName.h"

class CDynamicGameObject : public CGameObject {

protected:

	//! テクスチャのポインタ
	CTexture*						m_pTexture;

	//! モーション
	CSpriteMotionController*		m_pMotion;

	//! 座標
	Vector2							m_Pos;

	//! 移動量
	Vector2							m_Move;

	//! テクスチャーの幅
	Vector2							m_Size;

	//! 表示フラグ
	bool							m_bShow;

	//! 反転フラグ
	bool							m_bReverse;

	//! 個体識別番号
	int								m_IDNo;

	//! 種類
	int								m_Type;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CDynamicGameObject(const Vector2 size) : CGameObject(), m_Pos(), m_Move(), m_Size(size) {

					m_bShow = false, m_bReverse = false, m_IDNo = 0, m_Type = 0;

				}
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CDynamicGameObject(void) { ; }

#pragma endregion

#pragma region 関数

	/**
		@brief Reverse
		@param なし
		@return なし
		@details 反転処理を行う
	*/
	virtual		void		Reverse(void) { if (m_Move.x > 0) { m_bReverse = false; } else if (m_Move.x < 0) { m_bReverse = true; } };
	/**
		@brief PosMove
		@param なし
		@return なし
		@details 座標移動処理を行う
	*/
	virtual		void		PosMove(void) {

		m_Move.y += CGameElement::GRAVITY;

		m_Pos += m_Move;

	};

#pragma endregion

#pragma region セッター

	/**
		@brief SetTexture
		@param[in] pTexture テクスチャのポインタ
		@return なし
		@details テクスチャの設定を行う
	*/
	void		SetTexture(CTexture* pTexture) { m_pTexture = pTexture; }
	/**
		@brief SetShow
		@param[in] show 表示フラグ
		@return なし
		@details 表示フラグの設定を行う
	*/
	void		SetShow(const bool show) { m_bShow = show; }
	/**
		@brief SetIDNo
		@param[in] IDNo 個体識別番号
		@return なし
		@details 個体識別番号の設定を行う
	*/
	void		SetIDNo(const int IDNo) { m_IDNo = IDNo; }
	/**
		@brief SetPosX
		@param[in] px X座標
		@return なし
		@details X座標の設定を行う
	*/
	void		SetPosX(const float px) { m_Pos.x = px; }
	/**
		@brief SetPosY
		@param[in] py Y座標
		@return なし
		@details Y座標の設定を行う
	*/
	void		SetPosY(const float py) { m_Pos.y = py; }
	
#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param なし
		@return CRectangle 矩形
		@details 矩形を取得する
	*/
	virtual		CRectangle		GetRect() const { return CRectangle(m_Pos.x, m_Pos.y, m_Pos.x + m_Size.x, m_Pos.y + m_Size.y); }
	/**
		@brief GetPos
		@param なし
		@return Vector2 座標
		@details 座標を取得する
	*/
				Vector2&		GetPos(void) { return m_Pos; }
	/**
		@brief GetMove
		@param なし
		@return Vector2 移動量
		@details 移動量を取得する
	*/
				Vector2&	GetMove(void) { return m_Move; }
	/**
		@brief GetSize
		@param なし
		@return Vector2 サイズ
		@details サイズを取得する
	*/
				Vector2&	GetSize(void) { return m_Size; }
	/**
		@brief IsShow
		@param なし
		@return bool true 表示 false 非表示
		@details 表示フラグを取得する
	*/
				bool		IsShow(void) { return m_bShow; }
	/**
		@brief GetType
		@param なし
		@return int 個体識別番号
		@details 個体識別番号を取得する
	*/
				int			GetIDNo(void) { return m_IDNo; }
	/**
		@brief GetType
		@param なし
		@return int 種類
		@details 種類を取得する
	*/
				int			GetType(void) { return m_Type; }

#pragma endregion

};