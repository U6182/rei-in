#pragma once

/**

	@file Sound.h
	@brief サウンド
	@author 木村憂哉
	@date 2019/10/23

*/

#include		"GameElement.h"

class CSound {

private:

	//! サウンドのポインタ
	CSoundBuffer*		m_pSound;

	//! サウンドのストップフラグ
	bool				m_bStop;

	//! サウンドのボリューム
	float				m_Volume;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CSound(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CSound(void);

#pragma endregion

#pragma region 関数

	/**
		@brief Initialize
		@param なし
		@return なし
		@details サウンドの初期化を行う
	*/
	void	Initialize(void);
	/**
		@brief Play
		@param なし
		@return なし
		@details サウンドの再生を行う
	*/
	void	Play(void);
	/**
		@brief Stop
		@param[in] stopType 停止する種類
		@return なし
		@details サウンドを指定した種類で停止を行う
	*/
	void	Stop(const int stopType);
	/**
		@brief Stop
		@param なし
		@return なし
		@details サウンドの停止を行う
	*/
	void	Stop(void);
	/**
		@brief GraduallyStop
		@param なし
		@return なし
		@details サウンドを徐々に停止を行う
	*/
	void	GraduallyStop(void);
	/**
		@brief Pause
		@param なし
		@return なし
		@details サウンドの一時停止を行う
	*/
	void	Pause(void);
	/**
		@brief Resume
		@param なし
		@return なし
		@details サウンドの再開を行う
	*/
	void	Resume(void);
	
#pragma endregion

#pragma region セッター

	/**
		@brief SetSound
		@param[in] pSound 設定するサウンドのポインタ
		@return なし
		@details サウンドの設定を行う
	*/
	void	SetSound(CSoundBuffer* pSound) { m_pSound = pSound; }
	/**
		@brief SetVolume
		@param[in] volume 設定するボリューム
		@return なし
		@details サウンドに指定したボリュームの設定を行う
	*/
	void	SetVolume(const float volume);

#pragma endregion

#pragma region ゲッター

	/**
		@brief IsPlay
		@param なし
		@return bool true 再生されている false 再生されていない
		@details サウンドが再生されているかを取得する
	*/
	bool	IsPlay(void) { return m_pSound->IsPlay(); }

#pragma endregion

};