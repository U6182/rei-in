#pragma once

/**

	@file Utili.h
	@brief �ėp�N���X
	@author �ؑ��J��
	@date 2020/10/13

*/

#include		"Mof.h"

class CUtili {

public:

	/**
		@brief CenterTexturePos
		@param[in] texture �e�N�X�`��
		@return �Ȃ�
		@details �e�N�X�`������ʒ����ɂȂ���W�̎擾���s��
	*/
	static Vector2 CenterTexturePos(CTexture& texture) {

		return Vector2((g_pGraphics->GetTargetWidth() - texture.GetWidth()) * 0.5f, (g_pGraphics->GetTargetHeight() - texture.GetHeight()) * 0.5f);

	}
	/**
		@brief CenterTexturePosX
		@param[in] texture �e�N�X�`��
		@return �Ȃ�
		@details �e�N�X�`�������X�������ɂȂ���W�̎擾���s��
	*/
	static float CenterTexturePosX(CTexture& texture) {

		return (g_pGraphics->GetTargetWidth() - texture.GetWidth()) * 0.5f;

	}
	/**
		@brief CenterTexturePosY
		@param[in] texture �e�N�X�`��
		@return �Ȃ�
		@details �e�N�X�`�������Y�������ɂȂ���W�̎擾���s��
	*/
	static float CenterTexturePosY(CTexture& texture) {

		return (g_pGraphics->GetTargetHeight() - texture.GetHeight()) * 0.5f;

	}

};