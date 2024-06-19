/**

	@file Player.cpp
	@brief プレイヤー
	@author 木村憂哉
	@date 2020/10/24

*/

#include		"Player.h"
#include		"Game.h"

CPlayer::CPlayer(void) : CAnime(Vector2()) {

	m_Weapon = new CViscera(g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_VISCERA), Vector2(50, 50), Vector2(8, -10));

	m_Pos = Vector2(0, 1080 - 120 - 256);

	m_bItemCollision = false, m_bCarry = false, m_bEnemyCollision = false, m_bMove = false, m_bDeadBehaviorEnd = false, m_PossessionState = CGameElement::PLAYER_SOUL, m_JumpPower = -10.0f, m_ChargeAttackState = 0, m_AttackState = 0, m_PossessionColor = 255, m_Charging = 0.0f;

}

void CPlayer::Load() {

	//プレイヤーのテクスチャの読み込み
	for (int i = CGameElement::TEXTURE_GAME_SOUL; i <= CGameElement::TEXTURE_GAME_HUMANBODYMODLE; i++) {

		m_pTexture.push_back(g_pGame->GetTextureManager()->GetTexture(i));

	}

	//プレイヤーのモーションの読み込み
	for (int i = CGameElement::MOTION_SOUL; i <= CGameElement::MOTION_HUMANBODYMODLE; i++) {

		m_pMotion.push_back(g_pGame->GetMotionManager()->GetMotion(i));

	}

}

void CPlayer::Render() {

	const Vector2 pos = m_Pos - m_Scrooll;

	CRectangle dr = m_pMotion[m_PossessionState]->GetSrcRect();

	if (m_bReverse) {

		float tmp = dr.Right;

		dr.Right = dr.Left;

		dr.Left = tmp;

	}

	int damageInterval = m_DamageInterval * 10;

	int renderInterval = static_cast<int>(damageInterval);

	//プレイヤーの描画
	if (renderInterval % 2 == 0 || m_bDead || m_Possession == CGameElement::POSSESSION_BEHAVIOR) {

		m_pTexture[m_PossessionState]->Render(pos.x, pos.y, dr, MOF_ARGB(m_Transparency, m_PossessionColor, 255, 255));

	}

}

void CPlayer::Jump() {

	if (!m_bJump) {

		m_Move.y = m_JumpPower;

		m_bJump = true;

	}

}

void CPlayer::Move() {

	float horizontal = g_pGame->GetController()->GetHorizontal();

	int direction = horizontal > 0 ? 1 : -1;

	m_Move.x += direction * CGameElement::PLAYER_MOVE;

	float nowMaxSpeed = (std::round(horizontal * 100) / 100.0f) * m_StateMaxMove[m_PossessionState];

	if (m_MaxSpeed > nowMaxSpeed || m_MaxSpeed < nowMaxSpeed) {

		m_MaxSpeed = nowMaxSpeed;

	}

	if (direction > 0) {

		if (m_Move.x > m_MaxSpeed) {

			m_Move.x -= CGameElement::PLAYER_MOVE * 2;

			if (m_Move.x <= m_MaxSpeed) {

				m_Move.x = m_MaxSpeed;

			}

		}

	}
	else {

		if (m_Move.x < m_MaxSpeed) {

			m_Move.x += CGameElement::PLAYER_MOVE * 2;

			if (m_Move.x >= m_MaxSpeed) {

				m_Move.x = m_MaxSpeed;

			}

		}

	}
	
}

void CPlayer::MoveWait() {

	if (m_Move.x > 0) {

		m_Move.x -= CGameElement::PLAYER_MOVE;

		if (m_Move.x < 0) {

			m_Move.x = 0;

		}

	}
	else if (m_Move.x < 0) {

		m_Move.x += CGameElement::PLAYER_MOVE;

		if (m_Move.x > 0) {

			m_Move.x = 0;

		}

	}

}

void CPlayer::Possession() {

	if (m_bPossessionLifted && m_DamageInterval > 0) {

		return;

	}

	switch (m_Possession)
	{

	case CGameElement::POSSESSION_NOTMODE:

		m_Possession = CGameElement::POSSESSION_MODE;

		break;

	}

	g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_TIMEFASTER);

}

