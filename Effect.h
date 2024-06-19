#pragma once

/**

	@file Effect.h
	@brief �G�t�F�N�g
	@author �ؑ��J��
	@date 2019/11/23

*/

#include		"GameElement.h"

class CEffect {

private:

	//! �e�N�X�`���̃|�C���^
	CTexture*					m_pTexture;

	//! ���[�V����
	CSpriteMotionController*	m_pMotion;

	//! ��`
	CRectangle					m_StrRect;

	//! ���W
	Vector2						m_Pos;

	//! �T�C�Y
	Vector2						m_Size;

	//! �\���t���O
	bool						m_bShow;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CEffect(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CEffect(void);

#pragma endregion
			
#pragma region �֐�

	/**
		@brief Initialize
		@param[in] type �G�t�F�N�g�̎��
		@return �Ȃ�
		@details �G�t�F�N�g�̏��������s��
	*/
	void	Initialize(const int type);
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �G�t�F�N�g�̍X�V���s��
	*/
	void	Update(void);
	/**
		@brief Render
		@param[in] scrooll �X�N���[���l
		@return �Ȃ�
		@details �G�t�F�N�g�̕`����s��
	*/
	void	Render(const Vector2& scrooll);
	/**
		@brief Start
		@param[in] pos �G�t�F�N�g�̍��W
		@return �Ȃ�
		@details �w�肵���ʒu�ɃG�t�F�N�g�̕\�����s��
	*/
	void	Start(const Vector2& pos);

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetTexture
		@param[in] pTexture �G�t�F�N�g�̃e�N�X�`���|�C���^
		@return �Ȃ�
		@details �G�t�F�N�g�̃e�N�X�`���̐ݒ���s��
	*/
	void	SetTexture(CTexture* pTexture) { m_pTexture = pTexture; }

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param �Ȃ�
		@return CRectangle ��`
		@details ��`���擾����
	*/
				CRectangle		GetRect() { return CRectangle(m_Pos.x, m_Pos.y, m_Pos.x + m_Size.x, m_Pos.y + m_Size.y); }
	/**
		@brief GetSize
		@param �Ȃ�
		@return Vector2 �G�t�F�N�g�̃T�C�Y
		@details �G�t�F�N�g�̃T�C�Y���擾����
	*/
	const		Vector2&		GetSize(void) { return m_Size; }
	/**
		@brief IsShow
		@param �Ȃ�
		@return �Ȃ�
		@details �G�t�F�N�g�̕\���t���O���擾����
	*/
				bool			IsShow(void) { return m_bShow; }

#pragma endregion
	
};