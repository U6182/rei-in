/**

	@file GameOverScene.cpp
	@brief ゲームオーバーシーン
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"GameOverScene.h"

CGameOverScene::CGameOverScene() : CSceneBase(&m_NextSceneList) {

	//コマンドの設定
	g_pGame->GetController()->SetGameOverCommand();

}

CGameOverScene::~CGameOverScene() {

	//解放処理
	Release();

}

bool CGameOverScene::Load() {

	//ゲームオーバーの背景の読み込み
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAMEOVER_BACKIMAGE);

	return true;

}

void CGameOverScene::Initialize() {

	//読み込み
	Load();

}

void CGameOverScene::Update() {

	//操作
	Operation(m_Transition);

}

void CGameOverScene::Render() {

	//背景の描画
	m_pTexture->Render(0, 0);

}

void CGameOverScene::Release() {

	;

}