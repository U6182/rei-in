#pragma once

/**

	@file DownSelectCommand.h
	@brief ダウンセレクトコマンド
	@author 木村憂哉
	@date 2020/10/23

*/

#include	"Command.h"

class CDownSelectCommand : public CCommand {

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

			pTransition->SelectDownAndRight();

		}

	}

#pragma endregion

};