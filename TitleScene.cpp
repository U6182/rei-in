/**

	@file TitleScene.cpp
	@brief タイトルシーン
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"TitleScene.h"

CTitleScene::CTitleScene() : CSceneBase(&m_NextSceneList) {

	//コマンドの設定
	g_pGame->GetController()->SetTitleCommand();

	//選択番号の取得
	m_SelectNo = m_Transition->GetSelectNo();

	//スクロールの初期化
	m_Scrooll = 0;

}

CTitleScene::~CTitleScene() {

	//解放
	Release();

}

bool CTitleScene::Load() {

	//タイトルの背景の読み込み
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_STAGE_BACKIMAGE);

	//ロゴの読み込み
	m_pLogo = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_TITEL_LOGO);

	//矢印の読み込み
	m_pArrow = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_ARROW);

	//タイトルのメニューの読み込み
	const int menuList[] = { CGameElement::TEXTURE_TITEL_MENU_GAME, CGameElement::TEXTURE_TITEL_MENU_OPTION, CGameElement::TEXTURE_TITEL_MENU_OPERATIONDESCRIPTION, CGameElement::TEXTURE_TITEL_MENU_EXIT,
							 CGameElement::TEXTURE_TITEL_MENU_GAME_SELECT, CGameElement::TEXTURE_TITEL_MENU_OPTION_SELECT, CGameElement::TEXTURE_TITEL_MENU_OPERATIONDESCRIPTION_SELECT, CGameElement::TEXTURE_TITEL_MENU_EXIT_SELECT };

	const int menuEL = sizeof(menuList) / sizeof(menuList[0]);

	for (int i = 0; i < menuEL; i++) {

		m_pMenuTitle.push_back(g_pGame->GetTextureManager()->GetTexture(menuList[i]));


	}

	const int offset = 100;

	//タイトルロゴの座標
	m_LogoPos = Vector2(CUtili::CenterTexturePosX(*m_pLogo), offset);

	float posX = (g_pGraphics->GetTargetWidth() - ((m_pMenuTitle[0]->GetWidth() * (menuEL / 2) - 1) + (m_pArrow->GetWidth() * (menuEL / 2) - 1)) + m_pMenuTitle[5]->GetWidth()) / 2;

	//タイトルのメニューの座標
	for (int i = 0; i < menuEL / 2; i++) {

		m_MenuTitlePos.push_back(Vector2(posX + i * (m_pArrow->GetWidth() + m_pMenuTitle[i]->GetWidth()), g_pGraphics->GetTargetHeight() * 0.58f));

	}

	return true;

}

void CTitleScene::Initialize() {

	//読み込み
	Load();

}

void CTitleScene::Update() {

	//BGMの再生
	g_pGame->GetSoundManager()->Play(CGameElement::SOUND_BGM_GAME);

	//操作
	Operation(m_Transition);

	//選択番号の取得
	m_SelectNo = m_Transition->GetSelectNo();

	//スクロールの加算
	m_Scrooll++;

}

void CTitleScene::Render() {

	//背景の描画
	int sw = g_pGraphics->GetTargetWidth();

	int sh = g_pGraphics->GetTargetHeight();

	int wn = m_pTexture->GetWidth();

	int hn = m_pTexture->GetHeight();

	for (float y = ((int)-0 % hn) - hn; y < sh; y += hn) {

		for (float x = ((int)-m_Scrooll % wn) - wn; x < sw; x += wn) {

			//背景の描画
			m_pTexture->Render(x, y);

		}

	}
	
	//ロゴの描画
	m_pLogo->Render(m_LogoPos.x, m_LogoPos.y);

	//タイトルメニューの描画
	for (int i = 0; i < m_NextSceneList.size();i++) {

		if (i == m_SelectNo) {

			int selectMenu = i + m_NextSceneList.size();

			m_pMenuTitle[selectMenu]->Render(m_MenuTitlePos[i].x, m_MenuTitlePos[i].y);

		}
		else {

			m_pMenuTitle[i]->Render(m_MenuTitlePos[i].x, m_MenuTitlePos[i].y);

		}

	}

	//選択矢印の描画
	m_pArrow->Render(m_MenuTitlePos[m_SelectNo].x - m_pArrow->GetWidth(), m_MenuTitlePos[m_SelectNo].y + 50);

}

void CTitleScene::Release() {

	g_pGame->GetSoundManager()->Stop(CGameElement::SOUND_BGM_GAME, CGameElement::STOP_GRADUALLY);

}