void CPlayer::PossessionLifted() {

	m_Possession = CGameElement::POSSESSION_NOTMODE;

	m_PossessionState = CGameElement::PLAYER_SOUL;

	m_PossessionColor = 255;

	m_pEnemyState->GetPos() = m_Pos;

	m_pEnemyState->SetPossession(CGameElement::POSSESSION_NOTMODE);

	m_pEnemyState->SetShow(true);

	m_bDamage = true;

	m_bPossessionLifted = true;

	m_DamageInterval = 0.0f;

	if (m_pEnemyState->GetType() == CGameElement::ENEMY_TEKETEKE) {

		Jump();

	}

}

void CPlayer::Attack() {

	if (m_AttackState != CGameElement::PLAYER_ATTACKSTATE_NOT) {

		return;

	}

	g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_HANAKOATTACK);

	m_AttackState = CGameElement::PLAYER_ATTACKSTATE_ATTACK;

}

void CPlayer::Charge() {

	if (m_ChargeAttackState == PLAYER_CHARGEATTACK_CHARGEATTACK) {

		return;

	}

	m_ChargeAttackState = PLAYER_CHARGEATTACK_CHARGE;

	m_Charging += m_bReverse ? CUtilities::GetFrameSecond() : -CUtilities::GetFrameSecond();

	if (m_Charging < 0) {

		if (m_Charging <= -m_MAXCHARGETIME) {

			m_Charging = -m_MAXCHARGETIME;

		}

	}
	else if (m_Charging > 0) {

		if (m_Charging >= m_MAXCHARGETIME) {

			m_Charging = m_MAXCHARGETIME;

		}

	}
	

}

void CPlayer::ChargeAttack() {

	if (m_ChargeAttackState != PLAYER_CHARGEATTACK_CHARGE) {

		return;

	}

	g_pGame->GetSoundManager()->EPlay(CGameElement::SOUND_SE_CHARGEATTACK);

	m_Move.x = m_Charging * m_StateMaxMove[m_PossessionState];

	m_ChargeAttackState = PLAYER_CHARGEATTACK_CHARGEATTACK;

	m_AttackState = CGameElement::PLAYER_ATTACKSTATE_ATTACK;

}

void CPlayer::ChargeAttackStop() {

	m_Move.x = 0.0f;

	if (m_ChargeAttackState == PLAYER_CHARGEATTACK_CHARGEATTACK) {

		m_ChargeAttackState = PLAYER_CHARGEATTACK_NOT;

		m_Charging = 0.0f;

	}

	m_AttackState = CGameElement::PLAYER_ATTACKSTATE_NOT;

}

void CPlayer::Carry() {

	if (m_bItemCollision) {

		m_bCarry = true;

	}

}

void CPlayer::BodyAttack() {

	if (m_Weapon->IsShow()) {

		return;

	}

	m_Weapon->Shot(m_Pos, !m_bReverse);

	m_AttackState = CGameElement::PLAYER_ATTACKSTATE_ATTACK;

}

void CPlayer::Behavior() {

	if (m_Possession == CGameElement::POSSESSION_MODE) {

		m_Possession = CGameElement::POSSESSION_NOTMODE;

	}

	bool bWait = true;

	for (int i = 0; i < CGameElement::PLAYER_OPERATION_COUNT; i++) {

		int operation = -1;

		if (m_bOperation[i]) {

			operation = i;

		}

		switch (operation)
		{
		case CGameElement::PLAYER_OPERATION_MOVE:

			if (!m_bOperation[CGameElement::PLAYER_OPERATION_BODYATTACK] && !m_bOperation[CGameElement::PLAYER_OPERATION_CHARGE] && m_ChargeAttackState != PLAYER_CHARGEATTACK_CHARGEATTACK) {

				Move();

				bWait = false;

			}

			break;

		case CGameElement::PLAYER_OPERATION_JUMP:

			if (!m_bOperation[CGameElement::PLAYER_OPERATION_CHARGE]) {

				Jump();

			}

			break;

		case CGameElement::PLAYER_OPERATION_POSSESSION:

			Possession();

			break;

		case CGameElement::PLAYER_OPERATION_POSSESSIONLIFTED:

			PossessionLifted();

			break;

		case CGameElement::PLAYER_OPERATION_ATTACK:

			Attack();

			break;

		case CGameElement::PLAYER_OPERATION_CHARGE:

			Charge();

			break;

		case CGameElement::PLAYER_OPERATION_CHARGEATTACK:

			ChargeAttack();

			break;

		case CGameElement::PLAYER_OPERATION_CHARGEATTACKSTOP:

			ChargeAttackStop();

			break;

		case CGameElement::PLAYER_OPERATION_CARRY:

			Carry();

			break;

		case CGameElement::PLAYER_OPERATION_BODYATTACK:

			BodyAttack();

			break;

		}

	}

	if (bWait && m_ChargeAttackState != PLAYER_CHARGEATTACK_CHARGEATTACK) {

		MoveWait();

	}

	for (int i = 0; i < CGameElement::PLAYER_OPERATION_COUNT; i++) {

		m_bOperation[i] = false;

	}

	if (m_Possession == CGameElement::POSSESSION_MODE) {

		if (m_Transparency > 122) {

			m_Transparency--;

		}

	}
	else {

		if (m_Transparency < 255) {

			m_Transparency++;

		}

	}

}

