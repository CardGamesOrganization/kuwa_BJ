//**************************************************************************
//			�v���C���[[CPlayer.cpp]
//
//			Toshiki Kuwazoe
//			2017/8/20
//
//**************************************************************************

//**************************************************************************
//			�t�@�C���C���N���[�h
//**************************************************************************
#include "CPlayer.h"

//**************************************************************************
//			�����������֐�
//**************************************************************************
void CPlayer::Init()
{
	// �v���C���[�̖��O������
	m_cPlayerName[256] = { NULL };			// NULL�����Ȃ��Ă������̂ɏ������Ⴄ^�`

	// �v���C���[�̖��O���߂�I
	printf("�v���C���[�̖��O����͂��ĂˁI\n");
	scanf("%s", &m_cPlayerName);

	// �v���C���[�̎�D����������
	m_nPlayerHands = 0;

	// �v���C���[�̎�D������
	m_cPlayerHands[5][4] = { NULL };		// ����ς�NULL�����Ȃ��Ă������̂ɏ������Ⴄ^�`

	// �v���C���[�̓_��
	m_nPlayerPoints = 0;

	// �v���C���[�̏��
	m_nPlayerType = TYPE_NONE;

}

//**************************************************************************
//			�X�V�����֐�
//**************************************************************************
void CPlayer::Update()
{
	// �I�����p�ϐ�
	int nTypeNum = TYPE_NONE;
	// ���͂�����������͈ꐶ���͂�����c�I
	while ((nTypeNum == TYPE_NONE) )
	{
		// �v���C���[�ɂ́u�ӎv�v������b�I�I�I
		printf("%s�͂ǂ�����H\n", m_cPlayerName);
		printf("�q�b�g�F�u1�v�@�@�@�X�^���h�F�u2�v����͂��Ă�������");
		scanf("%d", &nTypeNum);

		// ���͂����������ꍇ
		if (nTypeNum <= 0 || nTypeNum >= 3)
		{
			printf("���͂��ꂽ�l�����������ł�\n");
			printf("������x���͂��Ă�������\n");

			nTypeNum = TYPE_NONE;
		}
		else
		{// ���ŁunTypeNum�v���um_nPlayerType�v�ɂ���Ă��������ǒ��J�ɂ����ĕ��򂳂���

			if (nTypeNum == TYPE_HIT)
			{
				m_nPlayerType = TYPE_HIT;
			}
			if (nTypeNum == TYPE_STAND)
			{
				m_nPlayerType = TYPE_STAND;
			}
		}
	}

	// �X�^���h��ԂȂ�
	if (m_nPlayerType == TYPE_STAND)
	{
		printf("%s�u�X�^���h�Ȃ��I�v\n", m_cPlayerName);
	}

	Point();

}

//**************************************************************************
//			�`�揈���֐�
//**************************************************************************
void CPlayer::Draw()
{

	// �Ȃ񂩂��������Ŏ�D�Ƃ����낢��\��
	printf("--------------------------------------------------------------\n");
	printf("%s", m_cPlayerName);

	switch (m_nPlayerType)
	{
	default:
		break;
	
	case TYPE_NONE:
			// ��D�ɉ������邩�\��
			for (int i = 0; i < m_nPlayerHands; i++)
			{
				printf(" [%s] | ", m_cPlayerHands[i]);
			}

			// �_����\��
			printf(" = %d", m_nPlayerPoints);
		break;

	case TYPE_HIT:
			// ��D�ɉ������邩�\��
			for (int i = 0; i < m_nPlayerHands; i++)
			{
				printf(" [%s] | ", m_cPlayerHands[i]);
			}

			// �_����\��
			printf(" = %d", m_nPlayerPoints);
		break;

	case TYPE_STAND:
			// ��D�ɉ������邩�\��
			for (int i = 0; i < m_nPlayerHands; i++)
			{
				printf(" [%s] | ", m_cPlayerHands[i]);
			}

			// �_����\��
			printf(" = %d", m_nPlayerPoints);
		break;

	case TYPE_BURST:
		// �_����\��
			printf("�̓_����21�_�𒴂��Ă��܂��o�[�X�g�����I\n");

			printf("%s�̕����c", m_cPlayerName);
		break;

	case TYPE_WIN:
			printf("�̓��_���f�B�[���[���������I\n%s�̏����I", m_cPlayerName);
		break;

	case TYPE_DRAW:
			printf("�̓��_�ƃf�B�[���[�̓��_�͓����I���������c�I", m_cPlayerName);
		break;

	case TYPE_LOSE:
			printf("�̓��_���f�B�[���[����������c\n%s�̕����c", m_cPlayerName);
		break;
	}
	printf("\n--------------------------------------------------------------\n");


}


//**************************************************************************
//			��D�̓_���o�������֐�
//**************************************************************************
void CPlayer::Point()
// �f�B�[���[�̂܂�܃R�s�y^^	���Ă��Ƃ͊֐��������ق���������ˁH^^
{
	int		nScoer = 0;			// ���v�_���I�ȃT���V���O
	char	cNum[3];			// ��D�̐��l�������p
	int		nNum[5];			// ����int�^�ɕϊ������Ƃ��̓��ꕨ
	int		nACunt = 0;			// �uA�v�J�E���g�p

	// �Ƃ肠������D�ǂ�Ȋ�����
	for (int i = 0; i < m_nPlayerHands; i++)
	{
		// �������������������
		for (int Cnt = 0; Cnt < 3; Cnt++)
		{
			cNum[Cnt] = m_cPlayerHands[i][Cnt + 1];	// �������O���邽�߂Ɂu+1�v
		}

		// �G���Ȃ�u10�v������
		if ((!strcmp(cNum, "J")) ||
			(!strcmp(cNum, "Q")) ||
			(!strcmp(cNum, "K")))
		{
			nNum[i] = 10;
		}
		// �uA�v�̏ꍇ
		else if (!strcmp(cNum, "A"))
		{
			nACunt++;
			nNum[i] = 1;	// ��U�A�u1�v�����Ƃ�
		}
		// �����Ȃ炻�̂܂ܓ����
		else
		{
			// �v�Z�ł���悤��int�ɕϊ�
			nNum[i] = atoi(cNum);
		}

	}

	// �ŏI�I�ȓ_���Z�o
	for (int i = 0; i < m_nPlayerHands; i++)
	{
		nScoer += nNum[i];
	}


	// �uA�v�J�E���^�[���u0�v����Ȃ��āA
	// ���_���u11�v�ȉ��Ȃ�uA�v�́u11�v�ɂȂ�b�I
	if (nACunt)
	{
		if (nScoer <= 11)
		{
			nScoer += 10;	// ��Łu1�v�͑����Ă��邩�炻�̎c��́u10�v�𑫂�
		}
	}

	// ������D���u22�v�ȏ�Ȃ�c
	if (nScoer >= 22)
	{
		nScoer = 0;		// �o�[�X�g�����U�R�̓_���́u0�v�ȉ����b�I�I�I

		m_nPlayerType = TYPE_BURST;		// �o�[�X�g������u�o�[�X�g�v���
	}

	// �ϐ��ɔ��f
	m_nPlayerPoints = nScoer;

}

//**************************************************************************
//			��D�̓_���o�������֐�
//**************************************************************************
void CPlayer::SetHands(char NewCard[])
// �f�B�[���[�̂܂�܃R�s�y^^	���Ă��Ƃ͊֐��������ق���������ˁH^^
{
	// �J�[�h���Z�b�g
	strcpy(m_cPlayerHands[m_nPlayerHands], &NewCard[0]);

	// �Z�b�g�������D���₷
	m_nPlayerHands++;

}