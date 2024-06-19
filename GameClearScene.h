#pragma once

/**

	@file GameClearScene.h
	@brief �Q�[���N���A�V�[��
	@author �ؑ��J��
	@date 2019/11/20

*/

#include		"SceneBase.h"

class CGameClearScene : public CSceneBase {

private:

	//! ���̃V�[��
	const	std::vector<int>		m_NextSceneList = { CGameElement::SCENENO_TITLE };

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CGameClearScene(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CGameClearScene(void);

#pragma endregion		

#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return bool true ���� false ���s
		@details �Q�[���N���A�V�[���̓ǂݍ���
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���N���A�V�[���̏��������s��
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���N���A�V�[���̍X�V���s��
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���N���A�V�[���̕`����s��
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �Q�[���N���A�V�[���̉�����s��
	*/
	void	Release(void) override;

#pragma endregion

};