#pragma once

/**

	@file Controller.h
	@brief コントローラー
	@author 木村憂哉
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

	//! ゲームパッド
	CGamePad			m_GameKey;

	//! コマンド
	CCommand**			m_pButton;

	//! コマンドリスト
	CDynamicArray<int>	m_CommandList;

	//! 振動時間
	float				m_VibrationTime;

#pragma region セッター

	/**
		@brief SetCommand_A
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Aの設定を行う
	*/
	void	SetCommand_A(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_A]) {

			delete m_pButton[CGameElement::CONTROLLER_A];

		}

		m_pButton[CGameElement::CONTROLLER_A] = pCommand;

	}
	/**
		@brief SetCommand_B
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Bの設定を行う
	*/
	void	SetCommand_B(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_B]) {

			delete m_pButton[CGameElement::CONTROLLER_B];

		}

		m_pButton[CGameElement::CONTROLLER_B] = pCommand;

	}
	/**
		@brief SetCommandPull_B
		@param pCommand 設定するコマンド
		@return なし
		@details CommandPull_Bの設定を行う
	*/
	void	SetCommandPull_B(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_PULL_B]) {

			delete m_pButton[CGameElement::CONTROLLER_PULL_B];

		}

		m_pButton[CGameElement::CONTROLLER_PULL_B] = pCommand;

	}
	/**
		@brief SetCommandHold_B
		@param pCommand 設定するコマンド
		@return なし
		@details CommandHold_Bの設定を行う
	*/
	void	SetCommandHold_B(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_HOLD_B]) {

			delete m_pButton[CGameElement::CONTROLLER_HOLD_B];

		}

		m_pButton[CGameElement::CONTROLLER_HOLD_B] = pCommand;

	}
	/**
		@brief SetCommand_X
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Xの設定を行う
	*/
	void	SetCommand_X(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_X]) {

			delete m_pButton[CGameElement::CONTROLLER_X];

		}

		m_pButton[CGameElement::CONTROLLER_X] = pCommand;

	}
	/**
		@brief SetCommandHold_X
		@param pCommand 設定するコマンド
		@return なし
		@details CommandHold_Xの設定を行う
	*/
	void	SetCommandHold_X(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_HOLD_X]) {

			delete m_pButton[CGameElement::CONTROLLER_HOLD_X];

		}

		m_pButton[CGameElement::CONTROLLER_HOLD_X] = pCommand;

	}
	/**
		@brief SetCommand_Y
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Yの設定を行う
	*/
	void	SetCommand_Y(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_Y]) {

			delete m_pButton[CGameElement::CONTROLLER_Y];

		}

		m_pButton[CGameElement::CONTROLLER_Y] = pCommand;

	}
	/**
		@brief SetCommand_Start
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Startの設定を行う
	*/
	void	SetCommand_Start(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_START]) {

			delete m_pButton[CGameElement::CONTROLLER_START];

		}

		m_pButton[CGameElement::CONTROLLER_START] = pCommand;

	}
	/**
		@brief SetCommand_Back
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Backの設定を行う
	*/
	void	SetCommand_Back(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_BACK]) {

			delete m_pButton[CGameElement::CONTROLLER_BACK];

		}

		m_pButton[CGameElement::CONTROLLER_BACK] = pCommand;

	}
	/**
		@brief SetCommand_Key_Left
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Key_Upの設定を行う
	*/
	void	SetCommand_Key_Left(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_LEFT]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_LEFT];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_LEFT] = pCommand;

	}
	/**
		@brief SetCommand_Key_Right
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Key_Downの設定を行う
	*/
	void	SetCommand_Key_Right(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_RIGHT]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_RIGHT];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_RIGHT] = pCommand;

	}
	/**
		@brief SetCommand_Key_Up
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Key_Upの設定を行う
	*/
	void	SetCommand_Key_Up(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_UP]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_UP];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_UP] = pCommand;

	}
	/**
		@brief SetCommand_Key_Down
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Key_Downの設定を行う
	*/
	void	SetCommand_Key_Down(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_KEY_DOWN]) {

			delete m_pButton[CGameElement::CONTROLLER_KEY_DOWN];

		}

		m_pButton[CGameElement::CONTROLLER_KEY_DOWN] = pCommand;

	}
	/**
		@brief SetCommand_Stick
		@param pCommand 設定するコマンド
		@return なし
		@details Command_Stickの設定を行う
	*/
	void	SetCommand_Stick(CCommand* pCommand) {

		if (m_pButton[CGameElement::CONTROLLER_STICK]) {

			delete m_pButton[CGameElement::CONTROLLER_STICK];

		}

		m_pButton[CGameElement::CONTROLLER_STICK] = pCommand;

	}

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CController(void) : m_pButton(new CCommand*[CGameElement::CONTROLLER_COUNT]()) {
	
		XGAMEPADCREATEINFO padInfo;

		padInfo.Size = sizeof(padInfo);

		//接続番号
		padInfo.No = 0;

		//ゲームパッドの初期化
		m_GameKey.Create(&padInfo);

		//バイブレーション時間の初期化
		m_VibrationTime = 0.0f;

	}
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CController(void) { Release(); }

