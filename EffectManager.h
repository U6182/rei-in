#pragma once

/**

	@file EffectManager.h
	@brief �G�t�F�N�g�̊Ǘ�
	@author �ؑ��J��
	@date 2019/11/23

*/

#include		"Effect.h"

class CEffectManager {

private:

	//! �G�t�F�N�g
	CEffect				m_Effect[CGameElement::EFFECT_COUNT][CGameElement::EFFECT_TYPE_COUNT];

	//! �e�N�X�`���z��
	CTexture*			m_Texture;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CEffectManager(void) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CEffectManager(void) { ; }

#pragma endregion				

#pragma region �֐�

	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �G�t�F�N�g�̏��������s��
	*/
	void		Initialize(void);
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �G�t�F�N�g�̍X�V���s��
	*/
	void		Update(void);
	/**
		@brief Render
		@param[in] scrooll �X�N���[���l
		@return �Ȃ�
		@details �G�t�F�N�g�̕`����s��
	*/
	void		Render(const Vector2& scrooll);
	/**
		@brief Start
		@param[in] pos �G�t�F�N�g�̍��W
		@param[out] �G�t�F�N�g�̎��
		@return �Ȃ�
		@details �w�肵���ʒu�Ɏw�肵����ނ̃G�t�F�N�g�̕\�����s��
	*/
	void		Start(const Vector2& pos, const int type);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param[in] type �G�t�F�N�g�̎��
		@return CRectangle ��`
		@details �G�t�F�N�g�̋�`���擾����
	*/
				CRectangle			GetRect(const int type) { return m_Effect[0][type].GetRect(); }
	/**
		@brief GetRect
		@param[in] type �G�t�F�N�g�̎��
		@param[out] IDNo �G�t�F�N�g�ԍ�
		@return CRectangle ��`
		@details �G�t�F�N�g�̋�`���擾����
	*/
				CRectangle			GetRect(const int type, const int IDNo) { return m_Effect[IDNo][type].GetRect(); }
	/**
		@brief GetSize
		@param[in] type �G�t�F�N�g�̎��
		@return Vector2 �G�t�F�N�g�̃T�C�Y
		@details �G�t�F�N�g�̃T�C�Y���擾����
	*/
	const		Vector2&			GetSize(const int type) { return m_Effect[0][type].GetSize(); }
	/**
		@brief IsEffect
		@param[in] type �G�t�F�N�g�̎��
		@return bool true �G�t�F�N�g�\���� false�@�G�t�F�N�g��\��
		@details �w�肵����ނ̃G�t�F�N�g�����݂��邩���擾����
	*/
				bool				IsEffect(const int type);

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetTexture
		@param[in] pTexture	�ݒ���s���e�N�X�`���̃|�C���^
		@return �Ȃ�
		@details �e�N�X�`���̐ݒ���s��
	*/
	void				SetTexture(CTexture* pTexture) { m_Texture = pTexture; }

#pragma endregion

};