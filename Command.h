#pragma once

/**

	@file Command.h
	@brief コマンド
	@author 木村憂哉
	@date 2020/10/23

*/

#include		"GameObject.h"

class CCommand {

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CCommand(void) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CCommand(void) { ; }

#pragma endregion

#pragma region 関数

	/**
		@brief Execute
		@param[in] pGameObject ゲームオブジェクト
		@return なし
		@details コマンド操作を行う
	*/
	const	virtual		void		Execute(CGameObject* pGameObject) { ; }

#pragma endregion

};