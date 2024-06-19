#pragma once

/**

	@file FontManager.h
	@brief �t�H���g�̊Ǘ�
	@author �ؑ��J��
	@date 2019/11/23

*/

#include		"GameElement.h"

class CFontManager {

private:

	//! �t�H���g
	std::map<int, CFont*>	m_Font;

public:

#pragma region �R���X�g���N�^ �f�X�g���N�^

	/**
		@brief �R���X�g���N�^
		@param �Ȃ�
		@details �������ɌĂяo���A�����o�̏��������s��
	*/
	CFontManager(void) : m_Font() { ; }
	/**
		@brief �f�X�g���N�^
		@param �Ȃ�
		@details ������ɌĂяo���A�����o�̉�����s��
	*/
	~CFontManager(void) { Release(); }

#pragma endregion		

#pragma region �֐�

	/**
		@brief Release
		@param �Ȃ�
		@return �Ȃ�
		@details �t�H���g�Ǝ��g�̉�����s��
	*/
	void	Release(void);
	/**
		@brief Length
		@param[in] str �������𒲂ׂ镶����
		@return int ������
		@details ������̕������𒲂ׂ�
	*/
	int		Length(const char* str);

#pragma endregion

#pragma region �Q�b�^�[

	
	/**
		@brief GetFont
		@param[in] size �t�H���g�̃T�C�Y
		@return CFont* �t�H���g�̃|�C���^
		@details �쐬�����t�H���g���擾����
	*/
	CFont*	GetFont(const int size);

#pragma endregion
	
};