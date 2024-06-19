/**

	@file Item.cpp
	@brief �A�C�e��
	@author �ؑ��J��
	@date 2019/12/15

*/

#include	"Item.h"

CItem::CItem(const Vector2 pos, const Vector2 size, const int type) : CDynamicGameObject(size) {

	//���W�̏�����
	m_Pos = pos;

	//��ނ̏�����
	m_Type = type;

	//�o���t���O�̏�����
	m_bAppear = false;

}

CItem::~CItem() {

	//�����o�̉��
	Release();

}

void CItem::Render(const Vector2& scrooll) {
	
	if (!m_bShow || !m_bAppear) {

		return;

	}

	Vector2 pos = m_Pos - scrooll;
	
	//�A�C�e���̕`��
	m_pTexture->Render(pos.x, pos.y);

}

void CItem::Release() {

}