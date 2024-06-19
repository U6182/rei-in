/**

	@file Load.cpp
	@brief 素材の読み込み
	@author 木村憂哉
	@date 2020/10/22

*/

#include	"Load.h"

void CLoad::Run() {

	//ロード終了の結果
	m_State = Load();

}

int CLoad::Load() {

	//素材数のカウント
	for (m_LoadMaxCount = 0; CGameElement::g_FileName[m_LoadMaxCount] != nullptr; m_LoadMaxCount++);

	//テクスチャの読み込み
	for (; m_LoadCount < CGameElement::TEXTURE_MAXCOUNT - 1; m_LoadCount++) {

		if (!m_Texture[m_LoadCount].Load(CGameElement::g_FileName[m_LoadCount])) {

			return LOADING_ERROR;

		}
	
	}

	//サウンドの読み込み
	/*for (; m_LoadCount < m_LoadMaxCount; m_LoadCount++) {

		if (!m_Sound->Load(CGameElement::g_FileName[m_LoadCount])) {

			return LOADING_ERROR;

		}

	}*/

	return LOADING_FINISHED;

}

void CLoad::Render() {

	//計算おかしい
	int percentCount = m_LoadMaxCount / 100;

	switch (m_State)
	{

	case LOADING_FINISHED:

		CGraphicsUtilities::RenderString(0, 50, "読み込みが完了しました");

		break;
	case LOADING_ERROR:

		CGraphicsUtilities::RenderString(0, 50, "読み込み中にエラーが発生しました");

		break;
	}

	//m_LoadPercent = m_LoadCount / percentCount;

	//CGraphicsUtilities::RenderString(0, 0, "%d %", m_LoadPercent);

}