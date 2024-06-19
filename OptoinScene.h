#pragma once

/**

	@file OptionScene.h
	@brief オプションシーン
	@author 木村憂哉
	@date 2019/11/20

*/

#include		"SceneBase.h"

class COptionScene : public CSceneBase {

private:

	//! 背景のテクスチャポインタ
			std::vector<CTexture*>		m_pTextureList;

	//! セレクト番号
			int							m_SelectNo;

	//! 次のシーン
	const	std::vector<int>			m_NextSceneList = { CGameElement::SCENENO_TITLE, CGameElement::SCENENO_TITLE };

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	COptionScene(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~COptionScene(void);

#pragma endregion		

#pragma region 関数

	/**
		@brief Load
		@param なし
		@return bool true 成功 false 失敗
		@details オプションシーンの読み込み
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param なし
		@return なし
		@details オプションシーンの初期化を行う
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param なし
		@return なし
		@details オプションシーンの更新を行う
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param なし
		@return なし
		@details オプションシーンの描画を行う
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param なし
		@return なし
		@details オプションシーンの解放を行う
	*/
	void	Release(void) override;

#pragma endregion

};