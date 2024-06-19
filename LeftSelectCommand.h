#pragma once

/**

	@file LeftSelectCommand.h
	@brief ���t�g�Z���N�g�R�}���h
	@author �ؑ��J��
	@date 2020/10/23

*/

#include	"Command.h"
#include	"Transition.h"

class CLeftSelectCommand : public CCommand {

public:

#pragma region �֐�

	/**
		@brief Execute
		@param[in] pGameObject �Q�[���I�u�W�F�N�g
		@return �Ȃ�
		@details �R�}���h������s��
	*/
	const	virtual		void	Execute(CGameObject* pGameObject) {

		CTransition* pTransition = dynamic_cast<CTransition*>(pGameObject);

		if (pTransition) {

			pTransition->SelectUpAndLeft();

		}

	}

#pragma endregion

};