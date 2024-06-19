#pragma once

/**

	@file Utili.h
	@brief 汎用クラス
	@author 木村憂哉
	@date 2020/10/13

*/

#include		"Mof.h"

class CUtili {

public:

	/**
		@brief CenterTexturePos
		@param[in] texture テクスチャ
		@return なし
		@details テクスチャが画面中央になる座標の取得を行う
	*/
	static Vector2 CenterTexturePos(CTexture& texture) {

		return Vector2((g_pGraphics->GetTargetWidth() - texture.GetWidth()) * 0.5f, (g_pGraphics->GetTargetHeight() - texture.GetHeight()) * 0.5f);

	}
	/**
		@brief CenterTexturePosX
		@param[in] texture テクスチャ
		@return なし
		@details テクスチャが画面X軸中央になる座標の取得を行う
	*/
	static float CenterTexturePosX(CTexture& texture) {

		return (g_pGraphics->GetTargetWidth() - texture.GetWidth()) * 0.5f;

	}
	/**
		@brief CenterTexturePosY
		@param[in] texture テクスチャ
		@return なし
		@details テクスチャが画面Y軸中央になる座標の取得を行う
	*/
	static float CenterTexturePosY(CTexture& texture) {

		return (g_pGraphics->GetTargetHeight() - texture.GetHeight()) * 0.5f;

	}

};