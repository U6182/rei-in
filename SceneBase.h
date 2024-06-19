#pragma once

/**

	@file SceneBase.h
	@brief �V�[���x�[�X
	@author �ؑ��J��
	@date 2019/11/02

*/

#include		"Transition.h"
#include		"Game.h"

class CSceneBase {

protected:

	//! �e�N�X�`���̃|�C���^
	CTexture*		m_pTexture;

	//! �J��
	CTransition*	m_Transition;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CSceneBase(const std::vector<int>* nextScene) : m_pTexture(nullptr), m_Transition(new CTransition(nextScene)) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CSceneBase(void) {

				if (m_Transition) { delete m_Transition; m_Transition = nullptr; }

	}

#pragma endregion
						
#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return bool true ���� false ���s
		@details �V�[���̓ǂݍ���
	*/
	virtual		bool		Load(void) = 0;
	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �V�[���̏��������s��
	*/
	virtual		void		Initialize(void) = 0;
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �V�[���̍X�V���s��
	*/
	virtual		void		Update(void) = 0;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �V�[���̕`����s��
	*/
	virtual		void		Render(void) = 0;
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �V�[���̉�����s��
	*/
	virtual		void		Release(void) = 0;
	/**
		@brief Operation
		@param �Ȃ�
		@return �Ȃ�
		@details �V�[���̑�����s��
	*/
	virtual		void		Operation(CGameObject* pGameObject) {

		//���̓R�}���h�̎擾
		const CDynamicArray<int>* inputCommand = CGame::GetInstance()->GetController()->Input();

		//�R�}���h���擾
		CCommand** command = CGame::GetInstance()->GetController()->GetCommand();

		for (int i = 0; i < inputCommand->GetArrayCount(); i++) {

			//�ݒ肳��Ă���R�}���h�����s
			if (command[inputCommand->GetData(i)] != nullptr) {

				command[inputCommand->GetData(i)]->Execute(pGameObject);

			}

		}

	}

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetTransition
		@param �Ȃ�
		@return CTransition* �J��
		@details �J�ڃI�u�W�F�N�g���擾����
	*/
	CTransition*	GetTransition(void) { return m_Transition; }

#pragma endregion

};