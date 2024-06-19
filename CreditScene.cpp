/**

	@file CreditScene.cpp
	@brief �N���W�b�g�V�[��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"CreditScene.h"

CCreditScene::CCreditScene() : CSceneBase(&m_NextSceneList), m_Player(new CPlayer()), m_Stage(new CStage()), m_Credit(), m_CreditPos(nullptr), m_CreditColor(nullptr) {
	
	//�R�}���h�̐ݒ�
	g_pGame->GetController()->SetCreditCommand();

	//�N���A�S�[�X�g�����t���O
	m_bGhostFind = false;

	//�ҋ@�C���^�[�o��
	m_WaitInterval = 0.0f;

}

CCreditScene::~CCreditScene() {

	//�������
	Release();

}

bool CCreditScene::Load() {

	const char* pName = "CreditScene/Credit.txt";

	//�X�e�[�W�e�L�X�g�̓ǂݍ���
	FILE* fp = fopen(pName, "rt");

	if (fp == NULL) {

		return false;

	}

	//��l�̐ݒ�
	fseek(fp, 0, SEEK_END);

	//�t�@�C���̃T�C�Y���擾
	long fSize = ftell(fp);

	fseek(fp, 0, SEEK_SET);

	//�X�e�[�W�̏�񕪂̃T�C�Y���m��
	char* pInfo = (char*)malloc(fSize + 1);

	fSize = fread(pInfo, 1, fSize, fp);

	pInfo[fSize] = '\0';

	char* pStr;

	pStr = strtok(pInfo, "\n");

	//�N���W�b�g�̐�
	const int creditCount = atoi(pStr);

	m_CreditPos = new Vector2[creditCount]();

	m_CreditColor = new MofU32[creditCount];

	//�N���W�b�g�̓ǂݍ��݂ƍ��W�̏�����
	for (int i = 0; i < creditCount; i++) {

		pStr = strtok(NULL, ",");

		int len = g_pGame->GetFontManager()->Length(pStr);

		m_CreditPos[i].x = 100;

		int posY = i * 100 + g_pGraphics->GetTargetHeight();

		m_CreditPos[i].y = posY;

		len = strlen(pStr);

		char* pCreditStr = new char[len + 1];

		strcpy(pCreditStr, pStr);

		m_Credit.push_back(pCreditStr);

		pStr = strtok(NULL, "\n");

		const int creditColor = atoi(pStr);

		switch (creditColor)
		{
		case 0:
			m_CreditColor[i] = MOF_COLOR_RED;
			break;
		case 1:
			m_CreditColor[i] = MOF_COLOR_GREEN;
			break;
		case 2:
			m_CreditColor[i] = MOF_COLOR_BLUE;
			break;
		case 3:
			m_CreditColor[i] = MOF_COLOR_YELLOW;
			break;
		case 4:
			m_CreditColor[i] = MOF_COLOR_HGREEN;
			break;

		}

	}

	//�t�@�C�������
	fclose(fp);

	//�X�e�[�W�̏����������
	free(pInfo);

	return true;

}

void CCreditScene::Initialize() {

	//�ǂݍ���
	Load();

	//�v���C���[�̓ǂݍ���
	m_Player->Load();

	//�v���C���[�̈ړ���
	m_Player->GetMove() = Vector2(CGameElement::PLAYER_MAXMOVE_SOUL, 0);

	//�X�e�[�W�̓ǂݍ���
	m_Stage->Load("CreditScene/CreditStage.txt");

	//�X�e�[�W�̏�����
	m_Stage->Initialize(m_EnemyArray, m_ClearGhost);

}

void CCreditScene::Update() {

	//�X�e�[�W�̍X�V
	if (!m_bGhostFind) {

		m_Stage->Update(m_Player);

	}

	//�X�N���[���l��ݒ�
	m_Player->SetScrooll(m_Stage->GetScrooll());

	float frameScecond = CUtilities::GetFrameSecond();

	CSpriteMotionController* pPlayerMotion = m_Player->GetMotion();

	if (m_WaitInterval <= 0) {

		pPlayerMotion->ChangeMotion(CMotionName::MOTOIN_SOUL_MOVE, FALSE);

		m_Player->PosMove();

	}
	else {

		pPlayerMotion->ChangeMotion(CMotionName::MOTOIN_SOUL_WAIT, FALSE);

		m_WaitInterval -= frameScecond;

	}

	Vector2 buried;

	//�v���C���[�ƃX�e�[�W�̏Փ˔���
	if (m_Stage->Collision(m_Player->GetRect(), buried)) {

		m_Player->CollisionStage(buried);

	}

	pPlayerMotion->AddTimer(frameScecond);

	//�N���A�S�[�X�g�̕`��
	for (CItem* pClearGhost : m_ClearGhost) {

		Vector2& clearGhostPos = pClearGhost->GetPos() - m_Stage->GetScrooll();

		if (clearGhostPos.x + pClearGhost->GetSize().x > 0 && clearGhostPos.x < g_pGraphics->GetTargetWidth() &&
			clearGhostPos.y + pClearGhost->GetSize().y > 0 && clearGhostPos.y < g_pGraphics->GetTargetHeight()) {

			if (!pClearGhost->IsShow()) {

				pClearGhost->SetShow(true);

			}

			pClearGhost->SetAppear(true);

		}
		else {

			pClearGhost->SetAppear(false);

		}

		if (clearGhostPos.x + pClearGhost->GetSize().x < g_pGraphics->GetTargetWidth()) {

			if (!m_bGhostFind) {

				m_WaitInterval = m_WAITINTERVALTIME;

				m_bGhostFind = true;

			}

		}

		if (pClearGhost->GetRect().CollisionRect(m_Player->GetRect())) {

			m_Transition->Transition();

		}

	}

	//�ŏI���W�܂ŃN���W�b�g�̃X�N���[�����s��
	for (int i = 0; i < m_Credit.size(); i++) {

		m_CreditPos[i].y -= 1.35f;

	}

}

void CCreditScene::Render() {

	//�X�e�[�W�̕`��
	m_Stage->Render();

	//�v���C���[�̕`��
	m_Player->Render();

	//�N���A�S�[�X�g�̕`��
	for (CItem* pClearGhost : m_ClearGhost) {

		pClearGhost->Render(m_Stage->GetScrooll());

	}

	//�N���W�b�g�̕`��
	for (int i = 0; i < m_Credit.size(); i++) {

		g_pGame->GetFontManager()->GetFont(CGameElement::FONTSIZE_32)->RenderString(m_CreditPos[i].x, m_CreditPos[i].y, m_CreditColor[i], m_Credit[i]);

	}

}

void CCreditScene::Release() {

	//�v���C���[�̉��
	if (m_Player) {

		delete m_Player;

		m_Player = nullptr;

	}

	//�N���W�b�g�̉��
	for (auto it = begin(m_Credit); it != end(m_Credit); ++it) {

		delete *it;

	}

	//�N���W�b�g�̍��W�̉��
	if (m_CreditPos) {

		delete[] m_CreditPos;

		m_CreditPos = nullptr;

	}

	//�N���W�b�g�̍��W�̉��
	if (m_CreditColor) {

		delete[] m_CreditColor;

		m_CreditColor = nullptr;

	}

	//�X�e�[�W�̉��
	if (m_Stage) {

		//�G�̉��
		for (auto it = begin(m_EnemyArray); it != end(m_EnemyArray); ++it) {

			delete *it;

		}

		m_EnemyArray.clear();

		//�A�C�e���̉��
		for (auto it = begin(m_ClearGhost); it != end(m_ClearGhost); ++it) {

			delete *it;

		}

		m_ClearGhost.clear();

		delete m_Stage;

		m_Stage = nullptr;

	}

}