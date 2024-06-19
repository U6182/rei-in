#pragma once

/**

	@file Viscera.h
	@brief �l�̖͌^�̓���
	@author �ؑ��J��
	@date 2019/11/25

*/

#include		"Weapon.h"

class CViscera : public CWeapon {

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param[in] pTexture �e�N�X�`���̃|�C���^
		@param[out] size �T�C�Y
		@param[in.out] move �ړ���
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CViscera(CTexture* pTexture, const Vector2 size, const Vector2 move);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CViscera(void);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param �Ȃ�
		@return CRectangle ��`
		@details ��`���擾����
	*/
	CRectangle	GetRect() const override { return CRectangle(m_Pos.x + 5, m_Pos.y + 5, m_Pos.x + m_Size.x - 5, m_Pos.y + m_Size.y - 5); }

#pragma endregion

};