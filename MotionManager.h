#pragma once

/**

	@file MotionManager.h
	@brief モーションの管理
	@author 木村憂哉
	@date 2019/10/23

*/

#include		"GameElement.h"

class CMotionManager {

private:

	//! モーションの配列
	std::vector<CSpriteMotionController*>	m_pMotion[CGameElement::MOTION_TYPECOUNT];

	//! モーション
	std::vector<SpriteAnimationCreate>		m_Anim;

#pragma region 関数

	/**
		@brief Release
		@param なし
		@return なし
		@details モーションの解放を行う
	*/
	void		Release(void);
	/**
		@brief AddMotion
		@param anim モーション
		@return なし
		@details モーションの追加を行う
	*/
	void		AddMotion(SpriteAnimationCreate* anim, int animCount);

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CMotionManager(void) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CMotionManager(void) { Release(); }

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetMotion
		@param[in] type 取得するモーション
		@return CMotion* 指定したモーションのポインタ
		@details 指定したモーションを取得する
	*/
	CSpriteMotionController*	GetMotion(const int type);

#pragma endregion

};