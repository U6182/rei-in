/**

	@file OperationDescriptionScene.cpp
	@brief 操作説明シーン
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"OperationDescriptionScene.h"

COperationDescriptionScene::COperationDescriptionScene() : CSceneBase(&m_NextSceneList) {

	//コマンドの設定
	g_pGame->GetController()->SetOperationDescriptionCommand();

	//選択番号の取得
	m_SelectNo = m_Transition->GetSelectNo();

}

COperationDescriptionScene::~COperationDescriptionScene() {

	//解放処理
	Release();

}

bool COperationDescriptionScene::Load() {

	//操作説明の背景の読み込み
	for (int name = CGameElement::TEXTURE_OPERATIONDESCRIPTION_SOUL_BACKIMAGE; name <= CGameElement::TEXTURE_OPERATIONDESCRIPTION_HUMANBODYMODLE_BACKIMAGE; name++) {

		m_pTextureList.push_back(g_pGame->GetTextureManager()->GetTexture(name));

	}

	return true;

}

void COperationDescriptionScene::Initialize() {

	//読み込み
	Load();

}

void COperationDescriptionScene::Update() {

	//操作
	Operation(m_Transition);

	//選択番号の取得
	m_SelectNo = m_Transition->GetSelectNo();

}

void COperationDescriptionScene::Render() {

	//背景の描画
	m_pTextureList[m_SelectNo]->Render(0, 0);
	
}

void COperationDescriptionScene::Release() {

	;

}