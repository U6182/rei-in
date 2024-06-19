/**

	@file GameScene.cpp
	@brief �Q�[���V�[��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include	"GameScene.h"
#include	"Charm.h"

CGameScene::CGameScene() : CSceneBase(&m_NextSceneList), m_WorldTimeLimit(new CWorldTimeLimit()), m_Player(new CPlayer()), m_Stage(new CStage()) {

	//�R���g���[���[�����v���C���[�̃R�}���h�ɐݒ�
	g_pGame->GetController()->SetSoulPlayerCommand();

	//�U���t���O�̏�����
	m_bVibration = false;

	//�R���g���[���[�̏��
	m_ControllerState = m_Player->GetPossessionState();

	//�Q�[���̏��
	m_GameState = CGameElement::GAME_RUN;

	//�v���C���[�U�����̒�~����
	m_BreakTime = 0.0f;

}

CGameScene::~CGameScene() {

	//�������
	Release();

}

bool CGameScene::Load() {

	//�v���C���[�̓ǂݍ���
	m_Player->Load();

	//�X�e�[�W�̓ǂݍ���
	m_Stage->Load("GameScene/Stage/Stage.txt");

	return true;

}

void CGameScene::Initialize() {

	//�ǂݍ���
	Load();

	//�X�e�[�W�̏�����
	m_Stage->Initialize(m_EnemyArray, m_ItemArray);

	//�v���C���[�̏�Ԃ̐ݒ�
	for (CEnemy* pEnemy : m_EnemyArray) {

		pEnemy->SetPlayerState(m_Player);

	}

}

void CGameScene::Update() {

	//BGM�̍Đ�
	g_pGame->GetSoundManager()->Play(CGameElement::SOUND_BGM_GAME);

	//�v���C���[�̍U�������������ꍇ�A�t���[�Y���o
	if (m_BreakTime > 0) {

		m_BreakTime -= CUtilities::GetFrameSecond();

		return;

	}

	//�v���C���[�̍s�������Z�b�g
	m_Player->ResetMove();

	//�R�}���h����ւ�
	CommandTransition();

	//����
	Operation(GameState());

	//�X�e�[�W�̍X�V
	m_Stage->Update(m_Player);

	//�G�t�F�N�g�̍X�V
	g_pGame->GetEffectManager()->Update();

	//�L�����N�^�[�̏Փˏ����̍X�V
	if (m_Player->GetPossession() != CGameElement::POSSESSION_BEHAVIOR) {

		AnimeCollision();

	}

	if (m_Player->GetPossession() == CGameElement::POSSESSION_BEHAVIOREND) {

		for (CEnemy* pEnemy : m_EnemyArray) {

			pEnemy->SetBehaviorWait(false);

		}

		m_Player->SetPossession(CGameElement::POSSESSION_NOW);

	}

	//�v���C���[�̍X�V
	PlayerUpdate();

	//�G�̍X�V
	EnemyUpdate();
	
	//�A�C�e���̍X�V
	ItemUpdate();

	//�A�C�e���Ƃ̏Փ˔���
	ItemCollision();

	//���Ԃ̍X�V
	WorldTimeLimitUpdate();

	//�R���g���[���[�̍X�V
	ControllerUpdate();

	//�Q�[���J�ڏ����̍X�V
	GameTransition();

}

void CGameScene::GameTransition() {

	bool bGameEnd = false;

	for (CItem* pItem : m_ItemArray) {

		CCharm* pCharm = dynamic_cast<CCharm*>(pItem);

		if (pCharm != nullptr) {

			if (TypeItemFind(m_ItemArray, CGameElement::ITEM_PIANO)->GetPos().x - 20 > TypeItemFind(m_ItemArray, CGameElement::ITEM_BEETHOVEN)->GetPos().x && !pCharm->IsAppear()) {

				g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_PIANOPLAY);
				
				pCharm->SetAppear(true);

				m_Player->SetBehaviorWait(true);

				for (CEnemy* pEnemy : m_EnemyArray) {

					pEnemy->SetBehaviorWait(true);

				}

			}

			if (pCharm->IsLiberation()) {

				m_GameState = CGameElement::GAME_GAMECLEAR;

				bGameEnd = true;

			}

		}

	}

	if (m_WorldTimeLimit->GetTimeLimit() <= 0 || m_Player->GetPos().y > m_Stage->GetStageHeight()) {

		m_Player->SetDead(true);

	}

	if (m_Player->IsDeadBehaviorEnd()) {

		m_GameState = CGameElement::GAME_GAMEOVER;

		bGameEnd = true;

	}

	if (bGameEnd) {

		m_Transition->SetSelectNo(m_GameState);

		m_Transition->Transition();

	}

}

void CGameScene::AnimeCollision() {

	for (CEnemy* pEnemy : m_EnemyArray) {

		//��\���̏ꍇ�X�L�b�v
		if (!pEnemy->IsShow() || !pEnemy->IsAppear() || pEnemy->IsDead()) {

			continue;

		}

		//�߈˃��[�h�ŏՓ˂����ꍇ
		if (m_Player->GetPossession() == CGameElement::POSSESSION_MODE && m_Player->GetRect().CollisionRect(pEnemy->GetRect())) {

			m_Player->SetPossession(CGameElement::POSSESSION_BEHAVIOR);

			m_Player->SetEnemyState(pEnemy);

			for (CEnemy* pEne : m_EnemyArray) {

				pEne->SetBehaviorWait(true);

			}

			return;

		}

		//��������
		if (pEnemy->GetFindRect().CollisionRect(m_Player->GetRect()) && m_Player->GetPossession() != CGameElement::POSSESSION_MODE) {

			pEnemy->SetFind(true);

		}
		else {

			pEnemy->SetFind(false);

		}

		if (pEnemy->IsAttackPossible() && pEnemy->IsFind()) {

			//�G�̍U���ƃv���C���[�̏Փ˔���
			if (pEnemy->GetAttackRect().CollisionRect(m_Player->GetRect()) && m_Player->GetDamageInterval() <= 0) {

				pEnemy->SetAttack(true);

				m_Player->SetDamage(true);

				//���Ԃ����
				m_WorldTimeLimit->LessTime(pEnemy->GetAttackPoint());

				g_pGame->GetEffectManager()->Start(Vector2(pEnemy->GetAttackRect().Left, pEnemy->GetAttackRect().Top), CGameElement::EFFECT_ENEMY_ATTACK);

				m_bVibration = true;

				g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_DAMAGE);

			}

		}

		//�v���C���[���U�������ꍇ
		if (m_Player->GetAttackState() == CGameElement::PLAYER_ATTACKSTATE_ATTACK) {

			//�v���C���[�̍U���ƓG�̏Փ˔���
			if (m_Player->GetAttackRect().CollisionRect(pEnemy->GetRect())) {

				m_Player->SetAttackState(CGameElement::PLAYER_ATTACKSTATE_ATTACKLATE);

				pEnemy->Damage(m_Player->GetAttackPoint());

				g_pGame->GetEffectManager()->Start(Vector2(m_Player->GetAttackRect().Left, m_Player->GetAttackRect().Top), CGameElement::EFFECT_ENEMY_ATTACK);

				m_BreakTime = CGameElement::BREAKTIME;

				m_bVibration = true;

				g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_DAMAGE);

			}

		}
		
	}

}

void CGameScene::ItemCollision() {

	int id = -1;

	for (CItem* pItem : m_ItemArray) {

		if (pItem->GetType() == CGameElement::ITEM_PIANO) {

			id = pItem->GetIDNo();

		}

		if (pItem->GetType() == CGameElement::ITEM_PIANO && pItem->GetRect().CollisionRect(m_Player->GetRect())) {

			m_Player->SetItemCollision(true);

		}
		else {

			m_Player->SetItemCollision(false);

		}

	}

	if (m_Player->IsCarry()) {

		m_ItemArray[id]->GetPos().x += m_Player->GetMove().x;
		m_ItemArray[id]->GetPos().y = m_Player->GetPos().y - m_ItemArray[id]->GetSize().y;

	}

}

void CGameScene::PlayerUpdate() {

	//�X�N���[���l��ݒ�
	m_Player->SetScrooll(m_Stage->GetScrooll());

	//�v���C���[�̍X�V
	m_Player->Update();

	CWeapon* pWeapon = m_Player->GetWeapon();

	if (pWeapon != nullptr) {

		pWeapon->Update();

		Vector2& weaponPos = pWeapon->GetPos() - m_Stage->GetScrooll();

		if (weaponPos.x + pWeapon->GetSize().x < 0 || weaponPos.x > g_pGraphics->GetTargetWidth() ||
			weaponPos.y + pWeapon->GetSize().y < 0 || weaponPos.y > g_pGraphics->GetTargetHeight()) {

			pWeapon->SetShow(false);

		}

	}

	Vector2 buried;

	//�v���C���[�ƃX�e�[�W�̏Փ˔���
	if (m_Stage->Collision(m_Player->GetRect(), buried)) {

		m_Player->CollisionStage(buried);

	}

}

void CGameScene::EnemyUpdate() {

	//�G�̏o������
	EnemyAppear();

	for (CEnemy* pEnemy : m_EnemyArray) {

		//�X�N���[���l�̐ݒ�
		pEnemy->SetScrooll(m_Stage->GetScrooll());

		pEnemy->Update();

		CWeapon* pWeapon = pEnemy->GetWeapon();

		 if (pWeapon != nullptr) {

			pWeapon->Update();

		}

		Vector2 buried;

		//�G�ƃX�e�[�W�̏Փ˔���
		if (m_Stage->Collision(pEnemy->GetRect(), buried)) {

			pEnemy->ColisionStage(buried);

			if (!m_Stage->Collision(pEnemy->GetFallRect(), buried)) {

				pEnemy->SetFall(true);

			}
			else {

				pEnemy->SetFall(false);

			}

		}

	}

}

void CGameScene::ItemUpdate() {

	//�A�C�e���̏o������
	ItemAppear();

	for (CItem* pItem : m_ItemArray) {

		pItem->Update();

	}

}

void CGameScene::WorldTimeLimitUpdate() {

	bool isPossessionMode = m_Player->GetPossession() == CGameElement::POSSESSION_MODE ? true : false;

	m_WorldTimeLimit->SetTimeFaster(isPossessionMode);

	m_WorldTimeLimit->Update();

}

void CGameScene::ControllerUpdate() {

	if (g_pGame->GetSetting()->IsVibration()) {

		if (m_bVibration) {

			g_pGame->GetController()->Vibration(0.5f, 0.5f, 0.5f);

			m_bVibration = false;

		}

	}
	
	g_pGame->GetController()->Update();

}

void CGameScene::SoundUpdate() {


}

CGameObject* CGameScene::GameState() {

	CGameObject* pGameObject;

	pGameObject = m_Player;

	/*switch (m_GameState)
	{
	case CGameElement::GAME_RUN:
	case CGameElement::GAME_:
	case CGameElement::GAME_RUN:



		break;

	case CGameElement::GAME_GAMEOVER:

		pGameObject = m_Transition;

		break;

	}
*/
	return pGameObject;

}

