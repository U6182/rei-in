#pragma once

/**

	@file Viscera.h
	@brief 人体模型の内臓
	@author 木村憂哉
	@date 2019/11/25

*/

#include		"Weapon.h"

class CViscera : public CWeapon {

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param[in] pTexture テクスチャのポインタ
		@param[out] size サイズ
		@param[in.out] move 移動量
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CViscera(CTexture* pTexture, const Vector2 size, const Vector2 move);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CViscera(void);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param なし
		@return CRectangle 矩形
		@details 矩形を取得する
	*/
	CRectangle	GetRect() const override { return CRectangle(m_Pos.x + 5, m_Pos.y + 5, m_Pos.x + m_Size.x - 5, m_Pos.y + m_Size.y - 5); }

#pragma endregion

};