void CPlayer::PossessionBehavior() {

	if (m_PossessionState == CGameElement::PLAYER_SOUL) {

		m_Transparency--;

	}
	else {

		m_PossessionColor--;

		if (m_PossessionColor <= 0) {

			m_PossessionColor = 0;

			m_Possession = CGameElement::POSSESSION_BEHAVIOREND;

		}

	}
	
	if (m_Transparency <= 0) {

		m_Transparency = 255;

		m_Pos = m_pEnemyState->GetPos();

		m_Move = Vector2();

		m_bReverse = m_pEnemyState->IsReverse();

		m_PossessionState = m_pEnemyState->GetType() + 1;

		m_pEnemyState->SetPossession(CGameElement::POSSESSION_NOW);

		m_pEnemyState->SetShow(false);

	}

}

void CPlayer::DeadBehavior() {

	m_Pos.y -= 3;

	m_Transparency--;

	if (m_Transparency < 20) {

		m_bDeadBehaviorEnd = true;

	}

	if (m_Transparency <= 0) {

		m_Transparency = 0;

	}
}

void CPlayer::MotionChange() {

	if (m_PossessionState != CGameElement::PLAYER_SOUL && m_Possession == CGameElement::POSSESSION_BEHAVIOR) {

		return;

	}

	switch (m_PossessionState)
	{
	case CGameElement::PLAYER_SOUL:

		SoulMotionChange();

		break;
	case CGameElement::PLAYER_HANAKO:

		HanakoMotionChange();

		break;
	case CGameElement::PLAYER_TEKETEKE:

		TekeTekeMotionChange();

		break;
	case CGameElement::PLAYER_KINZIROU:

		KinzirouMotionChange();

		break;
	case CGameElement::PLAYER_HUMANBODYMODLE:

		HumanBodyModleMotionChange();

		break;

	}

}

void CPlayer::SoulMotionChange() {

	if (m_bDamage || m_bDead) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_SOUL_DAMAGE, FALSE);

	}
	else if (m_bJump) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_SOUL_JUMP, FALSE);

	}
	else if (m_Move.x) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_SOUL_MOVE, FALSE);

	}
	else {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_SOUL_WAIT, FALSE);

	}

}

void CPlayer::HanakoMotionChange() {

	if (m_bDamage || m_bDead) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HANAKO_DAMAGE, FALSE);

	}
	else if (m_AttackState != CGameElement::PLAYER_ATTACKSTATE_NOT) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HANAKO_ATTACK, FALSE);

		if (m_pMotion[m_PossessionState]->IsEndMotion()) {

			m_AttackState = CGameElement::PLAYER_ATTACKSTATE_NOT;

		}

	}else if (m_bJump) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HANAKO_JUMP, FALSE);

	}else if (m_Move.x) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HANAKO_MOVE, FALSE);

	}
	else {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HANAKO_WAIT, FALSE);

	}

}

void CPlayer::TekeTekeMotionChange() {

	if (m_bDamage || m_bDead) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_DAMAGE, FALSE);

	}
	else {

		if (m_ChargeAttackState == PLAYER_CHARGEATTACK_CHARGEATTACK) {

			m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_CHARGEATTACK, FALSE);

		}
		else if (m_ChargeAttackState == PLAYER_CHARGEATTACK_CHARGE) {

			m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_WAIT, FALSE);

		}
		else {

			if (m_Move.x) {

				m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_MOVE, FALSE);

			}
			else {

				m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_TEKETEKE_WAIT, FALSE);

			}

		}

	}
	
}

