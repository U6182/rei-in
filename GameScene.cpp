/**

	@file GameScene.cpp
	@brief ゲームシーン
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"GameScene.h"
#include	"Charm.h"

CGameScene::CGameScene() : CSceneBase(&m_NextSceneList), m_WorldTimeLimit(new CWorldTimeLimit()), m_Player(new CPlayer()), m_Stage(new CStage()) {

	//コントローラーを魂プレイヤーのコマンドに設定
	g_pGame->GetController()->SetSoulPlayerCommand();

	//振動フラグの初期化
	m_bVibration = false;

	//コントローラーの状態
	m_ControllerState = m_Player->GetPossessionState();

	//ゲームの状態
	m_GameState = CGameElement::GAME_RUN;

	//プレイヤー攻撃時の停止時間
	m_BreakTime = 0.0f;

}

CGameScene::~CGameScene() {

	//解放処理
	Release();

}

bool CGameScene::Load() {

	//プレイヤーの読み込み
	m_Player->Load();

	//ステージの読み込み
	m_Stage->Load("GameScene/Stage/Stage.txt");

	return true;

}

void CGameScene::Initialize() {

	//読み込み
	Load();

	//ステージの初期化
	m_Stage->Initialize(m_EnemyArray, m_ItemArray);

	//プレイヤーの状態の設定
	for (CEnemy* pEnemy : m_EnemyArray) {

		pEnemy->SetPlayerState(m_Player);

	}

}

void CGameScene::Update() {

	//BGMの再生
	g_pGame->GetSoundManager()->Play(CGameElement::SOUND_BGM_GAME);

	//プレイヤーの攻撃が当たった場合、フリーズ演出
	if (m_BreakTime > 0) {

		m_BreakTime -= CUtilities::GetFrameSecond();

		return;

	}

	//プレイヤーの行動をリセット
	m_Player->ResetMove();

	//コマンド入れ替え
	CommandTransition();

	//操作
	Operation(GameState());

	//ステージの更新
	m_Stage->Update(m_Player);

	//エフェクトの更新
	g_pGame->GetEffectManager()->Update();

	//キャラクターの衝突処理の更新
	if (m_Player->GetPossession() != CGameElement::POSSESSION_BEHAVIOR) {

		AnimeCollision();

	}

	if (m_Player->GetPossession() == CGameElement::POSSESSION_BEHAVIOREND) {

		for (CEnemy* pEnemy : m_EnemyArray) {

			pEnemy->SetBehaviorWait(false);

		}

		m_Player->SetPossession(CGameElement::POSSESSION_NOW);

	}

	//プレイヤーの更新
	PlayerUpdate();

	//敵の更新
	EnemyUpdate();
	
	//アイテムの更新
	ItemUpdate();

	//アイテムとの衝突判定
	ItemCollision();

	//時間の更新
	WorldTimeLimitUpdate();

	//コントローラーの更新
	ControllerUpdate();

	//ゲーム遷移処理の更新
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

		//非表示の場合スキップ
		if (!pEnemy->IsShow() || !pEnemy->IsAppear() || pEnemy->IsDead()) {

			continue;

		}

		//憑依モードで衝突した場合
		if (m_Player->GetPossession() == CGameElement::POSSESSION_MODE && m_Player->GetRect().CollisionRect(pEnemy->GetRect())) {

			m_Player->SetPossession(CGameElement::POSSESSION_BEHAVIOR);

			m_Player->SetEnemyState(pEnemy);

			for (CEnemy* pEne : m_EnemyArray) {

				pEne->SetBehaviorWait(true);

			}

			return;

		}

		//発見処理
		if (pEnemy->GetFindRect().CollisionRect(m_Player->GetRect()) && m_Player->GetPossession() != CGameElement::POSSESSION_MODE) {

			pEnemy->SetFind(true);

		}
		else {

			pEnemy->SetFind(false);

		}

		if (pEnemy->IsAttackPossible() && pEnemy->IsFind()) {

			//敵の攻撃とプレイヤーの衝突判定
			if (pEnemy->GetAttackRect().CollisionRect(m_Player->GetRect()) && m_Player->GetDamageInterval() <= 0) {

				pEnemy->SetAttack(true);

				m_Player->SetDamage(true);

				//時間を削る
				m_WorldTimeLimit->LessTime(pEnemy->GetAttackPoint());

				g_pGame->GetEffectManager()->Start(Vector2(pEnemy->GetAttackRect().Left, pEnemy->GetAttackRect().Top), CGameElement::EFFECT_ENEMY_ATTACK);

				m_bVibration = true;

				g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_DAMAGE);

			}

		}

		//プレイヤーが攻撃した場合
		if (m_Player->GetAttackState() == CGameElement::PLAYER_ATTACKSTATE_ATTACK) {

			//プレイヤーの攻撃と敵の衝突判定
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

	//スクロール値を設定
	m_Player->SetScrooll(m_Stage->GetScrooll());

	//プレイヤーの更新
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

	//プレイヤーとステージの衝突判定
	if (m_Stage->Collision(m_Player->GetRect(), buried)) {

		m_Player->CollisionStage(buried);

	}

}

void CGameScene::EnemyUpdate() {

	//敵の出現処理
	EnemyAppear();

	for (CEnemy* pEnemy : m_EnemyArray) {

		//スクロール値の設定
		pEnemy->SetScrooll(m_Stage->GetScrooll());

		pEnemy->Update();

		CWeapon* pWeapon = pEnemy->GetWeapon();

		 if (pWeapon != nullptr) {

			pWeapon->Update();

		}

		Vector2 buried;

		//敵とステージの衝突判定
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

	//アイテムの出現処理
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

	//ボタンは一の入れ替え
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

	//復活あるのか、移動するのか
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

	//復活あるのか、移動するのか
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

	//ステージの描画
	m_Stage->Render();

	//時間の描画
	m_WorldTimeLimit->Render();

	//エフェクトの描画
	g_pGame->GetEffectManager()->Render(m_Stage->GetScrooll());

	//プレイヤーの描画
	m_Player->Render();

	CWeapon* pPlayerWeapon = m_Player->GetWeapon();

	if (pPlayerWeapon != nullptr) {

		pPlayerWeapon->Render(m_Stage->GetScrooll());

	}

	//敵の描画
	for (CEnemy* pEnemy : m_EnemyArray) {

		pEnemy->Render();

		CWeapon* pWeapon = pEnemy->GetWeapon();

		if (pWeapon != nullptr) {

			pWeapon->Render(m_Stage->GetScrooll());

		}

		//pEnemy->RenderDebug(0);

	}

	//アイテムの描画
	for (CItem* pItem : m_ItemArray) {

		pItem->Render(m_Stage->GetScrooll());

	}

}

void CGameScene::Release() {

	//時間制限の解放
	if (m_WorldTimeLimit) {

		delete m_WorldTimeLimit;

		m_WorldTimeLimit = nullptr;

	}

	//プレイヤーの解放
	if (m_Player) {

		delete m_Player;

		m_Player = nullptr;

	}

	//ステージの解放
	if (m_Stage) {

		//敵の解放
		for (auto it = begin(m_EnemyArray); it != end(m_EnemyArray); ++it) {

			delete *it;

		}

		m_EnemyArray.clear();

		//アイテムの解放
		for (auto it = begin(m_ItemArray); it != end(m_ItemArray); ++it) {

			delete *it;

		}

		m_ItemArray.clear();

		delete m_Stage;

		m_Stage = nullptr;

	}

	g_pGame->GetSoundManager()->Stop(CGameElement::SOUND_BGM_GAME, CGameElement::STOP_GRADUALLY);

}