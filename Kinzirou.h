#pragma once

/**

	@file Kinzirou.h
	@brief ��m�{�����Y
	@author �ؑ��J��
	@date 2019/11/25

*/

#include		"Enemy.h"

class CKinzirou : public CEnemy {

protected:

#pragma region �֐�

	/**
		@brief MotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details ��m�{�����Y�̃��[�V�����������s��
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
				CKinzirou(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CKinzirou(void);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param �Ȃ�
		@return CRectangle ��`
		@details ��`���擾����
	*/
	CRectangle		GetRect(void) const override { return CRectangle(m_Pos.x + 60, m_Pos.y + 15, m_Pos.x + m_Size.x - 70, m_Pos.y + m_Size.y - 5); }
	/**
		@brief IsAttackPossible
		@param �Ȃ�
		@return bool true �U���\ false �U���s�\
		@details �U���\�t���O���擾����
	*/
	bool			IsAttackPossible(void) override{ return false; }

#pragma endregion

};