#pragma once

/**

	@file GamePad.h
	@brief �Q�[���p�b�h
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"Mof.h"

class CGamePad : public CXGamePad {

public:

#pragma region �Q�b�^�[

	/**
		@brief GetGamePad
		@param �Ȃ�
		@return XINPUT_GAMEPAD �Q�[���p�b�h�̏��
		@details �Q�[���p�b�h�̏�Ԃ̎擾���s��
	*/
	XINPUT_GAMEPAD GetGamePad() {

		return m_PadState.Gamepad;

	}

#pragma endregion

};