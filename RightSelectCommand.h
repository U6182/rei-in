#pragma once

/**

	@file RightSelectCommand.h
	@brief ���C�g�Z���N�g�R�}���h
	@author �ؑ��J��
	@date 2020/10/23

*/

#include	"Command.h"
#include	"Transition.h"

class CRightSelectCommand : public CCommand {

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

			pTransition->SelectDownAndRight();

		}

	}

#pragma endregion

};