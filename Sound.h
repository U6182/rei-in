#pragma once

/**

	@file Sound.h
	@brief �T�E���h
	@author �ؑ��J��
	@date 2019/10/23

*/

#include		"GameElement.h"

class CSound {

private:

	//! �T�E���h�̃|�C���^
	CSoundBuffer*		m_pSound;

	//! �T�E���h�̃X�g�b�v�t���O
	bool				m_bStop;

	//! �T�E���h�̃{�����[��
	float				m_Volume;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CSound(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CSound(void);

#pragma endregion

#pragma region �֐�

	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�̏��������s��
	*/
	void	Initialize(void);
	/**
		@brief Play
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�̍Đ����s��
	*/
	void	Play(void);
	/**
		@brief Stop
		@param[in] stopType ��~������
		@return �Ȃ�
		@details �T�E���h���w�肵����ނŒ�~���s��
	*/
	void	Stop(const int stopType);
	/**
		@brief Stop
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�̒�~���s��
	*/
	void	Stop(void);
	/**
		@brief GraduallyStop
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�����X�ɒ�~���s��
	*/
	void	GraduallyStop(void);
	/**
		@brief Pause
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�̈ꎞ��~���s��
	*/
	void	Pause(void);
	/**
		@brief Resume
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�̍ĊJ���s��
	*/
	void	Resume(void);
	
#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetSound
		@param[in] pSound �ݒ肷��T�E���h�̃|�C���^
		@return �Ȃ�
		@details �T�E���h�̐ݒ���s��
	*/
	void	SetSound(CSoundBuffer* pSound) { m_pSound = pSound; }
	/**
		@brief SetVolume
		@param[in] volume �ݒ肷��{�����[��
		@return �Ȃ�
		@details �T�E���h�Ɏw�肵���{�����[���̐ݒ���s��
	*/
	void	SetVolume(const float volume);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief IsPlay
		@param �Ȃ�
		@return bool true �Đ�����Ă��� false �Đ�����Ă��Ȃ�
		@details �T�E���h���Đ�����Ă��邩���擾����
	*/
	bool	IsPlay(void) { return m_pSound->IsPlay(); }

#pragma endregion

};