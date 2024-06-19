/**

	@file Weapon.cpp
	@brief 武器
	@author 木村憂哉
	@date 2019/01/05

*/

#include	"Weapon.h"
#include	"Game.h"

CWeapon::CWeapon(CTexture* pTexture, const Vector2 size, const Vector2 move) : CDynamicGameObject(size), m_MOVE(move) {

	//テクスチャの設定
	m_pTexture = pTexture;

	m_bShot = false;

}

CWeapon::~CWeapon() {

}

void CWeapon::Shot(const Vector2& pos) {

	if (m_bShow || m_bShot) {

		return;

	}

	g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_BODYATTACK);

	m_bShot = true;

	m_bShow = true;

	m_bReverse = !m_bReverse;

	int direction = m_bReverse ? -1 : 1;

	m_Pos = pos;

	m_Move = m_MOVE;

	m_Move.x = direction * m_MOVE.x;

}

void CWeapon::Shot(const Vector2& pos, const bool bReverse) {

	if (m_bShow || m_bShot) {

		return;

	}

	g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_BODYATTACK);

	m_bShot = true;

	m_bShow = true;

	m_bReverse = bReverse;

	int direction = m_bReverse ? -1 : 1;

	m_Pos = pos;

	m_Move = m_MOVE;

	m_Move.x = direction * m_MOVE.x;

}

void CWeapon::Update() {

	if (!m_bShow) {

		return;

	}

	//行動処理の更新
	Behavior();

	//モーション処理の更新
	MotionChange();

	//反転処理の更新
	Reverse();

	//座標の更新
	PosMove();

}

void CWeapon::Render(const Vector2& scrooll) {

	if (!m_bShow) {

		return;

	}

	const Vector2 pos = m_Pos - scrooll;

	//敵の描画
	m_pTexture->Render(pos.x, pos.y);

}