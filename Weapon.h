#pragma once

/**

	@file Weapon.h
	@brief 武器
	@author 木村憂哉
	@date 2019/11/25

*/

#include		"DynamicGameObject.h"

class CWeapon : public CDynamicGameObject {

protected:

	//! 移動量
	const	Vector2		m_MOVE;

	//! 発射フラグ
			bool		m_bShot;

#pragma region 関数

	/**
		@brief Behavior
		@param なし
		@return なし
		@details 武器の行動処理を行う
	*/
	virtual		void		Behavior(void) { ; };
	/**
		@brief MotionChange
		@param なし
		@return なし
		@details 武器のモーション処理を行う
	*/
	virtual		void		MotionChange(void) { ; };

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param[in] pTexture テクスチャのポインタ
		@param[out] size サイズ
		@param[in.out] move 移動量
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CWeapon(CTexture* pTexture, const Vector2 size, const Vector2 move);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CWeapon(void);

#pragma endregion

#pragma region 関数

	/**
		@brief Update
		@param なし
		@return なし
		@details 武器の更新を行う
	*/
	virtual		void	Update(void);
	/**
		@brief Render
		@param[in] scrooll スクロール
		@return なし
		@details 武器の描画を行う
	*/
	virtual		void	Render(const Vector2& scrooll);
	/**
		@brief Shot
		@param[in] pos 座標
		@return なし
		@details 武器の発射を行う
	*/
	virtual		void	Shot(const Vector2& pos);
	/**
		@brief Shot
		@param[in] pos 座標
		@param[out] bReverse 反転フラグ
		@return なし
		@details 武器の発射を行う
	*/
	virtual		void	Shot(const Vector2& pos, const bool bReverse);

#pragma endregion

#pragma region セッター

	/**
		@brief SetShot
		@param[in] bShot ショットフラグ
		@return なし
		@details ショットフラグの設定を行う
	*/
	void	SetShot(bool bShot) { m_bShot = bShot; }

#pragma endregion
	
#pragma region ゲッター

	/**
		@brief IsShot
		@param なし
		@return bool true ショット false 未ショット
		@details ショットフラグを取得する
	*/
	bool	IsShot() { return m_bShot; }

#pragma endregion

};