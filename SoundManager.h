#pragma once

/**

	@file SoundManager.h
	@brief �T�E���h�̊Ǘ�
	@author �ؑ��J��
	@date 2019/10/23

*/

#include		"Sound.h"

class CSoundManager {

private:
	
	//! �T�E���h�N���X�̔z��
	CSound				m_Audio[CGameElement::SOUND_TYPECOUNT];

	//! �T�E���h�̔z��
	CSoundBuffer		m_Sound[CGameElement::SOUND_TYPECOUNT];
			
public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CSoundManager(void) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CSoundManager(void) { Release(); }

#pragma endregion

#pragma region �֐�

	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �S�ẴT�E���h�̏��������s��
	*/
	void		Initialize(void);
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �S�ẴT�E���h�̒�~�����̍X�V���s��
	*/
	void		Update(void);
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�Ǝ��g�̉�����s��
	*/
	void		Release(void);
	/**
		@brief Play
		@param[in] type �Đ�����T�E���h
		@return �Ȃ�
		@details �w�肵���T�E���h�̍Đ����s��
	*/
	void		Play(const int type);
	/**
	@brief EPlay
	@param[in] type �Đ�����T�E���h�G�t�F�N�g
	@return �Ȃ�
	@details �w�肵���T�E���h�G�t�F�N�g�̍Đ����s��
	*/
	void		EPlay(const int type);
	/**
		@brief AllStop
		@param �Ȃ�
		@return �Ȃ�
		@details �S�ẴT�E���h�̒�~���s��
	*/
	void		AllStop(void);
	/**
		@brief Stop
		@param[in] type ��~����T�E���h
		@param[out] stopType ��~������ 
		@return �Ȃ�
		@details �w�肵���T�E���h���w�肵����ނŒ�~���s��
	*/
	void		Stop(const int type, const int stopType);
	/**
		@brief AllPause
		@param �Ȃ�
		@return �Ȃ�
		@details �S�ẴT�E���h�̈ꎞ��~���s��
	*/
	void		AllPause(void);
	/**
		@brief Pause
		@param[in] type �ꎞ��~����T�E���h
		@return �Ȃ�
		@details �w�肵���T�E���h�̈ꎞ��~���s��
	*/
	void		Pause(const int type);
	/**
		@brief AllResume
		@param �Ȃ�
		@return �Ȃ�
		@details �S�ẴT�E���h�̍ĊJ���s��
	*/
	void		AllResume(void);
	/**
		@brief Resume
		@param[in] type �ĊJ����T�E���h
		@return �Ȃ�
		@details �w�肵���T�E���h�̍ĊJ���s��
	*/
	void		Resume(const int type);
	
#pragma endregion

	void Load();

#pragma region �Z�b�^�[

	/**
		@brief AllSetVolume
		@param[in] volume �ݒ肷��{�����[��
		@return �Ȃ�
		@details �S�ẴT�E���h�̃{�����[���̐ݒ���s��
	*/
	void		AllSetVolume(const float volume);
	/**
		@brief SetVolume
		@param[in] type �{�����[����ݒ肷��T�E���h
		@param[out] volume	�ݒ肷��{�����[��
		@return �Ȃ�
		@details �w�肵���T�E���h�̃{�����[���̐ݒ���s��
	*/
	void		SetVolume(const int type, const float volume);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief IsPlay
		@param[in] type �m�F����T�E���h
		@return bool true �Đ�����Ă��� false �Đ�����Ă��Ȃ�
		@details �w�肵���T�E���h���Đ�����Ă��邩�̊m�F���s��
	*/
	bool	IsPlay(const int type);
	
#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetSound
		@param[in] pSound
		@return �Ȃ�
		@details �T�E���h�̐ݒ���s��
	*/
	//void	SetSound(CSoundBuffer* pSound) { m_Sound = pSound; }

#pragma endregion

};