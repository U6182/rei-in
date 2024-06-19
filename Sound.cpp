/**

	@file Sound.cpp
	@brief �T�E���h
	@author �ؑ��J��
	@date 2019/12/14

*/

#include		"Sound.h"

CSound::CSound() : m_pSound(nullptr) {

	//! �T�E���h�̃X�g�b�v�t���O�̏�����
	m_bStop = false;

	//! �T�E���h�̃{�����[���̏�����
	m_Volume = 1.0f;

}

CSound::~CSound() {

}

void CSound::Initialize() {

	//! �T�E���h�̃X�g�b�v�t���O�̏�����
	m_bStop = false;

	//! �T�E���h�̃{�����[���̏�����
	m_Volume = 1.0f;

}

void CSound::Play() {

	//�T�E���h�̍Đ�
	m_pSound->Play();

}

void CSound::Stop(const int stopType) {

	//�w�肵����ނŃT�E���h�̒�~
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

	//�T�E���h�̒�~
	m_pSound->Stop();

}

void CSound::GraduallyStop() {

	if (m_bStop) {

		//�T�E���h���Đ�����Ă���ԏ��X�ɒ�~
		if (m_pSound->IsPlay()) {

			m_Volume -= 0.1f;

			m_pSound->SetVolume(m_Volume);

			//�{�����[����0�ȉ��ɂȂ����ꍇ�T�E���h���~�����������s��
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

	//�T�E���h�̈ꎞ��~
	m_pSound->Pause();

}

void CSound::Resume() {

	//�T�E���h�̍ĊJ
	m_pSound->Resume();

}

void CSound::SetVolume(const float volume) {

	//�{�����[���̐ݒ�
	m_Volume = volume;

	m_pSound->SetVolume(m_Volume);

}