/**

	@file Stage.cpp
	@brief �X�e�[�W
	@author �ؑ��J��
	@date 2019/12/14

*/

#include	"Stage.h"
#include	"Hanako.h"
#include	"TekeTeke.h"
#include	"Kinzirou.h"
#include	"HumanBodyModle.h"
#include	"Charm.h"

CStage::CStage() : m_EnemyTexture(), m_ItemTexture(), m_pChipTexture(nullptr), m_Scrooll()/*, m_PlayerPos()*/ {
	
	//�X�e�[�W�̈ʒu���̏�����
	m_pChipData = nullptr;

	//�G�̈ʒu���̏�����
	m_pEnemyData = nullptr;

	//�A�C�e���̈ʒu���̏�����
	m_pItemData = nullptr;

	//�X�e�[�W�̗�̐��̏�����
	m_XCount = 0;

	//�X�e�[�W�̍s�̐��̏�����
	m_YCount = 0;

	//�G�̏o�����̏�����
	m_EnemyCount = 0;

	//�A�C�e���̏o�����̏�����
	m_ItemCount = 0;

	//�X�e�[�W�e�N�X�`���̃T�C�Y�̏�����
	m_ChipSize = 0.0f;

}

CStage::~CStage() {

	//�����o�̉��
	Release();

}

bool CStage::Load(char* pName) {

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
	
	//�X�e�[�W�̏��̓ǂݍ���
	bool info = InfoLoad(pInfo);
	
	//�t�@�C�������
	fclose(fp);

	//�X�e�[�W�̏����������
	free(pInfo);

	return info;

}

bool CStage::InfoLoad(char* pInfo) {

	char* pStr = nullptr;

	//�X�e�[�W�w�i�e�N�X�`���̓ǂݍ���
	m_pBackImageTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_STAGE_BACKIMAGE);

	//�X�e�[�W�e�N�X�`���̓ǂݍ���
	m_pChipTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_STAGECHIP);
	
	pStr = strtok(pInfo, ",");

	//�X�e�[�W�e�N�X�`���̃T�C�Y�̓ǂݍ���
	m_ChipSize = atof(pStr);

	pStr = strtok(NULL, ",");

	//�X�e�[�W�̍s�̐��̓ǂݍ���
	m_XCount = atoi(pStr);
	
	pStr = strtok(NULL, ",");
	
	//�X�e�[�W�̗�̐��̓ǂݍ���
	m_YCount = atoi(pStr);

	m_pChipData = (char*)malloc(m_XCount * m_YCount);

	//�X�e�[�W�̈ʒu���̓ǂݍ���
	for (int y = 0; y < m_YCount; y++) {
		
		for (int x = 0; x < m_XCount; x++) {
			
			pStr = strtok(NULL, ",");
	
			m_pChipData[y * m_XCount + x] = atoi(pStr);

		}

	}

	//�G�̃e�N�X�`���̓ǂݍ���
	for (int i = CGameElement::TEXTURE_GAME_HANAKO; i <= CGameElement::TEXTURE_GAME_HUMANBODYMODLE; i++) {

		m_EnemyTexture.push_back(g_pGame->GetTextureManager()->GetTexture(i));

	}
	
	m_pEnemyData = (char*)malloc(m_XCount * m_YCount);
	
	//�G�̈ʒu���̓ǂݍ���
	for (int y = 0; y < m_YCount; y++) {

		for (int x = 0; x < m_XCount; x++) {

			pStr = strtok(NULL, ",");
			
			m_pEnemyData[y * m_XCount + x] = atoi(pStr);
			
			if (m_pEnemyData[y * m_XCount + x] > 0) {
				
				m_EnemyCount++;

			}

		}

	}

	//�A�C�e���̃e�N�X�`���̓ǂݍ���
	for (int i = CGameElement::TEXTURE_GAME_PIANO; i <= CGameElement::TEXTURE_GAME_CLEARGHOST; i++) {

		m_ItemTexture.push_back(g_pGame->GetTextureManager()->GetTexture(i));

	}

	m_pItemData = (char*)malloc(m_XCount * m_YCount);

	//�A�C�e���̈ʒu���̓ǂݍ���
	for (int y = 0; y < m_YCount; y++) {

		for (int x = 0; x < m_XCount; x++) {

			pStr = strtok(NULL, ",");
			
			m_pItemData[y * m_XCount + x] = atoi(pStr);
			
			if (m_pItemData[y * m_XCount + x] > 0) {
				
				m_ItemCount++;

			}

		}

	}

	return true;

}

void CStage::Initialize(std::vector<CEnemy*>& pEnemy, std::vector<CItem*>& pItem) {

	//�G�̏�����
	EnemyInitialize(pEnemy);

	//�A�C�e���̏�����
	ItemInitialize(pItem);
	
}

