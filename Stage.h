#pragma once

/**

	@file Stage.h
	@brief �X�e�[�W
	@author �ؑ��J��
	@date 2019/10/23

*/

#include	"Game.h"
#include	"Player.h"
#include	"Enemy.h"
#include	"Item.h"

class CStage {

private:

	//! �G�̃e�N�X�`���̃|�C���^
	std::vector<CTexture*>		m_EnemyTexture;

	//! �A�C�e���̃e�N�X�`���̃|�C���^
	std::vector<CTexture*>		m_ItemTexture;

	//! �X�e�[�W�̔w�i�e�N�X�`��
	CTexture*					m_pBackImageTexture;

	//! �X�e�[�W�̃e�N�X�`��
	CTexture*					m_pChipTexture;

	//! �X�e�[�W�̃X�N���[���l
	Vector2						m_Scrooll;
	
	//! �X�e�[�W�̈ʒu���
	char*						m_pChipData;

	//! �G�̈ʒu���
	char*						m_pEnemyData;
	
	//! �A�C�e���̈ʒu���
	char*						m_pItemData;

	//! �X�e�[�W�̗�̐�
	int							m_XCount;

	//! �X�e�[�W�̍s�̐�
	int							m_YCount;

	//! �G�̏o����
	int							m_EnemyCount;

	//! �A�C�e���̏o����
	int							m_ItemCount;
	
	//! �X�e�[�W�e�N�X�`���̃T�C�Y
	float						m_ChipSize;

#pragma region �֐�

	/**
		@brief InfoLoad
		@param[in] pInfo �X�e�[�W�̏��
		@return bool true ���� false ���s
		@details �X�e�[�W�̏���ǂݍ���
	*/
	bool		InfoLoad(char* pInfo);
	/**
		@brief EnemyInitialize
		@param[in] pEnemy �o������G�̃|�C���^
		@return �Ȃ�
		@details �G�̏��������s��
	*/
	void		EnemyInitialize(std::vector<CEnemy*>& pEnemy);
	/**
		@brief ItemInitialize
		@param[in] pItem �o������A�C�e���̃|�C���^
		@return �Ȃ�
		@details �A�C�e���̏��������s��
	*/
	void		ItemInitialize(std::vector<CItem*>& pItem);
	/**
		@brief ScroollCorrection
		@param[in] pPlayer �v���C���[�̃|�C���^
		@return �Ȃ�
		@details �v���C���[�̃X�N���[���␳���s��
	*/
	void		ScroollCorrection(CPlayer* pPlayer);

#pragma endregion

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CStage(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CStage(void);

#pragma endregion
					
#pragma region �֐�

	/**
		@brief Load
		@param[in] pName �X�e�[�W�e�L�X�g�̃t�@�C���p�X
		@return bool true ���� false ���s
		@details �e�L�X�g����X�e�[�W��ǂݍ���
	*/
	bool		Load(char* pName);
	/**
		@brief Initialize
		@param[in] pEnemy �o������G�̃|�C���^
		@param[out] pItem �o������A�C�e���̃|�C���^
		@return �Ȃ�
		@details �G�ƃA�C�e���Ǝ��g�̏��������s��
	*/
	void		Initialize(std::vector<CEnemy*>& pEnemy, std::vector<CItem*>& pItem);
	/**
		@brief Update
		@param[in] pPlayer �v���C���[�̃|�C���^
		@return �Ȃ�
		@details �X�e�[�W�̍X�V���s��
	*/
	void		Update(CPlayer* pPlayer);
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �X�e�[�W�̕`����s��
	*/
	void		Render(void);
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �X�e�[�W�̉�����s��
	*/
	void		Release(void);
	/**
		@brief Collision
		@param[in] r �X�e�[�W�Ɠ����蔻����s����`
		@param[out] buried ���܂�l
		@return bool true �X�e�[�W�ƏՓ˂����@false �X�e�[�W�ƏՓ˂��Ă��Ȃ�
		@details �X�e�[�W�Ƃ̏Փ˔�����s��
	*/
	bool		Collision(CRectangle r, Vector2& buried);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetScroll
		@param �Ȃ�
		@return Vector2& �X�e�[�W�̃X�N���[���l
		@details �X�e�[�W�̃X�N���[���l���擾����
	*/
	const		Vector2&		GetScrooll(void) { return m_Scrooll; }
	/**
		@brief GetStageHeight
		@param �Ȃ�
		@return int �X�e�[�W�̃}�b�v�̍������擾
		@details �X�e�[�W�̃}�b�v�̍������擾����
	*/
				int				GetStageHeight(void) { return m_YCount * m_ChipSize; };

#pragma endregion

};
