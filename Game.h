#pragma once

/**

	@file Game.h
	@brief ゲームシステムへのアクセス
	@author 木村憂哉
	@date 2020/10/13

*/

#include		"Controller.h"
#include		"TextureManager.h"
#include		"EffectManager.h"
#include		"FontManager.h"
#include		"SoundManager.h"
#include		"MotionManager.h"
#include		"Setting.h"

class CGame {

private:

	//! 自身のポインタ
	static		CGame*				m_pInstance;

	//! コントローラー
				CController*		m_pController;

	//! テクスチャマネージャー
				CTextureManager*	m_pTextureManager;

	//! エフェクトマネージャー
				CEffectManager*		m_pEffectManager;

	//! フォントマネージャー
				CFontManager*		m_pFontManager;

	//! サウンドマネージャー
				CSoundManager*		m_pSoundManager;

	//! モーションマネージャー
				CMotionManager*		m_pMotionManager;

	//! 設定
				CSetting*			m_pSetting;


#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CGame(void) : m_pController(nullptr), m_pTextureManager(nullptr), m_pEffectManager(nullptr), m_pFontManager(nullptr), m_pSoundManager(nullptr), m_pMotionManager(nullptr), m_pSetting(nullptr) { ; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CGame(void) { ; }

#pragma endregion

public:

#pragma region 関数

	/**
		@brief Release
		@param なし
		@return なし
		@details 自身とメンバの解放を行う
	*/
	void Release() {

		//コントローラーの解放
		if (m_pController) {

			delete m_pController;

			m_pController = nullptr;

		}

		//テクスチャマネージャーの解放
		if (m_pTextureManager) {

			delete m_pTextureManager;

			m_pTextureManager = nullptr;

		}

		//エフェクトマネージャーの解放
		if (m_pEffectManager) {

			delete m_pEffectManager;

			m_pEffectManager = nullptr;

		}
		
		//フォントマネージャーの解放
		if (m_pFontManager) {

			delete m_pFontManager;

			m_pFontManager = nullptr;

		}

		//サウンドマネージャーの解放
		if (m_pSoundManager) {

			delete m_pSoundManager;

			m_pSoundManager = nullptr;

		}

		//モーションマネージャーの解放
		if (m_pMotionManager) {

			delete m_pMotionManager;

			m_pMotionManager = nullptr;

		}

		//設定の解放
		if (m_pSetting) {

			delete m_pSetting;

			m_pSetting = nullptr;

		}

		//自身の解放
		if (m_pInstance) {

			delete m_pInstance;

			m_pInstance = nullptr;

		}

	}

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetInstance
		@param なし
		@return CGame* 自身のインスタンス
		@details 自身のインスタンスを取得する
	*/
	static	CGame*	GetInstance(void) {

		if (m_pInstance == nullptr) {

			m_pInstance = new CGame();

		}

		return m_pInstance;

	}
	/**
		@brief GetController
		@param なし
		@return CControllerr* コントローラー
		@details コントローラーを取得する
	*/
	CController*	GetController(void) {

		if (m_pController == nullptr) {

			m_pController = new CController();

		}

		return m_pController;

	}

	/**
		@brief GetTextureManager
		@param なし
		@return CTextureManager* テクスチャマネージャー
		@details テクスチャマネージャーを取得する
	*/
	CTextureManager*	GetTextureManager(void) {

		if (m_pTextureManager == nullptr) {

			m_pTextureManager = new CTextureManager();

		}

		return m_pTextureManager;

	}

	/**
		@brief GetEffectManager
		@param なし
		@return CEffectManager* エフェクトマネージャー
		@details エフェクトマネージャーを取得する
	*/
	CEffectManager*	GetEffectManager(void) {

		if (m_pEffectManager == nullptr) {

			m_pEffectManager = new CEffectManager();

		}

		return m_pEffectManager;

	}

	/**
		@brief GetFontManager
		@param なし
		@return CFontManager* フォントマネージャー
		@details フォントマネージャーを取得する
	*/
	CFontManager*	GetFontManager(void) {

		if (m_pFontManager == nullptr) {

			m_pFontManager = new CFontManager();

		}

		return m_pFontManager;

	}

	/**
		@brief GetSoundManager
		@param なし
		@return CSoundManager* サウンドマネージャー
		@details サウンドマネージャーを取得する
	*/
	CSoundManager*	GetSoundManager(void) {

		if (m_pSoundManager == nullptr) {

			m_pSoundManager = new CSoundManager();

		}

		return m_pSoundManager;

	}

	/**
		@brief GetMotionManager
		@param なし
		@return CMotionManager* モーションマネージャー
		@details モーションマネージャーを取得する
	*/
	CMotionManager*	GetMotionManager(void) {

		if (m_pMotionManager == nullptr) {

			m_pMotionManager = new CMotionManager();

		}

		return m_pMotionManager;

	}

	/**
		@brief GetSetting
		@param なし
		@return CSetting* 設定
		@details 設定を取得する
	*/
	CSetting*	GetSetting(void) {

		if (m_pSetting == nullptr) {

			m_pSetting = new CSetting();

		}

		return m_pSetting;

	}

#pragma endregion

};

/**
	@def
	自身のインスタンスをグローバルとして置換する
*/
#define		g_pGame		CGame::GetInstance()