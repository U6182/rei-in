#pragma once

/**

	@file GameElement.h
	@brief ゲームに必要な要素
	@author 木村憂哉
	@date 2020/10/13

*/

#include	"Utili.h"
#include	"Random.h"

class CGameElement {

public:

	//! エフェクト数
	static	constexpr	int		EFFECT_COUNT = 20;

	//! 重力
	static	constexpr	float	GRAVITY = 0.3f;

	//! プレイヤー攻撃時の停止時間
	static	constexpr	float	BREAKTIME = 0.2f;

	//! プレイヤーの移動
	static  constexpr	float	PLAYER_MOVE = 0.2f;

	//! 移動するのに必要なスティックの値
	static	constexpr	float	MOVE_STICK = 0.4f;

	//! リソースのファイル名
	static	constexpr	char*	g_FileName[]{

		//Textureのファイル名
		#pragma region タイトルシーン

		"TitleScene/TitleLogo.png",
		"TitleScene/TitleMenuGame.png",
		"TitleScene/TitleMenuOption.png",
		"TitleScene/TitleMenuOperationDescription.png",
		"TitleScene/TitleMenuExit.png",
		"TitleScene/TitleMenuGame_Select.png",
		"TitleScene/TitleMenuOption_Select.png",
		"TitleScene/TitleMenuOperationDescription_Select.png",
		"TitleScene/TitleMenuExit_Select.png",
		"TitleScene/Arrow.png",

		#pragma endregion

		#pragma region オプションシーン

		"OptionScene/OptionMenuVibration_ON.png",
		"OptionScene/OptionMenuVibration_OFF.png",

		#pragma endregion

		#pragma region 操作説明シーン

		"OperationDescriptionScene/OperationDescriptionSoulBackImage.png",
		"OperationDescriptionScene/OperationDescriptionHanakoBackImage.png",
		"OperationDescriptionScene/OperationDescriptionTekeTekeBackImage.png",
		"OperationDescriptionScene/OperationDescriptionKinzirouBackImage.png",
		"OperationDescriptionScene/OperationDescriptionHumanBodyModleBackImage.png",

		#pragma endregion

		#pragma region ゲーム

		"GameScene/Stage/StageBackImage.jpg",
		"GameScene/Stage/StageChip.png",

		"GameScene/Player/Soul.png",

		"GameScene/Enemy/Hanako.png",
		"GameScene/Enemy/TekeTeke.png",
		"GameScene/Enemy/Kinzirou.png",
		"GameScene/Enemy/HumanBodyModle.png",

		"GameScene/Item/Piano.png",
		"GameScene/Item/Charm.png",
		"GameScene/Item/Beethoven.png",
		"GameScene/Item/ClearGhost.png",

		"GameScene/Weapon/Viscera.png",

		"GameScene/UI/Number.png",
		"GameScene/UI/NumberFrame.png",
		"GameScene/UI/NegativeSymbol.png",

		#pragma endregion

		#pragma region ゲームオーバー

		"GameOverScene/GameOverBackImage.png",

		#pragma endregion

		#pragma region ゲームクリア

		"GameClearScene/GameClearBackImage.png",

		#pragma endregion

		//Effectのファイル名
		"Effect/Soul/Possession.png",
		"Effect/Soul/PlayerDead.png",

		"Effect/Enemy/Attack.png",
		"Effect/Enemy/EnemyDead.png",

		"Effect/TekeTeke/ChargeStage1.png",
		"Effect/TekeTeke/ChargeStage2.png",
		"Effect/TekeTeke/ChargeStage3.png",
		"Effect/TekeTeke/ChargeStage4.png",
		"Effect/TekeTeke/ChargeStage5.png",

		//Soundのファイル名
		#pragma region タイトルシーン

		#pragma endregion

		#pragma region オプションシーン

		#pragma endregion

		#pragma region 操作説明シーン

		#pragma endregion

		#pragma region ゲームシーン

			"GameScene/GameBGM.mp3",
			"GameScene/TimeFaster.mp3",
			"GameScene/HanakoAttack.mp3",
			"GameScene/ChargeAttack.mp3",
			"GameScene/BodyAttack.mp3",
			"GameScene/PianoPlay.mp3",
			"GameScene/Damage.mp3",

		#pragma endregion

		#pragma region ゲームオーバー

		#pragma endregion

		//"",

		nullptr

	};

