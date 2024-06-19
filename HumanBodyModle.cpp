/**

	@file HumanBodyModle.cpp
	@brief l‘Ì–ÍŒ^
	@author –Ø‘º—JÆ
	@date 2019/01/05

*/

#include	"HumanBodyModle.h"
#include	"MotionName.h"

CHumanBodyModle::CHumanBodyModle(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint) : CEnemy(pMotoin, pos, move, size, type, HP, attackPoint) {

	//”­Œ©”ÍˆÍ‚Ì‰Šú‰»
	m_FindRange = m_Type == CGameElement::ENEMY_HUMANBODYMODLE_DIAGONAL ? Vector2(300, 300) : Vector2(g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());

	const Vector2 MOVE = m_Type == CGameElement::ENEMY_HUMANBODYMODLE_DIAGONAL ? Vector2(8, -10) : Vector2(0, 3);

	m_Weapon = new CViscera(g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_VISCERA), Vector2(50, 50), MOVE);

}

CHumanBodyModle::~CHumanBodyModle() {

	if (m_Weapon) {

		delete m_Weapon;

		m_Weapon = nullptr;

	}

}

void CHumanBodyModle::Behavior() {

	if (m_bFind && m_bAppear) {

		m_Weapon->Shot(Vector2(m_Pos.x + 50, m_Pos.y + 100));

	}

}

void CHumanBodyModle::MotionChange() {

	if (m_bDamage) {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_DAMAGE, FALSE);

		if (m_pMotion->IsEndMotion()) {

			m_bDamage = false;

		}

	}else if (m_Weapon->IsShot()) {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_ATTACK, FALSE);

		if (m_pMotion->IsEndMotion()) {

			m_Weapon->SetShot(false);

		}

	}
	else {

		m_pMotion->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_WAIT, FALSE);

	}

}