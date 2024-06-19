/**

	@file WorldTimeLimit
	@brief 時間制限
	@author 木村憂哉
	@date 2019/01/05

*/

#include	"WorldTimeLimit.h"
#include	"Game.h"

CWorldTimeLimit::CWorldTimeLimit() {

	//タイムリミットのテクスチャの設定
	m_pNumberTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_NUMBER);

	//タイムリミットフレームのテクスチャの設定
	m_pNumberFrameTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_NUMBERFRAME);

	//マイナス記号のテクスチャ
	m_pNegativeSymbolTexture = g_pGame->GetTextureManager()->GetTexture(CGameElement::TEXTURE_GAME_NEGATIVESYMBOL);

	//タイム加速フラグの初期化
	m_bTimeFaster = false;

	//透明度の初期化
	m_LessTimeAlpha = 0;

	//タイムリミットの初期化
	m_TimeLimit = 300;

}

void CWorldTimeLimit::Update() {

	int faster = m_bTimeFaster ? 2 : 1;

	m_TimeLimit -= CUtilities::GetFrameSecond() * faster;

	if (m_LessTimeRenderTime <= 0) {

		m_LessTimeAlpha -= 2;

		if (m_LessTimeAlpha < 0) {

			m_LessTimeAlpha = 0;

		}

	}
	else {

		m_LessTimeRenderTime -= CUtilities::GetFrameSecond();

		if (m_LessTimeRenderTime <= 0) {

			m_LessTimeRenderTime = 0;

		}

	}

}

void CWorldTimeLimit::Render() {

	float posX = CUtili::CenterTexturePosX(*m_pNumberFrameTexture);

	//タイムリミットフレームの描画
	m_pNumberFrameTexture->Render(posX, 0);

	int timeLimit = static_cast<int>(m_TimeLimit);

	std::vector<int> num;

	num.push_back((timeLimit / 100) % 10);
	num.push_back((timeLimit / 10) % 10);
	num.push_back(timeLimit % 10);

	float size = 100;

	posX = (g_pGraphics->GetTargetWidth() - size * 3) * 0.5f;

	Vector2 aling(100, 80);

	//タイムリミットの描画
	for (int i = 0; i < num.size(); i++) {

		CRectangle rec(num[i] * size, 0, num[i] * size + size, 150);

		m_pNumberTexture->Render(posX + (size * i) - aling.x, aling.y, rec);

	}

	CRectangle rec(m_LessTime * size, 0, m_LessTime * size + size, 150);

	posX = posX + m_pNumberFrameTexture->GetWidth();

	//削られた時間の描画
	m_pNegativeSymbolTexture->RenderRotate(posX - m_pNegativeSymbolTexture->GetWidth() + 30, aling.y + 80, MOF_ToRadian(45.0f), MOF_ARGB(m_LessTimeAlpha, 255, 255, 255), TEXALIGN_CENTERCENTER);
	m_pNumberTexture->RenderRotate(posX, aling.y + 150, MOF_ToRadian(45.0f), rec, MOF_ARGB(m_LessTimeAlpha, 255, 255, 255), TEXALIGN_CENTERCENTER);

}
