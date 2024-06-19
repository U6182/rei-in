#pragma once

/**

	@file FontManager.h
	@brief フォントの管理
	@author 木村憂哉
	@date 2019/11/23

*/

#include		"GameElement.h"

class CFontManager {

private:

	//! フォント
	std::map<int, CFont*>	m_Font;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CFontManager(void) : m_Font() { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CFontManager(void) { Release(); }

#pragma endregion		

#pragma region 関数

	/**
		@brief Release
		@param なし
		@return なし
		@details フォントと自身の解放を行う
	*/
	void	Release(void);
	/**
		@brief Length
		@param[in] str 文字数を調べる文字列
		@return int 文字数
		@details 文字列の文字数を調べる
	*/
	int		Length(const char* str);

#pragma endregion

#pragma region ゲッター

	
	/**
		@brief GetFont
		@param[in] size フォントのサイズ
		@return CFont* フォントのポインタ
		@details 作成したフォントを取得する
	*/
	CFont*	GetFont(const int size);

#pragma endregion
	
};