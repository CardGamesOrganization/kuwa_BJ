//**************************************************************************
//			���C��[main.cpp]
//
//			Toshiki Kuwazoe
//			2017/8/20
//
//**************************************************************************

//**************************************************************************
//			�C���N���[�h�t�@�C��
//**************************************************************************
#include "main.h"
#include "CCard.h"
#include "CShuffle.h"
#include "CCroupiers.h"
#include "CPlayer.h"

//*************************************************************************
//			�O���[�o���ϐ��錾
//*************************************************************************
char **MainCard;
int Player[HAND_MAX] = {};
int Enemy[HAND_MAX] = {};

CCard		*g_pCard		= NULL;			// CCard�N���X�̏�����
CShuffle	*g_pShuffle		= NULL;			// CShuffle�N���X�̏�����
CCroupiers	*g_pCroupiers	= NULL;			// CCroupiers�N���X�̏�����
CPlayer		*g_pPlayer		= NULL;			// CPlayer�N���X�̏�����
//**************************************************************************
//		���C���֐�
//**************************************************************************
void main()
{
	// �R�D���������������J�E���g
	int CardCnt = 0;

	// Card�N���X�̐���
	g_pCard = new CCard();
	// Shuffle�N���X�̐���
//	g_pShuffle = new CShuffle();
	// CCroupiers�N���X�̐���
	g_pCroupiers = new CCroupiers();
	// ���������珉�����I
	g_pCroupiers->Init();
	// CPlayer�N���X�̐���
	g_pPlayer = new CPlayer();
	// ���������珉����
	g_pPlayer->Init();

	// �������𓮓I�Ɋm��
	MainCard = (char **)malloc(sizeof(char *) * CARD_MAX);
	for (int i = 0; i < CARD_MAX; i++)
	{
		MainCard[i] = (char *)malloc(sizeof(char) * 4);
	}

	// �J�[�h���V���b�t������
	g_pCard->CardShuffle( MainCard );

	// �f�B�[���[�Ɏ�D��n��
	for (int i = 0; i < 2; i++)
	{
		g_pCroupiers->SetHands(MainCard[i]);
		CardCnt++;
	}
	// �v���C���[�Ɏ�D��n��
	for (int i = 0; i < 2; i++)
	{
		g_pPlayer->SetHands(MainCard[CardCnt + i]);
		CardCnt++;
	}

	// �v���C���[�̓_��
	g_pPlayer->Point();
	// �v���C���[�̕`��
	g_pPlayer->Draw();

	// �f�B�[���[�̓_��
	g_pCroupiers->Point();
	// �f�B�[���[�̕`��
	g_pCroupiers->Draw();

	// �ǂ�����X�^���h��Ԃł͂Ȃ��Ȃ�
	while ((g_pPlayer->GetPlayerType() != TYPE_STAND) || 
			g_pCroupiers->GetCroupiersType() != TYPE_STAND)
	{
		// �v���C���[�̍X�V
		g_pPlayer->Update();
		// �f�B�[���[�̍X�V
		g_pCroupiers->Update();

		// �v���C���[���uHIT�v��ԂȂ�
		if ((g_pPlayer->GetPlayerType() == TYPE_HIT))
		{
			g_pPlayer->SetHands(MainCard[CardCnt + 1]);
			g_pPlayer->Point();
			CardCnt++;
		}

		// �v���C���[���o�[�X�g������
		if (g_pPlayer->GetPlayerType() == TYPE_BURST)
		{
			g_pPlayer->SetPlayerType(TYPE_BURST);
			g_pPlayer->Draw();
			break;
		}

		// �f�B�[���[���uHIT�v��ԂȂ�
		if ((g_pCroupiers->GetCroupiersType() == TYPE_HIT))
		{
			g_pCroupiers->SetHands(MainCard[CardCnt + 1]);
			g_pCroupiers->Point();
			CardCnt++;
		}

		// �f�B�[���[���o�[�X�g������
		if (g_pCroupiers->GetCroupiersType() == TYPE_BURST)
		{
			g_pPlayer->SetPlayerType(TYPE_WIN);
			g_pPlayer->Draw();
			break;
		}

		// �v���C���[�̕`��
		g_pPlayer->Draw();
		// �f�B�[���[�̕`��
		g_pCroupiers->Draw();
	}

	// �o�`�o�`�̓_���o�g���I�I�I
	if ((g_pPlayer->GetPlayerType() == TYPE_STAND) &&
		g_pCroupiers->GetCroupiersType() == TYPE_STAND)
	{
		printf("�u�u�ǂ�����X�^���h�����̂ŏ����I�I�I�v�v\n");

		// �v���C���[�̂����l���傫���ꍇ
		if (g_pPlayer->GetPlayerPoints() > g_pCroupiers->GetCroupiersPoint())
		{
			g_pPlayer->SetPlayerType(TYPE_WIN);
		}
		// ���_�̏ꍇ
		else if (g_pPlayer->GetPlayerPoints() == g_pCroupiers->GetCroupiersPoint())
		{
			g_pPlayer->SetPlayerType(TYPE_DRAW);
		}
		// �����̏ꍇ
		else
		{
			g_pPlayer->SetPlayerType(TYPE_LOSE);
		}

		g_pPlayer->Draw();
	}

	// ���I�Ɋm�ۂ����̈���J������
	for (int i = 0; i < CARD_MAX; i++) free(MainCard[i]);
	free(MainCard);

	printf("�I�����܂��B�G���^�[�L�[�������Ă�������");
	rewind(stdin);
	getchar();

}

