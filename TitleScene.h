#pragma once

/**

	@file TitleScene.h
	@brief タイトルシーン
	@author 木村憂哉
	@date 2019/11/20

*/

#include		"SceneBase.h"

class CTitleScene : public CSceneBase {

private:

	//! タイトルロゴ
			CTexture*				m_pLogo;

	//! 選択矢印
			CTexture*				m_pArrow;

	//! メニューのタイトル
			std::vector<CTexture*>	m_pMenuTitle;

	//! メニューのタイトルの座標
			std::vector<Vector2>	m_MenuTitlePos;

	//! タイトルロゴの座標
			Vector2					m_LogoPos;

	//! セレクト番号
			int						m_SelectNo;

	//! スクロール
			int						m_Scrooll;

	//! 次のシーン
	const	std::vector<int>		m_NextSceneList = { CGameElement::SCENENO_GAME, CGameElement::SCENENO_OPTION, CGameElement::SCENENO_OPERATIONDESCRIPTION, CGameElement::SCENENO_EXIT };

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CTitleScene(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CTitleScene(void);

#pragma endregion		

#pragma region 関数

	/**
		@brief Load
		@param なし
		@return bool true 成功 false 失敗
		@details タイトルシーンの読み込み
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param なし
		@return なし
		@details タイトルシーンの初期化を行う
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param なし
		@return なし
		@details タイトルシーンの更新を行う
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param なし
		@return なし
		@details タイトルシーンの描画を行う
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param なし
		@return なし
		@details タイトルシーンの解放を行う
	*/
	void	Release(void) override;

#pragma endregion

};