#pragma once

/**

	@file GameObject.h
	@brief �Q�[���I�u�W�F�N�g
	@author �ؑ��J��
	@date 2019/11/24

*/

#include		"GameElement.h"

class CGameObject {

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
				CGameObject(void) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	virtual		~CGameObject(void) { }

#pragma endregion

};