/**

	@file SceneBase.cpp
	@brief �V�[���x�[�X
	@author �ؑ��J��
	@date 2019/12/20

*/

#include		"SceneBase.h"

void CSceneBase::FileDelete() {

	//�t�@�C���̍폜
	remove(SAVE_SCORE);
	remove(SAVE_SCORESTAGE1);
	remove(SAVE_SCORESTAGE2);
	remove(SAVE_SCORESTAGE3);
	remove(SAVE_SCORESTAGE4);
	remove(SAVE_SCORESTAGE5);
	remove(SAVE_SCORESTAGE6);
	remove(SAVE_STAGENAME);

}