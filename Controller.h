#pragma once

/**

	@file Controller.h
	@brief �R���g���[���[
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"GamePad.h"
#include	"Command.h"
#include	"JumpCommand.h"
#include	"TransitionCommand.h"
#include	"LeftSelectCommand.h"
#include	"RightSelectCommand.h"
#include	"DownSelectCommand.h"
#include	"UpSelectCommand.h"
#include	"MoveCommand.h"
#include	"PossessionCommand.h"
#include	"PossessionLiftedCommand.h"
#include	"HanakoAttackCommand.h"
#include	"TekeTekeChargeCommand.h"
#include	"TekeTekeChargeAttackCommand.h"
#include	"CarryCommand.h"
#include	"HumanBodyModleAttackCommand.h"
#include	"TekeTekeChargeStopCommand.h"

class CController {

private:

	//! �Q�[���p�b�h
	CGamePad			m_GameKey;

	//! �R�}���h
	CCommand**			m_pButton;

	//! �R�}���h���X�g
	CDynamicArray<int>	m_CommandList;

	//! �U������
	float				m_VibrationTime;

#pragma region �Z�b�^�[

	/**
		@brief SetCommand_A
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_A�̐ݒ���s��
	*/
	void	SetCommand_A(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_A]) {

			delete m_pButton[CGameElement::CONTROLLER_A];

		}

		m_pButton[CGameElement::CONTROLLER_A] = pCommand;

	}
	/**
		@brief SetCommand_B
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_B�̐ݒ���s��
	*/
	void	SetCommand_B(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_B]) {

			delete m_pButton[CGameElement::CONTROLLER_B];

		}

		m_pButton[CGameElement::CONTROLLER_B] = pCommand;

	}
	/**
		@brief SetCommandPull_B
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details CommandPull_B�̐ݒ���s��
	*/
	void	SetCommandPull_B(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_PULL_B]) {

			delete m_pButton[CGameElement::CONTROLLER_PULL_B];

		}

		m_pButton[CGameElement::CONTROLLER_PULL_B] = pCommand;

	}
	/**
		@brief SetCommandHold_B
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details CommandHold_B�̐ݒ���s��
	*/
	void	SetCommandHold_B(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_HOLD_B]) {

			delete m_pButton[CGameElement::CONTROLLER_HOLD_B];

		}

		m_pButton[CGameElement::CONTROLLER_HOLD_B] = pCommand;

	}
	/**
		@brief SetCommand_X
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_X�̐ݒ���s��
	*/
	void	SetCommand_X(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_X]) {

			delete m_pButton[CGameElement::CONTROLLER_X];

		}

		m_pButton[CGameElement::CONTROLLER_X] = pCommand;

	}
	/**
		@brief SetCommandHold_X
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details CommandHold_X�̐ݒ���s��
	*/
	void	SetCommandHold_X(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_HOLD_X]) {

			delete m_pButton[CGameElement::CONTROLLER_HOLD_X];

		}

		m_pButton[CGameElement::CONTROLLER_HOLD_X] = pCommand;

	}
	/**
		@brief SetCommand_Y
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Y�̐ݒ���s��
	*/
	void	SetCommand_Y(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_Y]) {

			delete m_pButton[CGameElement::CONTROLLER_Y];

		}

		m_pButton[CGameElement::CONTROLLER_Y] = pCommand;

	}
	/**
		@brief SetCommand_Start
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Start�̐ݒ���s��
	*/
	void	SetCommand_Start(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_START]) {

			delete m_pButton[CGameElement::CONTROLLER_START];

		}

		m_pButton[CGameElement::CONTROLLER_START] = pCommand;

	}
	/**
		@brief SetCommand_Back
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Back�̐ݒ���s��
	*/
	void	SetCommand_Back(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_BACK]) {

			delete m_pButton[CGameElement::CONTROLLER_BACK];

		}

		m_pButton[CGameElement::CONTROLLER_BACK] = pCommand;

	}
	/**
		@brief SetCommand_Key_Left
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Key_Up�̐ݒ���s��
	*/
	void	SetCommand_Key_Left(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_LEFT]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_LEFT];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_LEFT] = pCommand;

	}
	/**
		@brief SetCommand_Key_Right
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Key_Down�̐ݒ���s��
	*/
	void	SetCommand_Key_Right(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_RIGHT]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_RIGHT];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_RIGHT] = pCommand;

	}
	/**
		@brief SetCommand_Key_Up
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Key_Up�̐ݒ���s��
	*/
	void	SetCommand_Key_Up(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_UP]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_UP];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_UP] = pCommand;

	}
	/**
		@brief SetCommand_Key_Down
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Key_Down�̐ݒ���s��
	*/
	void	SetCommand_Key_Down(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_DOWN]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_DOWN];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_DOWN] = pCommand;

	}
	/**
		@brief SetCommand_Stick
		@param pCommand �ݒ肷��R�}���h
		@return �Ȃ�
		@details Command_Stick�̐ݒ���s��
	*/
	void	SetCommand_Stick(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_STICK]) {

			delete m_pButton[CGameElement::CONTROLLER_STICK];

		}

		m_pButton[CGameElement::CONTROLLER_STICK] = pCommand;

	}

