/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

#include	"SceneBase.h"

#include	"TitleScene.h"

#include	"OptoinScene.h"

#include	"OperationDescriptionScene.h"

#include	"GameScene.h"

#include	"GameOverScene.h"

#include	"GameClearScene.h"

#include	"CreditScene.h"

#include	"Load.h"

#include	"Game.h"

//�x�[�X�V�[��
CSceneBase*				g_pScene = nullptr;

//���[�h
CLoad*					g_pLoad = nullptr;

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	
	//�t�H���_�̓ǂݍ���
	CUtilities::SetCurrentDirectoryA("Resource");

	//�J�[�\���̔�\��
	while (::ShowCursor(FALSE) > 0)
	{
		;
	}

	//�t���X�N���[��
	g_pGraphics->ChangeScreenMode();
	
	//���[�h�̐���
	g_pLoad = new CLoad();

	//���[�h�̊J�n
	g_pLoad->Run();

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//�L�[�̍X�V
	g_pInput->RefreshKey();

	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE)) {

		//�I���֐�
		PostQuitMessage(0);

	}

	if (g_pLoad != nullptr) {

		//���[�h�ɃG���[�����������ꍇ
		if (g_pLoad->GetState() == g_pLoad->LOADING_ERROR) {

			return TRUE;

		}

		//���[�h�����������ꍇ
		if (g_pLoad->GetState() == g_pLoad->LOADING_FINISHED) {

			//���[�h�������̂������n��
			g_pGame->GetTextureManager()->SetTexture(g_pLoad->GetTexturePointer());

			g_pGame->GetEffectManager()->SetTexture(&g_pLoad->GetTexturePointer()[CGameElement::TEXTURE_COUNT]);

			//g_pGame->GetSoundManager()->SetSound(g_pLoad->GetSoundPointer());

			g_pGame->GetSoundManager()->Initialize();

			g_pGame->GetEffectManager()->Initialize();

			//���[�h�̉��
			delete g_pLoad;

			g_pLoad = nullptr;

			//�V�[���̐���
			g_pScene = new CTitleScene();

			//�V�[���̏�����
			g_pScene->Initialize();

		}

	}

	//�V�[���̍X�V
	g_pScene->Update();

	//�T�E���h�̍X�V
	g_pGame->GetSoundManager()->Update();

	//�J�ڂ̍X�V
	g_pScene->GetTransition()->Update();

	//�V�[���ԍ��ɂ���čX�V
	if(g_pScene->GetTransition()->IsEnd())
	{

		int change = g_pScene->GetTransition()->GetNowScene();

		delete g_pScene;

		switch (change)
		{

		case CGameElement::SCENENO_TITLE:					g_pScene = new CTitleScene();					break;
		case CGameElement::SCENENO_GAME:					g_pScene = new CGameScene();					break;
		case CGameElement::SCENENO_OPTION:					g_pScene = new COptionScene();					break;
		case CGameElement::SCENENO_OPERATIONDESCRIPTION:	g_pScene = new COperationDescriptionScene();	break;
		case CGameElement::SCENENO_GAMEOVER:				g_pScene = new CGameOverScene();				break;
		case CGameElement::SCENENO_CREDIT:					g_pScene = new CCreditScene();					break;
		case CGameElement::SCENENO_GAMECLEAR:				g_pScene = new CGameClearScene();				break;

		}
		
		//�ύX�����V�[���̏�����
		g_pScene->Initialize();

		g_pScene->GetTransition()->Initialize();

	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);

	if (g_pLoad) {

		//���[�h�̕`��
		g_pLoad->Render();

	}
	else {

		//�V�[���̕`��
		g_pScene->Render();

		//�J�ڂ̕`��
		g_pScene->GetTransition()->Render();

	}
	
	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void){
	
	//�V�[���̉��
	if (g_pScene) {

		g_pScene->Release();

		delete g_pScene;

		g_pScene = nullptr;

	}

	//���[�h�̉��
	if (g_pLoad) {

		delete g_pLoad;

		g_pLoad = nullptr;

	}

	//�Q�[���V�X�e���ւ̃A�N�Z�X�̉��
	g_pGame->Release();

	return TRUE;

}