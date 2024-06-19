/**

	@file OptionScene.cpp
	@brief オプションシーン
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"OptoinScene.h"

COptionScene::COptionScene() : CSceneBase(&m_NextSceneList) {

	//コマンドの設定
	g_pGame->GetController()->SetOptionCommand();

	//選択番号の取得
	m_SelectNo = m_Transition->GetSelectNo();

}

COptionScene::~COptionScene() {

	//解放処理
	Release();

}

bool COptionScene::Load() {

	//操作説明の背景の読み込み
	for (int name = CGameElement::TEXTURE_OPTION_MENU_VIBRATION_ON; name <= CGameElement::TEXTURE_OPTION_MENU_VIBRATION_OFF; name++) {

		m_pTextureList.push_back(g_pGame->GetTextureManager()->GetTexture(name));

	}

	return true;

}

void COptionScene::Initialize() {

	//読み込み
	Load();

}

void COptionScene::Update() {

	//操作
	Operation(m_Transition);

	//選択番号の取得
	m_SelectNo = m_Transition->GetSelectNo();

	if (m_SelectNo == 0) {

		g_pGame->GetSetting()->SetVibration(true);

	}
	else {

		g_pGame->GetSetting()->SetVibration(false);

	}

}

void COptionScene::Render() {

	//背景の描画
	m_pTextureList[m_SelectNo]->Render(0, 0);

}

void COptionScene::Release() {

	;

}