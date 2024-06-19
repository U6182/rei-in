/**

	@file Kinzirou.cpp
	@brief “ñƒm‹{‹àŽŸ˜Y
	@author –Ø‘º—JÆ
	@date 2019/01/05

*/

#include	"Kinzirou.h"
#include	"MotionName.h"

CKinzirou::CKinzirou(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint) : CEnemy(pMotoin, pos, move, size, type, HP, attackPoint) {

}

CKinzirou::~CKinzirou() {

}

void CKinzirou::MotionChange() {

	m_pMotion->ChangeMotion(CMotionName::MOTOIN_KINZIROU_WAIT, FALSE);

}
