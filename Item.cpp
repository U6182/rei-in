/**

	@file Item.cpp
	@brief アイテム
	@author 木村憂哉
	@date 2019/12/15

*/

#include	"Item.h"

CItem::CItem(const Vector2 pos, const Vector2 size, const int type) : CDynamicGameObject(size) {

	//座標の初期化
	m_Pos = pos;

	//種類の初期化
	m_Type = type;

	//出現フラグの初期化
	m_bAppear = false;

}

CItem::~CItem() {

	//メンバの解放
	Release();

}

void CItem::Render(const Vector2& scrooll) {
	
	if (!m_bShow || !m_bAppear) {

		return;

	}

	Vector2 pos = m_Pos - scrooll;
	
	//アイテムの描画
	m_pTexture->Render(pos.x, pos.y);

}

void CItem::Release() {

}