#pragma once

/**

	@file TekeTeke.h
	@brief �e�P�e�P
	@author �ؑ��J��
	@date 2019/11/25

*/

#include		"Enemy.h"

class CTekeTeke : public CEnemy {

protected:

	//! �`���[�W�G�t�F�N�g
	const	std::vector<int>	m_CHARGE_STAGE = {CGameElement::EFFECT_TEKETEKE_CHARGESTAGE1, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE2, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE3, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE4, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE5};

	//! �o�[�X�g
			bool				m_bBurst = false;

	//! �ő�`���[�W�^�C��
	const	int					m_MAX_CHARGE = 5;

	//! �`���[�W�^�C��
			float				m_ChargeTime;

	//! �`���[�W��
			float				m_Charging;

#pragma region �֐�

	/**
		@brief Behavior
		@param �Ȃ�
		@return �Ȃ�
		@details �e�P�e�P�̍s���������s��
	*/
	void		Behavior(void) override;
	/**
		@brief MotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �e�P�e�P�̃��[�V�����������s��
	*/
	void		MotionChange(void) override;
	/**
		@brief PosMove
		@param �Ȃ�
		@return �Ȃ�
		@details ���W�ړ��������s��
	*/
	void		PosMove(void) override{

		if (m_ChargeTime <= 0) {

			m_Move.y += CGameElement::GRAVITY;

			m_Pos += m_Move;

		}

	};
	/**
		@brief Effect
		@param �Ȃ�
		@return �Ȃ�
		@details ���ʏ������s��
	*/
	void		Effect(void) override;

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
				CTekeTeke(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CTekeTeke(void);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param �Ȃ�
		@return CRectangle ��`
		@details ��`���擾����
	*/
			CRectangle		GetRect(void) const override { return CRectangle(m_Pos.x + 30, m_Pos.y + 20, m_Pos.x + m_Size.x - 30, m_Pos.y + m_Size.y - 5); }
	/**
		@brief GetFindRect
		@param �Ȃ�
		@return CRectangle �v���C���[��������p�̋�`
		@details �v���C���[��������p�̋�`���擾����
	*/
			CRectangle	GetFindRect(void) override {

				if (m_bReverse) {

					return CRectangle(m_Pos.x + m_Size.x, m_Pos.y, m_Pos.x + m_Size.x + m_FindRange.x, m_Pos.y + m_Size.y);

				}
				else {

					return CRectangle(m_Pos.x - m_FindRange.x, m_Pos.y, m_Pos.x, m_Pos.y + m_Size.y);
			
				}

			}
	/**
		@brief GetAttackPoint
		@param �Ȃ�
		@return int	GetAttackPoint
		@details �U���͂̎擾���s��
	*/
			int			GetAttackPoint(void) override { 
		
				int charging = static_cast<int>(m_Charging);

				if (charging == 0) {

					charging = 1;

				}
				else if (charging < 0) {

					charging = -charging;

				}

				return m_AttackPoint * charging; 
	
			}

#pragma endregion

};