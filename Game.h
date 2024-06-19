#pragma once

/**

	@file Game.h
	@brief �Q�[���V�X�e���ւ̃A�N�Z�X
	@author �ؑ��J��
	@date 2020/10/13

*/

#include		"Controller.h"
#include		"TextureManager.h"
#include		"EffectManager.h"
#include		"FontManager.h"
#include		"SoundManager.h"
#include		"MotionManager.h"
#include		"Setting.h"

class CGame {

private:

	//! ���g�̃|�C���^
	static		CGame*				m_pInstance;

	//! �R���g���[���[
				CController*		m_pController;

	//! �e�N�X�`���}�l�[�W���[
				CTextureManager*	m_pTextureManager;

	//! �G�t�F�N�g�}�l�[�W���[
				CEffectManager*		m_pEffectManager;

	//! �t�H���g�}�l�[�W���[
				CFontManager*		m_pFontManager;

	//! �T�E���h�}�l�[�W���[
				CSoundManager*		m_pSoundManager;

	//! ���[�V�����}�l�[�W���[
				CMotionManager*		m_pMotionManager;

	//! �ݒ�
				CSetting*			m_pSetting;


#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CGame(void) : m_pController(nullptr), m_pTextureManager(nullptr), m_pEffectManager(nullptr), m_pFontManager(nullptr), m_pSoundManager(nullptr), m_pMotionManager(nullptr), m_pSetting(nullptr) { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CGame(void) { ; }

#pragma endregion

public:

#pragma region �֐�

	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details ���g�ƃ����o�̉�����s��
	*/
	void Release() {

		//�R���g���[���[�̉��
		if (m_pController) {

			delete m_pController;

			m_pController = nullptr;

		}

		//�e�N�X�`���}�l�[�W���[�̉��
		if (m_pTextureManager) {

			delete m_pTextureManager;

			m_pTextureManager = nullptr;

		}

		//�G�t�F�N�g�}�l�[�W���[�̉��
		if (m_pEffectManager) {

			delete m_pEffectManager;

			m_pEffectManager = nullptr;

		}
		
		//�t�H���g�}�l�[�W���[�̉��
		if (m_pFontManager) {

			delete m_pFontManager;

			m_pFontManager = nullptr;

		}

		//�T�E���h�}�l�[�W���[�̉��
		if (m_pSoundManager) {

			delete m_pSoundManager;

			m_pSoundManager = nullptr;

		}

		//���[�V�����}�l�[�W���[�̉��
		if (m_pMotionManager) {

			delete m_pMotionManager;

			m_pMotionManager = nullptr;

		}

		//�ݒ�̉��
		if (m_pSetting) {

			delete m_pSetting;

			m_pSetting = nullptr;

		}

		//���g�̉��
		if (m_pInstance) {

			delete m_pInstance;

			m_pInstance = nullptr;

		}

	}

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetInstance
		@param �Ȃ�
		@return CGame* ���g�̃C���X�^���X
		@details ���g�̃C���X�^���X���擾����
	*/
	static	CGame*	GetInstance(void) {

		if (m_pInstance == nullptr) {

			m_pInstance = new CGame();

		}

		return m_pInstance;

	}
	/**
		@brief GetController
		@param �Ȃ�
		@return CControllerr* �R���g���[���[
		@details �R���g���[���[���擾����
	*/
	CController*	GetController(void) {

		if (m_pController == nullptr) {

			m_pController = new CController();

		}

		return m_pController;

	}

	/**
		@brief GetTextureManager
		@param �Ȃ�
		@return CTextureManager* �e�N�X�`���}�l�[�W���[
		@details �e�N�X�`���}�l�[�W���[���擾����
	*/
	CTextureManager*	GetTextureManager(void) {

		if (m_pTextureManager == nullptr) {

			m_pTextureManager = new CTextureManager();

		}

		return m_pTextureManager;

	}

	/**
		@brief GetEffectManager
		@param �Ȃ�
		@return CEffectManager* �G�t�F�N�g�}�l�[�W���[
		@details �G�t�F�N�g�}�l�[�W���[���擾����
	*/
	CEffectManager*	GetEffectManager(void) {

		if (m_pEffectManager == nullptr) {

			m_pEffectManager = new CEffectManager();

		}

		return m_pEffectManager;

	}

	/**
		@brief GetFontManager
		@param �Ȃ�
		@return CFontManager* �t�H���g�}�l�[�W���[
		@details �t�H���g�}�l�[�W���[���擾����
	*/
	CFontManager*	GetFontManager(void) {

		if (m_pFontManager == nullptr) {

			m_pFontManager = new CFontManager();

		}

		return m_pFontManager;

	}

	/**
		@brief GetSoundManager
		@param �Ȃ�
		@return CSoundManager* �T�E���h�}�l�[�W���[
		@details �T�E���h�}�l�[�W���[���擾����
	*/
	CSoundManager*	GetSoundManager(void) {

		if (m_pSoundManager == nullptr) {

			m_pSoundManager = new CSoundManager();

		}

		return m_pSoundManager;

	}

	/**
		@brief GetMotionManager
		@param �Ȃ�
		@return CMotionManager* ���[�V�����}�l�[�W���[
		@details ���[�V�����}�l�[�W���[���擾����
	*/
	CMotionManager*	GetMotionManager(void) {

		if (m_pMotionManager == nullptr) {

			m_pMotionManager = new CMotionManager();

		}

		return m_pMotionManager;

	}

	/**
		@brief GetSetting
		@param �Ȃ�
		@return CSetting* �ݒ�
		@details �ݒ���擾����
	*/
	CSetting*	GetSetting(void) {

		if (m_pSetting == nullptr) {

			m_pSetting = new CSetting();

		}

		return m_pSetting;

	}

#pragma endregion

};

/**
	@def
	���g�̃C���X�^���X���O���[�o���Ƃ��Ēu������
*/
#define		g_pGame		CGame::GetInstance()