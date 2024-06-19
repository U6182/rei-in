/**

	@file FontManager.cpp
	@brief �t�H���g�̊Ǘ�
	@author �ؑ��J��
	@date 2019/12/21

*/

#include		"FontManager.h"

void CFontManager::Release() {

	//�t�H���g�̉��
	for (auto it : m_Font) {

		it.second->Release();
		
		delete it.second;

	}

	m_Font.clear();

}

CFont* CFontManager::GetFont(const int size) {

	//�w�肵���T�C�Y�̃t�H���g�̍쐬
	auto it = m_Font.find(size);

	if (it != m_Font.end()) {

		return it->second;

	}

	CFont* font = new CFont();

	font->Create(size, "MS ����");

	m_Font[size] = font;

	return font;

}

int CFontManager::Length(const char* str) {

	int length = 0;

	//�S�p���p�̕�����̕������𒲂ׂ�
	for (; *str != '\0'; str += IsDBCSLeadByte(*str) ? 2 : 1) {

		length++;

	}

	return length;

}