	/**
	@enum tag_TEXTURE
	テクスチャの種類の列挙定数

	*/
	typedef enum tag_TEXTURE {

		//Texture
		#pragma region タイトルシーン

				TEXTURE_TITEL_LOGO,
				TEXTURE_TITEL_MENU_GAME,
				TEXTURE_TITEL_MENU_OPTION,
				TEXTURE_TITEL_MENU_OPERATIONDESCRIPTION,
				TEXTURE_TITEL_MENU_EXIT,
				TEXTURE_TITEL_MENU_GAME_SELECT,
				TEXTURE_TITEL_MENU_OPTION_SELECT,
				TEXTURE_TITEL_MENU_OPERATIONDESCRIPTION_SELECT,
				TEXTURE_TITEL_MENU_EXIT_SELECT,
				TEXTURE_ARROW,

		#pragma endregion

		#pragma region オプションシーン

				TEXTURE_OPTION_MENU_VIBRATION_ON,
				TEXTURE_OPTION_MENU_VIBRATION_OFF,

		#pragma endregion

		#pragma region 操作説明シーン

				TEXTURE_OPERATIONDESCRIPTION_SOUL_BACKIMAGE,
				TEXTURE_OPERATIONDESCRIPTION_HANAKO_BACKIMAGE,
				TEXTURE_OPERATIONDESCRIPTION_TEKETEKE_BACKIMAGE,
				TEXTURE_OPERATIONDESCRIPTION_KINZIROU_BACKIMAGE,
				TEXTURE_OPERATIONDESCRIPTION_HUMANBODYMODLE_BACKIMAGE,

		#pragma endregion

		#pragma region ゲームシーン

				TEXTURE_GAME_STAGE_BACKIMAGE,
				TEXTURE_GAME_STAGECHIP,

				TEXTURE_GAME_SOUL,

				TEXTURE_GAME_HANAKO,
				TEXTURE_GAME_TEKETEKE,
				TEXTURE_GAME_KINZIROU,
				TEXTURE_GAME_HUMANBODYMODLE,

				TEXTURE_GAME_PIANO,
				TEXTURE_GAME_CHARM,
				TEXTURE_GAME_BEETHOVEN,
				TEXTURE_GAME_CLEARGHOST,

				TEXTURE_GAME_VISCERA,

				TEXTURE_GAME_NUMBER,
				TEXTURE_GAME_NUMBERFRAME,
				TEXTURE_GAME_NEGATIVESYMBOL,

		#pragma endregion


		#pragma region ゲームオーバー

				TEXTURE_GAMEOVER_BACKIMAGE,

		#pragma endregion

		#pragma region ゲームクリア

				TEXTURE_GAMECLEAR_BACKIMAGE,

		#pragma endregion

		TEXTURE_COUNT,
		EFFECTTEXTURE_SOUL_POSSESSION,
		EFFECTTEXTURE_SOUL_PLAYERDEAD,

		EFFECTTEXTURE_ENEMY_ATTACK,
		EFFECTTEXTURE_ENEMY_ENEMYDEAD,

		EFFECTTEXTURE_TEKETEKE_CHARGESTAGE1,
		EFFECTTEXTURE_TEKETEKE_CHARGESTAGE2,
		EFFECTTEXTURE_TEKETEKE_CHARGESTAGE3,
		EFFECTTEXTURE_TEKETEKE_CHARGESTAGE4,
		EFFECTTEXTURE_TEKETEKE_CHARGESTAGE5,

		//Effect
		EFFECTTEXTURE_COUNT,

		//Textureカウント
		TEXTURE_MAXCOUNT = EFFECTTEXTURE_COUNT

	}TEXTURE_NAME;

	/**
	@enum tag_EFFECT
	エフェクト種類の列挙定数

	*/
	enum tag_EFFECT {
		EFFECT_SOUL_POSSESSION,
		EFFECT_SOUL_PLAYERDEAD,

		EFFECT_ENEMY_ATTACK,
		EFFECT_ENEMY_ENEMYDEAD,

