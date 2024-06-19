#pragma once

/**

	@file GameScene.h
	@brief �Q�[���V�[��
	@author �ؑ��J��
	@date 2019/11/20

*/

#include		"SceneBase.h"
#include		"Player.h"
#include		"Enemy.h"
#include		"Item.h"
#include		"Stage.h"
#include		"WorldTimeLimit.h"

class CGameScene : public CSceneBase {

private:

	//! ���Ԑ���
			CWorldTimeLimit*			m_WorldTimeLimit;

	//! �v���C���[
			CPlayer*					m_Player;

	//! �X�e�[�W
			CStage*						m_Stage;

	//! �G
			std::vector<CEnemy*>		m_EnemyArray;

	//! �A�C�e��
			std::vector<CItem*>			m_ItemArray;

	//! �U���t���O
			bool						m_bVibration;

	//! �R���g���[���̏��
			int							m_ControllerState;

	//! �Q�[���̏��
			int							m_GameState;

	//! ���̃V�[��
	const	std::vector<int>			m_NextSceneList = { CGameElement::SCENENO_GAMEOVER, CGameElement::SCENENO_CREDIT };

	//! �v���C���[�U�����̒�~����
			float						m_BreakTime;

#pragma region �֐�

	/**
		@brief PlayerUpdate
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̍X�V���s��
	*/
	void			PlayerUpdate(void);
	/**
		@brief EnemyUpdate
		@param �Ȃ�
		@return �Ȃ�
		@details �G�̍X�V���s��
	*/
	void			EnemyUpdate(void);
	/**
		@brief ItemUpdate
		@param �Ȃ�
		@return �Ȃ�
		@details �A�C�e���̍X�V���s��
	*/
	void			ItemUpdate(void);
	/**
		@brief ControllerUpdate
		@param �Ȃ�
		@return �Ȃ�
		@details �R���g���[���[�̍X�V���s��
	*/
	void			ControllerUpdate(void);
	/**
		@brief SoundUpdate
		@param �Ȃ�
		@return �Ȃ�
		@details �T�E���h�̍X�V���s��
	*/
	void			SoundUpdate(void);
	/**
		@brief WorldTimeLimitUpdate
		@param �Ȃ�
		@return �Ȃ�
		@details ���Ԑ����̍X�V���s��
	*/
	void			WorldTimeLimitUpdate(void);
	/**
		@brief CommandTransition
		@param �Ȃ�
		@return �Ȃ�
		@details �R�}���h�J�ڂ��s��
	*/
	void			CommandTransition(void);
	/**
		@brief GameState
		@param �Ȃ�
		@return CGameObject* �Q�[���I�u�W�F�N�g
		@details �Q�[���̏�Ԃɍ��킹���I�u�W�F�N�g���擾����
	*/
	CGameObject*	GameState(void);
	/**
		@brief EnemyAppear
		@param �Ȃ�
		@return �Ȃ�
		@details �G�̏o���������s��
	*/
	void			EnemyAppear(void);
	/**
		@brief ItemAppear
		@param �Ȃ�
		@return �Ȃ�
		@details �A�C�e���̏o���������s��
	*/
	void			ItemAppear(void);
	/**
		@brief AnimeCollision
		@param �Ȃ�
		@return �Ȃ�
		@details �L�����N�^�[�̏Փˏ������s��
	*/
	void			AnimeCollision(void);
	/**
		@brief ItemCollision
		@param �Ȃ�
		@return �Ȃ�
		@details �A�C�e���̏Փˏ������s��
	*/
	void			ItemCollision(void);
	/**
		@brief GameTransition
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���̑J�ڏ������s��
	*/
	void			GameTransition(void);
	/**
		@brief TypeItemFind
		@param[in] type�@���
		@return �Ȃ�
		@details �w�肵����ނ̃I�u�W�F�N�g�̎��ʔԍ��̎擾�������s��
	*/
	CItem*		TypeItemFind(std::vector<CItem*> pItem, const int type) {

		CItem* pFindItem = nullptr;

		for (CItem* pGameItem : pItem) {

			if (pGameItem->GetType() == type) {

				pFindItem = pGameItem;

			}

		}

		return pFindItem;

	};

#pragma endregion

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CGameScene(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CGameScene(void);

#pragma endregion		

#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return bool true ���� false ���s
		@details �Q�[���V�[���̓ǂݍ���
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���V�[���̏��������s��
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���V�[���̍X�V���s��
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���V�[���̕`����s��
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���V�[���̉�����s��
	*/
	void	Release(void) override;

#pragma endregion

};