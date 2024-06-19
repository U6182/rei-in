/**

	@file Transition.cpp
	@brief �J��
	@author �ؑ��J��
	@date 2020/10/24

*/

#include		"Transition.h"

void CTransition::Update() {

	if (m_bAlpha) {

		m_Alpha += 5;

		if (m_Alpha >= 255) {

			m_bAlpha = false;

			m_Alpha = 255;

			//�J��
			m_bEnd = true;

			m_NowScene = (*m_NextScene)[m_SelectNo];

		}

	}
	else {

		m_Alpha -= 5;

		if (m_Alpha <= 0) {

			m_Alpha = 0;

		}

	}

}

void CTransition::Render() {

	//�t�F�[�h�̕`��
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_Alpha, 0, 0, 0));

}