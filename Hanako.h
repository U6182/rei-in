#pragma once

/**

	@file Hanako.h
	@brief �Ԏq
	@author �ؑ��J��
	@date 2019/11/25

*/

#include		"Enemy.h"

class CHanako : public CEnemy {

protected:

#pragma region �֐�

	/**
		@brief Behavior
		@param �Ȃ�
		@return �Ȃ�
		@details �Ԏq�̍s���������s��
	*/
	void		Behavior(void) override;
	/**
		@brief MotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details �Ԏq�̃��[�V�����������s��
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
				CHanako(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CHanako(void);

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

		if (m_bReverse) {

			return CRectangle(GetRect().Right, GetRect().Top, GetRect().Right + 31, GetRect().Bottom);

		}
		else {

			return CRectangle(GetRect().Left - 31, GetRect().Top, GetRect().Left, GetRect().Bottom);

		}
	
	}

#pragma endregion

};