		EFFECT_TEKETEKE_CHARGESTAGE1,
		EFFECT_TEKETEKE_CHARGESTAGE2,
		EFFECT_TEKETEKE_CHARGESTAGE3,
		EFFECT_TEKETEKE_CHARGESTAGE4,
		EFFECT_TEKETEKE_CHARGESTAGE5,
		//エフェクト
		EFFECT_TYPE_COUNT,

	};

	/**
	@enum tag_SOUNDTYPE
	サウンドの種類の列挙定数

	*/
	typedef enum tag_SOUNDTYPE {

		#pragma region タイトルシーン

		#pragma endregion

		#pragma region オプションシーン

		#pragma endregion

		#pragma region 操作説明シーン

		#pragma endregion

		#pragma region ゲームシーン

		SOUND_BGM_GAME,
		SOUND_SE_TIMEFASTER,
		SOUND_SE_HANAKOATTACK,
		SOUND_SE_CHARGEATTACK,
		SOUND_SE_BODYATTACK,
		SOUND_SE_PIANOPLAY,
		SOUND_SE_DAMAGE,

		#pragma endregion

		#pragma region ゲームオーバー

		#pragma endregion
		
		SOUND_TYPECOUNT,

	}SOUNDTYPE_NAME;

	/**
	@enum tag_SOUNDSTOPTYPE
	サウンドの停止の種類の列挙定数

	*/
	enum tag_SOUNDSTOPTYPE {

		STOP_SUDDEN, STOP_GRADUALLY,

	};

	/**
	@enum tag_FONTSIZE
	フォントのサイズの列挙定数

	*/
	enum tag_FONTSIZE {

		FONTSIZE_20 = 20, FONTSIZE_21, FONTSIZE_22, FONTSIZE_23, FONTSIZE_24, FONTSIZE_25, FONTSIZE_26, FONTSIZE_27, FONTSIZE_28, FONTSIZE_29,
		FONTSIZE_30, FONTSIZE_31, FONTSIZE_32, FONTSIZE_33, FONTSIZE_34, FONTSIZE_35, FONTSIZE_36, FONTSIZE_37, FONTSIZE_38, FONTSIZE_39,

	};

	/**
	@enum tag_MOTIONTYPE
	アニメモーションの列挙定数

	*/
	typedef enum tag_MOTIONTYPE {

		MOTION_SOUL,
		MOTION_HANAKO,
		MOTION_TEKETEKE,
		MOTION_KINZIROU,
		MOTION_HUMANBODYMODLE,

		MOTION_POSSESSION,
		MOTION_PLAYERDEAD,

		MOTION_ATTACK,
		MOTION_ENEMYDEAD,

		MOTION_CHARGE,

		MOTION_TYPECOUNT,

	}MOTIONTYPE_NAME;

	/**
	@enum tag_PLAYERSTATE
	プレイヤーの状態の列挙定数

	*/
	typedef enum tag_PLAYERSTATE {

		PLAYER_SOUL,
		PLAYER_HANAKO,
		PLAYER_TEKETEKE,
		PLAYER_KINZIROU,
		PLAYER_HUMANBODYMODLE,
		PLAYER_COUNT,

	}PLAYERSTATE_NAME;

	/**
	@enum tag_POSSESSION_MODE
	憑依状態の列挙定数

	*/
	enum tag_POSSESSION_MODE {

		POSSESSION_NOTMODE,
		POSSESSION_MODE,
		POSSESSION_BEHAVIOR,
		POSSESSION_BEHAVIOREND,
		POSSESSION_NOW,

	};

	/**
	@enum tag_PLAYEROPERATION
	プレイヤーの状態の列挙定数

	*/
	typedef enum tag_PLAYEROPERATION {

		PLAYER_OPERATION_MOVE,
		PLAYER_OPERATION_JUMP,
		PLAYER_OPERATION_POSSESSION,
		PLAYER_OPERATION_POSSESSIONLIFTED,
		PLAYER_OPERATION_ATTACK,
		PLAYER_OPERATION_CHARGE,
		PLAYER_OPERATION_CHARGEATTACK,
		PLAYER_OPERATION_CHARGEATTACKSTOP,
		PLAYER_OPERATION_BODYATTACK,
		PLAYER_OPERATION_CARRY,
		PLAYER_OPERATION_COUNT,

	}PLAYEROPERATION_NAME;

