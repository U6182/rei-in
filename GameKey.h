#pragma once

/**

	@file GameKey.h
	@brief �Q�[���L�[
	@author �ؑ��J��
	@date 2019/11/23

*/

#include		"GamePad.h"

class CGameKey {

private:

	//! �L�[�̃v�b�V���t���O
	bool			m_bLastPush;

	//! �X�e�B�b�N�̃z�[���h�t���O
	bool			m_bHold;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CGameKey(void) { m_bLastPush = false, m_bHold = false; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CGameKey(void) = default;

#pragma endregion	

#pragma region �֐�

	/**
		@brief RenderDebug
		@param �Ȃ�
		@return �Ȃ�
		@details �f�o�b�O�̕`����s��
	*/
	void		RenderDebug(void);
	/**
		@brief KeyUp
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details ��L�[�̃v�b�V���������s��
	*/
	bool		KeyUp(void);
	/**
		@brief KeyDown
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details ���L�[�̃v�b�V���������s��
	*/
	bool		KeyDown(void);
	/**
		@brief KeyLeft
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details ���L�[�̃v�b�V���������s��
	*/
	bool		KeyLeft(void);
	/**
		@brief KeyRight
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details �E�L�[�̃v�b�V���������s��
	*/
	bool		KeyRight(void);
	/**
		@brief PushA
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details A�L�[�̃v�b�V��������s��
	*/
	bool		PushA(void);
	/**
		@brief PushB
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details B�L�[�̃v�b�V��������s��
	*/
	bool		PushB(void);
	/**
		@brief PushX
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details X�L�[�̃v�b�V��������s��
	*/
	bool		PushX(void);
	/**
		@brief PushY
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details Y�L�[�̃v�b�V��������s��
	*/
	bool		PushY(void);
	/**
		@brief PushLB
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details LB�L�[�̃v�b�V��������s��
	*/
	bool		PushLB(void);
	/**
		@brief PushRB
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details RB�L�[�̃v�b�V��������s��
	*/
	bool		PushRB(void);
	/**
		@brief PushSTRAT
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details STRAT�L�[�̃v�b�V��������s��
	*/
	bool		PushSTART(void);
	/**
		@brief PushBACK
		@param �Ȃ�
		@return bool true �L�[�������Ă���  false �L�[������Ă���
		@details BACK�L�[�̃v�b�V��������s��
	*/
	bool		PushBACK(void);
	/**
		@brief HoldLT
		@param �Ȃ�
		@return bool true �z�[���h���  false �z�[���h��Ԃł͂Ȃ�
		@details LT�̃z�[���h������s��
	*/
	bool		HoldLT(void);
	/**
		@brief HoldRT
		@param �Ȃ�
		@return bool true �z�[���h���  false �z�[���h��Ԃł͂Ȃ�
		@details RT�̃z�[���h������s��
	*/
	bool		HoldRT(void);
	/**
		@brief UpStick
		@param �Ȃ�
		@return bool true �z�[���h���  false �z�[���h��Ԃł͂Ȃ�
		@details ��X�e�B�b�N�̃z�[���h������s��
	*/
	bool		UpStick(void);
	/**
		@brief DownStick
		@param �Ȃ�
		@return bool true �z�[���h���  false �z�[���h��Ԃł͂Ȃ�
		@details ���X�e�B�b�N�̃z�[���h������s��
	*/
	bool		DownStick(void);
	/**
		@brief LeftStick
		@param �Ȃ�
		@return bool true �z�[���h���  false �z�[���h��Ԃł͂Ȃ�
		@details ���X�e�B�b�N�̃z�[���h������s��
	*/
	bool		LeftStick(void);
	/**
		@brief RightStick
		@param �Ȃ�
		@return bool true �z�[���h���  false �z�[���h��Ԃł͂Ȃ�
		@details �E�X�e�B�b�N�̃z�[���h������s��
	*/
	bool		RigthStick(void);

#pragma endregion

};