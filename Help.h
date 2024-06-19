#pragma once

/**

	@file Help.h
	@brief �w���v
	@author �ؑ��J��
	@date 2019/11/20

*/

#include		"SceneBase.h"

class CHelp : public CSceneBase {

private:

	/**
	@enum tag_HELP
	�w���v�̗񋓒萔

	*/
	enum tag_HELP {

		HELP_PLAYER, HELP_BACKPLAYER, HELP_COUNT

	};

	//! ���̍��W
				Vector2							m_ArrowPos[HELP_COUNT];

	//! �w���v
	const		int		m_Help[HELP_COUNT] = { TEXTURE_HELP_IMAGE, TEXTURE_HELP_IMAGE2 };

	//! �y�[�W
				int		m_Page;

	//! ���̕���
	const		float	m_Arrow[HELP_COUNT] = { ARROW_RIGHT, ARROW_LEFT };

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CHelp(void);
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CHelp(void);

#pragma endregion		

#pragma region �֐�

	/**
		@brief Load
		@param �Ȃ�
		@return bool true ���� false ���s
		@details �w���v�̓ǂݍ���
	*/
	bool	Load(void);
	/**
		@brief Initialize
		@param �Ȃ�
		@return �Ȃ�
		@details �w���v�̏��������s��
	*/
	void	Initialize(void);
	/**
		@brief Update
		@param �Ȃ�
		@return �Ȃ�
		@details �w���v�̍X�V���s��
	*/
	void	Update(void);
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �w���v�̕`����s��
	*/
	void	Render(void);
	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �w���v�̉�����s��
	*/
	void	Release(void);
	/**
		@brief GamePadOperation
		@param �Ȃ�
		@return �Ȃ�
		@details �w���v�̑��쏈�����s��
	*/
	void	GamePadOperation(void);

#pragma endregion

};