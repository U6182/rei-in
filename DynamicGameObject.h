#pragma once

/**

	@file DynamicGameObject.h
	@brief �L�����N�^�[��A�C�e���̃x�[�X
	@author �ؑ��J��
	@date 2019/11/24

*/

#include		"GameObject.h"
#include		"MotionName.h"

class CDynamicGameObject : public CGameObject {

protected:

	//! �e�N�X�`���̃|�C���^
	CTexture*						m_pTexture;

	//! ���[�V����
	CSpriteMotionController*		m_pMotion;

	//! ���W
	Vector2							m_Pos;

	//! �ړ���
	Vector2							m_Move;

	//! �e�N�X�`���[�̕�
	Vector2							m_Size;

	//! �\���t���O
	bool							m_bShow;

	//! ���]�t���O
	bool							m_bReverse;

	//! �̎��ʔԍ�
	int								m_IDNo;

	//! ���
	int								m_Type;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CDynamicGameObject(const Vector2 size) : CGameObject(), m_Pos(), m_Move(), m_Size(size) {

					m_bShow = false, m_bReverse = false, m_IDNo = 0, m_Type = 0;

				}
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CDynamicGameObject(void) { ; }

#pragma endregion

#pragma region �֐�

	/**
		@brief Reverse
		@param �Ȃ�
		@return �Ȃ�
		@details ���]�������s��
	*/
	virtual		void		Reverse(void) { if (m_Move.x > 0) { m_bReverse = false; } else if (m_Move.x < 0) { m_bReverse = true; } };
	/**
		@brief PosMove
		@param �Ȃ�
		@return �Ȃ�
		@details ���W�ړ��������s��
	*/
	virtual		void		PosMove(void) {

		m_Move.y += CGameElement::GRAVITY;

		m_Pos += m_Move;

	};

#pragma endregion

#pragma region �Z�b�^�[

	/**
		@brief SetTexture
		@param[in] pTexture �e�N�X�`���̃|�C���^
		@return �Ȃ�
		@details �e�N�X�`���̐ݒ���s��
	*/
	void		SetTexture(CTexture* pTexture) { m_pTexture = pTexture; }
	/**
		@brief SetShow
		@param[in] show �\���t���O
		@return �Ȃ�
		@details �\���t���O�̐ݒ���s��
	*/
	void		SetShow(const bool show) { m_bShow = show; }
	/**
		@brief SetIDNo
		@param[in] IDNo �̎��ʔԍ�
		@return �Ȃ�
		@details �̎��ʔԍ��̐ݒ���s��
	*/
	void		SetIDNo(const int IDNo) { m_IDNo = IDNo; }
	/**
		@brief SetPosX
		@param[in] px X���W
		@return �Ȃ�
		@details X���W�̐ݒ���s��
	*/
	void		SetPosX(const float px) { m_Pos.x = px; }
	/**
		@brief SetPosY
		@param[in] py Y���W
		@return �Ȃ�
		@details Y���W�̐ݒ���s��
	*/
	void		SetPosY(const float py) { m_Pos.y = py; }
	
#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetRect
		@param �Ȃ�
		@return CRectangle ��`
		@details ��`���擾����
	*/
	virtual		CRectangle		GetRect() const { return CRectangle(m_Pos.x, m_Pos.y, m_Pos.x + m_Size.x, m_Pos.y + m_Size.y); }
	/**
		@brief GetPos
		@param �Ȃ�
		@return Vector2 ���W
		@details ���W���擾����
	*/
				Vector2&		GetPos(void) { return m_Pos; }
	/**
		@brief GetMove
		@param �Ȃ�
		@return Vector2 �ړ���
		@details �ړ��ʂ��擾����
	*/
				Vector2&	GetMove(void) { return m_Move; }
	/**
		@brief GetSize
		@param �Ȃ�
		@return Vector2 �T�C�Y
		@details �T�C�Y���擾����
	*/
				Vector2&	GetSize(void) { return m_Size; }
	/**
		@brief IsShow
		@param �Ȃ�
		@return bool true �\�� false ��\��
		@details �\���t���O���擾����
	*/
				bool		IsShow(void) { return m_bShow; }
	/**
		@brief GetType
		@param �Ȃ�
		@return int �̎��ʔԍ�
		@details �̎��ʔԍ����擾����
	*/
				int			GetIDNo(void) { return m_IDNo; }
	/**
		@brief GetType
		@param �Ȃ�
		@return int ���
		@details ��ނ��擾����
	*/
				int			GetType(void) { return m_Type; }

#pragma endregion

};