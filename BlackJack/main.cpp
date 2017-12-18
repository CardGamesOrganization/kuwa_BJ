//**************************************************************************
//			メイン[main.cpp]
//
//			Toshiki Kuwazoe
//			2017/8/20
//
//**************************************************************************

//**************************************************************************
//			インクルードファイル
//**************************************************************************
#include "main.h"
#include "CCard.h"
#include "CShuffle.h"
#include "CCroupiers.h"
#include "CPlayer.h"

//*************************************************************************
//			グローバル変数宣言
//*************************************************************************
char **MainCard;
int Player[HAND_MAX] = {};
int Enemy[HAND_MAX] = {};

CCard		*g_pCard		= NULL;			// CCardクラスの初期化
CShuffle	*g_pShuffle		= NULL;			// CShuffleクラスの初期化
CCroupiers	*g_pCroupiers	= NULL;			// CCroupiersクラスの初期化
CPlayer		*g_pPlayer		= NULL;			// CPlayerクラスの初期化
//**************************************************************************
//		メイン関数
//**************************************************************************
void main()
{
	// 山札から取った枚数をカウント
	int CardCnt = 0;

	// Cardクラスの生成
	g_pCard = new CCard();
	// Shuffleクラスの生成
//	g_pShuffle = new CShuffle();
	// CCroupiersクラスの生成
	g_pCroupiers = new CCroupiers();
	// 生成したら初期化！
	g_pCroupiers->Init();
	// CPlayerクラスの生成
	g_pPlayer = new CPlayer();
	// 生成したら初期化
	g_pPlayer->Init();

	// メモリを動的に確保
	MainCard = (char **)malloc(sizeof(char *) * CARD_MAX);
	for (int i = 0; i < CARD_MAX; i++)
	{
		MainCard[i] = (char *)malloc(sizeof(char) * 4);
	}

	// カードをシャッフルする
	g_pCard->CardShuffle( MainCard );

	// ディーラーに手札を渡す
	for (int i = 0; i < 2; i++)
	{
		g_pCroupiers->SetHands(MainCard[i]);
		CardCnt++;
	}
	// プレイヤーに手札を渡す
	for (int i = 0; i < 2; i++)
	{
		g_pPlayer->SetHands(MainCard[CardCnt + i]);
		CardCnt++;
	}

	// プレイヤーの点数
	g_pPlayer->Point();
	// プレイヤーの描画
	g_pPlayer->Draw();

	// ディーラーの点数
	g_pCroupiers->Point();
	// ディーラーの描画
	g_pCroupiers->Draw();

	// どちらもスタンド状態ではないなら
	while ((g_pPlayer->GetPlayerType() != TYPE_STAND) || 
			g_pCroupiers->GetCroupiersType() != TYPE_STAND)
	{
		// プレイヤーの更新
		g_pPlayer->Update();
		// ディーラーの更新
		g_pCroupiers->Update();

		// プレイヤーが「HIT」状態なら
		if ((g_pPlayer->GetPlayerType() == TYPE_HIT))
		{
			g_pPlayer->SetHands(MainCard[CardCnt + 1]);
			g_pPlayer->Point();
			CardCnt++;
		}

		// プレイヤーがバーストしたら
		if (g_pPlayer->GetPlayerType() == TYPE_BURST)
		{
			g_pPlayer->SetPlayerType(TYPE_BURST);
			g_pPlayer->Draw();
			break;
		}

		// ディーラーが「HIT」状態なら
		if ((g_pCroupiers->GetCroupiersType() == TYPE_HIT))
		{
			g_pCroupiers->SetHands(MainCard[CardCnt + 1]);
			g_pCroupiers->Point();
			CardCnt++;
		}

		// ディーラーがバーストしたら
		if (g_pCroupiers->GetCroupiersType() == TYPE_BURST)
		{
			g_pPlayer->SetPlayerType(TYPE_WIN);
			g_pPlayer->Draw();
			break;
		}

		// プレイヤーの描画
		g_pPlayer->Draw();
		// ディーラーの描画
		g_pCroupiers->Draw();
	}

	// バチバチの点数バトル！！！
	if ((g_pPlayer->GetPlayerType() == TYPE_STAND) &&
		g_pCroupiers->GetCroupiersType() == TYPE_STAND)
	{
		printf("「「どちらもスタンドしたので勝負！！！」」\n");

		// プレイヤーのが数値が大きい場合
		if (g_pPlayer->GetPlayerPoints() > g_pCroupiers->GetCroupiersPoint())
		{
			g_pPlayer->SetPlayerType(TYPE_WIN);
		}
		// 同点の場合
		else if (g_pPlayer->GetPlayerPoints() == g_pCroupiers->GetCroupiersPoint())
		{
			g_pPlayer->SetPlayerType(TYPE_DRAW);
		}
		// 負けの場合
		else
		{
			g_pPlayer->SetPlayerType(TYPE_LOSE);
		}

		g_pPlayer->Draw();
	}

	// 動的に確保した領域を開放する
	for (int i = 0; i < CARD_MAX; i++) free(MainCard[i]);
	free(MainCard);

	printf("終了します。エンターキーを押してください");
	rewind(stdin);
	getchar();

}

