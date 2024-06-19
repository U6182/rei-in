#pragma once

/**

	@file TekeTeke.h
	@brief テケテケ
	@author 木村憂哉
	@date 2019/11/25

*/

#include		"Enemy.h"

class CTekeTeke : public CEnemy {

protected:

	//! チャージエフェクト
	const	std::vector<int>	m_CHARGE_STAGE = {CGameElement::EFFECT_TEKETEKE_CHARGESTAGE1, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE2, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE3, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE4, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE5};

	//! バースト
			bool				m_bBurst = false;

	//! 最大チャージタイム
	const	int					m_MAX_CHARGE = 5;

	//! チャージタイム
			float				m_ChargeTime;

	//! チャージ量
			float				m_Charging;

#pragma region 関数

	/**
		@brief Behavior
		@param なし
		@return なし
		@details テケテケの行動処理を行う
	*/
	void		Behavior(void) override;
	/**
		@brief MotionChange
		@param なし
		@return なし
		@details テケテケのモーション処理を行う
	*/
	void		MotionChange(void) override;
	/**
		@brief PosMove
		@param なし
		@return なし
		@details 座標移動処理を行う
	*/
	void		PosMove(void) override{

		if (m_ChargeTime <= 0) {

			m_Move.y += CGameElement::GRAVITY;

			m_Pos += m_Move;

		}

	};
	/**
		@brief Effect
		@param なし
		@return なし
		@details 効果処理を行う
	*/
	void		Effect(void) override;

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
				CTekeTeke(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CTekeTeke(void);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param なし
		@return CRectangle 矩形
		@details 矩形を取得する
	*/
			CRectangle		GetRect(void) const override { return CRectangle(m_Pos.x + 30, m_Pos.y + 20, m_Pos.x + m_Size.x - 30, m_Pos.y + m_Size.y - 5); }
	/**
		@brief GetFindRect
		@param なし
		@return CRectangle プレイヤー発見判定用の矩形
		@details プレイヤー発見判定用の矩形を取得する
	*/
			CRectangle	GetFindRect(void) override {

				if (m_bReverse) {

					return CRectangle(m_Pos.x + m_Size.x, m_Pos.y, m_Pos.x + m_Size.x + m_FindRange.x, m_Pos.y + m_Size.y);

				}
				else {

					return CRectangle(m_Pos.x - m_FindRange.x, m_Pos.y, m_Pos.x, m_Pos.y + m_Size.y);
			
				}

			}
	/**
		@brief GetAttackPoint
		@param なし
		@return int	GetAttackPoint
		@details 攻撃力の取得を行う
	*/
			int			GetAttackPoint(void) override { 
		
				int charging = static_cast<int>(m_Charging);

				if (charging == 0) {

					charging = 1;

				}
				else if (charging < 0) {

					charging = -charging;

				}

				return m_AttackPoint * charging; 
	
			}

#pragma endregion

};