#pragma once

/**

	@file Charm.h
	@brief �D
	@author �ؑ��J��
	@date 2019/11/02

*/

#include		"Item.h"

class CCharm : public CItem {

protected:

	//! ����t���O
			bool	m_bLiberation;

	//! �X�P�[��
			float	m_Scale;

	//! �ő�X�P�[��
	const	float	m_MAXSCALE = 4.0f;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param[in] pos ���W
		@param[out] size �T�C�Y
		@param[in.out] type ���
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CCharm(const Vector2 pos, const Vector2 size, const int type);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CCharm(void);

#pragma endregion						

#pragma region �֐�

	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �D�̍X�V���s��
	*/
	virtual		void		Update(void);
	/**
		@brief Render
		@param[in] scrooll �X�N���[���l
		@return �Ȃ�
		@details �D�̕`����s��
	*/
	virtual		void		Render(const Vector2& scrooll);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief IsLiberation
		@param �Ȃ�
		@return bool true �o�� false ���o��
		@details ����t���O���擾����
	*/
	bool		IsLiberation(void) { return m_bLiberation; }

#pragma endregion

};