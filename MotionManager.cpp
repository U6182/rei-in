/**

	@file MotionManager.cpp
	@brief モーションの管理
	@author 木村憂哉
	@date 2019/12/21

*/

#include		"MotionManager.h"

CSpriteMotionController* CMotionManager::GetMotion(const int type) {


	switch (type)
	{
	case CGameElement::MOTION_SOUL:
	{
		SpriteAnimationCreate anim[] = {
			//待機
			{
				"待機",
				0,0,
				180,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0}}
			},

			//移動
			{
				"移動",
				0,256,
				180,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0}}
			},
			//ジャンプ
			{
				"ジャンプ",
				0,768,
				180,256,
				FALSE,{{10,0,0}}
			},
			//ダメージ
			{
				"ダメージ",
				0,512,
				180,256,
				FALSE,{{10,0,0}}
			},


		};

		AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_HANAKO:
	{

		SpriteAnimationCreate anim[] = {
			//待機
			{
				"待機",
				0,512,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0}}
			},
			//移動
			{
				"移動",
				0,0,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//ジャンプ
			{
				"ジャンプ",
				0,1280,
				228,256,
				FALSE,{{10,0,0}}
			},
			//ダメージ
			{
				"ダメージ",
				0,1024,
				228,256,
				FALSE,{{10,0,0}}
			},
			//攻撃
			{
				"攻撃",
				0,256,
				228,256,
				FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0}}
			},

		};

		AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_TEKETEKE:
	{

		SpriteAnimationCreate anim[] = {
			//待機
			{
				"待機",
				0,0,
				200,127,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},

			//移動 MOVE
			{
				"移動",
				0,127,
				200,127,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//チャージ CHARGE(2秒 仮)
			{
				"チャージ",
				400,127,
				200,127,
				TRUE,{{120,0,0}}
			},
			//突進攻撃
			{
				"突進",
				0,127,
				200,127,
				TRUE,{{1,0,0},{1,1,0},{1,2,0},{1,3,0},{1,4,0},{1,5,0}}
			},
			//ダメージ
			{
				"ダメージ",
				0,254,
				200,127,
				FALSE,{{10,0,0}}
			}
		};

		  AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_KINZIROU:
	{

		SpriteAnimationCreate anim[] = {
			//待機
			{
				"待機",
				0,256,
				228,256,
				FALSE,{{5,0,0}}
			},
			//移動
			{
				"移動",
				0,0,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//ジャンプ
			{
				"ジャンプ",
				0,512,
				228,256,
				FALSE,{{10,0,0}}
			},
			//運搬中
			{
				"運搬中",
				0,768,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//運搬待機中
			{
				"運搬待機中",
				0,1024,
				228,256,
				FALSE,{{10,0,0}}
			}

		};

		  AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_HUMANBODYMODLE:
	{

		SpriteAnimationCreate anim[] = {
			//待機
			{
				"待機",
				0,0,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}}
			},
			//移動
			{
				"移動",
				0, 512,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//ジャンプ
			{
				"ジャンプ",
				0,1280,
				228,256,
				FALSE,{{10,0,0}}
			},
			//ダメージ
			{
				"ダメージ",
				0,1024,
				228,256,
				FALSE,{{10,0,0}}
			},
			//攻撃
			{
				"攻撃",
				0,256,
				228,256,
				FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}}
			},

		};

		  AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_POSSESSION:
	{

		SpriteAnimationCreate anim[] = {

			//憑依
			{
				"憑依",
				0,0,
				256,256,
				FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			}

		};

		  AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_PLAYERDEAD:
	{

		SpriteAnimationCreate anim[] = {
			//プレイヤー死亡
			{
				"プレイヤー死亡",
				0,0,
				256,256,
				FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			}

		};

		  AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_ATTACK:
	{

		SpriteAnimationCreate anim[] = {

			//攻撃ヒット
			{
				"ヒット",
				0,0,
				64,64,
				FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0}}
			}

		};

		  AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_ENEMYDEAD:
	{

		SpriteAnimationCreate anim[] = {

			//エネミー死亡
			{
				"エネミー死亡",
				0,0,
				256,256,
				FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			}

		};

		  AddMotion(anim, _countof(anim));

	}
		break;

	case CGameElement::MOTION_CHARGE:
	{

		SpriteAnimationCreate anim[] = {

			//チャージ（テケテケ）
			{
				"チャージ",
				0,0,
				150,150,
				FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0}}
			}

		};

		  AddMotion(anim, _countof(anim));

	}
		break;
	
	}

	m_pMotion[type].push_back(new CSpriteMotionController());

	int size = m_pMotion[type].size() - 1;

	m_pMotion[type][size]->Create(&m_Anim[0], m_Anim.size());

	return m_pMotion[type][size];

}

void CMotionManager::AddMotion(SpriteAnimationCreate* anim, int animCount) {

	m_Anim.clear();

	for (int i = 0; i < animCount;i++) {

		m_Anim.push_back(anim[i]);

	}

}

void CMotionManager::Release() {

	//テクスチャの解放
	for (int i = 0; i < CGameElement::MOTION_TYPECOUNT; i++) {

		for (int j = 0; j < m_pMotion[i].size(); j++) {

			m_pMotion[i][j]->Release();

			delete m_pMotion[i][j];

			m_pMotion[i][j] = nullptr;

		}

	}

}