#pragma once

/**

	@file TitleScene.h
	@brief �^�C�g���V�[��
	@author �ؑ��J��
	@date 2019/11/20

*/

#include		"SceneBase.h"

class CTitleScene : public CSceneBase {

private:

	//! �^�C�g�����S
			CTexture*				m_pLogo;

	//! �I����
			CTexture*				m_pArrow;

	//! ���j���[�̃^�C�g��
			std::vector<CTexture*>	m_pMenuTitle;

	//! ���j���[�̃^�C�g���̍��W
			std::vector<Vector2>	m_MenuTitlePos;

	//! �^�C�g�����S�̍��W
			Vector2					m_LogoPos;

	//! �Z���N�g�ԍ�
			int						m_SelectNo;

	//! �X�N���[��
			int						m_Scrooll;

	//! ���̃V�[��
	const	std::vector<int>		m_NextSceneList = { CGameElement::SCENENO_GAME, CGameElement::SCENENO_OPTION, CGameElement::SCENENO_OPERATIONDESCRIPTION, CGameElement::SCENENO_EXIT };

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CTitleScene(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CTitleScene(void);

#pragma endregion		

#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return bool true ���� false ���s
		@details �^�C�g���V�[���̓ǂݍ���
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �^�C�g���V�[���̏��������s��
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �^�C�g���V�[���̍X�V���s��
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �^�C�g���V�[���̕`����s��
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �^�C�g���V�[���̉�����s��
	*/
	void	Release(void) override;

#pragma endregion

};