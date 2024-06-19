/**

	@file Load.cpp
	@brief �f�ނ̓ǂݍ���
	@author �ؑ��J��
	@date 2020/10/22

*/

#include	"Load.h"

void CLoad::Run() {

	//���[�h�I���̌���
	m_State = Load();

}

int CLoad::Load() {

	//�f�ސ��̃J�E���g
	for (m_LoadMaxCount = 0; CGameElement::g_FileName[m_LoadMaxCount] != nullptr; m_LoadMaxCount++);

	//�e�N�X�`���̓ǂݍ���
	for (; m_LoadCount < CGameElement::TEXTURE_MAXCOUNT - 1; m_LoadCount++) {

		if (!m_Texture[m_LoadCount].Load(CGameElement::g_FileName[m_LoadCount])) {

			return LOADING_ERROR;

		}
	
	}

	//�T�E���h�̓ǂݍ���
	/*for (; m_LoadCount < m_LoadMaxCount; m_LoadCount++) {

		if (!m_Sound->Load(CGameElement::g_FileName[m_LoadCount])) {

			return LOADING_ERROR;

		}

	}*/

	return LOADING_FINISHED;

}

void CLoad::Render() {

	//�v�Z��������
	int percentCount = m_LoadMaxCount / 100;

	switch (m_State)
	{

	case LOADING_FINISHED:

		CGraphicsUtilities::RenderString(0, 50, "�ǂݍ��݂��������܂���");

		break;
	case LOADING_ERROR:

		CGraphicsUtilities::RenderString(0, 50, "�ǂݍ��ݒ��ɃG���[���������܂���");

		break;
	}

	//m_LoadPercent = m_LoadCount / percentCount;

	//CGraphicsUtilities::RenderString(0, 0, "%d %", m_LoadPercent);

}