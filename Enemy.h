#pragma once

/**

	@file Enemy.h
	@brief 敵
	@author 木村憂哉
	@date 2019/11/25

*/

#include		"Anime.h"
#include		"Game.h"

class CEnemy : public CAnime {

protected:

	//! プレイヤーの状態
	const	CAnime*		m_pPlayerState;

	//! 発見範囲
			Vector2		m_FindRange;

	//! 発見フラグ
			bool		m_bFind;

	//! 落下フラグ
			bool		m_bFall;

	//! 出現フラグ
			bool		m_bAppear;

	//! HP
			int			m_HP;

#pragma region 関数

	/**
		@brief Behavior
		@param なし
		@return なし
		@details 敵の行動処理を行う
	*/
	virtual		void		Behavior(void) { ; }
	/**
		@brief DeadBehavior
		@param なし
		@return なし
		@details 敵死亡時の動作処理を行う
	*/
	virtual		void		DeadBehavior(void);
	/**
		@brief MotionChange
		@param なし
		@return なし
		@details 敵のモーション処理を行う
	*/
	virtual		void		MotionChange(void);
	/**
		@brief Reverse
		@param なし
		@return なし
		@details 反転処理を行う
	*/
	virtual		void		Reverse(void) override{ 

		if (m_Move.x < 0) { 
			
			m_bReverse = false;

		} else if (m_Move.x > 0) { 
			
			m_bReverse = true;
		
		} 
	
	};
	/**
		@brief Effect
		@param なし
		@return なし
		@details 効果処理を行う
	*/
	virtual		void		Effect(void) { 
	
		if (m_bDead) {

			if (!g_pGame->GetEffectManager()->IsEffect(CGameElement::EFFECT_ENEMY_ENEMYDEAD)) {

				const Vector2 pos(m_Pos.x, m_Pos.y);

				g_pGame->GetEffectManager()->Start(pos, CGameElement::EFFECT_ENEMY_ENEMYDEAD);

			}

		}

	}

#pragma endregion

public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param[in] pMotion モーション
		@param[out] pos 座標
		@param[in.out] move 移動量
		@param[in] size サイズ
		@param[out] type 種類
		@param[in.out] HP HP
		@param[in] attackPoint 攻撃力
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CEnemy(CSpriteMotionController* pMotoin, const Vector2 pos, const Vector2 move, const Vector2 size, const int type, const int HP, const int attackPoint);
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CEnemy(void);

#pragma endregion
							
#pragma region 関数

	/**
		@brief Update
		@param なし
		@return なし
		@details 敵の更新を行う
	*/
	virtual		void		Update(void);
	/**
		@brief Render
		@param なし
		@return なし
		@details 敵の描画を行う
	*/
	virtual		void		Render(void);
	/**
		@brief RenderDebug
		@param[in] i 敵の要素番号
		@return なし
		@details 敵のデバッグ描画を行う
	*/
	virtual		void		RenderDebug(int i);
	/**
		@brief ColisionStage
		@param[in] buried 敵の埋まり値
		@return なし
		@details 敵がステージと衝突した時の処理を行う
	*/
	virtual		void		ColisionStage(const Vector2& buried);
	/**
		@brief Damage
		@param[in] damage
		@return なし
		@details ダメージ処理を行う
	*/
	virtual		void		Damage(int damage) {
		
		m_HP -= damage;
	
		if (m_HP <= 0) {

			m_bDead = true;

		}
		else {

			m_bDamage = true;

		}

	}
	/**
		@brief FallBehavior
		@param なし
		@return なし
		@details 落下処理を行う
	*/
	virtual		void		FallBehavior(void) {

		if (m_bFall) {

			m_Move.x = -m_Move.x;

		}

	}

#pragma endregion

#pragma region セッター

	/**
		@brief SetPlayerState
		@param[in] PlayerState プレイヤーの状態
		@return なし
		@details プレイヤーの状態の設定を行う
	*/
	virtual		void		SetPlayerState(const CAnime* pPlayerState) { m_pPlayerState = pPlayerState; }
	/**
		@brief SetFind
		@param[in] Find 発見フラグ
		@return なし
		@details 敵の発見フラグの設定を行う
	*/
	virtual		void		SetFind(bool bFind) { m_bFind = bFind; }
	/**
		@brief SetFall
		@param[in] fall 落下フラグ
		@return なし
		@details 敵の落下フラグの設定を行う
	*/
	virtual		void		SetFall(bool bFall) { m_bFall = bFall; }
	/**
		@brief SetAppear
		@param[in] bAppear 出現フラグ
		@return なし
		@details 敵の出現フラグの設定を行う
	*/
	virtual		void		SetAppear(bool bAppar) { m_bAppear = bAppar; }

#pragma endregion

#pragma region ゲッター

	/**
		@brief FallRect
		@param なし
		@return CRectangle 落下判定用の矩形
		@details 落下判定用の矩形を取得する
	*/
			CRectangle	GetFallRect(void) {

				if (m_bReverse) {

					return CRectangle(m_Pos.x + m_Size.x, m_Pos.y, m_Pos.x + m_Size.x + 128, m_Pos.y + m_Size.y);

				}
				else {

					return CRectangle(m_Pos.x - 128, m_Pos.y, m_Pos.x, m_Pos.y + m_Size.y);

				}

			}
	/**
		@brief GetFindRect
		@param なし
		@return CRectangle プレイヤー発見判定用の矩形
		@details プレイヤー発見判定用の矩形を取得する
	*/
	virtual	CRectangle	GetFindRect(void) {

		return CRectangle(m_Pos.x - m_FindRange.x, m_Pos.y - m_FindRange.y, m_Pos.x + m_FindRange.x, m_Pos.y + m_FindRange.y);

	}
	/**
		@brief IsFind
		@param なし
		@return bool true 発見 false 未発見
		@details 発見フラグを取得する
	*/
			bool		IsFind(void) { return m_bFind; }
	/**
		@brief IsAppear
		@param なし
		@return bool true 出現 false 未出現
		@details 出現フラグを取得する
	*/
			bool		IsAppear(void) { return m_bAppear; }
	/**
		@brief IsAttackPossible
		@param なし
		@return bool true 攻撃可能 false 攻撃不可能
		@details 攻撃可能フラグを取得する
	*/
	virtual	bool		IsAttackPossible(void) { return true; }

#pragma endregion

};