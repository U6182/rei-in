#pragma once

/**

	@file MotionManager.h
	@brief ���[�V�����̊Ǘ�
	@author �ؑ��J��
	@date 2019/10/23

*/

#include		"GameElement.h"

class CMotionManager {

private:

	//! ���[�V�����̔z��
	std::vector<CSpriteMotionController*>	m_pMotion[CGameElement::MOTION_TYPECOUNT];

	//! ���[�V����
	std::vector<SpriteAnimationCreate>		m_Anim;

#pragma region �֐�

	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details ���[�V�����̉�����s��
	*/
	void		Release(void);
	/**
		@brief AddMotion
		@param anim ���[�V����
		@return �Ȃ�
		@details ���[�V�����̒ǉ����s��
	*/
	void		AddMotion(SpriteAnimationCreate* anim, int animCount);

#pragma endregion

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CMotionManager(void) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CMotionManager(void) { Release(); }

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetMotion
		@param[in] type �擾���郂�[�V����
		@return CMotion* �w�肵�����[�V�����̃|�C���^
		@details �w�肵�����[�V�������擾����
	*/
	CSpriteMotionController*	GetMotion(const int type);

#pragma endregion

};