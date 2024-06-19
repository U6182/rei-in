/**

	@file GameOverScene.cpp
	@brief �Q�[���I�[�o�[�V�[��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"GameOverScene.h"

CGameOverScene::CGameOverScene() : CSceneBase(&m_NextSceneList) {

	//�R�}���h�̐ݒ�
	g_pGame->GetController()->SetGameOverCommand();

}

CGameOverScene::~CGameOverScene() {

	//�������
	Release();

}

bool CGameOverScene::Load() {

	//�Q�[���I�[�o�[�̔w�i�̓ǂݍ���
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAMEOVER_BACKIMAGE);

	return true;

}

void CGameOverScene::Initialize() {

	//�ǂݍ���
	Load();

}

void CGameOverScene::Update() {

	//����
	Operation(m_Transition);

}

void CGameOverScene::Render() {

	//�w�i�̕`��
	m_pTexture->Render(0, 0);

}

void CGameOverScene::Release() {

	;

}