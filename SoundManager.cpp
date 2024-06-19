/**

	@file SoundManager.cpp
	@brief サウンドの管理
	@author 木村憂哉
	@date 2019/12/14

*/

#include		"SoundManager.h"

void CSoundManager::Load() {

	//サウンドのファイルパス
	char* name[] = {

		"GameScene/GameBGM.mp3",
			"GameScene/TimeFaster.mp3",
			"GameScene/HanakoAttack.mp3",
			"GameScene/ChargeAttack.mp3",
			"GameScene/BodyAttack.mp3",
			"GameScene/PianoPlay.mp3",
			"GameScene/Damage.mp3",

	};

	//サウンドの読み込み
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Sound[i].SetBufferCount(5);

		if (!m_Sound[i].Load(name[i])) {

			

		}

	}

	

}

void CSoundManager::Initialize() {

	Load();

	//サウンドの初期化、設定
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].SetSound(&m_Sound[i]);

		m_Audio[i].Initialize();

	}

}

void CSoundManager::Update() {

	//サウンドの停止処理の更新
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].GraduallyStop();

	}

}

void CSoundManager::Release() {

	//全てのサウンドの解放
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Sound[i].Release();

	}

	/*if (m_Sound) {

		delete[] m_Sound;

		m_Sound = nullptr;

	}*/

}

void CSoundManager::Play(const int type) {

	//既に再生されている場合は再生しない
	if (m_Audio[type].IsPlay()) {

		return;

	}

	//サウンドの再生
	m_Audio[type].Play();

}

void CSoundManager::EPlay(const int type) {

	//サウンドエフェクトの再生
	m_Audio[type].Play();

}

void CSoundManager::AllStop() {

	//全てのサウンドを停止
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		if (m_Audio[i].IsPlay()) {

			m_Audio[i].Stop();

		}

	}

}

void CSoundManager::Stop(const int type, const int stopType) {

	//指定したサウンドを指定したタイプで停止
	m_Audio[type].Stop(stopType);

}

void CSoundManager::AllPause() {

	//全てのサウンドを一時停止
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].Pause();

	}

}

void CSoundManager::Pause(int type) {

	//指定したサウンドを一時停止
	m_Audio[type].Pause();

}

void CSoundManager::AllResume() {

	//全ての一時停止されたサウンドを再開
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].Resume();

	}

}

void CSoundManager::Resume(const int type) {

	//指定した一時停止されているサウンドを再開
	m_Audio[type].Resume();

}

void CSoundManager::SetVolume(const int type, const float volume) {

	//指定したサウンドを指定したボリュームに設定
	m_Audio[type].SetVolume(volume);

}

void CSoundManager::AllSetVolume(const float volume) {

	//全てのサウンドを指定したボリュームに設定
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].SetVolume(volume);

	}
	
}

bool CSoundManager::IsPlay(const int type) {

	//指定したサウンドが再生されているかを返す
	return m_Audio[type].IsPlay();

}