void CStage::EnemyInitialize(std::vector<CEnemy*>& pEnemy) {

	//���݂̓G�̗v�f�ԍ�
	int no = 0;

	for (int y = 0; y < m_YCount; y++) {

		for (int x = 0; x < m_XCount; x++) {

			char type = m_pEnemyData[y * m_XCount + x] - 1;

			//0�����Ȃ炻�̈ʒu�ɑ��݂��Ȃ��̂Ŕ�΂�
			if (type < 0) {

				continue;

			}
			

			//�G�̏o�����W
			const Vector2 pos(x * m_ChipSize, y * m_ChipSize);
			
			//�G�̐���
			switch (type)
			{
			case CGameElement::ENEMY_HANAKO:
				pEnemy.push_back(new CHanako(g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_HANAKO), pos, Vector2(CGameElement::PLAYER_MAXMOVE_HANAKO, 0), Vector2(228, 256), type, CGameElement::ENEMY_HP_HANAKO, CGameElement::ENEMY_ATTACKPOINT_HANAKO));
				break;
			case CGameElement::ENEMY_TEKETEKE:
				pEnemy.push_back(new CTekeTeke(g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_TEKETEKE), pos, Vector2(CGameElement::PLAYER_MAXMOVE_TEKETEKE, 0), Vector2(200, 127), type, CGameElement::ENEMY_HP_TEKETEKE, CGameElement::ENEMY_ATTACKPOINT_TEKETEKE));
				break;
			case CGameElement::ENEMY_KINZIROU:
				pEnemy.push_back(new CKinzirou(g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_KINZIROU), pos, Vector2(0, 0), Vector2(228, 256), type, CGameElement::ENEMY_HP_KINZIROU, CGameElement::ENEMY_ATTACKPOINT_KINZIROU));
				break;
			case CGameElement::ENEMY_HUMANBODYMODLE_DIAGONAL:
				pEnemy.push_back(new CHumanBodyModle(g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_HUMANBODYMODLE), pos, Vector2(0, 0), Vector2(228, 256), type, CGameElement::ENEMY_HP_HUMANBODYMODLE, CGameElement::ENEMY_ATTACKPOINT_HUMANBODYMODLE));
				break;
			case CGameElement::ENEMY_HUMANBODYMODLE_DOWN:

				pEnemy.push_back(new CHumanBodyModle(g_pGame->GetMotionManager()->GetMotion(CGameElement::MOTION_HUMANBODYMODLE), pos, Vector2(0, 0), Vector2(228, 256), type, CGameElement::ENEMY_HP_HUMANBODYMODLE, CGameElement::ENEMY_ATTACKPOINT_HUMANBODYMODLE));
				
				type = CGameElement::ENEMY_HUMANBODYMODLE_DIAGONAL;

				break;
			
			}

			pEnemy[no++]->SetTexture(m_EnemyTexture[type]);
			
		}

	}

}

void CStage::ItemInitialize(std::vector<CItem*>& pItem) {

	//���݂̃A�C�e���̗v�f�ԍ�
	int no = 0;

	for (int y = 0; y < m_YCount; y++) {

		for (int x = 0; x < m_XCount; x++) {
			
			char type = m_pItemData[y * m_XCount + x] - 1;

			//0�����Ȃ炻�̈ʒu�ɑ��݂��Ȃ��̂Ŕ�΂�
			if (type < 0) {

				continue;

			}

			//�A�C�e���̏o�����W
			const Vector2 pos(x * m_ChipSize, y * m_ChipSize);

			//�A�C�e���̐���
			switch (type)
			{
			
			case CGameElement::ITEM_PIANO:
				pItem.push_back(new CItem(pos, Vector2(256, 180), type));
				break;
			case CGameElement::ITEM_CHARM:
				pItem.push_back(new CCharm(pos, Vector2(64, 64), type));
				break;
			case CGameElement::ITEM_BEETHOVEN:
				pItem.push_back(new CItem(pos, Vector2(256, 256), type));
				break;
			case CGameElement::ITEM_CLEARGHOST:
				pItem.push_back(new CItem(pos, Vector2(640, 820), type));
				break;
			}
			
			pItem[no]->SetIDNo(no);

			pItem[no++]->SetTexture(m_ItemTexture[type]);

		}

	}

}

void CStage::Update(CPlayer* pPlayer) {
	
	//�X�N���[���␳�̍X�V
	ScroollCorrection(pPlayer);

}

void CStage::ScroollCorrection(CPlayer* pPlayer) {

	float sw = CGraphicsUtilities::GetGraphics()->GetTargetWidth();

	float sh = CGraphicsUtilities::GetGraphics()->GetTargetHeight();

	float stgw = m_ChipSize * m_XCount;

	float stgh = m_ChipSize * m_YCount;

	const CRectangle& prec = pPlayer->GetRect();

	//�߂�̃v���C���[��X���W��400�ŌŒ肷��
	if (prec.Left - m_Scrooll.x < 550) {
		
		m_Scrooll.x -= 550 - (prec.Left - m_Scrooll.x);

		if (m_Scrooll.x <= 0) {

			m_Scrooll.x = 0;

		}

	}
	else if (prec.Right - m_Scrooll.x > sw - 700) {
		
		m_Scrooll.x += (prec.Right - m_Scrooll.x) - (sw - 700);
		
		if (m_Scrooll.x >= stgw - sw) {
			
			m_Scrooll.x = stgw - sw;

		}

	}

}

