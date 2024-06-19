/**

	@file GameKey.cpp
	@brief �Q�[���L�[
	@author �ؑ��J��
	@date 2019/12/20

*/

#include		"GameKey.h"

bool CGameKey::KeyUp() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//�O�񉟂��Ă����������ꍇ
	if (m_bLastPush && Pov == -1) {

		//������悤�ɂȂ�
		m_bLastPush = false;

	}else if (m_bLastPush) {

		return false;

	}

	//�����Ă��ď�L�[���������ꍇ
	if (Pov == 0 && !m_bLastPush) {

		m_bLastPush = true;

	}

	return m_bLastPush;

}

bool CGameKey::KeyDown() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//�O�񉟂��Ă����������ꍇ
	if (m_bLastPush && Pov == -1) {

		//������悤�ɂȂ�
		m_bLastPush = false;

	}
	else if (m_bLastPush) {

		return false;

	}

	//�����Ă��ĉ��L�[���������ꍇ
	if (Pov / 100 == 180 && !m_bLastPush) {

		m_bLastPush = true;

	}

	return m_bLastPush;

}

bool CGameKey::KeyLeft() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//�O�񉟂��Ă����������ꍇ
	if (m_bLastPush && Pov == -1) {

		//������悤�ɂȂ�
		m_bLastPush = false;

	}
	else if (m_bLastPush) {

		return false;

	}

	//�����Ă��č��L�[���������ꍇ
	if (Pov / 100 == 270 && !m_bLastPush) {

		m_bLastPush = true;

	}

	return m_bLastPush;

}

bool CGameKey::KeyRight() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//�O�񉟂��Ă����������ꍇ
	if (m_bLastPush && Pov == -1) {

		//������悤�ɂȂ�
		m_bLastPush = false;

	}
	else if (m_bLastPush) {

		return false;

	}

	//�����Ă��ĉE�L�[���������ꍇ
	if (Pov / 100 == 90 && !m_bLastPush) {

		m_bLastPush = true;

	}

	return m_bLastPush;

}

void CGameKey::RenderDebug() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	CGraphicsUtilities::RenderString(0, 30, "%ld",Pov);
	CGraphicsUtilities::RenderString(0, 60, "%ld",Pov/100);
}

bool CGameKey::PushA() {

	//A�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_A);

}

bool CGameKey::PushB() {

	//B�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_B);

}

bool CGameKey::PushX() {

	//X�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_X);

}

bool CGameKey::PushY() {

	//Y�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_Y);

}

bool CGameKey::PushLB() {

	//LB�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_LB);

}

bool CGameKey::PushRB() {

	//RB�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_RB);

}

bool CGameKey::PushSTART() {

	//START�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_START);

}

bool CGameKey::PushBACK() {

	//BACK�{�^���������Ă��邩��Ԃ�
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_BACK);

}

bool CGameKey::HoldLT() {

	//LT���z�[���h���Ă��邩��Ԃ�
	if (g_pInput->GetGamePad(0)->GetPadState()->lZ >= 500.0f) {

		m_bHold = true;

	}
	else {

		m_bHold = false;

	}

	return m_bHold;

}

bool CGameKey::HoldRT() {

	//RT���z�[���h���Ă��邩��Ԃ�
	if (g_pInput->GetGamePad(0)->GetPadState()->lZ <= -500.0f) {

		m_bHold = true;

	}
	else {

		m_bHold = false;

	}

	return m_bHold;

}

bool CGameKey::UpStick() {

	m_bHold = false;

	//��X�e�B�b�N���X���Ă��邩��Ԃ�
	if (g_pInput->GetGamePad(0)->GetStickVertical() > 0.8f) {

		m_bHold = true;
		
	}

	return m_bHold;

}

bool CGameKey::DownStick() {

	m_bHold = false;

	//���X�e�B�b�N���X���Ă��邩��Ԃ�
	if (g_pInput->GetGamePad(0)->GetStickVertical() < -0.8f) {

		m_bHold = true;

	}

	return m_bHold;

}

bool CGameKey::LeftStick() {

	m_bHold = false;

	//���X�e�B�b�N���X���Ă��邩��Ԃ�
	if (g_pInput->GetGamePad(0)->GetStickHorizontal() > 0.8f) {

		m_bHold = true;

	}

	return m_bHold;

}

bool CGameKey::RigthStick() {

	m_bHold = false;

	//�E�X�e�B�b�N���X���Ă��邩��Ԃ�
	if (g_pInput->GetGamePad(0)->GetStickHorizontal() < -0.8f) {

		m_bHold = true;

	}

	return m_bHold;

}

