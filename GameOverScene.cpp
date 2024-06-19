/**

	@file GameOverScene.cpp
	@brief ƒQ[ƒ€ƒI[ƒo[ƒV[ƒ“
	@author –Ø‘º—JÆ
	@date 2020/10/24

*/

#include	"GameOverScene.h"

CGameOverScene::CGameOverScene() : CSceneBase(&m_NextSceneList) {

	//ƒRƒ}ƒ“ƒh‚ÌÝ’è
	g_pGame->GetController()->SetGameOverCommand();

}

CGameOverScene::~CGameOverScene() {

	//‰ð•úˆ—
	Release();

}

bool CGameOverScene::Load() {

	//ƒQ[ƒ€ƒI[ƒo[‚Ì”wŒi‚Ì“Ç‚Ýž‚Ý
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAMEOVER_BACKIMAGE);

	return true;

}

void CGameOverScene::Initialize() {

	//“Ç‚Ýž‚Ý
	Load();

}

void CGameOverScene::Update() {

	//‘€ì
	Operation(m_Transition);

}

void CGameOverScene::Render() {

	//”wŒi‚Ì•`‰æ
	m_pTexture->Render(0, 0);

}

void CGameOverScene::Release() {

	;

}