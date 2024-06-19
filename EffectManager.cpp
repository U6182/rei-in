/**

	@file EffectManager.cpp
	@brief エフェクトの管理
	@author 木村憂哉
	@date 2019/12/21

*/

#include		"EffectManager.h"

void CEffectManager::Initialize() {

	//エフェクトの初期化
	for (int j = 0; j < CGameElement::EFFECT_TYPE_COUNT; j++) {

		for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

			m_Effect[i][j].SetTexture(&m_Texture[j]);

			m_Effect[i][j].Initialize(j);

		}

	}

}

void CEffectManager::Start(const Vector2& pos, const int type) {

	//エフェクトの表示
	for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

		if (m_Effect[i][type].IsShow()) {

			continue;

		}

		m_Effect[i][type].Start(pos);

		return;

	}

}

void CEffectManager::Update() {

	//エフェクトの更新
	for (int j = 0; j < CGameElement::EFFECT_TYPE_COUNT; j++) {

		for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

			m_Effect[i][j].Update();

		}

	}

}

void CEffectManager::Render(const Vector2& scrooll) {

	//エフェクトの描画
	for (int j = 0; j < CGameElement::EFFECT_TYPE_COUNT; j++) {

		for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

			m_Effect[i][j].Render(scrooll);

		}

	}

}

bool CEffectManager::IsEffect(const int type) {

	bool show = false;

	//指定したエフェクトが表示されているかを返す
	for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

		if (m_Effect[i][type].IsShow()) {

			show = true;

		}

	}

	return show;

}