#pragma once

/**

	@file Setting.h
	@brief テキスチャの管理
	@author 木村憂哉
	@date 2019/10/23

*/

#include		"GameElement.h"

class CSetting {

private:

	//! バイブレーションの設定
	bool	m_bVibration;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CSetting(void) { m_bVibration = true; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CSetting(void) { ; }

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetSize
		@param なし
		@return true バイブレーション設定　false バイブレーション未設定
		@details バイブレーション設定を取得する
	*/
	bool		IsVibration(void) { return m_bVibration; }

#pragma endregion

#pragma region セッター

	/**
		@brief SetVibration
		@param[in] bVibration	バイブレーションフラグ
		@return なし
		@details バイブレーションの設定を行う
	*/
	void	SetVibration(const bool bVibration) {

		m_bVibration = bVibration;

	}

#pragma endregion

};