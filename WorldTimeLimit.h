#pragma once

/**

	@file WorldTimeLimit.h
	@brief �^�C�����~�b�g
	@author �ؑ��J��
	@date 2019/11/24

*/

#include	"GameObject.h"

class CWorldTimeLimit : public CGameObject {

private:

	//! �^�C�����~�b�g�̃e�N�X�`��
			CTexture*	m_pNumberTexture;

	//! �^�C�����~�b�g�t���[���̃e�N�X�`��
			CTexture*	m_pNumberFrameTexture;

	//! �}�C�i�X�L���̃e�N�X�`��
			CTexture*	m_pNegativeSymbolTexture;

	//! ���~�b�g�����t���O
			bool		m_bTimeFaster;

	//! ���ꂽ����
			int			m_LessTime;

	//! �����x
			int			m_LessTimeAlpha;

	//! �^�C�����~�b�g
			float		m_TimeLimit;

	//! �`�掞�Ԓ萔
	const	float		m_LESSRENDERTIME = 3.0f;

	//! �`�掞��
			float		m_LessTimeRenderTime;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CWorldTimeLimit(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CWorldTimeLimit(void) { ; }

#pragma endregion

#pragma region �֐�

	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �^�C�����~�b�g�̍X�V���s��
	*/
	void		Update(void);
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �^�C�����~�b�g�̕`����s��
	*/
	void		Render(void);
	/**
		@brief LessTime
		@param[in] lessTime ���ꂽ����
		@return �Ȃ�
		@details �c�莞�Ԃ����炷�������s��
	*/
	void		LessTime(const int lessTime) {
	
		m_TimeLimit -= lessTime;

		m_LessTime = lessTime;

		m_LessTimeAlpha = 255;

		m_LessTimeRenderTime = m_LESSRENDERTIME;

	}

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetTimeFaster
		@param[in] bFaster �^�C�������t���O
		@return �Ȃ�
		@details �^�C�������t���O�̐ݒ���s��
	*/
	void	SetTimeFaster(bool bFaster) { m_bTimeFaster = bFaster; }

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetTimeLimit
		@param �Ȃ�
		@return int �^�C�����~�b�g
		@details �^�C�����~�b�g�̎擾���s��
	*/
	int		GetTimeLimit(void) { return m_TimeLimit; }

#pragma endregion

};