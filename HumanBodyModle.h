#pragma once

/**

	@file HumanBodyModle.h
	@brief 人体模型
	@author 木村憂哉
	@date 2019/11/25

*/

#include		"Enemy.h"
#include		"Viscera.h"

class CHumanBodyModle : public CEnemy {

protected:

#pragma region 関数

	/**
		@brief Behavior
		@param なし
		@return なし
		@details 人体模型の行動処理を行う
	*/
	void		Behavior(void) override;
	/**
		@brief MotionChange
		@param なし
		@return なし
		@details 人体模型のモーション処理を行う
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
				CHumanBodyModle(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CHumanBodyModle(void);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param なし
		@return CRectangle 矩形
		@details 矩形を取得する
	*/
	CRectangle	GetRect(void) const override { return CRectangle(m_Pos.x + 40, m_Pos.y + 20, m_Pos.x + m_Size.x - 40, m_Pos.y + m_Size.y - 5); }

	/**
		@brief GetAttackRect
		@param なし
		@return CRectangle 攻撃矩形
		@details 攻撃矩形を取得する
	*/
	CRectangle	GetAttackRect(void) override {

		return m_Weapon->GetRect();

	}

#pragma endregion

};