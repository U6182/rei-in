#pragma once

/**

	@file HumanBodyModle.h
	@brief �l�̖͌^
	@author �ؑ��J��
	@date 2019/11/25

*/

#include		"Enemy.h"
#include		"Viscera.h"

class CHumanBodyModle : public CEnemy {

protected:

#pragma region �֐�

	/**
		@brief Behavior
		@param �Ȃ�
		@return �Ȃ�
		@details �l�̖͌^�̍s���������s��
	*/
	void		Behavior(void) override;
	/**
		@brief MotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �l�̖͌^�̃��[�V�����������s��
	*/
	void		MotionChange(void) override;

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
				CHumanBodyModle(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CHumanBodyModle(void);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param �Ȃ�
		@return CRectangle ��`
		@details ��`���擾����
	*/
	CRectangle	GetRect(void) const override { return CRectangle(m_Pos.x + 40, m_Pos.y + 20, m_Pos.x + m_Size.x - 40, m_Pos.y + m_Size.y - 5); }

	/**
		@brief GetAttackRect
		@param �Ȃ�
		@return CRectangle �U����`
		@details �U����`���擾����
	*/
	CRectangle	GetAttackRect(void) override {

		return m_Weapon->GetRect();

	}

#pragma endregion

};