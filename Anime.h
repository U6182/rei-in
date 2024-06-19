#pragma once

/**

	@file Anime.h
	@brief キャラクター
	@author 木村憂哉
	@date 2019/11/24

*/

#include		"DynamicGameObject.h"
#include		"Weapon.h"

class CAnime : public CDynamicGameObject {

protected:

	//! 武器
	CWeapon*	m_Weapon;

	//! ステージのスクロール
	Vector2		m_Scrooll;

	//! 攻撃フラグ
	bool		m_bAttack;

	//! ジャンプフラグ
	bool		m_bJump;

	//! 死亡フラグ
	bool		m_bDead;

	//! ダメージフラグ
	bool		m_bDamage;

	//! 解除フラグ
	bool		m_bPossessionLifted;

	//! 動作停止フラグ
	bool		m_bBehaviorWait;

	//! 憑依透明度
	int			m_Transparency;

	//! 憑依モード
	int			m_Possession;

	//! 攻撃力
	int			m_AttackPoint;

	//! ダメージ待機時間
	float		m_DamageWait;

	//! ジャンプ力
	float		m_JumpPower;

	//! ダメージインターバルタイム
	const	float									m_DAMAGEINTERVALTIME = 3;

	//! ダメージインターバル
	float									m_DamageInterval;

#pragma region 関数

	/**
		@brief DamageBehavior
		@param なし
		@return なし
		@details 敵のダメージ動作処理を行う
	*/
	void		DamageBehavior(void) {

		if (m_bDamage && m_DamageInterval <= 0) {

			m_DamageInterval = m_DAMAGEINTERVALTIME;

		}

		if (m_DamageInterval > 0) {

			m_DamageInterval -= CUtilities::GetFrameSecond();

			if (m_DamageInterval <= 2) {

				m_bDamage = false;

			}

			if (m_DamageInterval <= 0) {

				m_DamageInterval = 0;

				m_bPossessionLifted = false;

			}

		}

	}

#pragma endregion


public:

#pragma region コンストラクタ デストラクタ

	/**
		@brief コンストラクタ
		@param なし
		@details 生成時に呼び出し、メンバの初期化を行う
	*/
				CAnime(const Vector2 size) : CDynamicGameObject(size), m_Weapon(nullptr), m_Scrooll() {

					m_bAttack = false, m_bJump = false, m_bDead = false, m_bDamage = false, m_bPossessionLifted = false, m_bBehaviorWait = false, m_Transparency = 255, m_Possession = 0, m_AttackPoint = 0, m_DamageWait = 0.0f, m_JumpPower = 0.0f, m_DamageInterval = 0.0f;

				}
	/**
		@brief デストラクタ
		@param なし
		@details 解放時に呼び出し、メンバの解放を行う
	*/
	virtual		~CAnime(void) { ; }

#pragma endregion

#pragma region 関数

	/**
		@brief Update
		@param なし
		@return なし
		@details キャラクターの更新を行う
	*/
	virtual		void	Update(void) = 0;
	/**
		@brief Render
		@param なし
		@return なし
		@details キャラクターの描画を行う
	*/
	virtual		void	Render(void) = 0;

#pragma endregion

#pragma region セッター

	/**
		@brief SetDead
		@param[in] dead 死亡フラグ
		@return なし
		@details 死亡フラグの設定を行う
	*/
	void		SetDead(const bool bDead) { m_bDead = bDead; }
	/**
		@brief SetDamage
		@param[in] damage ダメージフラグ
		@return なし
		@details ダメージフラグの設定を行う
	*/
	void		SetDamage(const bool bDamage) { m_bDamage = bDamage; }
	/**
		@brief SetAttack
		@param[in] bAttack アタックフラグ
		@return なし
		@details アタックフラグの設定を行う
	*/
	void		SetAttack(const bool bAttack) { m_bAttack = bAttack; }
	/**
		@brief SetBehaviorWait
		@param[in] BehaviorWait 行動待機フラグ
		@return なし
		@details 行動待機フラグの設定を行う
	*/
	void		SetBehaviorWait(bool bBehaviorWait) { m_bBehaviorWait = bBehaviorWait; }
	/**
		@brief SetPossession
		@param[in] bPossession 憑依モード
		@return なし
		@details 憑依モードの設定を行う
	*/
	void		SetPossession(const int possessionMode) { m_Possession = possessionMode; }
	/**
		@brief SetScrooll
		@param[in] scrooll スクロール値
		@return なし
		@details スクロール値の設定を行う
	*/
	void		SetScrooll(const Vector2& scrooll) { m_Scrooll = scrooll; }
	
#pragma endregion

#pragma region ゲッター

	/**
		@brief GetWeapon
		@param なし
		@return CWeapon 武器
		@details 武器を取得する
	*/
	virtual		CWeapon*		GetWeapon(void) { return m_Weapon; }
	/**
		@brief GetAttackRect
		@param なし
		@return CRectangle 攻撃矩形
		@details 攻撃矩形を取得する
	*/
	virtual		CRectangle		GetAttackRect() { return GetRect(); }
	/**
		@brief GetScrooll
		@param なし
		@return Vector2& スクロール値
		@details スクロール値を取得する
	*/
				Vector2&		GetScrooll(void) { return m_Scrooll; }
	/**
		@brief IsAttack
		@param なし
		@return bool true 攻撃 false 攻撃でない
		@details 攻撃フラグを取得する
	*/
				bool			IsAttack(void) { return m_bAttack; }
	/**
		@brief IsReverse
		@param なし
		@return bool true 左向き(左進行) false 右向き(右進行)
		@details 反転フラグを取得する
	*/
				bool			IsReverse(void) { return m_bReverse; }
	/**
		@brief IsDead
		@param なし
		@return bool true 死亡 false 生存
		@details 死亡フラグを取得する
	*/
				bool			IsDead(void) { return m_bDead; }
	/**
		@brief IsDamage
		@param なし
		@return bool true ダメージ(死亡) false 生存
		@details 死亡フラグを取得する
	*/
	virtual		bool			IsDamage(void) { return m_bDamage; }
	/**
		@brief GetPossession
		@param なし
		@return int 憑依モード
		@details 憑依モードの取得をする
	*/
	virtual		int				GetPossession(void) { return m_Possession; }
	/**
		@brief GetAttackPoint
		@param なし
		@return int	GetAttackPoint
		@details 攻撃力の取得を行う
	*/
	virtual		int				GetAttackPoint(void) { return m_AttackPoint; }

#pragma endregion

};