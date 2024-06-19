/**

	@file Charm.cpp
	@brief �J��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include		"Charm.h"

CCharm::CCharm(const Vector2 pos, const Vector2 size, const int type) : CItem(pos, size, type) {

	//����t���O�̏�����
	m_bLiberation = false;

	//�X�P�[���̏�����
	m_Scale = 0.0f;

}

CCharm::~CCharm() {

	//�������
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

	//�D�̕`��
	m_pTexture->RenderScale(pos.x, pos.y, m_Scale);

}