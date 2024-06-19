#pragma once

/**

	@file TextureManager.h
	@brief テキスチャの管理
	@author 木村憂哉
	@date 2019/10/23

*/

#include		"GameElement.h"

class CTextureManager {

private:

	//! テクスチャの配列
	CTexture*		m_Texture;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CTextureManager(void) : m_Texture(nullptr) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CTextureManager(void) { Release(); }

#pragma endregion

#pragma region 関数

	/**
		@brief Release
		@param なし
		@return なし
		@details テクスチャの解放を行う
	*/
	void		Release(void);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetTexture
		@param[in] type 取得するテクスチャ
		@return CTexture* 指定したテクスチャのポインタ
		@details 指定したテクスチャを取得する
	*/
			CTexture*	GetTexture(const int type);
	/**
		@brief GetSize
		@param[in] type サイズを取得するテクスチャ
		@return Vector2 テクスチャのサイズ
		@details 指定したテクスチャを取得する
	*/
	const	Vector2		GetSize(const int type) { return Vector2(m_Texture[type].GetWidth(), m_Texture[type].GetHeight()); }

#pragma endregion

#pragma region セッター

	/**
		@brief SetTexture
		@param[in] pTexture	設定を行うテクスチャ
		@return なし
		@details テクスチャの設定を行う
	*/
	void	SetTexture(CTexture* pTexture) {

		m_Texture = pTexture;

	}
	
#pragma endregion

};