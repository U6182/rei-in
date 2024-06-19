#pragma once

/**

	@file SoundManager.h
	@brief サウンドの管理
	@author 木村憂哉
	@date 2019/10/23

*/

#include		"Sound.h"

class CSoundManager {

private:
	
	//! サウンドクラスの配列
	CSound				m_Audio[CGameElement::SOUND_TYPECOUNT];

	//! サウンドの配列
	CSoundBuffer		m_Sound[CGameElement::SOUND_TYPECOUNT];
			
public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CSoundManager(void) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CSoundManager(void) { Release(); }

#pragma endregion

#pragma region 関数

	/**
		@brief Initialize
		@param なし
		@return なし
		@details 全てのサウンドの初期化を行う
	*/
	void		Initialize(void);
	/**
		@brief Update
		@param なし
		@return なし
		@details 全てのサウンドの停止処理の更新を行う
	*/
	void		Update(void);
	/**
		@brief Release
		@param なし
		@return なし
		@details サウンドと自身の解放を行う
	*/
	void		Release(void);
	/**
		@brief Play
		@param[in] type 再生するサウンド
		@return なし
		@details 指定したサウンドの再生を行う
	*/
	void		Play(const int type);
	/**
	@brief EPlay
	@param[in] type 再生するサウンドエフェクト
	@return なし
	@details 指定したサウンドエフェクトの再生を行う
	*/
	void		EPlay(const int type);
	/**
		@brief AllStop
		@param なし
		@return なし
		@details 全てのサウンドの停止を行う
	*/
	void		AllStop(void);
	/**
		@brief Stop
		@param[in] type 停止するサウンド
		@param[out] stopType 停止する種類 
		@return なし
		@details 指定したサウンドを指定した種類で停止を行う
	*/
	void		Stop(const int type, const int stopType);
	/**
		@brief AllPause
		@param なし
		@return なし
		@details 全てのサウンドの一時停止を行う
	*/
	void		AllPause(void);
	/**
		@brief Pause
		@param[in] type 一時停止するサウンド
		@return なし
		@details 指定したサウンドの一時停止を行う
	*/
	void		Pause(const int type);
	/**
		@brief AllResume
		@param なし
		@return なし
		@details 全てのサウンドの再開を行う
	*/
	void		AllResume(void);
	/**
		@brief Resume
		@param[in] type 再開するサウンド
		@return なし
		@details 指定したサウンドの再開を行う
	*/
	void		Resume(const int type);
	
#pragma endregion

	void Load();

#pragma region セッター

	/**
		@brief AllSetVolume
		@param[in] volume 設定するボリューム
		@return なし
		@details 全てのサウンドのボリュームの設定を行う
	*/
	void		AllSetVolume(const float volume);
	/**
		@brief SetVolume
		@param[in] type ボリュームを設定するサウンド
		@param[out] volume	設定するボリューム
		@return なし
		@details 指定したサウンドのボリュームの設定を行う
	*/
	void		SetVolume(const int type, const float volume);

#pragma endregion

#pragma region ゲッター

	/**
		@brief IsPlay
		@param[in] type 確認するサウンド
		@return bool true 再生されている false 再生されていない
		@details 指定したサウンドが再生されているかの確認を行う
	*/
	bool	IsPlay(const int type);
	
#pragma endregion

#pragma region セッター

	/**
		@brief SetSound
		@param[in] pSound
		@return なし
		@details サウンドの設定を行う
	*/
	//void	SetSound(CSoundBuffer* pSound) { m_Sound = pSound; }

#pragma endregion

};