void CPlayer::KinzirouMotionChange() {

	if (m_bCarry) {

		if (m_Move.x) {

			m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_KINZIROU_CARRY, FALSE);

		}
		else {

			m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_KINZIROU_CARRYWAIT, FALSE);

		}

	}
	else {

		if (m_bJump) {

			m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_KINZIROU_JUMP, FALSE);

		}
		else if (m_Move.x) {

			m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_KINZIROU_MOVE, FALSE);

		}
		else {

			m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_KINZIROU_WAIT, FALSE);

		}

	}

}

void CPlayer::HumanBodyModleMotionChange() {

	if (m_bDamage || m_bDead) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_DAMAGE, FALSE);

	}else if (m_Weapon->IsShot()) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_ATTACK, FALSE);

		if (m_pMotion[m_PossessionState]->IsEndMotion()) {

			m_Weapon->SetShot(false);

		}

	}else if (m_bJump) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_JUMP, FALSE);

	}else if (m_Move.x) {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_MOVE, FALSE);

	}
	else {

		m_pMotion[m_PossessionState]->ChangeMotion(CMotionName::MOTOIN_HUMANBODYMODLE_WAIT, FALSE);

	}

}

void CPlayer::Effect() {

	if (m_bDead && m_Transparency > 0) {

		if (!g_pGame->GetEffectManager()->IsEffect(CGameElement::EFFECT_SOUL_PLAYERDEAD)) {

			g_pGame->GetEffectManager()->Start(m_Pos, CGameElement::EFFECT_SOUL_PLAYERDEAD);

		}

	}

	if (m_Possession == CGameElement::POSSESSION_BEHAVIOR) {

		if (!g_pGame->GetEffectManager()->IsEffect(CGameElement::EFFECT_SOUL_POSSESSION)) {

			g_pGame->GetEffectManager()->Start(m_Pos, CGameElement::EFFECT_SOUL_POSSESSION);

		}

	}

	if (m_ChargeAttackState == PLAYER_CHARGEATTACK_CHARGE) {

		int CHARGE_STAGE = static_cast<int>(m_Charging);

		if (CHARGE_STAGE < 0) {

			CHARGE_STAGE = -CHARGE_STAGE;

		}

		if (!g_pGame->GetEffectManager()->IsEffect(m_CHARGE_STAGE[CHARGE_STAGE])) {

			const Vector2 pos(m_Pos.x, m_Pos.y);

			g_pGame->GetEffectManager()->Start(pos, m_CHARGE_STAGE[CHARGE_STAGE]);

		}

	}

}

void CPlayer::Update() {

	//効果処理の更新
	Effect();

	//モーション処理の更新
	MotionChange();

	//死亡動作処理の更新
	if (m_bDead) {

		DeadBehavior();

		return;

	}

	//憑依動作処理の更新
	if (m_Possession == CGameElement::POSSESSION_BEHAVIOR) {

		PossessionBehavior();

	}
	else {

		if (!m_bBehaviorWait) {

			//動作処理の更新
			Behavior();

			//ダメージ動作処理の更新
			DamageBehavior();

			//反転処理の更新
			Reverse();

			//座標移動処理の更新
			PosMove();

		}
		
	}

	m_pMotion[m_PossessionState]->AddTimer(CUtilities::GetFrameSecond());

}

void CPlayer::CollisionStage(const Vector2& buried) {

	m_Pos += buried;

	//下辺との衝突
	if (buried.y < 0 && m_Move.y > 0) {

		m_Move.y = 0.0f;

		if (m_bJump) {

			m_bJump = false;

		}

		if (m_bEnemyCollision) {

			m_bEnemyCollision = false;

		}

	}//上辺との衝突
	else if (buried.y > 0 && m_Move.y < 0) {

		m_Move.y = 0.0f;

	}

	//右辺との衝突
	if (buried.x < 0 && m_Move.x > 0) {

		ChargeAttackStop();

	}//左辺との衝突
	else if (buried.x > 0 && m_Move.x < 0) {

		ChargeAttackStop();

	}

}

