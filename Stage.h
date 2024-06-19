#pragma once

/**

	@file Stage.h
	@brief ステージ
	@author 木村憂哉
	@date 2019/10/23

*/

#include	"Game.h"
#include	"Player.h"
#include	"Enemy.h"
#include	"Item.h"

class CStage {

private:

	//! 敵のテクスチャのポインタ
	std::vector<CTexture*>		m_EnemyTexture;

	//! アイテムのテクスチャのポインタ
	std::vector<CTexture*>		m_ItemTexture;

	//! ステージの背景テクスチャ
	CTexture*					m_pBackImageTexture;

	//! ステージのテクスチャ
	CTexture*					m_pChipTexture;

	//! ステージのスクロール値
	Vector2						m_Scrooll;
	
	//! ステージの位置情報
	char*						m_pChipData;

	//! 敵の位置情報
	char*						m_pEnemyData;
	
	//! アイテムの位置情報
	char*						m_pItemData;

	//! ステージの列の数
	int							m_XCount;

	//! ステージの行の数
	int							m_YCount;

	//! 敵の出現数
	int							m_EnemyCount;

	//! アイテムの出現数
	int							m_ItemCount;
	
	//! ステージテクスチャのサイズ
	float						m_ChipSize;

#pragma region 関数

	/**
		@brief InfoLoad
		@param[in] pInfo ステージの情報
		@return bool true 成功 false 失敗
		@details ステージの情報を読み込む
	*/
	bool		InfoLoad(char* pInfo);
	/**
		@brief EnemyInitialize
		@param[in] pEnemy 出現する敵のポインタ
		@return なし
		@details 敵の初期化を行う
	*/
	void		EnemyInitialize(std::vector<CEnemy*>& pEnemy);
	/**
		@brief ItemInitialize
		@param[in] pItem 出現するアイテムのポインタ
		@return なし
		@details アイテムの初期化を行う
	*/
	void		ItemInitialize(std::vector<CItem*>& pItem);
	/**
		@brief ScroollCorrection
		@param[in] pPlayer プレイヤーのポインタ
		@return なし
		@details プレイヤーのスクロール補正を行う
	*/
	void		ScroollCorrection(CPlayer* pPlayer);

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CStage(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CStage(void);

#pragma endregion
					
#pragma region 関数

	/**
		@brief Load
		@param[in] pName ステージテキストのファイルパス
		@return bool true 成功 false 失敗
		@details テキストからステージを読み込む
	*/
	bool		Load(char* pName);
	/**
		@brief Initialize
		@param[in] pEnemy 出現する敵のポインタ
		@param[out] pItem 出現するアイテムのポインタ
		@return なし
		@details 敵とアイテムと自身の初期化を行う
	*/
	void		Initialize(std::vector<CEnemy*>& pEnemy, std::vector<CItem*>& pItem);
	/**
		@brief Update
		@param[in] pPlayer プレイヤーのポインタ
		@return なし
		@details ステージの更新を行う
	*/
	void		Update(CPlayer* pPlayer);
	/**
		@brief Render
		@param なし
		@return なし
		@details ステージの描画を行う
	*/
	void		Render(void);
	/**
		@brief Release
		@param なし
		@return なし
		@details ステージの解放を行う
	*/
	void		Release(void);
	/**
		@brief Collision
		@param[in] r ステージと当たり判定を行う矩形
		@param[out] buried 埋まり値
		@return bool true ステージと衝突した　false ステージと衝突していない
		@details ステージとの衝突判定を行う
	*/
	bool		Collision(CRectangle r, Vector2& buried);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetScroll
		@param なし
		@return Vector2& ステージのスクロール値
		@details ステージのスクロール値を取得する
	*/
	const		Vector2&		GetScrooll(void) { return m_Scrooll; }
	/**
		@brief GetStageHeight
		@param なし
		@return int ステージのマップの高さを取得
		@details ステージのマップの高さを取得する
	*/
				int				GetStageHeight(void) { return m_YCount * m_ChipSize; };

#pragma endregion

};
