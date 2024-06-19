#pragma once

/**

	@file Weapon.h
	@brief ����
	@author �ؑ��J��
	@date 2019/11/25

*/

#include		"DynamicGameObject.h"

class CWeapon : public CDynamicGameObject {

protected:

	//! �ړ���
	const	Vector2		m_MOVE;

	//! ���˃t���O
			bool		m_bShot;

#pragma region �֐�

	/**
		@brief Behavior
		@param �Ȃ�
		@return �Ȃ�
		@details ����̍s���������s��
	*/
	virtual		void		Behavior(void) { ; };
	/**
		@brief MotionChange
		@param �Ȃ�
		@return �Ȃ�
		@details ����̃��[�V�����������s��
	*/
	virtual		void		MotionChange(void) { ; };

#pragma endregion

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param[in] pTexture �e�N�X�`���̃|�C���^
		@param[out] size �T�C�Y
		@param[in.out] move �ړ���
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CWeapon(CTexture* pTexture, const Vector2 size, const Vector2 move);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CWeapon(void);

#pragma endregion

#pragma region �֐�

	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details ����̍X�V���s��
	*/
	virtual		void	Update(void);
	/**
		@brief Render
		@param[in] scrooll �X�N���[��
		@return �Ȃ�
		@details ����̕`����s��
	*/
	virtual		void	Render(const Vector2& scrooll);
	/**
		@brief Shot
		@param[in] pos ���W
		@return �Ȃ�
		@details ����̔��˂��s��
	*/
	virtual		void	Shot(const Vector2& pos);
	/**
		@brief Shot
		@param[in] pos ���W
		@param[out] bReverse ���]�t���O
		@return �Ȃ�
		@details ����̔��˂��s��
	*/
	virtual		void	Shot(const Vector2& pos, const bool bReverse);

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetShot
		@param[in] bShot �V���b�g�t���O
		@return �Ȃ�
		@details �V���b�g�t���O�̐ݒ���s��
	*/
	void	SetShot(bool bShot) { m_bShot = bShot; }

#pragma endregion
	
#pragma region �Q�b�^�[

	/**
		@brief IsShot
		@param �Ȃ�
		@return bool true �V���b�g false ���V���b�g
		@details �V���b�g�t���O���擾����
	*/
	bool	IsShot() { return m_bShot; }

#pragma endregion

};