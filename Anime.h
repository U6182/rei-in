#pragma once

/**

	@file Anime.h
	@brief �L�����N�^�[
	@author �ؑ��J��
	@date 2019/11/24

*/

#include		"DynamicGameObject.h"
#include		"Weapon.h"

class CAnime : public CDynamicGameObject {

protected:

	//! ����
	CWeapon*	m_Weapon;

	//! �X�e�[�W�̃X�N���[��
	Vector2		m_Scrooll;

	//! �U���t���O
	bool		m_bAttack;

	//! �W�����v�t���O
	bool		m_bJump;

	//! ���S�t���O
	bool		m_bDead;

	//! �_���[�W�t���O
	bool		m_bDamage;

	//! �����t���O
	bool		m_bPossessionLifted;

	//! �����~�t���O
	bool		m_bBehaviorWait;

	//! �߈˓����x
	int			m_Transparency;

	//! �߈˃��[�h
	int			m_Possession;

	//! �U����
	int			m_AttackPoint;

	//! �_���[�W�ҋ@����
	float		m_DamageWait;

	//! �W�����v��
	float		m_JumpPower;

	//! �_���[�W�C���^�[�o���^�C��
	const	float									m_DAMAGEINTERVALTIME = 3;

	//! �_���[�W�C���^�[�o��
	float									m_DamageInterval;

#pragma region �֐�

	/**
		@brief DamageBehavior
		@param �Ȃ�
		@return �Ȃ�
		@details �G�̃_���[�W���쏈�����s��
	*/
	void		DamageBehavior(void) {

		if (m_bDamage && m_DamageInterval <= 0) {

			m_DamageInterval = m_DAMAGEINTERVALTIME;

		}

		if (m_DamageInterval > 0) {

			m_DamageInterval -= CUtilities::GetFrameSecond();

			if (m_DamageInterval <= 2) {

				m_bDamage = false;

			}

			if (m_DamageInterval <= 0) {

				m_DamageInterval = 0;

				m_bPossessionLifted = false;

			}

		}

	}

#pragma endregion


public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CAnime(const Vector2 size) : CDynamicGameObject(size), m_Weapon(nullptr), m_Scrooll() {

					m_bAttack = false, m_bJump = false, m_bDead = false, m_bDamage = false, m_bPossessionLifted = false, m_bBehaviorWait = false, m_Transparency = 255, m_Possession = 0, m_AttackPoint = 0, m_DamageWait = 0.0f, m_JumpPower = 0.0f, m_DamageInterval = 0.0f;

				}
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CAnime(void) { ; }

#pragma endregion

#pragma region �֐�

	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �L�����N�^�[�̍X�V���s��
	*/
	virtual		void	Update(void) = 0;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �L�����N�^�[�̕`����s��
	*/
	virtual		void	Render(void) = 0;

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetDead
		@param[in] dead ���S�t���O
		@return �Ȃ�
		@details ���S�t���O�̐ݒ���s��
	*/
	void		SetDead(const bool bDead) { m_bDead = bDead; }
	/**
		@brief SetDamage
		@param[in] damage �_���[�W�t���O
		@return �Ȃ�
		@details �_���[�W�t���O�̐ݒ���s��
	*/
	void		SetDamage(const bool bDamage) { m_bDamage = bDamage; }
	/**
		@brief SetAttack
		@param[in] bAttack �A�^�b�N�t���O
		@return �Ȃ�
		@details �A�^�b�N�t���O�̐ݒ���s��
	*/
	void		SetAttack(const bool bAttack) { m_bAttack = bAttack; }
	/**
		@brief SetBehaviorWait
		@param[in] BehaviorWait �s���ҋ@�t���O
		@return �Ȃ�
		@details �s���ҋ@�t���O�̐ݒ���s��
	*/
	void		SetBehaviorWait(bool bBehaviorWait) { m_bBehaviorWait = bBehaviorWait; }
	/**
		@brief SetPossession
		@param[in] bPossession �߈˃��[�h
		@return �Ȃ�
		@details �߈˃��[�h�̐ݒ���s��
	*/
	void		SetPossession(const int possessionMode) { m_Possession = possessionMode; }
	/**
		@brief SetScrooll
		@param[in] scrooll �X�N���[���l
		@return �Ȃ�
		@details �X�N���[���l�̐ݒ���s��
	*/
	void		SetScrooll(const Vector2& scrooll) { m_Scrooll = scrooll; }
	
#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetWeapon
		@param �Ȃ�
		@return CWeapon ����
		@details ������擾����
	*/
	virtual		CWeapon*		GetWeapon(void) { return m_Weapon; }
	/**
		@brief GetAttackRect
		@param �Ȃ�
		@return CRectangle �U����`
		@details �U����`���擾����
	*/
	virtual		CRectangle		GetAttackRect() { return GetRect(); }
	/**
		@brief GetScrooll
		@param �Ȃ�
		@return Vector2& �X�N���[���l
		@details �X�N���[���l���擾����
	*/
				Vector2&		GetScrooll(void) { return m_Scrooll; }
	/**
		@brief IsAttack
		@param �Ȃ�
		@return bool true �U�� false �U���łȂ�
		@details �U���t���O���擾����
	*/
				bool			IsAttack(void) { return m_bAttack; }
	/**
		@brief IsReverse
		@param �Ȃ�
		@return bool true ������(���i�s) false �E����(�E�i�s)
		@details ���]�t���O���擾����
	*/
				bool			IsReverse(void) { return m_bReverse; }
	/**
		@brief IsDead
		@param �Ȃ�
		@return bool true ���S false ����
		@details ���S�t���O���擾����
	*/
				bool			IsDead(void) { return m_bDead; }
	/**
		@brief IsDamage
		@param �Ȃ�
		@return bool true �_���[�W(���S) false ����
		@details ���S�t���O���擾����
	*/
	virtual		bool			IsDamage(void) { return m_bDamage; }
	/**
		@brief GetPossession
		@param �Ȃ�
		@return int �߈˃��[�h
		@details �߈˃��[�h�̎擾������
	*/
	virtual		int				GetPossession(void) { return m_Possession; }
	/**
		@brief GetAttackPoint
		@param �Ȃ�
		@return int	GetAttackPoint
		@details �U���͂̎擾���s��
	*/
	virtual		int				GetAttackPoint(void) { return m_AttackPoint; }

#pragma endregion

};