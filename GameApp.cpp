/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
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

//ベースシーン
CSceneBase*				g_pScene = nullptr;

//ロード
CLoad*					g_pLoad = nullptr;

/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	
	//フォルダの読み込み
	CUtilities::SetCurrentDirectoryA("Resource");

	//カーソルの非表示
	while (::ShowCursor(FALSE) > 0)
	{
		;
	}

	//フルスクリーン
	g_pGraphics->ChangeScreenMode();
	
	//ロードの生成
	g_pLoad = new CLoad();

	//ロードの開始
	g_pLoad->Run();

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//キーの更新
	g_pInput->RefreshKey();

	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE)) {

		//終了関数
		PostQuitMessage(0);

	}

	if (g_pLoad != nullptr) {

		//ロードにエラーが発生した場合
		if (g_pLoad->GetState() == g_pLoad->LOADING_ERROR) {

			return TRUE;

		}

		//ロードが完了した場合
		if (g_pLoad->GetState() == g_pLoad->LOADING_FINISHED) {

			//ロードしたものを引き渡す
			g_pGame->GetTextureManager()->SetTexture(g_pLoad->GetTexturePointer());

			g_pGame->GetEffectManager()->SetTexture(&g_pLoad->GetTexturePointer()[CGameElement::TEXTURE_COUNT]);

			//g_pGame->GetSoundManager()->SetSound(g_pLoad->GetSoundPointer());

			g_pGame->GetSoundManager()->Initialize();

			g_pGame->GetEffectManager()->Initialize();

			//ロードの解放
			delete g_pLoad;

			g_pLoad = nullptr;

			//シーンの生成
			g_pScene = new CTitleScene();

			//シーンの初期化
			g_pScene->Initialize();

		}

	}

	//シーンの更新
	g_pScene->Update();

	//サウンドの更新
	g_pGame->GetSoundManager()->Update();

	//遷移の更新
	g_pScene->GetTransition()->Update();

	//シーン番号によって更新
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
		
		//変更したシーンの初期化
		g_pScene->Initialize();

		g_pScene->GetTransition()->Initialize();

	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);

	if (g_pLoad) {

		//ロードの描画
		g_pLoad->Render();

	}
	else {

		//シーンの描画
		g_pScene->Render();

		//遷移の描画
		g_pScene->GetTransition()->Render();

	}
	
	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void){
	
	//シーンの解放
	if (g_pScene) {

		g_pScene->Release();

		delete g_pScene;

		g_pScene = nullptr;

	}

	//ロードの解放
	if (g_pLoad) {

		delete g_pLoad;

		g_pLoad = nullptr;

	}

	//ゲームシステムへのアクセスの解放
	g_pGame->Release();

	return TRUE;

}