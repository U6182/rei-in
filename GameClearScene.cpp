/**

	@file GameClearScene.cpp
	@brief �Q�[���N���A�V�[��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"GameClearScene.h"

CGameClearScene::CGameClearScene() : CSceneBase(&m_NextSceneList) {

	//�R�}���h�̐ݒ�
	g_pGame->GetController()->SetGameClearCommand();

}

CGameClearScene::~CGameClearScene() {

	//�������
	Release();

}

bool CGameClearScene::Load() {

	//�Q�[���N���A�̔w�i�̓ǂݍ���
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAMECLEAR_BACKIMAGE);

	return true;

}

void CGameClearScene::Initialize() {

	//�ǂݍ���
	Load();

}

void CGameClearScene::Update() {

	//����
	Operation(m_Transition);

}

void CGameClearScene::Render() {

	//�w�i�̕`��
	m_pTexture->Render(0, 0);

}

void CGameClearScene::Release() {

	;

}