#pragma endregion

#pragma region 関数

	/**
		@brief Input
		@param なし
		@return CCommand 入力コマンド
		@details 入力コマンドを返す
	*/
	const	CDynamicArray<int>*	Input(void) {

		m_GameKey.RefreshKey();

		//コマンドのリセット
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
		@param なし
		@return なし
		@details タイトルシーンのコマンドの設定を行う
	*/
	void	SetTitleCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

		SetCommand_Key_Left(new CLeftSelectCommand());

		SetCommand_Key_Right(new CRightSelectCommand());

	}
	/**
		@brief SetOptionCommand
		@param なし
		@return なし
		@details オプションシーンのコマンドの設定を行う
	*/
	void	SetOptionCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

		SetCommand_Key_Left(new CLeftSelectCommand());

		SetCommand_Key_Right(new CRightSelectCommand());

	}
	/**
		@brief SetOperationDescriptionCommand
		@param なし
		@return なし
		@details 操作説明シーンのコマンドの設定を行う
	*/
	void	SetOperationDescriptionCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

		SetCommand_Key_Left(new CLeftSelectCommand());

		SetCommand_Key_Right(new CRightSelectCommand());

	}
	/**
		@brief SetGameOverCommand
		@param なし
		@return なし
		@details ゲームオーバーシーンのコマンドの設定を行う
	*/
	void	SetGameOverCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

	}
	/**
		@brief SetGameClearCommand
		@param なし
		@return なし
		@details ゲームクリアシーンのコマンドの設定を行う
	*/
	void	SetGameClearCommand(void) {

		ButtonRelease();

		SetCommand_A(new CTransitionCommand());

	}
	/**
		@brief SetCreditCommand
		@param なし
		@return なし
		@details クレジットシーンのコマンドの設定を行う
	*/
	void	SetCreditCommand(void) {

		ButtonRelease();

	}
	/**
		@brief SetSoulPlayerCommand
		@param なし
		@return なし
		@details 魂プレイヤーのコマンドの設定を行う
	*/
	void	SetSoulPlayerCommand(void) {

		ButtonRelease();

		SetCommand_Stick(new CMoveCommand());

		SetCommand_A(new CJumpCommand());

		SetCommandHold_X(new CPossessionCommand());

	}
	/**
		@brief SetHanakoPlayerCommand
		@param なし
		@return なし
		@details 花子プレイヤーのコマンドの設定を行う
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
		@param なし
		@return なし
		@details テケテケプレイヤーのコマンドの設定を行う
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
		@param なし
		@return なし
		@details 金次郎プレイヤーのコマンドの設定を行う
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
		@param なし
		@return なし
		@details 人体模型プレイヤーのコマンドの設定を行う
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
		@param なし
		@return なし
		@details ボタンの解放を行う
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
		@param なし
		@return なし
		@details コントローラーの解放を行う
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
		@param なし
		@return なし
		@details コントローラーの更新を行う
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
		@param[in] left 左の振動
		@param[in] right 右の振動
		@param[in] vibrationTime 振動時間
		@return なし
		@details コントローラーの振動を行う
	*/
	void	Vibration(const float left, const float right, const float vibrationTime) {

		//振動の停止
		m_GameKey.StopVibration();

		//振動開始
		m_GameKey.StartVibration(left * USHRT_MAX, right * USHRT_MAX);

		m_VibrationTime = vibrationTime;

	}

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetCommand
		@param なし
		@return CCommand** コマンド
		@details コマンドの取得を行う
	*/
	CCommand**	GetCommand(void) {

		return m_pButton;

	}
	/**
		@brief GetHorizontal
		@param なし
		@return float horizonatal
		@details horizontalの取得を行う
	*/
	float	GetHorizontal(void) {

		return m_GameKey.GetStickHorizontal();

	}

#pragma endregion

};