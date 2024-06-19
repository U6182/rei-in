/**

	@file TextureManager.cpp
	@brief テキスチャの管理
	@author 木村憂哉
	@date 2019/12/14

*/

#include		"TextureManager.h"

void CTextureManager::Release() {

	//テクスチャの解放
	for (int i = 0; i < CGameElement::TEXTURE_MAXCOUNT; i++) {

		m_Texture[i].Release();

	}

	if (m_Texture) {

		delete[] m_Texture;

		m_Texture = nullptr;

	}

}

CTexture* CTextureManager::GetTexture(const int type) {

	//指定したテクスチャのポインタを返す
	return &m_Texture[type];

}