void	CPlayer::SetbOperation(bool bOperation, int operation) {

	float horizontal = g_pGame->GetController()->GetHorizontal();

	if (bOperation) {

		switch (operation)
		{
		case CGameElement::PLAYER_OPERATION_MOVE:

			m_bOperation[operation] = horizontal > CGameElement::MOVE_STICK || horizontal < -CGameElement::MOVE_STICK ? true : false;

			break;

		default:

			m_bOperation[operation] = bOperation;

			break;

		}

	}
	else {

		m_bOperation[operation] = bOperation;

	}

}

CRectangle CPlayer::GetRect() const {

	//座標をポインタにして敵側から矩形を取得できるようにする
	switch (m_PossessionState)
	{

	case CGameElement::PLAYER_SOUL:

		return CRectangle(m_Pos.x + 40, m_Pos.y + 20, m_Pos.x + m_Size[m_PossessionState].x - 40, m_Pos.y + m_Size[m_PossessionState].y - 5);

		break;
	case CGameElement::PLAYER_HANAKO:

		return CRectangle(m_Pos.x + 40, m_Pos.y + 20, m_Pos.x + m_Size[m_PossessionState].x - 40, m_Pos.y + m_Size[m_PossessionState].y - 5);

		break;
	case CGameElement::PLAYER_TEKETEKE:

		return CRectangle(m_Pos.x + 30, m_Pos.y + 20, m_Pos.x + m_Size[m_PossessionState].x - 30, m_Pos.y + m_Size[m_PossessionState].y - 5);

		break;
	case CGameElement::PLAYER_KINZIROU:

		return CRectangle(m_Pos.x + 60, m_Pos.y + 15, m_Pos.x + m_Size[m_PossessionState].x - 70, m_Pos.y + m_Size[m_PossessionState].y - 5);

		break;
	case CGameElement::PLAYER_HUMANBODYMODLE:

		return CRectangle(m_Pos.x + 40, m_Pos.y + 20, m_Pos.x + m_Size[m_PossessionState].x - 40, m_Pos.y + m_Size[m_PossessionState].y - 5);

		break;

	}

	return nullptr;

}

CRectangle CPlayer::GetAttackRect() {

	switch (m_PossessionState)
	{

	case CGameElement::PLAYER_SOUL:

		return nullptr;

		break;
	case CGameElement::PLAYER_HANAKO:

		if (m_bReverse) {

			return CRectangle(GetRect().Right, GetRect().Top, GetRect().Right + 31, GetRect().Bottom);

		}
		else {

			return CRectangle(GetRect().Left - 31, GetRect().Top, GetRect().Left, GetRect().Bottom);

		}

		break;
	case CGameElement::PLAYER_TEKETEKE:

		return GetRect();

		break;
	case CGameElement::PLAYER_KINZIROU:

		return CRectangle(m_Pos.x + 60, m_Pos.y + 15, m_Pos.x + m_Size[m_PossessionState].x - 70, m_Pos.y + m_Size[m_PossessionState].y - 5);

		break;
	case CGameElement::PLAYER_HUMANBODYMODLE:

		if (m_Weapon->IsShow()) {

			return m_Weapon->GetRect();

		}
		else {

			return CRectangle(0, 0, 0, 0);

		}

		break;

	}

	return nullptr;

}

int CPlayer::GetAttackPoint() {

	int test = 0;
	switch (m_PossessionState)
	{

	case CGameElement::PLAYER_SOUL:

		return 0;

		break;
	case CGameElement::PLAYER_HANAKO:

		return CGameElement::ENEMY_ATTACKPOINT_HANAKO;

		break;
	case CGameElement::PLAYER_TEKETEKE:

		test = CGameElement::ENEMY_ATTACKPOINT_TEKETEKE * static_cast<int>(m_Charging);

		return CGameElement::ENEMY_ATTACKPOINT_TEKETEKE * static_cast<int>(m_Charging);

		break;
	case CGameElement::PLAYER_KINZIROU:

		return CGameElement::ENEMY_ATTACKPOINT_KINZIROU;

		break;
	case CGameElement::PLAYER_HUMANBODYMODLE:

		return CGameElement::ENEMY_ATTACKPOINT_HUMANBODYMODLE;

		break;

	}

	return 0;

}