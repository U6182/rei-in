#pragma once

/**

	@file TextureManager.h
	@brief �e�L�X�`���̊Ǘ�
	@author �ؑ��J��
	@date 2019/10/23

*/

#include		"GameElement.h"

class CTextureManager {

private:

	//! �e�N�X�`���̔z��
	CTexture*		m_Texture;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CTextureManager(void) : m_Texture(nullptr) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CTextureManager(void) { Release(); }

#pragma endregion

#pragma region �֐�

	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �e�N�X�`���̉�����s��
	*/
	void		Release(void);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetTexture
		@param[in] type �擾����e�N�X�`��
		@return CTexture* �w�肵���e�N�X�`���̃|�C���^
		@details �w�肵���e�N�X�`�����擾����
	*/
			CTexture*	GetTexture(const int type);
	/**
		@brief GetSize
		@param[in] type �T�C�Y���擾����e�N�X�`��
		@return Vector2 �e�N�X�`���̃T�C�Y
		@details �w�肵���e�N�X�`�����擾����
	*/
	const	Vector2		GetSize(const int type) { return Vector2(m_Texture[type].GetWidth(), m_Texture[type].GetHeight()); }

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetTexture
		@param[in] pTexture	�ݒ���s���e�N�X�`��
		@return �Ȃ�
		@details �e�N�X�`���̐ݒ���s��
	*/
	void	SetTexture(CTexture* pTexture) {

		m_Texture = pTexture;

	}
	
#pragma endregion

};