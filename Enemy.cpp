/**

	@file Enemy.cpp
	@brief 敵
	@author 木村憂哉
	@date 2019/01/05

*/

#include	"Enemy.h"

CEnemy::CEnemy(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint) : CAnime(size),m_FindRange() {

	//モーションの設定
	m_pMotion = pMotoin;

	//座標の初期化
	m_Pos = pos;

	//移動量の初期化
	m_Move = move;

	//種類の初期化
	m_Type = type;

	//HPの初期化
	m_HP = HP;

	//攻撃力の初期化
	m_AttackPoint = attackPoint;
	
	//発見フラグの初期化
	m_bFind = false;

	//落下フラグの初期化
	m_bFall = false;

	//出現フラグの初期化
	m_bAppear = false;

}

CEnemy::~CEnemy() {

}

void CEnemy::Update() {

	if (m_Possession == CGameElement::POSSESSION_NOW || !m_bShow) {

		return;

	}

	//落下処理の更新
	FallBehavior();

	if (!m_bBehaviorWait) {

		if (m_bDead) {

			//死亡動作処理の更新
			DeadBehavior();

		}
		else {

			//行動処理の更新
			Behavior();

			//ダメージ動作処理の更新
			DamageBehavior();

			//反転処理の更新
			Reverse();

			//座標の更新
			PosMove();

		}
		
		//モーション処理の更新
		MotionChange();

	}

	//効果処理の更新
	Effect();

	m_pMotion->AddTimer(CUtilities::GetFrameSecond());

}

void CEnemy::Render() {

	if (!m_bShow  || !m_bAppear) {

		return;

	}

	const Vector2 pos = m_Pos - m_Scrooll;

	CRectangle dr = m_pMotion->GetSrcRect();

	if (m_bReverse) {

		float tmp = dr.Right;
		
		dr.Right = dr.Left;

		dr.Left = tmp;

	}

	//敵の描画
	m_pTexture->Render(pos.x, pos.y, dr, MOF_ARGB(m_Transparency, 255, 255, 255));

}

void CEnemy::RenderDebug(int i) {

	CRectangle rect(GetRect().Left - m_Scrooll.x, GetRect().Top - m_Scrooll.y, GetRect().Right - m_Scrooll.x, GetRect().Bottom - m_Scrooll.y);

	CRectangle aRect(GetAttackRect().Left - m_Scrooll.x, GetAttackRect().Top - m_Scrooll.y, GetAttackRect().Right - m_Scrooll.x, GetAttackRect().Bottom - m_Scrooll.y);

	CRectangle fRect(GetFindRect().Left - m_Scrooll.x, GetFindRect().Top - m_Scrooll.y, GetFindRect().Right - m_Scrooll.x, GetFindRect().Bottom - m_Scrooll.y);

	CRectangle faRect(GetFallRect().Left - m_Scrooll.x, GetFallRect().Top - m_Scrooll.y, GetFallRect().Right - m_Scrooll.x, GetFallRect().Bottom - m_Scrooll.y);

	CGraphicsUtilities::RenderRect(rect, MOF_COLOR_BLUE);

	/*CGraphicsUtilities::RenderRect(aRect, MOF_COLOR_RED);

	CGraphicsUtilities::RenderRect(fRect, MOF_COLOR_GREEN);

	CGraphicsUtilities::RenderRect(faRect, MOF_COLOR_YELLOW);*/


	//CGraphicsUtilities::RenderString(0, 100, MOF_XRGB(255, 0, 0), "BreakInterval %.f DamageInterval %.f ColisionBreakInterval %.f", m_BossBehavior.BreakInterval, m_BossBehavior.DamageInterval, m_BossBehavior.ColisionBreakInterval);
	//CGraphicsUtilities::RenderString(0, 200, MOF_XRGB(255, 0, 0), "Life %d FireballCount %d AttackPossible %d count %d ", m_BossBehavior.Life, m_BossBehavior.FireballCount, m_BossBehavior.bAttackPossible,m_BossBehavior.count);
	//CGraphicsUtilities::RenderString(0, 300, MOF_XRGB(255, 0, 0), "m_Pos.x %.f m_Pos.y %.f PosX %.f ", m_Pos.x, m_Pos.y, m_BossBehavior.PosX);
}

void CEnemy::MotionChange() {	

}

void CEnemy::DeadBehavior() {
	
	m_Transparency--;

	if (m_Transparency <= 0) {

		m_Transparency = 0;

		m_bShow = false;

	}

}

void CEnemy::ColisionStage(const Vector2& buried) {

	m_Pos += buried;

	//下辺との衝突
	if (buried.y < 0 && m_Move.y > 0) {

		m_Move.y = 0.0f;

		if (m_bJump) {

			m_bJump = false;

		}

	}//上辺との衝突
	else if (buried.y > 0 && m_Move.y < 0) {

		m_Move.y = 0.0f;

	}
	
	//右辺との衝突
	if (buried.x < 0 && m_Move.x > 0) {
		
		m_Move.x = -m_Move.x;

	}//左辺との衝突
	else if (buried.x > 0 && m_Move.x < 0) {
		
		m_Move.x = -m_Move.x;

	}

}