#pragma once

/**

	@file OperationDescriptionScene.h
	@brief ��������V�[��
	@author �ؑ��J��
	@date 2019/11/20

*/

#include		"SceneBase.h"

class COperationDescriptionScene : public CSceneBase {

private:

	//! �w�i�̃e�N�X�`���|�C���^
			std::vector<CTexture*>		m_pTextureList;

			//! �Z���N�g�ԍ�
			int							m_SelectNo;

	//! ���̃V�[��
	const	std::vector<int>			m_NextSceneList = { CGameElement::SCENENO_TITLE, CGameElement::SCENENO_TITLE, CGameElement::SCENENO_TITLE, CGameElement::SCENENO_TITLE, CGameElement::SCENENO_TITLE };

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	COperationDescriptionScene(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~COperationDescriptionScene(void);

#pragma endregion		

#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return bool true ���� false ���s
		@details ��������V�[���̓ǂݍ���
	*/
	bool	Load(void) override;
	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details ��������V�[���̏��������s��
	*/
	void	Initialize(void) override;
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details ��������V�[���̍X�V���s��
	*/
	void	Update(void) override;
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details ��������V�[���̕`����s��
	*/
	void	Render(void) override;
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details ��������V�[���̉�����s��
	*/
	void	Release(void) override;

#pragma endregion

};