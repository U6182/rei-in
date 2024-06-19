#pragma once

/**

	@file Kinzirou.h
	@brief 二ノ宮金次郎
	@author 木村憂哉
	@date 2019/11/25

*/

#include		"Enemy.h"

class CKinzirou : public CEnemy {

protected:

#pragma region 関数

	/**
		@brief MotionChange
		@param なし
		@return なし
		@details 二ノ宮金次郎のモーション処理を行う
	*/
	void		MotionChange(void) override;

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param[in] pMotion モーション
		@param[out] pos 座標
		@param[in.out] move 移動量
		@param[in] size サイズ
		@param[out] type 種類
		@param[in.out] HP HP
		@param[in] attackPoint 攻撃力
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CKinzirou(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CKinzirou(void);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param なし
		@return CRectangle 矩形
		@details 矩形を取得する
	*/
	CRectangle		GetRect(void) const override { return CRectangle(m_Pos.x + 60, m_Pos.y + 15, m_Pos.x + m_Size.x - 70, m_Pos.y + m_Size.y - 5); }
	/**
		@brief IsAttackPossible
		@param なし
		@return bool true 攻撃可能 false 攻撃不可能
		@details 攻撃可能フラグを取得する
	*/
	bool			IsAttackPossible(void) override{ return false; }

#pragma endregion

};