/**

	@file SoundManager.cpp
	@brief �T�E���h�̊Ǘ�
	@author �ؑ��J��
	@date 2019/12/14

*/

#include		"SoundManager.h"

void CSoundManager::Load() {

	//�T�E���h�̃t�@�C���p�X
	char* name[] = {

		"GameScene/GameBGM.mp3",
			"GameScene/TimeFaster.mp3",
			"GameScene/HanakoAttack.mp3",
			"GameScene/ChargeAttack.mp3",
			"GameScene/BodyAttack.mp3",
			"GameScene/PianoPlay.mp3",
			"GameScene/Damage.mp3",

	};

	//�T�E���h�̓ǂݍ���
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Sound[i].SetBufferCount(5);

		if (!m_Sound[i].Load(name[i])) {

			

		}

	}

	

}

void CSoundManager::Initialize() {

	Load();

	//�T�E���h�̏������A�ݒ�
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].SetSound(&m_Sound[i]);

		m_Audio[i].Initialize();

	}

}

void CSoundManager::Update() {

	//�T�E���h�̒�~�����̍X�V
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].GraduallyStop();

	}

}

void CSoundManager::Release() {

	//�S�ẴT�E���h�̉��
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Sound[i].Release();

	}

	/*if (m_Sound) {

		delete[] m_Sound;

		m_Sound = nullptr;

	}*/

}

void CSoundManager::Play(const int type) {

	//���ɍĐ�����Ă���ꍇ�͍Đ����Ȃ�
	if (m_Audio[type].IsPlay()) {

		return;

	}

	//�T�E���h�̍Đ�
	m_Audio[type].Play();

}

void CSoundManager::EPlay(const int type) {

	//�T�E���h�G�t�F�N�g�̍Đ�
	m_Audio[type].Play();

}

void CSoundManager::AllStop() {

	//�S�ẴT�E���h���~
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		if (m_Audio[i].IsPlay()) {

			m_Audio[i].Stop();

		}

	}

}

void CSoundManager::Stop(const int type, const int stopType) {

	//�w�肵���T�E���h���w�肵���^�C�v�Œ�~
	m_Audio[type].Stop(stopType);

}

void CSoundManager::AllPause() {

	//�S�ẴT�E���h���ꎞ��~
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].Pause();

	}

}

void CSoundManager::Pause(int type) {

	//�w�肵���T�E���h���ꎞ��~
	m_Audio[type].Pause();

}

void CSoundManager::AllResume() {

	//�S�Ă̈ꎞ��~���ꂽ�T�E���h���ĊJ
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].Resume();

	}

}

void CSoundManager::Resume(const int type) {

	//�w�肵���ꎞ��~����Ă���T�E���h���ĊJ
	m_Audio[type].Resume();

}

void CSoundManager::SetVolume(const int type, const float volume) {

	//�w�肵���T�E���h���w�肵���{�����[���ɐݒ�
	m_Audio[type].SetVolume(volume);

}

void CSoundManager::AllSetVolume(const float volume) {

	//�S�ẴT�E���h���w�肵���{�����[���ɐݒ�
	for (int i = 0; i < CGameElement::SOUND_TYPECOUNT; i++) {

		m_Audio[i].SetVolume(volume);

	}
	
}

bool CSoundManager::IsPlay(const int type) {

	//�w�肵���T�E���h���Đ�����Ă��邩��Ԃ�
	return m_Audio[type].IsPlay();

}