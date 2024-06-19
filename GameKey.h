#pragma once

/**

	@file GameKey.h
	@brief ゲームキー
	@author 木村憂哉
	@date 2019/11/23

*/

#include		"GamePad.h"

class CGameKey {

private:

	//! キーのプッシュフラグ
	bool			m_bLastPush;

	//! スティックのホールドフラグ
	bool			m_bHold;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CGameKey(void) { m_bLastPush = false, m_bHold = false; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CGameKey(void) = default;

#pragma endregion	

#pragma region 関数

	/**
		@brief RenderDebug
		@param なし
		@return なし
		@details デバッグの描画を行う
	*/
	void		RenderDebug(void);
	/**
		@brief KeyUp
		@param なし
		@return bool true キーを押している  false キーを放している
		@details 上キーのプッシュ処理を行う
	*/
	bool		KeyUp(void);
	/**
		@brief KeyDown
		@param なし
		@return bool true キーを押している  false キーを放している
		@details 下キーのプッシュ処理を行う
	*/
	bool		KeyDown(void);
	/**
		@brief KeyLeft
		@param なし
		@return bool true キーを押している  false キーを放している
		@details 左キーのプッシュ処理を行う
	*/
	bool		KeyLeft(void);
	/**
		@brief KeyRight
		@param なし
		@return bool true キーを押している  false キーを放している
		@details 右キーのプッシュ処理を行う
	*/
	bool		KeyRight(void);
	/**
		@brief PushA
		@param なし
		@return bool true キーを押している  false キーを放している
		@details Aキーのプッシュ判定を行う
	*/
	bool		PushA(void);
	/**
		@brief PushB
		@param なし
		@return bool true キーを押している  false キーを放している
		@details Bキーのプッシュ判定を行う
	*/
	bool		PushB(void);
	/**
		@brief PushX
		@param なし
		@return bool true キーを押している  false キーを放している
		@details Xキーのプッシュ判定を行う
	*/
	bool		PushX(void);
	/**
		@brief PushY
		@param なし
		@return bool true キーを押している  false キーを放している
		@details Yキーのプッシュ判定を行う
	*/
	bool		PushY(void);
	/**
		@brief PushLB
		@param なし
		@return bool true キーを押している  false キーを放している
		@details LBキーのプッシュ判定を行う
	*/
	bool		PushLB(void);
	/**
		@brief PushRB
		@param なし
		@return bool true キーを押している  false キーを放している
		@details RBキーのプッシュ判定を行う
	*/
	bool		PushRB(void);
	/**
		@brief PushSTRAT
		@param なし
		@return bool true キーを押している  false キーを放している
		@details STRATキーのプッシュ判定を行う
	*/
	bool		PushSTART(void);
	/**
		@brief PushBACK
		@param なし
		@return bool true キーを押している  false キーを放している
		@details BACKキーのプッシュ判定を行う
	*/
	bool		PushBACK(void);
	/**
		@brief HoldLT
		@param なし
		@return bool true ホールド状態  false ホールド状態ではない
		@details LTのホールド判定を行う
	*/
	bool		HoldLT(void);
	/**
		@brief HoldRT
		@param なし
		@return bool true ホールド状態  false ホールド状態ではない
		@details RTのホールド判定を行う
	*/
	bool		HoldRT(void);
	/**
		@brief UpStick
		@param なし
		@return bool true ホールド状態  false ホールド状態ではない
		@details 上スティックのホールド判定を行う
	*/
	bool		UpStick(void);
	/**
		@brief DownStick
		@param なし
		@return bool true ホールド状態  false ホールド状態ではない
		@details 下スティックのホールド判定を行う
	*/
	bool		DownStick(void);
	/**
		@brief LeftStick
		@param なし
		@return bool true ホールド状態  false ホールド状態ではない
		@details 左スティックのホールド判定を行う
	*/
	bool		LeftStick(void);
	/**
		@brief RightStick
		@param なし
		@return bool true ホールド状態  false ホールド状態ではない
		@details 右スティックのホールド判定を行う
	*/
	bool		RigthStick(void);

#pragma endregion

};