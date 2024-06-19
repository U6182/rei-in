/**

	@file TekeTeke.cpp
	@brief テケテケ
	@author 木村憂哉
	@date 2019/01/05

*/

#include	"TekeTeke.h"
#include	"MotionName.h"

CTekeTeke::CTekeTeke(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint) : CEnemy(pMotoin, pos, move, size, type, HP, attackPoint) {

	//発見範囲の初期化
	m_FindRange = Vector2(300, 0);

	//チャージタイムの初期化
	m_ChargeTime = 0.0f;

	//チャージ量の初期化
	m_Charging = 0.0f;

}

CTekeTeke::~CTekeTeke() {

}

void CTekeTeke::Behavior() {

	float charge = CUtilities::GetFrameSecond();

	if (m_ChargeTime > 0) {

		m_ChargeTime -= charge;

		m_Move.x += m_bReverse ? charge : -charge;

		m_Charging += charge;

		return;

	}

	if (m_pMotion->GetMotionNo() == CMotionName::MOTOIN_TEKETEKE_CHARGEATTACK) {

		if (m_Move.x > CGameElement::PLAYER_MAXMOVE_TEKETEKE) {

			m_Move.x -= charge;

		}else if (m_Move.x < -CGameElement::PLAYER_MAXMOVE_TEKETEKE) {

			m_Move.x += charge;

		}

		return;

	}

	if (m_bFind) {

		if (m_ChargeTime <= 0 && m_pMotion->GetMotionNo() != CMotionName::MOTOIN_TEKETEKE_CHARGEATTACK) {

			m_ChargeTime = random(m_MAX_CHARGE);

			m_Charging = 0.0f;

		}

	}

}

void CTekeTeke::Effect() {

	if (m_bDead) {

		if (!g_pGame->GetEffectManager()->IsEffect(CGameElement::EFFECT_ENEMY_ENEMYDEAD)) {

			const Vector2 pos(m_Pos.x, m_Pos.y);

			g_pGame->GetEffectManager()->Start(pos, CGameElement::EFFECT_ENEMY_ENEMYDEAD);

		}

	}

	if (m_ChargeTime > 0) {

		const int CHARGE_STAGE = static_cast<int>(m_Charging);

		if (!g_pGame->GetEffectManager()->IsEffect(m_CHARGE_STAGE[CHARGE_STAGE])) {

			const Vector2 pos(m_Pos.x, m_Pos.y);

			g_pGame->GetEffectManager()->Start(pos, m_CHARGE_STAGE[CHARGE_STAGE]);

		}
		
	}

}

void CTekeTeke::MotionChange() {

	if (m_bDamage || m_bDead) {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_DAMAGE, FALSE);

	}else if (m_ChargeTime > 0) {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_WAIT, FALSE);

	}
	else if (m_Move.x > CGameElement::PLAYER_MAXMOVE_TEKETEKE || m_Move.x < -CGameElement::PLAYER_MAXMOVE_TEKETEKE) {

		if (!m_bBurst) {

			g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_CHARGEATTACK);

			m_bBurst = true;

		}

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_CHARGEATTACK, FALSE);

	}
	else if (m_Move.x) {

		m_bBurst = false;

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_MOVE, FALSE);

	}

}
