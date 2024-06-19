/**

	@file TextureManager.cpp
	@brief �e�L�X�`���̊Ǘ�
	@author �ؑ��J��
	@date 2019/12/14

*/

#include		"TextureManager.h"

void CTextureManager::Release() {

	//�e�N�X�`���̉��
	for (int i = 0; i < CGameElement::TEXTURE_MAXCOUNT; i++) {

		m_Texture[i].Release();

	}

	if (m_Texture) {

		delete[] m_Texture;

		m_Texture = nullptr;

	}

}

CTexture* CTextureManager::GetTexture(const int type) {

	//�w�肵���e�N�X�`���̃|�C���^��Ԃ�
	return &m_Texture[type];

}