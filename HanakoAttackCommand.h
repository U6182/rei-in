#pragma once

/**

	@file HanakoAttackCommand.h
	@brief 花子の攻撃コマンド
	@author 木村憂哉
	@date 2020/10/23

*/

#include	"Command.h"
#include	"Player.h"

class CHanakoAttackCommand : public CCommand {

public:

#pragma region 関数

	/**
		@brief Execute
		@param[in] pGameObject ゲームオブジェクト
		@return なし
		@details コマンド操作を行う
	*/
	const	virtual		void	Execute(CGameObject* pGameObject) {

		CPlayer* pPlayer = dynamic_cast<CPlayer*>(pGameObject);

		if (pPlayer) {

			pPlayer->SetbOperation(true, CGameElement::PLAYER_OPERATION_ATTACK);

		}

	}

#pragma endregion

};