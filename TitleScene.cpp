/**

	@file TitleScene.cpp
	@brief �^�C�g���V�[��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"TitleScene.h"

CTitleScene::CTitleScene() : CSceneBase(&m_NextSceneList) {

	//�R�}���h�̐ݒ�
	g_pGame->GetController()->SetTitleCommand();

	//�I��ԍ��̎擾
	m_SelectNo = m_Transition->GetSelectNo();

	//�X�N���[���̏�����
	m_Scrooll = 0;

}

CTitleScene::~CTitleScene() {

	//���
	Release();

}

bool CTitleScene::Load() {

	//�^�C�g���̔w�i�̓ǂݍ���
	m_pTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_STAGE_BACKIMAGE);

	//���S�̓ǂݍ���
	m_pLogo = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_TITEL_LOGO);

	//���̓ǂݍ���
	m_pArrow = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_ARROW);

	//�^�C�g���̃��j���[�̓ǂݍ���
	const int menuList[] = { CGameElement::TEXTURE_TITEL_MENU_GAME, CGameElement::TEXTURE_TITEL_MENU_OPTION, CGameElement::TEXTURE_TITEL_MENU_OPERATIONDESCRIPTION, CGameElement::TEXTURE_TITEL_MENU_EXIT,
							 CGameElement::TEXTURE_TITEL_MENU_GAME_SELECT, CGameElement::TEXTURE_TITEL_MENU_OPTION_SELECT, CGameElement::TEXTURE_TITEL_MENU_OPERATIONDESCRIPTION_SELECT, CGameElement::TEXTURE_TITEL_MENU_EXIT_SELECT };

	const int menuEL = sizeof(menuList) / sizeof(menuList[0]);

	for (int i = 0; i < menuEL; i++) {

		m_pMenuTitle.push_back(g_pGame->GetTextureManager()->GetTexture(menuList[i]));


	}

	const int offset = 100;

	//�^�C�g�����S�̍��W
	m_LogoPos = Vector2(CUtili::CenterTexturePosX(*m_pLogo), offset);

	float posX = (g_pGraphics->GetTargetWidth() - ((m_pMenuTitle[0]->GetWidth() * (menuEL / 2) - 1) + (m_pArrow->GetWidth() * (menuEL / 2) - 1)) + m_pMenuTitle[5]->GetWidth()) / 2;

	//�^�C�g���̃��j���[�̍��W
	for (int i = 0; i < menuEL / 2; i++) {

		m_MenuTitlePos.push_back(Vector2(posX + i * (m_pArrow->GetWidth() + m_pMenuTitle[i]->GetWidth()), g_pGraphics->GetTargetHeight() * 0.58f));

	}

	return true;

}

void CTitleScene::Initialize() {

	//�ǂݍ���
	Load();

}

void CTitleScene::Update() {

	//BGM�̍Đ�
	g_pGame->GetSoundManager()->Play(CGameElement::SOUND_BGM_GAME);

	//����
	Operation(m_Transition);

	//�I��ԍ��̎擾
	m_SelectNo = m_Transition->GetSelectNo();

	//�X�N���[���̉��Z
	m_Scrooll++;

}

void CTitleScene::Render() {

	//�w�i�̕`��
	int sw = g_pGraphics->GetTargetWidth();

	int sh = g_pGraphics->GetTargetHeight();

	int wn = m_pTexture->GetWidth();

	int hn = m_pTexture->GetHeight();

	for (float y = ((int)-0 % hn) - hn; y < sh; y += hn) {

		for (float x = ((int)-m_Scrooll % wn) - wn; x < sw; x += wn) {

			//�w�i�̕`��
			m_pTexture->Render(x, y);

		}

	}
	
	//���S�̕`��
	m_pLogo->Render(m_LogoPos.x, m_LogoPos.y);

	//�^�C�g�����j���[�̕`��
	for (int i = 0; i < m_NextSceneList.size();i++) {

		if (i == m_SelectNo) {

			int selectMenu = i + m_NextSceneList.size();

			m_pMenuTitle[selectMenu]->Render(m_MenuTitlePos[i].x, m_MenuTitlePos[i].y);

		}
		else {

			m_pMenuTitle[i]->Render(m_MenuTitlePos[i].x, m_MenuTitlePos[i].y);

		}

	}

	//�I����̕`��
	m_pArrow->Render(m_MenuTitlePos[m_SelectNo].x - m_pArrow->GetWidth(), m_MenuTitlePos[m_SelectNo].y + 50);

}

void CTitleScene::Release() {

	g_pGame->GetSoundManager()->Stop(CGameElement::SOUND_BGM_GAME, CGameElement::STOP_GRADUALLY);

}