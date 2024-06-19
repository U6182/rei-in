#pragma once

/**

	@file Player.h
	@brief プレイヤー
	@author 木村憂哉
	@date 2020/10/29

*/

#include		"Anime.h"
#include		"Viscera.h"

class CPlayer : public CAnime {

private:

	//! 敵の情報
			CAnime*									m_pEnemyState;

	//! プレイヤーのテクスチャ
			std::vector<CTexture*>					m_pTexture;

	//! プレイヤーのモーション
			std::vector<CSpriteMotionController*>	m_pMotion;

	//! プレイヤーのサイズ
	const	Vector2									m_Size[CGameElement::PLAYER_COUNT] = { Vector2(180,256), Vector2(228,256), Vector2(200,127), Vector2(228,256), Vector2(228,256) };

	//! チャージエフェクト
	const	std::vector<int>						m_CHARGE_STAGE = { CGameElement::EFFECT_TEKETEKE_CHARGESTAGE1, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE2, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE3, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE4, CGameElement::EFFECT_TEKETEKE_CHARGESTAGE5 };

	//! 操作フラグ
			bool									m_bOperation[CGameElement::PLAYER_OPERATION_COUNT] = { false };

	//! 敵を踏んだか
			bool									m_bEnemyCollision;

	//! 移動フラグ
			bool									m_bMove;

	//! 死亡演出終了フラグ
			bool									m_bDeadBehaviorEnd;

	//! アイテム接触フラグ
			bool									m_bItemCollision;

	//! 運ぶフラグ
			bool									m_bCarry;

	//! 状態
			int										m_PossessionState;

	//! 憑依色
			int										m_PossessionColor;

	//! チャージ攻撃の状態
			int										m_ChargeAttackState;

	//! 攻撃の状態
			int										m_AttackState;

	//! 憑依状態の最大スピード
			float									m_StateMaxMove[CGameElement::PLAYER_COUNT] = {CGameElement::PLAYER_MAXMOVE_SOUL, CGameElement::PLAYER_MAXMOVE_HANAKO, CGameElement::PLAYER_MAXMOVE_TEKETEKE, CGameElement::PLAYER_MAXMOVE_KINZIROU, CGameElement::PLAYER_MAXMOVE_HUMANBODYMODLE};

	//! 最大スピード
			float									m_MaxSpeed;

	//! チャージ量
			float									m_Charging;

	//! 最大チャージタイム
	const	float									m_MAXCHARGETIME = 4;

			/**
				@enum tag_PLAYER_CHARGEATTACKSTATE
				プレイヤーのチャージ攻撃状態の列挙定数

			*/
			typedef enum tag_PLAYER_CHARGEATTACKSTATE {

				PLAYER_CHARGEATTACK_NOT,
				PLAYER_CHARGEATTACK_CHARGE,
				PLAYER_CHARGEATTACK_CHARGEATTACK,

			}PLAYER_CHARGEATTACKSTATE_NAME;

#pragma region 関数

	/**
		@brief Behavior
		@param なし
		@return なし
		@details プレイヤーの動作処理を行う
	*/
	void		Behavior(void);
	/**
		@brief PossessionBehavior
		@param なし
		@return なし
		@details プレイヤーの憑依動作処理を行う
	*/
	void		PossessionBehavior(void);
	/**
		@brief DeadBehavior
		@param なし
		@return なし
		@details プレイヤーの死亡動作処理を行う
	*/
	void		DeadBehavior(void);
	/**
		@brief DamageBehavior
		@param なし
		@return なし
		@details プレイヤーのダメージ動作処理を行う
	*/
	//void		DamageBehavior(void);
	/**
		@brief MotionChange
		@param なし
		@return なし
		@details プレイヤーのモーションの変更処理を行う
	*/
	void		MotionChange(void);
	/**
		@brief SoulMotionChange
		@param なし
		@return なし
		@details 魂プレイヤーのモーションの変更処理を行う
	*/
	void		SoulMotionChange(void);
	/**
		@brief HanakoMotionChange
		@param なし
		@return なし
		@details 花子プレイヤーのモーションの変更処理を行う
	*/
	void		HanakoMotionChange(void);
	/**
		@brief TekeTekeMotionChange
		@param なし
		@return なし
		@details テケテケプレイヤーのモーションの変更処理を行う
	*/
	void		TekeTekeMotionChange(void);
	/**
		@brief KinzirouMotionChange
		@param なし
		@return なし
		@details 金次郎プレイヤーのモーションの変更処理を行う
	*/
	void		KinzirouMotionChange(void);
	/**
		@brief HumanBodyModleMotionChange
		@param なし
		@return なし
		@details 人体模型プレイヤーのモーションの変更処理を行う
	*/
	void		HumanBodyModleMotionChange(void);
	/**
		@brief Effect
		@param なし
		@return なし
		@details 効果処理を行う
	*/
	void		Effect(void);
	/**
		@brief Reverse
		@param なし
		@return なし
		@details 反転処理を行う
	*/
	void		Reverse(void) override { 
		
		if (m_PossessionState == CGameElement::PLAYER_SOUL) {

			if (m_Move.x > 0) {

				m_bReverse = false;

			}
			else if (m_Move.x < 0) {

				m_bReverse = true;

			}

		}
		else {

			if (m_Move.x < 0) {

				m_bReverse = false;

			}
			else if (m_Move.x > 0) {

				m_bReverse = true;

			}

		}
		
	
	};
	/**
		@brief Move
		@param なし
		@return なし
		@details 移動処理を行う
	*/
	void		Move(void);
	/**
		@brief Jump
		@param なし
		@return なし
		@details ジャンプ処理を行う
	*/
	void		Jump(void);
	/**
		@brief MoveWait
		@param なし
		@return なし
		@details 移動停止処理を行う
	*/
	void		MoveWait(void);
	/**
		@brief Possession
		@param なし
		@return なし
		@details 憑依処理を行う
	*/
	void		Possession(void);
	/**
		@brief PossessionLifted
		@param なし
		@return なし
		@details プレイヤーの憑依解除処理を行う
	*/
	void		PossessionLifted(void);
	/**
		@brief Attack
		@param なし
		@return なし
		@details 攻撃処理を行う
	*/
	void		Attack(void);
	/**
		@brief Charge
		@param なし
		@return なし
		@details チャージ処理を行う
	*/
	void		Charge(void);
	/**
		@brief ChargeAttack
		@param なし
		@return なし
		@details チャージ攻撃処理を行う
	*/
	void		ChargeAttack(void);
	/**
		@brief ChargeAttackStop
		@param なし
		@return なし
		@details チャージ攻撃停止処理を行う
	*/
	void		ChargeAttackStop(void);
	/**
		@brief Carry
		@param なし
		@return なし
		@details 運ぶ処理を行う
	*/
	void		Carry(void);
	/**
		@brief BodyAttack
		@param なし
		@return なし
		@details ボディー攻撃処理を行う
	*/
	void		BodyAttack(void);

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CPlayer(void);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CPlayer(void) { 
		
		if (m_Weapon) {

			delete m_Weapon;

			m_Weapon = nullptr;

		}

	}

#pragma endregion

#pragma region 関数