void CGameScene::CommandTransition() {

	//�{�^���͈�̓���ւ�
	if (m_ControllerState != m_Player->GetPossessionState()) {

		switch (m_Player->GetPossessionState())
		{

		case CGameElement::PLAYER_SOUL:

			g_pGame->GetController()->SetSoulPlayerCommand();

			m_ControllerState = CGameElement::PLAYER_SOUL;

			break;

		case CGameElement::PLAYER_HANAKO:

			g_pGame->GetController()->SetHanakoPlayerCommand();

			m_ControllerState = CGameElement::PLAYER_HANAKO;

			break;

		case CGameElement::PLAYER_TEKETEKE:

			g_pGame->GetController()->SetTekeTekePlayerCommand();

			m_ControllerState = CGameElement::PLAYER_TEKETEKE;

			break;

		case CGameElement::PLAYER_KINZIROU:

			g_pGame->GetController()->SetKinzirouPlayerCommand();

			m_ControllerState = CGameElement::PLAYER_KINZIROU;

			break;

		case CGameElement::PLAYER_HUMANBODYMODLE:

			g_pGame->GetController()->SetHumanBodyModlePlayerCommand();

			m_ControllerState = CGameElement::PLAYER_HUMANBODYMODLE;

			break;

		}

	}

}

void CGameScene::EnemyAppear() {

	//��������̂��A�ړ�����̂�
	for (CEnemy* pEnemy : m_EnemyArray) {

		if (pEnemy->IsDead() || pEnemy->GetPossession()) {

			continue;

		}

		Vector2& enemyPos = pEnemy->GetPos() - m_Stage->GetScrooll();

		if (enemyPos.x + pEnemy->GetSize().x > 0 && enemyPos.x < g_pGraphics->GetTargetWidth() &&
			enemyPos.y + pEnemy->GetSize().y > 0 && enemyPos.y < g_pGraphics->GetTargetHeight()) {

			if (!pEnemy->IsShow()) {

				pEnemy->SetShow(true);

			}

			pEnemy->SetAppear(true);

		}
		else {

			pEnemy->SetAppear(false);

		}

		CWeapon* pWeapon = pEnemy->GetWeapon();

		if (pWeapon != nullptr) {

			Vector2& weaponPos = pWeapon->GetPos() - m_Stage->GetScrooll();

			if (weaponPos.x + pWeapon->GetSize().x < 0 || weaponPos.x > g_pGraphics->GetTargetWidth() ||
				weaponPos.y + pWeapon->GetSize().y < 0 || weaponPos.y > g_pGraphics->GetTargetHeight()) {

				pWeapon->SetShow(false);

			}

		}

	}

}

