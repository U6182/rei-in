#pragma once

/**

	@file Player.h
	@brief �v���C���[
	@author �ؑ��J��
	@date 2020/10/29

*/

#include		"Anime.h"
#include		"Viscera.h"

class CPlayer : public CAnime {

private:

	//! �G�̏��
			CAnime*									m_pEnemyState;

	//! �v���C���[�̃e�N�X�`��
			std::vector<CTexture*>					m_pTexture;

	//! �v���C���[�̃��[�V����
			std::vector<CSpriteMotionController*>	m_pMotion;

	//! �v���C���[�̃T�C�Y
	const	Vector2									m_Size[CGameElement::PLAYER_COUNT] = { Vector2(180,256), Vector2(228,256), Vector2(200,127), Vector2(228,256), Vector2(228,256) };

	//! �`���[�W�G�t�F�N�g
	const	std::vector<int>						m_CHARGE_STAGE = { CGameElement::EFFECT_TEKETEKE_CHARGESTAGE1, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE2, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE3, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE4, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE5 };

	//! ����t���O
			bool									m_bOperation[CGameElement::PLAYER_OPERATION_COUNT] = { false };

	//! �G�𓥂񂾂�
			bool									m_bEnemyCollision;

	//! �ړ��t���O
			bool									m_bMove;

	//! ���S���o�I���t���O
			bool									m_bDeadBehaviorEnd;

	//! �A�C�e���ڐG�t���O
			bool									m_bItemCollision;

	//! �^�ԃt���O
			bool									m_bCarry;

	//! ���
			int										m_PossessionState;

	//! �߈ːF
			int										m_PossessionColor;

	//! �`���[�W�U���̏��
			int										m_ChargeAttackState;

	//! �U���̏��
			int										m_AttackState;

	//! �߈ˏ�Ԃ̍ő�X�s�[�h
			float									m_StateMaxMove[CGameElement::PLAYER_COUNT] = {CGameElement::PLAYER_MAXMOVE_SOUL, CGameElement::PLAYER_MAXMOVE_HANAKO, CGameElement::PLAYER_MAXMOVE_TEKETEKE, CGameElement::PLAYER_MAXMOVE_KINZIROU, CGameElement::PLAYER_MAXMOVE_HUMANBODYMODLE};

	//! �ő�X�s�[�h
			float									m_MaxSpeed;

	//! �`���[�W��
			float									m_Charging;

	//! �ő�`���[�W�^�C��
	const	float									m_MAXCHARGETIME = 4;

			/**
				@enum tag_PLAYER_CHARGEATTACKSTATE
				�v���C���[�̃`���[�W�U����Ԃ̗񋓒萔

			*/
			typedef enum tag_PLAYER_CHARGEATTACKSTATE {

				PLAYER_CHARGEATTACK_NOT,
				PLAYER_CHARGEATTACK_CHARGE,
				PLAYER_CHARGEATTACK_CHARGEATTACK,

			}PLAYER_CHARGEATTACKSTATE_NAME;

#pragma region �֐�

