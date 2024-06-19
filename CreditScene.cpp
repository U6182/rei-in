/**

	@file CreditScene.cpp
	@brief クレジットシーン
	@author 木村憂哉
	@date 2020/10/24

*/

#include	"CreditScene.h"

CCreditScene::CCreditScene() : CSceneBase(&m_NextSceneList), m_Player(new CPlayer()), m_Stage(new CStage()), m_Credit(), m_CreditPos(nullptr), m_CreditColor(nullptr) {
	
	//コマンドの設定
	g_pGame->GetController()->SetCreditCommand();

	//クリアゴースト発見フラグ
	m_bGhostFind = false;

	//待機インターバル
	m_WaitInterval = 0.0f;

}

CCreditScene::~CCreditScene() {

	//解放処理
	Release();

}

bool CCreditScene::Load() {

	const char* pName = "CreditScene/Credit.txt";

	//ステージテキストの読み込み
	FILE* fp = fopen(pName, "rt");

	if (fp == NULL) {

		return false;

	}

	//基準値の設定
	fseek(fp, 0, SEEK_END);

	//ファイルのサイズを取得
	long fSize = ftell(fp);

	fseek(fp, 0, SEEK_SET);

	//ステージの情報分のサイズを確保
	char* pInfo = (char*)malloc(fSize + 1);

	fSize = fread(pInfo, 1, fSize, fp);

	pInfo[fSize] = '\0';

	char* pStr;

	pStr = strtok(pInfo, "\n");

	//クレジットの数
	const int creditCount = atoi(pStr);

	m_CreditPos = new Vector2[creditCount]();

	m_CreditColor = new MofU32[creditCount];

	//クレジットの読み込みと座標の初期化
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

	//ファイルを閉じる
	fclose(fp);

	//ステージの情報を解放する
	free(pInfo);

	return true;

}

void CCreditScene::Initialize() {

	//読み込み
	Load();

	//プレイヤーの読み込み
	m_Player->Load();

	//プレイヤーの移動量
	m_Player->GetMove() = Vector2(CGameElement::PLAYER_MAXMOVE_SOUL, 0);

	//ステージの読み込み
	m_Stage->Load("CreditScene/CreditStage.txt");

	//ステージの初期化
	m_Stage->Initialize(m_EnemyArray, m_ClearGhost);

}

void CCreditScene::Update() {

	//ステージの更新
	if (!m_bGhostFind) {

		m_Stage->Update(m_Player);

	}

	//スクロール値を設定
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

	//プレイヤーとステージの衝突判定
	if (m_Stage->Collision(m_Player->GetRect(), buried)) {

		m_Player->CollisionStage(buried);

	}

	pPlayerMotion->AddTimer(frameScecond);

	//クリアゴーストの描画
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

	//最終座標までクレジットのスクロールを行う
	for (int i = 0; i < m_Credit.size(); i++) {

		m_CreditPos[i].y -= 1.35f;

	}

}

void CCreditScene::Render() {

	//ステージの描画
	m_Stage->Render();

	//プレイヤーの描画
	m_Player->Render();

	//クリアゴーストの描画
	for (CItem* pClearGhost : m_ClearGhost) {

		pClearGhost->Render(m_Stage->GetScrooll());

	}

	//クレジットの描画
	for (int i = 0; i < m_Credit.size(); i++) {

		g_pGame->GetFontManager()->GetFont(CGameElement::FONTSIZE_32)->RenderString(m_CreditPos[i].x, m_CreditPos[i].y, m_CreditColor[i], m_Credit[i]);

	}

}

void CCreditScene::Release() {

	//プレイヤーの解放
	if (m_Player) {

		delete m_Player;

		m_Player = nullptr;

	}

	//クレジットの解放
	for (auto it = begin(m_Credit); it != end(m_Credit); ++it) {

		delete *it;

	}

	//クレジットの座標の解放
	if (m_CreditPos) {

		delete[] m_CreditPos;

		m_CreditPos = nullptr;

	}

	//クレジットの座標の解放
	if (m_CreditColor) {

		delete[] m_CreditColor;

		m_CreditColor = nullptr;

	}

	//ステージの解放
	if (m_Stage) {

		//敵の解放
		for (auto it = begin(m_EnemyArray); it != end(m_EnemyArray); ++it) {

			delete *it;

		}

		m_EnemyArray.clear();

		//アイテムの解放
		for (auto it = begin(m_ClearGhost); it != end(m_ClearGhost); ++it) {

			delete *it;

		}

		m_ClearGhost.clear();

		delete m_Stage;

		m_Stage = nullptr;

	}

}