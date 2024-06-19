/**

	@file MotionManager.cpp
	@brief ���[�V�����̊Ǘ�
	@author �ؑ��J��
	@date 2019/12/21

*/

#include		"MotionManager.h"

CSpriteMotionController* CMotionManager::GetMotion(const int type) {


	switch (type)
	{
	case CGameElement::MOTION_SOUL:
	{
		SpriteAnimationCreate anim[] = {
			//�ҋ@
			{
				"�ҋ@",
				0,0,
				180,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0}}
			},

			//�ړ�
			{
				"�ړ�",
				0,256,
				180,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0}}
			},
			//�W�����v
			{
				"�W�����v",
				0,768,
				180,256,
				FALSE,{{10,0,0}}
			},
			//�_���[�W
			{
				"�_���[�W",
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
			//�ҋ@
			{
				"�ҋ@",
				0,512,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0}}
			},
			//�ړ�
			{
				"�ړ�",
				0,0,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//�W�����v
			{
				"�W�����v",
				0,1280,
				228,256,
				FALSE,{{10,0,0}}
			},
			//�_���[�W
			{
				"�_���[�W",
				0,1024,
				228,256,
				FALSE,{{10,0,0}}
			},
			//�U��
			{
				"�U��",
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
			//�ҋ@
			{
				"�ҋ@",
				0,0,
				200,127,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},

			//�ړ� MOVE
			{
				"�ړ�",
				0,127,
				200,127,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//�`���[�W CHARGE(2�b ��)
			{
				"�`���[�W",
				400,127,
				200,127,
				TRUE,{{120,0,0}}
			},
			//�ːi�U��
			{
				"�ːi",
				0,127,
				200,127,
				TRUE,{{1,0,0},{1,1,0},{1,2,0},{1,3,0},{1,4,0},{1,5,0}}
			},
			//�_���[�W
			{
				"�_���[�W",
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
			//�ҋ@
			{
				"�ҋ@",
				0,256,
				228,256,
				FALSE,{{5,0,0}}
			},
			//�ړ�
			{
				"�ړ�",
				0,0,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//�W�����v
			{
				"�W�����v",
				0,512,
				228,256,
				FALSE,{{10,0,0}}
			},
			//�^����
			{
				"�^����",
				0,768,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//�^���ҋ@��
			{
				"�^���ҋ@��",
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
			//�ҋ@
			{
				"�ҋ@",
				0,0,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}}
			},
			//�ړ�
			{
				"�ړ�",
				0, 512,
				228,256,
				TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
			},
			//�W�����v
			{
				"�W�����v",
				0,1280,
				228,256,
				FALSE,{{10,0,0}}
			},
			//�_���[�W
			{
				"�_���[�W",
				0,1024,
				228,256,
				FALSE,{{10,0,0}}
			},
			//�U��
			{
				"�U��",
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

			//�߈�
			{
				"�߈�",
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
			//�v���C���[���S
			{
				"�v���C���[���S",
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

			//�U���q�b�g
			{
				"�q�b�g",
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

			//�G�l�~�[���S
			{
				"�G�l�~�[���S",
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

			//�`���[�W�i�e�P�e�P�j
			{
				"�`���[�W",
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

	//�e�N�X�`���̉��
	for (int i = 0; i < CGameElement::MOTION_TYPECOUNT; i++) {

		for (int j = 0; j < m_pMotion[i].size(); j++) {

			m_pMotion[i][j]->Release();

			delete m_pMotion[i][j];

			m_pMotion[i][j] = nullptr;

		}

	}

}