	/**
		@brief Load
		@param なし
		@return なし
		@details プレイヤーの読み込みを行う
	*/
	void		Load(void);
	/**
		@brief Update
		@param なし
		@return なし
		@details プレイヤーの更新を行う
	*/
	void		Update(void) override;
	/**
		@brief Render
		@param なし
		@return なし
		@details プレイヤーの描画を行う
	*/
	void		Render(void) override;
	/**
		@brief CollisionStage
		@param[in] buried プレイヤーの埋まり値
		@return なし
		@details プレイヤーがステージと衝突した時の処理を行う
	*/
	void		CollisionStage(const Vector2& buried);
	/**
		@brief ResetMove
		@param なし
		@return なし
		@details 移動のリセットを行う
	*/
	void		ResetMove(void) { m_bMove = false; }

#pragma endregion

#pragma region セッター

	/**
		@brief SetEnemyState
		@param[in] pEnemyState 敵状態のポインタ
		@return なし
		@details 敵状態の設定を行う
	*/
	void	SetEnemyState(CAnime* pEnemyState) { m_pEnemyState = pEnemyState; }
	/**
		@brief SetAttackState
		@param[in] AttackState 攻撃状態
		@return なし
		@details 攻撃状態モードの設定を行う
	*/
	void		SetAttackState(const int AttackState) { m_AttackState = AttackState; }
	/**
		@brief SetbOperation
		@param[in] bOperation 操作フラグ
		@param[out] operation 操作
		@return なし
		@details 操作の設定を行う
	*/
	void	SetbOperation(const bool bOperation, const int operation);
	/**
		@brief SetItemCollision
		@param[in] bItemCollision アイテム衝突フラグ
		@return なし
		@details アイテム衝突フラグの設定を行う
	*/
	void	SetItemCollision(bool bItemCollision) { m_bItemCollision = bItemCollision; }

#pragma endregion

#pragma region ゲッター

	/**
		@brief GetRect
		@param なし
		@return CRectangle 矩形
		@details 矩形を取得する
	*/
	CRectangle					GetRect(void) const	override;
	/**
		@brief GetAttackRect
		@param なし
		@return CRectangle 攻撃矩形
		@details 攻撃矩形を取得する
	*/
	CRectangle					GetAttackRect() override;
	/**
		@brief GetMotion
		@param なし
		@return CSpriteMotionController モーション
		@details モーションを取得する
	*/
	CSpriteMotionController*	GetMotion(void) { return m_pMotion[m_PossessionState]; }
	/**
		@brief IsDeadBehaviorEnd
		@param なし
		@return bool true 終了 false 未終了
		@details 死亡演出フラグの取得をする
	*/
	bool						IsDeadBehaviorEnd(void) { return m_bDeadBehaviorEnd; }
	/**
		@brief IsDamage
		@param なし
		@return bool true ダメージ(死亡) false 生存
		@details ダメージフラグを取得する
	*/
	bool						IsDamage(void) override { return m_DamageInterval > 0 ? true : false; }
	/**
		@brief IsCarry
		@param なし
		@return bool true 運ぶ false 運んでいない
		@details 運ぶフラグを取得する
	*/
	bool						IsCarry(void) { return m_bCarry; }
	/**
		@brief GetPossessionState
		@param なし
		@return int	GetPossessionState
		@details 状態の取得を行う
	*/
	int							GetPossessionState(void) { return m_PossessionState; }
	/**
		@brief GetAttackPoint
		@param なし
		@return int	GetAttackPoint
		@details 攻撃力の取得を行う
	*/
	int							GetAttackPoint(void) override;
	/**
		@brief GetAttackState
		@param なし
		@return int	GetAttackState
		@details 攻撃状態の取得を行う
	*/
	int							GetAttackState(void) { return m_AttackState; }
	/**
		@brief GetDamageInterval
		@param なし
		@return int	GetDamageInterval
		@details ダメージインターバルの取得を行う
	*/
	float						GetDamageInterval(void) const { return m_DamageInterval; }

#pragma endregion

};