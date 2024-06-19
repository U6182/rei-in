/**

	@file Effect.cpp
	@brief エフェクト
	@author 木村憂哉
	@date 2019/12/21

*/

#include		"Effect.h"
#include		"Game.h"

CEffect::CEffect() : m_Pos() {

	//表示フラグの初期化
	m_bShow = false;

}

CEffect::~CEffect() {

}

void CEffect::Initialize(const int type) {

	//モーションの初期化
	switch (type)
	{

	case CGameElement::EFFECT_SOUL_POSSESSION:

		m_Size.x = 256.0f;
		m_Size.y = 256.0f;

		m_pMotion = g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_POSSESSION);

		break;
	case CGameElement::EFFECT_SOUL_PLAYERDEAD:

		m_Size.x = 256.0f;
		m_Size.y = 256.0f;

		m_pMotion = g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_PLAYERDEAD);

		break;
	case CGameElement::EFFECT_ENEMY_ATTACK:

		m_Size.x = 64.0f;
		m_Size.y = 64.0f;

		m_pMotion = g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_ATTACK);

		break;
	case CGameElement::EFFECT_ENEMY_ENEMYDEAD:

		m_Size.x = 256.0f;
		m_Size.y = 256.0f;

		m_pMotion = g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_ENEMYDEAD);

		break;

	case CGameElement::EFFECT_TEKETEKE_CHARGESTAGE1:
	case CGameElement::EFFECT_TEKETEKE_CHARGESTAGE2:
	case CGameElement::EFFECT_TEKETEKE_CHARGESTAGE3:
	case CGameElement::EFFECT_TEKETEKE_CHARGESTAGE4:
	case CGameElement::EFFECT_TEKETEKE_CHARGESTAGE5:

		m_Size.x = 150.0f;
		m_Size.y = 150.0f;

		m_pMotion = g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_CHARGE);

		break;

	}

	//表示フラグの初期化
	m_bShow = false;

}

void CEffect::Start(const Vector2& pos) {

	//表示フラグの初期化
	m_bShow = true;

	//座標の初期化
	m_Pos = pos;

}

void CEffect::Update() {

	if (!m_bShow) {

		return;

	}

	m_pMotion->AddTimer(CUtilities::GetFrameSecond());
	
	//モーションが終了した場合
	if (m_pMotion->IsEndMotion()) {

		m_bShow = false;

		m_pMotion->SetTime(0);
		//m_pMotion->Create(m_Anime);

	}

}

void CEffect::Render(const Vector2& scrooll) {

	if (!m_bShow) {

		return;

	}

	Vector2 pos = m_Pos - scrooll;

	m_StrRect = m_pMotion->GetSrcRect();

	//エフェクトの描画
	m_pTexture->Render(pos.x, pos.y, m_StrRect);
	
}