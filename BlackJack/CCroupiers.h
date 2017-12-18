//*************************************************************************
//			�f�B�[���[[CCroupiers.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			��d��`�h�~
//*************************************************************************
#ifndef _CCROUPIERS_H_
#define _CCROUPIERS_H_
#pragma once

//*************************************************************************
//			�t�@�C���C���N���[�h
//*************************************************************************
#include "main.h"

//*************************************************************************
//			�N���X�錾
//*************************************************************************
class CCroupiers
{
public:
	CCroupiers() {};
	~CCroupiers() {};

	void Init();						// ����������
	void Update();						// �X�V����
	void Draw();						// �`�揈��

	void Point();						// ��D�̓_���o������

	void SetHands(char NewCard[]);		// �V������D�p�֐�
	void SetCroupiersHands(int Hand)	// ��D�����Z�b�g
	{ 
		m_nCroupiersHands = Hand;
	};

	// �f�B�[���[�̏�Ԃ�Ԃ�
	TYPE GetCroupiersType() { return m_nCroupiersType; }
	// �f�B�[���[�̓_����Ԃ�
	int GetCroupiersPoint() { return m_nCroupiersPoints; }

private:
	int		m_nCroupiersHands;			// �f�B�[���[�̎�D����
	char	m_cCroupiersHands[5][4];	// �f�B�[���[�̎�D
	int		m_nCroupiersPoints;			// �f�B�[���[�̓_��
	TYPE	m_nCroupiersType;			// �f�B�[���[�̏��

};


#endif // _CCROUPIERS_H_


