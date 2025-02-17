/**

	@file GameClearScene.cpp
	@brief ゲームクリアシーン
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"GameClearScene.h"

CGameClearScene::CGameClearScene() : CSceneBase(&m_NextSceneList) {

	//コマンドの設定
	g_pGame->GetController()->SetGameClearCommand();

}

CGameClearScene::~CGameClearScene() {

	//解放処理
	Release();

}

bool CGameClearScene::Load() {

	//ゲームクリアの背景の読み込み
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAMECLEAR_BACKIMAGE);

	return true;

}

void CGameClearScene::Initialize() {

	//読み込み
	Load();

}

void CGameClearScene::Update() {

	//操作
	Operation(m_Transition);

}

void CGameClearScene::Render() {

	//背景の描画
	m_pTexture->Render(0, 0);

}

void CGameClearScene::Release() {

	;

}