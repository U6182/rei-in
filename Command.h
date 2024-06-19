#pragma once

/**

	@file Command.h
	@brief �R�}���h
	@author �ؑ��J��
	@date 2020/10/23

*/

#include		"GameObject.h"

class CCommand {

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CCommand(void) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CCommand(void) { ; }

#pragma endregion

#pragma region �֐�

	/**
		@brief Execute
		@param[in] pGameObject �Q�[���I�u�W�F�N�g
		@return �Ȃ�
		@details �R�}���h������s��
	*/
	const	virtual		void		Execute(CGameObject* pGameObject) { ; }

#pragma endregion

};