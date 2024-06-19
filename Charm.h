#pragma once

/**

	@file Charm.h
	@brief 札
	@author 木村憂哉
	@date 2019/11/02

*/

#include		"Item.h"

class CCharm : public CItem {

protected:

	//! 解放フラグ
			bool	m_bLiberation;

	//! スケール
			float	m_Scale;

	//! 最大スケール
	const	float	m_MAXSCALE = 4.0f;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param[in] pos 座標
		@param[out] size サイズ
		@param[in.out] type 種類
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CCharm(const Vector2 pos, const Vector2 size, const int type);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CCharm(void);

#pragma endregion						

#pragma region 関数

	/**
		@brief Update
		@param なし
		@return なし
		@details 札の更新を行う
	*/
	virtual		void		Update(void);
	/**
		@brief Render
		@param[in] scrooll スクロール値
		@return なし
		@details 札の描画を行う
	*/
	virtual		void		Render(const Vector2& scrooll);

#pragma endregion

#pragma region ゲッター

	/**
		@brief IsLiberation
		@param なし
		@return bool true 出現 false 未出現
		@details 解放フラグを取得する
	*/
	bool		IsLiberation(void) { return m_bLiberation; }

#pragma endregion

};