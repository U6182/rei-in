/**

	@file OperationDescriptionScene.cpp
	@brief ��������V�[��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"OperationDescriptionScene.h"

COperationDescriptionScene::COperationDescriptionScene() : CSceneBase(&m_NextSceneList) {

	//�R�}���h�̐ݒ�
	g_pGame->GetController()->SetOperationDescriptionCommand();

	//�I��ԍ��̎擾
	m_SelectNo = m_Transition->GetSelectNo();

}

COperationDescriptionScene::~COperationDescriptionScene() {

	//�������
	Release();

}

bool COperationDescriptionScene::Load() {

	//��������̔w�i�̓ǂݍ���
	for (int name = CGameElement::TEXTURE_OPERATIONDESCRIPTION_SOUL_BACKIMAGE; name <= CGameElement::TEXTURE_OPERATIONDESCRIPTION_HUMANBODYMODLE_BACKIMAGE; name++) {

		m_pTextureList.push_back(g_pGame->GetTextureManager()->GetTexture(name));

	}

	return true;

}

void COperationDescriptionScene::Initialize() {

	//�ǂݍ���
	Load();

}

void COperationDescriptionScene::Update() {

	//����
	Operation(m_Transition);

	//�I��ԍ��̎擾
	m_SelectNo = m_Transition->GetSelectNo();

}

void COperationDescriptionScene::Render() {

	//�w�i�̕`��
	m_pTextureList[m_SelectNo]->Render(0, 0);
	
}

void COperationDescriptionScene::Release() {

	;

}