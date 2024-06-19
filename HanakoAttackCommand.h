#pragma once

/**

	@file HanakoAttackCommand.h
	@brief �Ԏq�̍U���R�}���h
	@author �ؑ��J��
	@date 2020/10/23

*/

#include	"Command.h"
#include	"Player.h"

class CHanakoAttackCommand : public CCommand {

public:

#pragma region �֐�

	/**
		@brief Execute
		@param[in] pGameObject �Q�[���I�u�W�F�N�g
		@return �Ȃ�
		@details �R�}���h������s��
	*/
	const	virtual		void	Execute(CGameObject* pGameObject) {

		CPlayer* pPlayer = dynamic_cast<CPlayer*>(pGameObject);

		if (pPlayer) {

			pPlayer->SetbOperation(true, CGameElement::PLAYER_OPERATION_ATTACK);

		}

	}

#pragma endregion

};