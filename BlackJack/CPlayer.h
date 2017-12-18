//*************************************************************************
//			�v���C���[[CPlayer.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			��d��`�h�~
//*************************************************************************
#ifndef _CPLAYER_H_
#define _CPLAYER_H_
#pragma once

//*************************************************************************
//			�t�@�C���C���N���[�h
//*************************************************************************
#include "main.h"

//*************************************************************************
//			�N���X�錾
//*************************************************************************
class CPlayer
{
public:
	CPlayer() {};
	~CPlayer() {};

	void Init();						// ����������
	void Update();						// �X�V����
	void Draw();						// �`�揈��

	void Point();						// ��D�̓_���o������

	void SetHands(char NewCard[]);		// �V������D�p�֐�
	void SetCroupiersHands(int Hand)	// ��D�����Z�b�g
	{
		m_nPlayerHands = Hand;
	};

	// �v���C���[�̏�Ԃ�Ԃ�
	TYPE GetPlayerType() {	return m_nPlayerType;}
	// �v���C���[�̏�Ԑݒ�
	void SetPlayerType(TYPE Type) { m_nPlayerType = Type; }
	// �v���C���[�̓_���擾�֐�
	int GetPlayerPoints() { return m_nPlayerPoints; }
	// �v���C���[����Ԃ��֐�
	char GetPlayerName() { return m_cPlayerName[0]; }

private:

	char	m_cPlayerName[256];			// �v���C���[�̖��O
	int		m_nPlayerHands;				// �v���C���[�̎�D����
	char	m_cPlayerHands[5][4];		// �v���C���[�̎�D
	int		m_nPlayerPoints;			// �v���C���[�̓_��
	TYPE	m_nPlayerType;				// �v���C���[�̏��

};


#endif // _CPLAYER_H_