#pragma once

/**

	@file Enemy.h
	@brief �G
	@author �ؑ��J��
	@date 2019/11/25

*/

#include		"Anime.h"
#include		"Game.h"

class CEnemy : public CAnime {

protected:

	//! �v���C���[�̏��
	const	CAnime*		m_pPlayerState;

	//! �����͈�
			Vector2		m_FindRange;

	//! �����t���O
			bool		m_bFind;

	//! �����t���O
			bool		m_bFall;

	//! �o���t���O
			bool		m_bAppear;

	//! HP
			int			m_HP;

#pragma region �֐�

	/**
		@brief Behavior
		@param �Ȃ�
		@return �Ȃ�
		@details �G�̍s���������s��
	*/
	virtual		void		Behavior(void) { ; }
	/**
		@brief DeadBehavior
		@param �Ȃ�
		@return �Ȃ�
		@details �G���S���̓��쏈�����s��
	*/
	virtual		void		DeadBehavior(void);
	/**
		@brief MotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �G�̃��[�V�����������s��
	*/
	virtual		void		MotionChange(void);
	/**
		@brief Reverse
		@param �Ȃ�
		@return �Ȃ�
		@details ���]�������s��
	*/
	virtual		void		Reverse(void) override{ 

		if (m_Move.x < 0) { 
			
			m_bReverse = false;

		} else if (m_Move.x > 0) { 
			
			m_bReverse = true;
		
		} 
	
	};
	/**
		@brief Effect
		@param �Ȃ�
		@return �Ȃ�
		@details ���ʏ������s��
	*/
	virtual		void		Effect(void) { 
	
		if (m_bDead) {

			if (!g_pGame->GetEffectManager()->IsEffect(CGameElement::EFFECT_ENEMY_ENEMYDEAD)) {

				const Vector2 pos(m_Pos.x, m_Pos.y);

				g_pGame->GetEffectManager()->Start(pos, CGameElement::EFFECT_ENEMY_ENEMYDEAD);

			}

		}

	}

#pragma endregion

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param[in] pMotion ���[�V����
		@param[out] pos ���W
		@param[in.out] move �ړ���
		@param[in] size �T�C�Y
		@param[out] type ���
		@param[in.out] HP HP
		@param[in] attackPoint �U����
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CEnemy(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CEnemy(void);

#pragma endregion
							
#pragma region �֐�

	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �G�̍X�V���s��
	*/
	virtual		void		Update(void);
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �G�̕`����s��
	*/
	virtual		void		Render(void);
	/**
		@brief RenderDebug
		@param[in] i �G�̗v�f�ԍ�
		@return �Ȃ�
		@details �G�̃f�o�b�O�`����s��
	*/
	virtual		void		RenderDebug(int i);
	/**
		@brief ColisionStage
		@param[in] buried �G�̖��܂�l
		@return �Ȃ�
		@details �G���X�e�[�W�ƏՓ˂������̏������s��
	*/
	virtual		void		ColisionStage(const Vector2& buried);
	/**
		@brief Damage
		@param[in] damage
		@return �Ȃ�
		@details �_���[�W�������s��
	*/
	virtual		void		Damage(int damage) {
		
		m_HP -= damage;
	
		if (m_HP <= 0) {

			m_bDead = true;

		}
		else {

			m_bDamage = true;

		}

	}
	/**
		@brief FallBehavior
		@param �Ȃ�
		@return �Ȃ�
		@details �����������s��
	*/
	virtual		void		FallBehavior(void) {

		if (m_bFall) {

			m_Move.x = -m_Move.x;

		}

	}

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetPlayerState
		@param[in] PlayerState �v���C���[�̏��
		@return �Ȃ�
		@details �v���C���[�̏�Ԃ̐ݒ���s��
	*/
	virtual		void		SetPlayerState(const CAnime* pPlayerState) { m_pPlayerState = pPlayerState; }
	/**
		@brief SetFind
		@param[in] Find �����t���O
		@return �Ȃ�
		@details �G�̔����t���O�̐ݒ���s��
	*/
	virtual		void		SetFind(bool bFind) { m_bFind = bFind; }
	/**
		@brief SetFall
		@param[in] fall �����t���O
		@return �Ȃ�
		@details �G�̗����t���O�̐ݒ���s��
	*/
	virtual		void		SetFall(bool bFall) { m_bFall = bFall; }
	/**
		@brief SetAppear
		@param[in] bAppear �o���t���O
		@return �Ȃ�
		@details �G�̏o���t���O�̐ݒ���s��
	*/
	virtual		void		SetAppear(bool bAppar) { m_bAppear = bAppar; }

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief FallRect
		@param �Ȃ�
		@return CRectangle ��������p�̋�`
		@details ��������p�̋�`���擾����
	*/
			CRectangle	GetFallRect(void) {

				if (m_bReverse) {

					return CRectangle(m_Pos.x + m_Size.x, m_Pos.y, m_Pos.x + m_Size.x + 128, m_Pos.y + m_Size.y);

				}
				else {

					return CRectangle(m_Pos.x - 128, m_Pos.y, m_Pos.x, m_Pos.y + m_Size.y);

				}

			}
	/**
		@brief GetFindRect
		@param �Ȃ�
		@return CRectangle �v���C���[��������p�̋�`
		@details �v���C���[��������p�̋�`���擾����
	*/
	virtual	CRectangle	GetFindRect(void) {

		return CRectangle(m_Pos.x - m_FindRange.x, m_Pos.y - m_FindRange.y, m_Pos.x + m_FindRange.x, m_Pos.y + m_FindRange.y);

	}
	/**
		@brief IsFind
		@param �Ȃ�
		@return bool true ���� false ������
		@details �����t���O���擾����
	*/
			bool		IsFind(void) { return m_bFind; }
	/**
		@brief IsAppear
		@param �Ȃ�
		@return bool true �o�� false ���o��
		@details �o���t���O���擾����
	*/
			bool		IsAppear(void) { return m_bAppear; }
	/**
		@brief IsAttackPossible
		@param �Ȃ�
		@return bool true �U���\ false �U���s�\
		@details �U���\�t���O���擾����
	*/
	virtual	bool		IsAttackPossible(void) { return true; }

#pragma endregion

};