void CGameScene::ItemAppear() {

	//��������̂��A�ړ�����̂�
	for (CItem* pItem : m_ItemArray) {

		if (pItem->GetType() == CGameElement::ITEM_CHARM) {

			continue;

		}

		Vector2& itemPos = pItem->GetPos() - m_Stage->GetScrooll();

		if (itemPos.x + pItem->GetSize().x > 0 && itemPos.x < g_pGraphics->GetTargetWidth() &&
			itemPos.y + pItem->GetSize().y > 0 && itemPos.y < g_pGraphics->GetTargetHeight()) {

			if (!pItem->IsShow()) {

				pItem->SetShow(true);

			}

			pItem->SetAppear(true);

		}
		else {

			pItem->SetAppear(false);

		}

	}

}

void CGameScene::Render() {

	//�X�e�[�W�̕`��
	m_Stage->Render();

	//���Ԃ̕`��
	m_WorldTimeLimit->Render();

	//�G�t�F�N�g�̕`��
	g_pGame->GetEffectManager()->Render(m_Stage->GetScrooll());

	//�v���C���[�̕`��
	m_Player->Render();

	CWeapon* pPlayerWeapon = m_Player->GetWeapon();

	if (pPlayerWeapon != nullptr) {

		pPlayerWeapon->Render(m_Stage->GetScrooll());

	}

	//�G�̕`��
	for (CEnemy* pEnemy : m_EnemyArray) {

		pEnemy->Render();

		CWeapon* pWeapon = pEnemy->GetWeapon();

		if (pWeapon != nullptr) {

			pWeapon->Render(m_Stage->GetScrooll());

		}

		//pEnemy->RenderDebug(0);

	}

	//�A�C�e���̕`��
	for (CItem* pItem : m_ItemArray) {

		pItem->Render(m_Stage->GetScrooll());

	}

}

void CGameScene::Release() {

	//���Ԑ����̉��
	if (m_WorldTimeLimit) {

		delete m_WorldTimeLimit;

		m_WorldTimeLimit = nullptr;

	}

	//�v���C���[�̉��
	if (m_Player) {

		delete m_Player;

		m_Player = nullptr;

	}

	//�X�e�[�W�̉��
	if (m_Stage) {

		//�G�̉��
		for (auto it = begin(m_EnemyArray); it != end(m_EnemyArray); ++it) {

			delete *it;

		}

		m_EnemyArray.clear();

		//�A�C�e���̉��
		for (auto it = begin(m_ItemArray); it != end(m_ItemArray); ++it) {

			delete *it;

		}

		m_ItemArray.clear();

		delete m_Stage;

		m_Stage = nullptr;

	}

	g_pGame->GetSoundManager()->Stop(CGameElement::SOUND_BGM_GAME, CGameElement::STOP_GRADUALLY);

}