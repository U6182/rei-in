#pragma once

/**

	@file CreditScene.h
	@brief �N���W�b�g�V�[��
	@author �ؑ��J��
	@date 2019/11/20

*/

#include		"SceneBase.h"
#include		"Stage.h"

class CCreditScene : public CSceneBase {

private:

	//! �v���C���[
			CPlayer*						m_Player;

	//! �N���A�S�[�X�g
			std::vector<CItem*>				m_ClearGhost;

	//! �G
			std::vector<CEnemy*>			m_EnemyArray;

	//! �X�e�[�W
			CStage*							m_Stage;

	//! �N���W�b�g
			std::vector<char*>				m_Credit;

	//! �N���W�b�g�̍��W
			Vector2*						m_CreditPos;

	//! �N���W�b�g�̐F
			MofU32*							m_CreditColor;

	//! �N���A�S�[�X�g�����t���O
			bool							m_bGhostFind;

	//! �ҋ@�C���^�[�o��
			float							m_WaitInterval;

	//! �ҋ@�C���^�[�o���^�C��
	const	float							m_WAITINTERVALTIME = 4.0f;

	//! ���̃V�[��
	const	std::vector<int>				m_NextSceneList = { CGameElement::SCENENO_GAMECLEAR };

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CCreditScene(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CCreditScene(void);

#pragma endregion		

#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return bool true ���� false ���s
		@details �N���W�b�g�V�[���̓ǂݍ���
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �N���W�b�g�V�[���̏��������s��
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �N���W�b�g�V�[���̍X�V���s��
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �N���W�b�g�V�[���̕`����s��
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �N���W�b�g�V�[���̉�����s��
	*/
	void	Release(void) override;

#pragma endregion

};