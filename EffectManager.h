#pragma once

/**

	@file EffectManager.h
	@brief エフェクトの管理
	@author 木村憂哉
	@date 2019/11/23

*/

#include		"Effect.h"

class CEffectManager {

private:

	//! エフェクト
	CEffect				m_Effect[CGameElement::EFFECT_COUNT][CGameElement::EFFECT_TYPE_COUNT];

	//! テクスチャ配列
	CTexture*			m_Texture;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CEffectManager(void) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CEffectManager(void) { ; }

#pragma endregion				

#pragma region 関数

	/**
		@brief Initialize
		@param なし
		@return なし
		@details エフェクトの初期化を行う
	*/
	void		Initialize(void);
	/**
		@brief Update
		@param なし
		@return なし
		@details エフェクトの更新を行う
	*/
	void		Update(void);
	/**
		@brief Render
		@param[in] scrooll スクロール値
		@return なし
		@details エフェクトの描画を行う
	*/
	void		Render(const Vector2& scrooll);
	/**
		@brief Start
		@param[in] pos エフェクトの座標
		@param[out] エフェクトの種類
		@return なし
		@details 指定した位置に指定した種類のエフェクトの表示を行う
	*/
	void		Start(const Vector2& pos, const int type);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param[in] type エフェクトの種類
		@return CRectangle 矩形
		@details エフェクトの矩形を取得する
	*/
				CRectangle			GetRect(const int type) { return m_Effect[0][type].GetRect(); }
	/**
		@brief GetRect
		@param[in] type エフェクトの種類
		@param[out] IDNo エフェクト番号
		@return CRectangle 矩形
		@details エフェクトの矩形を取得する
	*/
				CRectangle			GetRect(const int type, const int IDNo) { return m_Effect[IDNo][type].GetRect(); }
	/**
		@brief GetSize
		@param[in] type エフェクトの種類
		@return Vector2 エフェクトのサイズ
		@details エフェクトのサイズを取得する
	*/
	const		Vector2&			GetSize(const int type) { return m_Effect[0][type].GetSize(); }
	/**
		@brief IsEffect
		@param[in] type エフェクトの種類
		@return bool true エフェクト表示中 false　エフェクト非表示
		@details 指定した種類のエフェクトが存在するかを取得する
	*/
				bool				IsEffect(const int type);

#pragma endregion

#pragma region セッター

	/**
		@brief SetTexture
		@param[in] pTexture	設定を行うテクスチャのポインタ
		@return なし
		@details テクスチャの設定を行う
	*/
	void				SetTexture(CTexture* pTexture) { m_Texture = pTexture; }

#pragma endregion

};