#pragma endregion

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CController(void) : m_pButton(new CCommand*[CGameElement::CONTROLLER_COUNT]()) {
	
		XGAMEPADCREATEINFO padInfo;

		padInfo.Size = sizeof(padInfo);

		//�ڑ��ԍ�
		padInfo.No = 0;

		//�Q�[���p�b�h�̏�����
		m_GameKey.Create(&padInfo);

		//�o�C�u���[�V�������Ԃ̏�����
		m_VibrationTime = 0.0f;

	}
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CController(void) { Release(); }

#pragma endregion

#pragma region �֐�

	/**
		@brief Input
		@param �Ȃ�
		@return CCommand ���̓R�}���h
		@details ���̓R�}���h��Ԃ�
	*/
	const	CDynamicArray<int>*	Input(void) {

		m_GameKey.RefreshKey();

		//�R�}���h�̃��Z�b�g
		m_CommandList.Release();

		if (m_GameKey.IsKeyPush(XINPUT_A)) {

			m_CommandList.Add(CGameElement::CONTROLLER_A);

		}

		if (m_GameKey.IsKeyHold(XINPUT_B)) {

			m_CommandList.Add(CGameElement::CONTROLLER_HOLD_B);

		}

		if (m_GameKey.IsKeyPull(XINPUT_B)) {

			m_CommandList.Add(CGameElement::CONTROLLER_PULL_B);

		}

		if (m_GameKey.IsKeyPush(XINPUT_B)) {

			m_CommandList.Add(CGameElement::CONTROLLER_B);

		}

		if (m_GameKey.IsKeyHold(XINPUT_X)) {

			m_CommandList.Add(CGameElement::CONTROLLER_HOLD_X);

		}
		
		if (m_GameKey.IsKeyPush(XINPUT_X)) {

			m_CommandList.Add(CGameElement::CONTROLLER_X);

		}

		if (m_GameKey.IsKeyPush(XINPUT_Y)) {

			m_CommandList.Add(CGameElement::CONTROLLER_Y);

		}
		
		if (m_GameKey.IsKeyPush(XINPUT_START)) {

			m_CommandList.Add(CGameElement::CONTROLLER_START);

		}

		if (m_GameKey.IsKeyPush(XINPUT_BACK)) {

			m_CommandList.Add(CGameElement::CONTROLLER_BACK);

		}

		if (m_GameKey.IsKeyPush(XINPUT_DP_LEFT)) {

			m_CommandList.Add(CGameElement::CONTROLLER_KEY_LEFT);

		}

		if (m_GameKey.IsKeyPush(XINPUT_DP_RIGHT)) {

			m_CommandList.Add(CGameElement::CONTROLLER_KEY_RIGHT);

		}

		if (m_GameKey.IsKeyPush(XINPUT_DP_UP)) {

			m_CommandList.Add(CGameElement::CONTROLLER_KEY_UP);

		}

		if (m_GameKey.IsKeyPush(XINPUT_DP_DOWN)) {

			m_CommandList.Add(CGameElement::CONTROLLER_KEY_DOWN);

		}

		if (m_GameKey.GetStickHorizontal() > 0.1f || m_GameKey.GetStickHorizontal() < -0.1f || m_GameKey.GetStickVertical() > 0.1f || m_GameKey.GetStickVertical() < -0.1f) {

			m_CommandList.Add(CGameElement::CONTROLLER_STICK);

		}

		return &m_CommandList;

	};
	/**
		@brief SetTitleCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �^�C�g���V�[���̃R�}���h�̐ݒ���s��
	*/
	void	SetTitleCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

		SetCommand_Key_Left(new CLeftSelectCommand());

		SetCommand_Key_Right(new CRightSelectCommand());

	}
	/**
		@brief SetOptionCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �I�v�V�����V�[���̃R�}���h�̐ݒ���s��
	*/
	void	SetOptionCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

		SetCommand_Key_Left(new CLeftSelectCommand());

		SetCommand_Key_Right(new CRightSelectCommand());

	}
	/**
		@brief SetOperationDescriptionCommand
		@param �Ȃ�
		@return �Ȃ�
		@details ��������V�[���̃R�}���h�̐ݒ���s��
	*/
	void	SetOperationDescriptionCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

		SetCommand_Key_Left(new CLeftSelectCommand());

		SetCommand_Key_Right(new CRightSelectCommand());

	}
	/**
		@brief SetGameOverCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���I�[�o�[�V�[���̃R�}���h�̐ݒ���s��
	*/
	void	SetGameOverCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

	}
	/**
		@brief SetGameClearCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���N���A�V�[���̃R�}���h�̐ݒ���s��
	*/
	void	SetGameClearCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

	}
	/**
		@brief SetCreditCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �N���W�b�g�V�[���̃R�}���h�̐ݒ���s��
	*/
	void	SetCreditCommand(void) {

		ButtonRelease();

	}
	/**
		@brief SetSoulPlayerCommand
		@param �Ȃ�
		@return �Ȃ�
		@details ���v���C���[�̃R�}���h�̐ݒ���s��
	*/
	void	SetSoulPlayerCommand(void) {

		ButtonRelease();

		SetCommand_Stick(new CMoveCommand());

		SetCommand_A(new CJumpCommand());

		SetCommandHold_X(new CPossessionCommand());

	}
	/**
		@brief SetHanakoPlayerCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �Ԏq�v���C���[�̃R�}���h�̐ݒ���s��
	*/
	void	SetHanakoPlayerCommand(void) {

		ButtonRelease();

		SetCommand_Stick(new CMoveCommand());

		SetCommand_A(new CJumpCommand());

		SetCommand_B(new CHanakoAttackCommand());

		SetCommand_X(new CPossessionLiftedCommand());

	}
	/**
		@brief SetTekeTekePlayerCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �e�P�e�P�v���C���[�̃R�}���h�̐ݒ���s��
	*/
	void	SetTekeTekePlayerCommand(void) {

		ButtonRelease();

		SetCommand_Stick(new CMoveCommand());

		SetCommand_A(new CJumpCommand());

		SetCommandHold_B(new CTekeTekeChargeCommand());

		SetCommandPull_B(new CTekeTekeChargeAttackCommand());

		SetCommand_Y(new CTekeTekeChargeStopCommand());

		SetCommand_X(new CPossessionLiftedCommand());

	}
	/**
		@brief SetKinzirouPlayerCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �����Y�v���C���[�̃R�}���h�̐ݒ���s��
	*/
	void	SetKinzirouPlayerCommand(void) {

		ButtonRelease();

		SetCommand_Stick(new CMoveCommand());

		SetCommand_A(new CJumpCommand());

		SetCommand_B(new CCarryCommand());

		SetCommand_X(new CPossessionLiftedCommand());

	}
	/**
		@brief SetHumanBodyModlePlayerCommand
		@param �Ȃ�
		@return �Ȃ�
		@details �l�̖͌^�v���C���[�̃R�}���h�̐ݒ���s��
	*/
	void	SetHumanBodyModlePlayerCommand(void) {

		ButtonRelease();

		SetCommand_Stick(new CMoveCommand());

		SetCommand_A(new CJumpCommand());

		SetCommand_B(new CHumanBodyModleAttackCommand());

		SetCommand_X(new CPossessionLiftedCommand());

	}
	/**
		@brief ButtonRelease
		@param �Ȃ�
		@return �Ȃ�
		@details �{�^���̉�����s��
	*/
	void	ButtonRelease(void) {

		for (int i = 0; i < CGameElement::CONTROLLER_COUNT; i++) {

			if (m_pButton[i]) {

				delete m_pButton[i];

				m_pButton[i] = nullptr;

			}

		}

	}
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �R���g���[���[�̉�����s��
	*/
	void	Release(void) {

		ButtonRelease();

		if (m_pButton) {

			delete[] m_pButton;

			m_pButton = nullptr;

		}

		m_GameKey.StopVibration();

	}
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �R���g���[���[�̍X�V���s��
	*/
	void	Update(void) {

		m_VibrationTime -= CUtilities::GetFrameSecond();

		if (m_VibrationTime < 0) {

			m_VibrationTime = 0;

			m_GameKey.StopVibration();

		}

	}
	/**
		@brief Vibration
		@param[in] left ���̐U��
		@param[in] right �E�̐U��
		@param[in] vibrationTime �U������
		@return �Ȃ�
		@details �R���g���[���[�̐U�����s��
	*/
	void	Vibration(const float left, const float right, const float vibrationTime) {

		//�U���̒�~
		m_GameKey.StopVibration();

		//�U���J�n
		m_GameKey.StartVibration(left * USHRT_MAX, right * USHRT_MAX);

		m_VibrationTime = vibrationTime;

	}

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetCommand
		@param �Ȃ�
		@return CCommand** �R�}���h
		@details �R�}���h�̎擾���s��
	*/
	CCommand**	GetCommand(void) {

		return m_pButton;

	}
	/**
		@brief GetHorizontal
		@param �Ȃ�
		@return float horizonatal
		@details horizontal�̎擾���s��
	*/
	float	GetHorizontal(void) {

		return m_GameKey.GetStickHorizontal();

	}

#pragma endregion

};