#pragma once

/**

	@file Item.h
	@brief �A�C�e��
	@author �ؑ��J��
	@date 2019/11/02

*/

#include		"DynamicGameObject.h"

class CItem : public CDynamicGameObject {

protected:

	//! �o���t���O
	bool	m_bAppear;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param[in] pos ���W
		@param[out] size �T�C�Y
		@param[in.out] type ���
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CItem(const Vector2 pos, const Vector2 size, const int type);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CItem(void);

#pragma endregion						
	
#pragma region �֐�

	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �A�C�e���̍X�V���s��
	*/
	virtual		void		Update(void) { ; }
	/**
		@brief Render
		@param[in] scrooll �X�N���[���l
		@return �Ȃ�
		@details �A�C�e���̕`����s��
	*/
	virtual		void		Render(const Vector2& scrooll);
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �A�C�e���̉�����s��
	*/
	virtual		void		Release(void);

#pragma endregion

#pragma region �Z�b�^�[

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
		@brief IsAppear
		@param �Ȃ�
		@return bool true �o�� false ���o��
		@details �o���t���O���擾����
	*/
	bool		IsAppear(void) { return m_bAppear; }

#pragma endregion

};