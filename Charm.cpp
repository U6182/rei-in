/**

	@file Charm.cpp
	@brief 遷移
	@author 木村憂哉
	@date 2020/10/24

*/

#include		"Charm.h"

CCharm::CCharm(const Vector2 pos, const Vector2 size, const int type) : CItem(pos, size, type) {

	//解放フラグの初期化
	m_bLiberation = false;

	//スケールの初期化
	m_Scale = 0.0f;

}

CCharm::~CCharm() {

	//解放処理
	Release();

}

void CCharm::Update() {

	if (!m_bAppear) {

		return;

	}

	m_Scale += CUtilities::GetFrameSecond();

	if (m_Scale >= m_MAXSCALE) {

		m_Scale = m_MAXSCALE;

		m_bLiberation = true;

	}

}

void CCharm::Render(const Vector2& scrooll) {

	if (!m_bAppear) {

		return;

	}

	const Vector2& pos = m_Pos - scrooll;

	//札の描画
	m_pTexture->RenderScale(pos.x, pos.y, m_Scale);

}