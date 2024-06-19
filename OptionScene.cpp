/**

	@file OptionScene.cpp
	@brief �I�v�V�����V�[��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"OptoinScene.h"

COptionScene::COptionScene() : CSceneBase(&m_NextSceneList) {

	//�R�}���h�̐ݒ�
	g_pGame->GetController()->SetOptionCommand();

	//�I��ԍ��̎擾
	m_SelectNo = m_Transition->GetSelectNo();

}

COptionScene::~COptionScene() {

	//�������
	Release();

}

bool COptionScene::Load() {

	//��������̔w�i�̓ǂݍ���
	for (int name = CGameElement::TEXTURE_OPTION_MENU_VIBRATION_ON; name <= CGameElement::TEXTURE_OPTION_MENU_VIBRATION_OFF; name++) {

		m_pTextureList.push_back(g_pGame->GetTextureManager()->GetTexture(name));

	}

	return true;

}

void COptionScene::Initialize() {

	//�ǂݍ���
	Load();

}

void COptionScene::Update() {

	//����
	Operation(m_Transition);

	//�I��ԍ��̎擾
	m_SelectNo = m_Transition->GetSelectNo();

	if (m_SelectNo == 0) {

		g_pGame->GetSetting()->SetVibration(true);

	}
	else {

		g_pGame->GetSetting()->SetVibration(false);

	}

}

void COptionScene::Render() {

	//�w�i�̕`��
	m_pTextureList[m_SelectNo]->Render(0, 0);

}

void COptionScene::Release() {

	;

}