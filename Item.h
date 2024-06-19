#pragma once

/**

	@file Item.h
	@brief アイテム
	@author 木村憂哉
	@date 2019/11/02

*/

#include		"DynamicGameObject.h"

class CItem : public CDynamicGameObject {

protected:

	//! 出現フラグ
	bool	m_bAppear;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param[in] pos 座標
		@param[out] size サイズ
		@param[in.out] type 種類
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CItem(const Vector2 pos, const Vector2 size, const int type);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CItem(void);

#pragma endregion						
	
#pragma region 関数

	/**
		@brief Update
		@param なし
		@return なし
		@details アイテムの更新を行う
	*/
	virtual		void		Update(void) { ; }
	/**
		@brief Render
		@param[in] scrooll スクロール値
		@return なし
		@details アイテムの描画を行う
	*/
	virtual		void		Render(const Vector2& scrooll);
	/**
		@brief Release
		@param なし
		@return なし
		@details アイテムの解放を行う
	*/
	virtual		void		Release(void);

#pragma endregion

#pragma region セッター

	/**
		@brief SetAppear
		@param[in] bAppear 出現フラグ
		@return なし
		@details 敵の出現フラグの設定を行う
	*/
	virtual		void		SetAppear(bool bAppar) { m_bAppear = bAppar; }

#pragma endregion

#pragma region ゲッター

	/**
		@brief IsAppear
		@param なし
		@return bool true 出現 false 未出現
		@details 出現フラグを取得する
	*/
	bool		IsAppear(void) { return m_bAppear; }

#pragma endregion

};