void CStage::Render() {

	int sw = g_pGraphics->GetTargetWidth();

	int sh = g_pGraphics->GetTargetHeight();

	int wn = m_pBackImageTexture->GetWidth();

	int hn = m_pBackImageTexture->GetHeight();

	//�X�e�[�W�̔w�i�̕`��
	for (float y = ((int)-m_Scrooll.y % hn) - hn; y < sh; y += hn) {

		for (float x = ((int)-m_Scrooll.x / 4 % wn) - wn; x < sw; x += wn) {

			m_pBackImageTexture->Render(x, y);

		}

	}

	int tcx = m_pChipTexture->GetWidth() / m_ChipSize;

	//�X�e�[�W�̕`��
	for (int y = 0; y < m_YCount; y++) {

		for (int x = 0; x < m_XCount; x++) {

			char cn = m_pChipData[y * m_XCount + x] - 1;

			//0�����Ȃ炻�̈ʒu�ɑ��݂��Ȃ��̂Ŕ�΂�
			if (cn < 0) {

				continue;

			}

			CRectangle cr(m_ChipSize*(cn % tcx), m_ChipSize * (cn / tcx), m_ChipSize * (cn % tcx + 1), m_ChipSize * (cn / tcx + 1));

			m_pChipTexture->Render(-m_Scrooll.x + x * m_ChipSize, -m_Scrooll.y + y * m_ChipSize, cr);

		}

	}

}

void CStage::Release() {

	//�}�b�v�`�b�v�̉��
	if (m_pChipData) {

		free(m_pChipData);

		m_pChipData = nullptr;

	}

	//�G�̈ʒu���̉��
	if (m_pEnemyData) {

		free(m_pEnemyData);

		m_pEnemyData = nullptr;

	}

	//�A�C�e���̈ʒu���̉��
	if (m_pItemData) {

		free(m_pItemData);

		m_pItemData = nullptr;

	}

}

bool CStage::Collision(CRectangle r, Vector2& buried) {

	bool re = false;
	
	//��`�̎��ӂ������Փ˔��肷��
	int lc = r.Left / m_ChipSize;
	
	int rc = r.Right / m_ChipSize;

	int tc = r.Top / m_ChipSize;
	
	int bc = r.Bottom / m_ChipSize;

	if (lc < 0) {
	
		lc = 0;

	}

	if (tc < 0) {
		
		tc = 0;

	}

	if (rc >= m_XCount) {
		
		rc = m_XCount - 1;

	}

	if (bc >= m_YCount) {
		
	    bc = m_YCount - 1;

	}

	for (int y = tc; y <= bc; y++) {

		for (int x = lc; x <= rc; x++) {

			char cn = m_pChipData[y * m_XCount + x] - 1;

			//0�����Ȃ炻�̈ʒu�ɑ��݂��Ȃ��̂Ŕ�΂�
			if (cn < 0) {

				continue;

			}

			CRectangle cr(x * m_ChipSize, y * m_ChipSize,
				x * m_ChipSize + m_ChipSize, y * m_ChipSize + m_ChipSize);
			
			CRectangle brec = r;
			
			brec.Top = brec.Bottom - 1;

			brec.Expansion(-15, 0);

			//��`�̉��ӕ��ƃX�e�[�W�̏Փ˔���
			if (cr.CollisionRect(brec)) {
				
				re = true;

				buried.y += cr.Top - brec.Bottom;

				r.Top += cr.Top - brec.Bottom;

				r.Bottom += cr.Top - brec.Bottom;

			}

			CRectangle lrec = r;

			lrec.Right = lrec.Left + 1;

			lrec.Expansion(0, -15);
				
			CRectangle rrec = r;

			rrec.Left = rrec.Right - 1;

			rrec.Expansion(0, -15);
			
			//��`�̍��ӕ��ƃX�e�[�W�̏Փ˔���
			if (cr.CollisionRect(lrec)) {

				re = true;

				buried.x += cr.Right - lrec.Left;

				r.Left += cr.Right - lrec.Left;

				r.Right += cr.Right - lrec.Left;

			}//��`�̉E�ӕ��ƃX�e�[�W�̏Փ˔���
			else if (cr.CollisionRect(rrec)) {
					
				re = true;

				buried.x += cr.Left - rrec.Right;

				r.Left += cr.Left - rrec.Right;

				r.Right += cr.Left - rrec.Right;

			}

			CRectangle trec = r;

			trec.Bottom = trec.Top + 1;

			trec.Expansion(-15, 0);

			//��`�̏�ӕ��ƃX�e�[�W�̏Փ˔���
			if (cr.CollisionRect(trec)) {

				re = true;

				buried.y += cr.Bottom - trec.Top;

				r.Top += cr.Bottom - trec.Top;

				r.Bottom += cr.Bottom - trec.Top;

			}

		}

	}
		
	return re;

}