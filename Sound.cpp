/**

	@file Sound.cpp
	@brief サウンド
	@author 木村憂哉
	@date 2019/12/14

*/

#include		"Sound.h"

CSound::CSound() : m_pSound(nullptr) {

	//! サウンドのストップフラグの初期化
	m_bStop = false;

	//! サウンドのボリュームの初期化
	m_Volume = 1.0f;

}

CSound::~CSound() {

}

void CSound::Initialize() {

	//! サウンドのストップフラグの初期化
	m_bStop = false;

	//! サウンドのボリュームの初期化
	m_Volume = 1.0f;

}

void CSound::Play() {

	//サウンドの再生
	m_pSound->Play();

}

void CSound::Stop(const int stopType) {

	//指定した種類でサウンドの停止
	switch (stopType) 
	{
		
	case CGameElement::STOP_SUDDEN:

		if (m_pSound->IsPlay()) {

			m_pSound->Stop();

		}

		break;
	case CGameElement::STOP_GRADUALLY:

		if (m_pSound->IsPlay()) {

			m_bStop = true;

		}

		break;

	}

}

void CSound::Stop() {

	//サウンドの停止
	m_pSound->Stop();

}

void CSound::GraduallyStop() {

	if (m_bStop) {

		//サウンドが再生されている間徐々に停止
		if (m_pSound->IsPlay()) {

			m_Volume -= 0.1f;

			m_pSound->SetVolume(m_Volume);

			//ボリュームが0以下になった場合サウンドを停止し初期化を行う
			if (m_Volume <= 0) {

				m_Volume = 1;//g_pElementList->GetVolume();

				m_pSound->SetVolume(m_Volume);

				m_bStop = false;

				m_pSound->Stop();

			}

		}

	}

}

void CSound::Pause() {

	//サウンドの一時停止
	m_pSound->Pause();

}

void CSound::Resume() {

	//サウンドの再開
	m_pSound->Resume();

}

void CSound::SetVolume(const float volume) {

	//ボリュームの設定
	m_Volume = volume;

	m_pSound->SetVolume(m_Volume);

}