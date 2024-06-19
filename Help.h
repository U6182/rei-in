#pragma once

/**

	@file Help.h
	@brief ヘルプ
	@author 木村憂哉
	@date 2019/11/20

*/

#include		"SceneBase.h"

class CHelp : public CSceneBase {

private:

	/**
	@enum tag_HELP
	ヘルプの列挙定数

	*/
	enum tag_HELP {

		HELP_PLAYER, HELP_BACKPLAYER, HELP_COUNT

	};

	//! 矢印の座標
				Vector2							m_ArrowPos[HELP_COUNT];

	//! ヘルプ
	const		int		m_Help[HELP_COUNT] = { TEXTURE_HELP_IMAGE, TEXTURE_HELP_IMAGE2 };

	//! ページ
				int		m_Page;

	//! 矢印の方向
	const		float	m_Arrow[HELP_COUNT] = { ARROW_RIGHT, ARROW_LEFT };

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CHelp(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CHelp(void);

#pragma endregion		

#pragma region 関数

	/**
		@brief Load
		@param なし
		@return bool true 成功 false 失敗
		@details ヘルプの読み込み
	*/
	bool	Load(void);
	/**
		@brief Initialize
		@param なし
		@return なし
		@details ヘルプの初期化を行う
	*/
	void	Initialize(void);
	/**
		@brief Update
		@param なし
		@return なし
		@details ヘルプの更新を行う
	*/
	void	Update(void);
	/**
		@brief Render
		@param なし
		@return なし
		@details ヘルプの描画を行う
	*/
	void	Render(void);
	/**
		@brief Release
		@param なし
		@return なし
		@details ヘルプの解放を行う
	*/
	void	Release(void);
	/**
		@brief GamePadOperation
		@param なし
		@return なし
		@details ヘルプの操作処理を行う
	*/
	void	GamePadOperation(void);

#pragma endregion

};