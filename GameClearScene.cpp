/**

	@file GameClearScene.cpp
	@brief ƒQ[ƒ€ƒNƒŠƒAƒV[ƒ“
	@author –Ø‘º—JÆ
	@date 2020/10/24

*/

#include	"GameClearScene.h"

CGameClearScene::CGameClearScene() : CSceneBase(&m_NextSceneList) {

	//ƒRƒ}ƒ“ƒh‚ÌÝ’è
	g_pGame->GetController()->SetGameClearCommand();

}

CGameClearScene::~CGameClearScene() {

	//‰ð•úˆ—
	Release();

}

bool CGameClearScene::Load() {

	//ƒQ[ƒ€ƒNƒŠƒA‚Ì”wŒi‚Ì“Ç‚Ýž‚Ý
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAMECLEAR_BACKIMAGE);

	return true;

}

void CGameClearScene::Initialize() {

	//“Ç‚Ýž‚Ý
	Load();

}

void CGameClearScene::Update() {

	//‘€ì
	Operation(m_Transition);

}

void CGameClearScene::Render() {

	//”wŒi‚Ì•`‰æ
	m_pTexture->Render(0, 0);

}

void CGameClearScene::Release() {

	;

}