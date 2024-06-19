#pragma once

/**

	@file Load.h
	@brief�@���\�[�X�̓ǂݍ���
	@author �ؑ��J��
	@date 2020/10/29

*/

#include	"Sound.h"

class CLoad : public CThread {

private:

	//! �e�N�X�`��
	CTexture*		m_Texture;

	//! �T�E���h
	CSoundBuffer*	m_Sound;

	//! ���[�h�̏��
	int				m_State;

	//! �ǂݍ��ݐ�
	int				m_LoadMaxCount;

	//! ���݂̓ǂݍ��ݐ�
	int				m_LoadCount;

	//! �ǂݍ��݂̐i�s�x
	int				m_LoadPercent;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CLoad(void) : m_Texture(new CTexture[CGameElement::TEXTURE_MAXCOUNT]), m_Sound(/*new CSoundBuffer[CGameElement::SOUND_TYPECOUNT]*/nullptr) { m_State = LOADING_NOW, m_LoadMaxCount = 0, m_LoadCount = 0, m_LoadPercent = 0; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CLoad(void) { ; }

#pragma endregion

#pragma region �֐�

	/**
		@brief Run
		@param �Ȃ�
		@return �Ȃ�
		@details �X���b�h���J�n����
	*/
	void	Run(void);
	/**
		@brief Load
		@param �Ȃ�
		@return �Ȃ�
		@details ���\�[�X�̓ǂݍ��݂��s��
	*/
	int		Load(void);
	/**
		@brief Render
		@param �Ȃ�
		@return �Ȃ�
		@details �ǂݍ��݂̕`����s��
	*/
	void	Render(void);

#pragma endregion

#pragma region �Q�b�^�[

	/**
		@brief GetTexturePointer
		@param �Ȃ�
		@return CTexture* �ǂݍ��񂾃e�N�X�`��
		@details �ǂݍ��񂾃e�N�X�`�����擾����
	*/
	CTexture*		GetTexturePointer(void) { return m_Texture; }
	/**
		@brief GetSoundPointer
		@param �Ȃ�
		@return CSoundBuffer* �ǂݍ��񂾃T�E���h
		@details �ǂݍ��񂾃T�E���h���擾����
	*/
	CSoundBuffer*	GetSoundPointer(void) { return m_Sound; }
	/**
		@brief GetState
		@param �Ȃ�
		@return int �ǂݍ��݂̏��
		@details �ǂݍ��݂̏�Ԃ��擾����
	*/
	int				GetState(void) { return m_State; }

#pragma endregion

	/**
	@enum tag_FINISHED
	�ǂݍ��݂̏�Ԃ̗񋓒萔

	*/
	typedef enum tag_FINISHED {

		LOADING_NOW,

		LOADING_FINISHED,

		LOADING_ERROR

	}LOAD_FINISHED_NO;

};