#pragma once

/**

	@file GamePad.h
	@brief ゲームパッド
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"Mof.h"

class CGamePad : public CXGamePad {

public:

#pragma region ゲッター

	/**
		@brief GetGamePad
		@param なし
		@return XINPUT_GAMEPAD ゲームパッドの状態
		@details ゲームパッドの状態の取得を行う
	*/
	XINPUT_GAMEPAD GetGamePad() {

		return m_PadState.Gamepad;

	}

#pragma endregion

};