#pragma once

/**

	@file LeftSelectCommand.h
	@brief レフトセレクトコマンド
	@author 木村憂哉
	@date 2020/10/23

*/

#include	"Command.h"
#include	"Transition.h"

class CLeftSelectCommand : public CCommand {

public:

#pragma region 関数

	/**
		@brief Execute
		@param[in] pGameObject ゲームオブジェクト
		@return なし
		@details コマンド操作を行う
	*/
	const	virtual		void	Execute(CGameObject* pGameObject) {

		CTransition* pTransition = dynamic_cast<CTransition*>(pGameObject);

		if (pTransition) {

			pTransition->SelectUpAndLeft();

		}

	}

#pragma endregion

};