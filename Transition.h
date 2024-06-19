#pragma once

/**

	@file Transition.h
	@brief �J��
	@author �ؑ��J��
	@date 2020/10/23

*/

#include		"GameObject.h"

class CTransition : public CGameObject {

private:

	//! �V�[���I���t���O
			bool				m_bEnd;

	//! �t�F�[�h�t���O
			bool				m_bAlpha;

	//! ���݂̃V�[��
			int					m_NowScene;

	//! ���ɑJ�ڂ���V�[��
	const	std::vector<int>*	m_NextScene;

	//! �t�F�[�h�l
			int					m_Alpha;

	//! �I��ԍ�
			int					m_SelectNo;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CTransition(const std::vector<int>* nextScene) : m_NextScene(nextScene) { m_bEnd = false, m_bAlpha = false, m_NowScene = NULL, m_SelectNo = 0, m_Alpha = 0; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CTransition(void) { ; }

#pragma endregion

#pragma region �֐�

	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �J�ڂ̏��������s��
	*/
	void		Initialize(void) { m_Alpha = 255; };
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �J�ڂ̍X�V���s��
	*/
	void		Update(void);
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �J�ڂ̕`����s��
	*/
	void		Render(void);
	/**
		@brief Transition
		@param �Ȃ�
		@return �Ȃ�
		@details �J�ڂ��s��
	*/
	void		Transition(void) { 
		
		if ((*m_NextScene)[m_SelectNo] == CGameElement::SCENENO_EXIT) {

			//�I���֐�
			PostQuitMessage(0);

			return;

		}

		m_bAlpha = true; 
	
	};
	/**
		@brief SelectDownAndRight
		@param �Ȃ�
		@return �Ȃ�
		@details �Z���N�g���s��
	*/
	void		SelectDownAndRight(void) {

		m_SelectNo++;

		if (m_SelectNo > m_NextScene->size() - 1) {

			m_SelectNo = m_NextScene->size() - 1;

		}

	}
	/**
		@brief SelectUpAndLeft
		@param �Ȃ�
		@return �Ȃ�
		@details �Z���N�g���s��
	*/
	void		SelectUpAndLeft(void) {

		m_SelectNo--;

		if (m_SelectNo < 0) {

			m_SelectNo = 0;

		}

	}

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetSelectNo
		@param[in] selectNo
		@return �Ȃ�
		@details �Z���N�g�ԍ��̐ݒ���s��
	*/
	void		SetSelectNo(const int selectNo) { m_SelectNo = selectNo; }

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief IsEnd
		@param �Ȃ�
		@return bool true �V�[���I�� false �V�[���p��
		@details �V�[���̏I���t���O���擾����
	*/
	bool		IsEnd(void) { return m_bEnd; }
	/**
		@brief GetNowScene
		@param �Ȃ�
		@return int ���݂̃V�[��
		@details ���݂̃V�[�����擾����
	*/
	int			GetNowScene(void) { return m_NowScene; }
	/**
		@brief GetNextScene
		@param �Ȃ�
		@return int ���ɑJ�ڂ���V�[��
		@details ���ɑJ�ڂ���V�[�����擾����
	*/
	int			GetNextScene(void) { return (*m_NextScene)[m_SelectNo]; }
	/**
		@brief GetSelectNo
		@param �Ȃ�
		@return int �I��ԍ�
		@details �I��ԍ����擾����
	*/
	int			GetSelectNo(void) { return m_SelectNo; }

#pragma endregion

};
