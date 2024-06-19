/**

	@file GameKey.cpp
	@brief ゲームキー
	@author 木村憂哉
	@date 2019/12/20

*/

#include		"GameKey.h"

bool CGameKey::KeyUp() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//前回押してたが放した場合
	if (m_bLastPush && Pov == -1) {

		//押せるようになる
		m_bLastPush = false;

	}else if (m_bLastPush) {

		return false;

	}

	//放していて上キーを押した場合
	if (Pov == 0 && !m_bLastPush) {

		m_bLastPush = true;

	}

	return m_bLastPush;

}

bool CGameKey::KeyDown() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//前回押してたが放した場合
	if (m_bLastPush && Pov == -1) {

		//押せるようになる
		m_bLastPush = false;

	}
	else if (m_bLastPush) {

		return false;

	}

	//放していて下キーを押した場合
	if (Pov / 100 == 180 && !m_bLastPush) {

		m_bLastPush = true;

	}

	return m_bLastPush;

}

bool CGameKey::KeyLeft() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//前回押してたが放した場合
	if (m_bLastPush && Pov == -1) {

		//押せるようになる
		m_bLastPush = false;

	}
	else if (m_bLastPush) {

		return false;

	}

	//放していて左キーを押した場合
	if (Pov / 100 == 270 && !m_bLastPush) {

		m_bLastPush = true;

	}

	return m_bLastPush;

}

bool CGameKey::KeyRight() {

	long Pov = g_pInput->GetGamePad(0)->GetPadState()->rgdwPOV[0];

	//前回押してたが放した場合
	if (m_bLastPush && Pov == -1) {

		//押せるようになる
		m_bLastPush = false;

	}
	else if (m_bLastPush) {

		return false;

	}

	//放していて右キーを押した場合
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

	//Aボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_A);

}

bool CGameKey::PushB() {

	//Bボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_B);

}

bool CGameKey::PushX() {

	//Xボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_X);

}

bool CGameKey::PushY() {

	//Yボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_Y);

}

bool CGameKey::PushLB() {

	//LBボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_LB);

}

bool CGameKey::PushRB() {

	//RBボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_RB);

}

bool CGameKey::PushSTART() {

	//STARTボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_START);

}

bool CGameKey::PushBACK() {

	//BACKボタンを押しているかを返す
	return g_pInput->GetGamePad(0)->IsKeyPush(GAMEKEY_BACK);

}

bool CGameKey::HoldLT() {

	//LTをホールドしているかを返す
	if (g_pInput->GetGamePad(0)->GetPadState()->lZ >= 500.0f) {

		m_bHold = true;

	}
	else {

		m_bHold = false;

	}

	return m_bHold;

}

bool CGameKey::HoldRT() {

	//RTをホールドしているかを返す
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

	//上スティックを傾けているかを返す
	if (g_pInput->GetGamePad(0)->GetStickVertical() > 0.8f) {

		m_bHold = true;
		
	}

	return m_bHold;

}

bool CGameKey::DownStick() {

	m_bHold = false;

	//下スティックを傾けているかを返す
	if (g_pInput->GetGamePad(0)->GetStickVertical() < -0.8f) {

		m_bHold = true;

	}

	return m_bHold;

}

bool CGameKey::LeftStick() {

	m_bHold = false;

	//左スティックを傾けているかを返す
	if (g_pInput->GetGamePad(0)->GetStickHorizontal() > 0.8f) {

		m_bHold = true;

	}

	return m_bHold;

}

bool CGameKey::RigthStick() {

	m_bHold = false;

	//右スティックを傾けているかを返す
	if (g_pInput->GetGamePad(0)->GetStickHorizontal() < -0.8f) {

		m_bHold = true;

	}

	return m_bHold;

}

