//**************************************************************************
//			プレイヤー[CPlayer.cpp]
//
//			Toshiki Kuwazoe
//			2017/8/20
//
//**************************************************************************

//**************************************************************************
//			ファイルインクルード
//**************************************************************************
#include "CPlayer.h"

//**************************************************************************
//			初期化処理関数
//**************************************************************************
void CPlayer::Init()
{
	// プレイヤーの名前初期化
	m_cPlayerName[256] = { NULL };			// NULL書かなくてもいいのに書いちゃう^～

	// プレイヤーの名前決める！
	printf("プレイヤーの名前を入力してね！\n");
	scanf("%s", &m_cPlayerName);

	// プレイヤーの手札枚数初期化
	m_nPlayerHands = 0;

	// プレイヤーの手札初期化
	m_cPlayerHands[5][4] = { NULL };		// やっぱりNULL書かなくてもいいのに書いちゃう^～

	// プレイヤーの点数
	m_nPlayerPoints = 0;

	// プレイヤーの状態
	m_nPlayerType = TYPE_NONE;

}

//**************************************************************************
//			更新処理関数
//**************************************************************************
void CPlayer::Update()
{
	// 選択肢用変数
	int nTypeNum = TYPE_NONE;
	// 入力おかしい限りは一生入力させる…！
	while ((nTypeNum == TYPE_NONE) )
	{
		// プレイヤーには「意思」があるッ！！！
		printf("%sはどうする？\n", m_cPlayerName);
		printf("ヒット：「1」　　　スタンド：「2」を入力してください");
		scanf("%d", &nTypeNum);

		// 入力がおかしい場合
		if (nTypeNum <= 0 || nTypeNum >= 3)
		{
			printf("入力された値がおかしいです\n");
			printf("もう一度入力してください\n");

			nTypeNum = TYPE_NONE;
		}
		else
		{// 直で「nTypeNum」を「m_nPlayerType」にいれても動くけど丁寧にあえて分岐させる

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

	// スタンド状態なら
	if (m_nPlayerType == TYPE_STAND)
	{
		printf("%s「スタンドなう！」\n", m_cPlayerName);
	}

	Point();

}

//**************************************************************************
//			描画処理関数
//**************************************************************************
void CPlayer::Draw()
{

	// なんかいい感じで手札とかいろいろ表示
	printf("--------------------------------------------------------------\n");
	printf("%s", m_cPlayerName);

	switch (m_nPlayerType)
	{
	default:
		break;
	
	case TYPE_NONE:
			// 手札に何があるか表示
			for (int i = 0; i < m_nPlayerHands; i++)
			{
				printf(" [%s] | ", m_cPlayerHands[i]);
			}

			// 点数を表示
			printf(" = %d", m_nPlayerPoints);
		break;

	case TYPE_HIT:
			// 手札に何があるか表示
			for (int i = 0; i < m_nPlayerHands; i++)
			{
				printf(" [%s] | ", m_cPlayerHands[i]);
			}

			// 点数を表示
			printf(" = %d", m_nPlayerPoints);
		break;

	case TYPE_STAND:
			// 手札に何があるか表示
			for (int i = 0; i < m_nPlayerHands; i++)
			{
				printf(" [%s] | ", m_cPlayerHands[i]);
			}

			// 点数を表示
			printf(" = %d", m_nPlayerPoints);
		break;

	case TYPE_BURST:
		// 点数を表示
			printf("の点数が21点を超えてしまいバーストした！\n");

			printf("%sの負け…", m_cPlayerName);
		break;

	case TYPE_WIN:
			printf("の得点がディーラーを上回った！\n%sの勝ち！", m_cPlayerName);
		break;

	case TYPE_DRAW:
			printf("の得点とディーラーの得点は同じ！引き分け…！", m_cPlayerName);
		break;

	case TYPE_LOSE:
			printf("の得点がディーラーを下回った…\n%sの負け…", m_cPlayerName);
		break;
	}
	printf("\n--------------------------------------------------------------\n");


}


//**************************************************************************
//			手札の点数出す処理関数
//**************************************************************************
void CPlayer::Point()
// ディーラーのまんまコピペ^^	ってことは関数分けたほうがいいよね？^^
{
	int		nScoer = 0;			// 合計点数的なサムシング
	char	cNum[3];			// 手札の数値抜き取り用
	int		nNum[5];			// ↑をint型に変換したときの入れ物
	int		nACunt = 0;			// 「A」カウント用

	// とりあえず手札どんな感じか
	for (int i = 0; i < m_nPlayerHands; i++)
	{
		// 数字部分だけ抜き取る
		for (int Cnt = 0; Cnt < 3; Cnt++)
		{
			cNum[Cnt] = m_cPlayerHands[i][Cnt + 1];	// 柄を除外するために「+1」
		}

		// 絵柄なら「10」を入れる
		if ((!strcmp(cNum, "J")) ||
			(!strcmp(cNum, "Q")) ||
			(!strcmp(cNum, "K")))
		{
			nNum[i] = 10;
		}
		// 「A」の場合
		else if (!strcmp(cNum, "A"))
		{
			nACunt++;
			nNum[i] = 1;	// 一旦、「1」足しとく
		}
		// 数字ならそのまま入れる
		else
		{
			// 計算できるようにintに変換
			nNum[i] = atoi(cNum);
		}

	}

	// 最終的な点数算出
	for (int i = 0; i < m_nPlayerHands; i++)
	{
		nScoer += nNum[i];
	}


	// 「A」カウンターが「0」じゃなくて、
	// 得点が「11」以下なら「A」は「11」になるッ！
	if (nACunt)
	{
		if (nScoer <= 11)
		{
			nScoer += 10;	// 上で「1」は足してあるからその残りの「10」を足す
		}
	}

	// もし手札が「22」以上なら…
	if (nScoer >= 22)
	{
		nScoer = 0;		// バーストしたザコの点数は「0」以下だッ！！！

		m_nPlayerType = TYPE_BURST;		// バーストしたら「バースト」状態
	}

	// 変数に反映
	m_nPlayerPoints = nScoer;

}

//**************************************************************************
//			手札の点数出す処理関数
//**************************************************************************
void CPlayer::SetHands(char NewCard[])
// ディーラーのまんまコピペ^^	ってことは関数分けたほうがいいよね？^^
{
	// カードをセット
	strcpy(m_cPlayerHands[m_nPlayerHands], &NewCard[0]);

	// セットしたら手札増やす
	m_nPlayerHands++;

}