/**

	@file Hanako.cpp
	@brief ‰ÔŽq
	@author –Ø‘º—JÆ
	@date 2019/01/05

*/

#include	"Hanako.h"
#include	"MotionName.h"

CHanako::CHanako(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint) : CEnemy(pMotoin, pos, move, size, type, HP, attackPoint) {

	//”­Œ©”ÍˆÍ‚Ì‰Šú‰»
	m_FindRange = Vector2(300, g_pGraphics->GetTargetHeight());

}

CHanako::~CHanako() {

}

void CHanako::Behavior() {

	if (m_bFind) {

		if (GetRect().Left > m_pPlayerState->GetRect().Right && m_Move.x > 0) {

			m_Move.x = -m_Move.x;
			
		}else if (GetRect().Right < m_pPlayerState->GetRect().Left && m_Move.x < 0) {

			m_Move.x = -m_Move.x;

		}

	}

}

void CHanako::MotionChange() {

	if (m_bDamage || m_bDead) {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_HANAKO_DAMAGE, FALSE);

	}
	else if (m_bAttack) {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_HANAKO_ATTACK, FALSE);

		g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_HANAKOATTACK);

		if (m_pMotion->IsEndMotion()) {

			m_bAttack = false;

		}

	}else if (m_Move.x) {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_HANAKO_MOVE, FALSE);

	}

}