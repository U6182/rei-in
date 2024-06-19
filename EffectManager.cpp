/**

	@file EffectManager.cpp
	@brief �G�t�F�N�g�̊Ǘ�
	@author �ؑ��J��
	@date 2019/12/21

*/

#include		"EffectManager.h"

void CEffectManager::Initialize() {

	//�G�t�F�N�g�̏�����
	for (int j = 0; j < CGameElement::EFFECT_TYPE_COUNT; j++) {

		for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

			m_Effect[i][j].SetTexture(&m_Texture[j]);

			m_Effect[i][j].Initialize(j);

		}

	}

}

void CEffectManager::Start(const Vector2& pos, const int type) {

	//�G�t�F�N�g�̕\��
	for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

		if (m_Effect[i][type].IsShow()) {

			continue;

		}

		m_Effect[i][type].Start(pos);

		return;

	}

}

void CEffectManager::Update() {

	//�G�t�F�N�g�̍X�V
	for (int j = 0; j < CGameElement::EFFECT_TYPE_COUNT; j++) {

		for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

			m_Effect[i][j].Update();

		}

	}

}

void CEffectManager::Render(const Vector2& scrooll) {

	//�G�t�F�N�g�̕`��
	for (int j = 0; j < CGameElement::EFFECT_TYPE_COUNT; j++) {

		for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

			m_Effect[i][j].Render(scrooll);

		}

	}

}

bool CEffectManager::IsEffect(const int type) {

	bool show = false;

	//�w�肵���G�t�F�N�g���\������Ă��邩��Ԃ�
	for (int i = 0; i < CGameElement::EFFECT_COUNT; i++) {

		if (m_Effect[i][type].IsShow()) {

			show = true;

		}

	}

	return show;

}