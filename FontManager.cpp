/**

	@file FontManager.cpp
	@brief フォントの管理
	@author 木村憂哉
	@date 2019/12/21

*/

#include		"FontManager.h"

void CFontManager::Release() {

	//フォントの解放
	for (auto it : m_Font) {

		it.second->Release();
		
		delete it.second;

	}

	m_Font.clear();

}

CFont* CFontManager::GetFont(const int size) {

	//指定したサイズのフォントの作成
	auto it = m_Font.find(size);

	if (it != m_Font.end()) {

		return it->second;

	}

	CFont* font = new CFont();

	font->Create(size, "MS 明朝");

	m_Font[size] = font;

	return font;

}

int CFontManager::Length(const char* str) {

	int length = 0;

	//全角半角の文字列の文字数を調べる
	for (; *str != '\0'; str += IsDBCSLeadByte(*str) ? 2 : 1) {

		length++;

	}

	return length;

}