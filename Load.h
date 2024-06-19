#pragma once

/**

	@file Load.h
	@brief　リソースの読み込み
	@author 木村憂哉
	@date 2020/10/29

*/

#include	"Sound.h"

class CLoad : public CThread {

private:

	//! テクスチャ
	CTexture*		m_Texture;

	//! サウンド
	CSoundBuffer*	m_Sound;

	//! ロードの状態
	int				m_State;

	//! 読み込み数
	int				m_LoadMaxCount;

	//! 現在の読み込み数
	int				m_LoadCount;

	//! 読み込みの進行度
	int				m_LoadPercent;

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
	CLoad(void) : m_Texture(new CTexture[CGameElement::TEXTURE_MAXCOUNT]), m_Sound(/*new CSoundBuffer[CGameElement::SOUND_TYPECOUNT]*/nullptr) { m_State = LOADING_NOW, m_LoadMaxCount = 0, m_LoadCount = 0, m_LoadPercent = 0; }
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	~CLoad(void) { ; }

#pragma endregion

#pragma region 関数

	/**
		@brief Run
		@param なし
		@return なし
		@details スレッドを開始する
	*/
	void	Run(void);
	/**
		@brief Load
		@param なし
		@return なし
		@details リソースの読み込みを行う
	*/
	int		Load(void);
	/**
		@brief Render
		@param なし
		@return なし
		@details 読み込みの描画を行う
	*/
	void	Render(void);

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetTexturePointer
		@param なし
		@return CTexture* 読み込んだテクスチャ
		@details 読み込んだテクスチャを取得する
	*/
	CTexture*		GetTexturePointer(void) { return m_Texture; }
	/**
		@brief GetSoundPointer
		@param なし
		@return CSoundBuffer* 読み込んだサウンド
		@details 読み込んだサウンドを取得する
	*/
	CSoundBuffer*	GetSoundPointer(void) { return m_Sound; }
	/**
		@brief GetState
		@param なし
		@return int 読み込みの状態
		@details 読み込みの状態を取得する
	*/
	int				GetState(void) { return m_State; }

#pragma endregion

	/**
	@enum tag_FINISHED
	読み込みの状態の列挙定数

	*/
	typedef enum tag_FINISHED {

		LOADING_NOW,

		LOADING_FINISHED,

		LOADING_ERROR

	}LOAD_FINISHED_NO;

};