	/**
		@brief Behavior
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̓��쏈�����s��
	*/
	void		Behavior(void);
	/**
		@brief PossessionBehavior
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̜߈˓��쏈�����s��
	*/
	void		PossessionBehavior(void);
	/**
		@brief DeadBehavior
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̎��S���쏈�����s��
	*/
	void		DeadBehavior(void);
	/**
		@brief DamageBehavior
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̃_���[�W���쏈�����s��
	*/
	//void		DamageBehavior(void);
	/**
		@brief MotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̃��[�V�����̕ύX�������s��
	*/
	void		MotionChange(void);
	/**
		@brief SoulMotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details ���v���C���[�̃��[�V�����̕ύX�������s��
	*/
	void		SoulMotionChange(void);
	/**
		@brief HanakoMotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �Ԏq�v���C���[�̃��[�V�����̕ύX�������s��
	*/
	void		HanakoMotionChange(void);
	/**
		@brief TekeTekeMotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �e�P�e�P�v���C���[�̃��[�V�����̕ύX�������s��
	*/
	void		TekeTekeMotionChange(void);
	/**
		@brief KinzirouMotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �����Y�v���C���[�̃��[�V�����̕ύX�������s��
	*/
	void		KinzirouMotionChange(void);
	/**
		@brief HumanBodyModleMotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �l�̖͌^�v���C���[�̃��[�V�����̕ύX�������s��
	*/
	void		HumanBodyModleMotionChange(void);
	/**
		@brief Effect
		@param �Ȃ�
		@return �Ȃ�
		@details ���ʏ������s��
	*/
	void		Effect(void);
	/**
		@brief Reverse
		@param �Ȃ�
		@return �Ȃ�
		@details ���]�������s��
	*/
	void		Reverse(void) override { 
		
		if (m_PossessionState == CGameElement::PLAYER_SOUL) {

			if (m_Move.x > 0) {

				m_bReverse = false;

			}
			else if (m_Move.x < 0) {

				m_bReverse = true;

			}

		}
		else {

			if (m_Move.x < 0) {

				m_bReverse = false;

			}
			else if (m_Move.x > 0) {

				m_bReverse = true;

			}

		}
		
	
	};
	/**
		@brief Move
		@param �Ȃ�
		@return �Ȃ�
		@details �ړ��������s��
	*/
	void		Move(void);
	/**
		@brief Jump
		@param �Ȃ�
		@return �Ȃ�
		@details �W�����v�������s��
	*/
	void		Jump(void);
	/**
		@brief MoveWait
		@param �Ȃ�
		@return �Ȃ�
		@details �ړ���~�������s��
	*/
	void		MoveWait(void);
	/**
		@brief Possession
		@param �Ȃ�
		@return �Ȃ�
		@details �߈ˏ������s��
	*/
	void		Possession(void);
	/**
		@brief PossessionLifted
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̜߈ˉ����������s��
	*/
	void		PossessionLifted(void);
	/**
		@brief Attack
		@param �Ȃ�
		@return �Ȃ�
		@details �U���������s��
	*/
	void		Attack(void);
	/**
		@brief Charge
		@param �Ȃ�
		@return �Ȃ�
		@details �`���[�W�������s��
	*/
	void		Charge(void);
	/**
		@brief ChargeAttack
		@param �Ȃ�
		@return �Ȃ�
		@details �`���[�W�U���������s��
	*/
	void		ChargeAttack(void);
	/**
		@brief ChargeAttackStop
		@param �Ȃ�
		@return �Ȃ�
		@details �`���[�W�U����~�������s��
	*/
	void		ChargeAttackStop(void);
	/**
		@brief Carry
		@param �Ȃ�
		@return �Ȃ�
		@details �^�ԏ������s��
	*/
	void		Carry(void);
	/**
		@brief BodyAttack
		@param �Ȃ�
		@return �Ȃ�
		@details �{�f�B�[�U���������s��
	*/
	void		BodyAttack(void);

#pragma endregion

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CPlayer(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CPlayer(void) { 
		
		if (m_Weapon) {

			delete m_Weapon;

			m_Weapon = nullptr;

		}

	}

#pragma endregion

#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̓ǂݍ��݂��s��
	*/
	void		Load(void);
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̍X�V���s��
	*/
	void		Update(void) override;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �v���C���[�̕`����s��
	*/
	void		Render(void) override;
	/**
		@brief CollisionStage
		@param[in] buried �v���C���[�̖��܂�l
		@return �Ȃ�
		@details �v���C���[���X�e�[�W�ƏՓ˂������̏������s��
	*/
	void		CollisionStage(const Vector2& buried);
	/**
		@brief ResetMove
		@param �Ȃ�
		@return �Ȃ�
		@details �ړ��̃��Z�b�g���s��
	*/
	void		ResetMove(void) { m_bMove = false; }

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetEnemyState
		@param[in] pEnemyState �G��Ԃ̃|�C���^
		@return �Ȃ�
		@details �G��Ԃ̐ݒ���s��
	*/
	void	SetEnemyState(CAnime* pEnemyState) { m_pEnemyState = pEnemyState; }
	/**
		@brief SetAttackState
		@param[in] AttackState �U�����
		@return �Ȃ�
		@details �U����ԃ��[�h�̐ݒ���s��
	*/
	void		SetAttackState(const int AttackState) { m_AttackState = AttackState; }
	/**
		@brief SetbOperation
		@param[in] bOperation ����t���O
		@param[out] operation ����
		@return �Ȃ�
		@details ����̐ݒ���s��
	*/
	void	SetbOperation(const bool bOperation, const int operation);
	/**
		@brief SetItemCollision
		@param[in] bItemCollision �A�C�e���Փ˃t���O
		@return �Ȃ�
		@details �A�C�e���Փ˃t���O�̐ݒ���s��
	*/
	void	SetItemCollision(bool bItemCollision) { m_bItemCollision = bItemCollision; }

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param �Ȃ�
		@return CRectangle ��`
		@details ��`���擾����
	*/
	CRectangle					GetRect(void) const	override;
	/**
		@brief GetAttackRect
		@param �Ȃ�
		@return CRectangle �U����`
		@details �U����`���擾����
	*/
	CRectangle					GetAttackRect() override;
	/**
		@brief GetMotion
		@param �Ȃ�
		@return CSpriteMotionController ���[�V����
		@details ���[�V�������擾����
	*/
	CSpriteMotionController*	GetMotion(void) { return m_pMotion[m_PossessionState]; }
	/**
		@brief IsDeadBehaviorEnd
		@param �Ȃ�
		@return bool true �I�� false ���I��
		@details ���S���o�t���O�̎擾������
	*/
	bool						IsDeadBehaviorEnd(void) { return m_bDeadBehaviorEnd; }
	/**
		@brief IsDamage
		@param �Ȃ�
		@return bool true �_���[�W(���S) false ����
		@details �_���[�W�t���O���擾����
	*/
	bool						IsDamage(void) override { return m_DamageInterval > 0 ? true : false; }
	/**
		@brief IsCarry
		@param �Ȃ�
		@return bool true �^�� false �^��ł��Ȃ�
		@details �^�ԃt���O���擾����
	*/
	bool						IsCarry(void) { return m_bCarry; }
	/**
		@brief GetPossessionState
		@param �Ȃ�
		@return int	GetPossessionState
		@details ��Ԃ̎擾���s��
	*/
	int							GetPossessionState(void) { return m_PossessionState; }
	/**
		@brief GetAttackPoint
		@param �Ȃ�
		@return int	GetAttackPoint
		@details �U���͂̎擾���s��
	*/
	int							GetAttackPoint(void) override;
	/**
		@brief GetAttackState
		@param �Ȃ�
		@return int	GetAttackState
		@details �U����Ԃ̎擾���s��
	*/
	int							GetAttackState(void) { return m_AttackState; }
	/**
		@brief GetDamageInterval
		@param �Ȃ�
		@return int	GetDamageInterval
		@details �_���[�W�C���^�[�o���̎擾���s��
	*/
	float						GetDamageInterval(void) const { return m_DamageInterval; }

#pragma endregion

};