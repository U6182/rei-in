#pragma once

/**

	@file GameObject.h
	@brief ゲームオブジェクト
	@author 木村憂哉
	@date 2019/11/24

*/

#include		"GameElement.h"

class CGameObject {

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CGameObject(void) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CGameObject(void) { }

#pragma endregion

};