	/**
	@enum tag_PLAYER_MAXMOVESTATE
	プレイヤーの状態の最大移動量列挙定数

	*/
	typedef enum tag_PLAYER_MAXMOVESTATE {

		PLAYER_MAXMOVE_SOUL = 5,
		PLAYER_MAXMOVE_HANAKO = 3,
		PLAYER_MAXMOVE_TEKETEKE = 4,
		PLAYER_MAXMOVE_KINZIROU = 3,
		PLAYER_MAXMOVE_HUMANBODYMODLE = 2,
		PLAYER_MAXMOVE_COUNT,

	}PLAYER_MAXMOVESTATE_NAME;

	/**
	@enum tag_PLAYER_ATTACKSTATE
	プレイヤーの攻撃状態の列挙定数

	*/
	typedef enum tag_PLAYER_ATTACKSTATE {

		PLAYER_ATTACKSTATE_NOT,
		PLAYER_ATTACKSTATE_ATTACK,
		PLAYER_ATTACKSTATE_ATTACKLATE,

	}PLAYER_ATTACKSTATE_NAME;

	/**
	@enum tag_ENEMY_HP
	敵のHP列挙定数

	*/
	typedef enum tag_ENEMY_HP {

		ENEMY_HP_HANAKO = 10,
		ENEMY_HP_TEKETEKE = 1,
		ENEMY_HP_KINZIROU = 1,
		ENEMY_HP_HUMANBODYMODLE = 8,
		ENEMY_HP_COUNT,

	}ENEMY_HP_NAME;

	/**
	@enum tag_ENEMY_ATTACKPOINT
	敵の攻撃力列挙定数

	*/
	typedef enum tag_ENEMY_ATTACKPOINT {

		ENEMY_ATTACKPOINT_HANAKO = 2,
		ENEMY_ATTACKPOINT_TEKETEKE = 1,
		ENEMY_ATTACKPOINT_KINZIROU = 0,
		ENEMY_ATTACKPOINT_HUMANBODYMODLE = 2,
		ENEMY_ATTACKPOINT_COUNT,

	}ENEMY_ATTACKPOINT_NAME;

	/**
	@enum tag_GAMESTATE
	ゲームシーンの状態の列挙定数

	*/
	typedef enum tag_GAMESTATE {

		GAME_GAMEOVER,
		GAME_GAMECLEAR,
		GAME_RUN,
		GAME_MENU,

	}GAMESTATE_NAME;

	/**
	@enum tag_CONTROLLER
	コントローラーの状態の列挙定数

	*/
	typedef enum tag_CONTROLLER {

		CONTROLLER_A,
		CONTROLLER_B,
		CONTROLLER_PULL_B,
		CONTROLLER_HOLD_B,
		CONTROLLER_X,
		CONTROLLER_HOLD_X,
		CONTROLLER_Y,
		CONTROLLER_STICK,
		CONTROLLER_START,
		CONTROLLER_BACK,
		CONTROLLER_RT,
		CONTROLLER_LT,
		CONTROLLER_KEY_LEFT,
		CONTROLLER_KEY_RIGHT,
		CONTROLLER_KEY_UP,
		CONTROLLER_KEY_DOWN,
		CONTROLLER_COUNT,


	}CONTROLLER_NAME;

	/**
	@enum tag_ENEMY
	敵の列挙定数

	*/
	typedef enum tag_ENEMY {

		ENEMY_HANAKO,
		ENEMY_TEKETEKE,
		ENEMY_KINZIROU,
		ENEMY_HUMANBODYMODLE_DIAGONAL,
		ENEMY_HUMANBODYMODLE_DOWN,

	}ENEMY_NAME;

	/**
	@enum tag_ITEM
	アイテムの列挙定数

	*/
	typedef enum tag_ITEM {

		ITEM_PIANO,
		ITEM_CHARM,
		ITEM_BEETHOVEN,
		ITEM_CLEARGHOST,

	}ITEM_NAME;

	/**
	@enum tag_STAGE_SCENE
	各シーンの遷移用列挙定数

	*/
	enum tag_STAGE_SCNEN {

		SCENENO_TITLE, SCENENO_GAME, SCENENO_GAMEOVER, SCENENO_CREDIT, SCENENO_GAMECLEAR, SCENENO_OPTION, SCENENO_OPERATIONDESCRIPTION, SCENENO_EXIT

	};

};