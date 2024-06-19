#pragma once

/**

	@file Setting.h
	@brief �e�L�X�`���̊Ǘ�
	@author �ؑ��J��
	@date 2019/10/23

*/

#include		"GameElement.h"

class CSetting {

private:

	//! �o�C�u���[�V�����̐ݒ�
	bool	m_bVibration;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CSetting(void) { m_bVibration = true; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CSetting(void) { ; }

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetSize
		@param �Ȃ�
		@return true �o�C�u���[�V�����ݒ�@false �o�C�u���[�V�������ݒ�
		@details �o�C�u���[�V�����ݒ���擾����
	*/
	bool		IsVibration(void) { return m_bVibration; }

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetVibration
		@param[in] bVibration	�o�C�u���[�V�����t���O
		@return �Ȃ�
		@details �o�C�u���[�V�����̐ݒ���s��
	*/
	void	SetVibration(const bool bVibration) {

		m_bVibration = bVibration;

	}

#pragma endregion

};