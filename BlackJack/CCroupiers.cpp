﻿//**************************************************************************
//			ディーラー[CCroupiers.cpp]
//
//			Toshiki Kuwazoe
//			2017/8/20
//
//**************************************************************************

//**************************************************************************
//			ファイルインクルード
//**************************************************************************
#include "CCroupiers.h"


//**************************************************************************
//			初期化処理関数
//**************************************************************************
void CCroupiers::Init()
{
	// ディーラーの手札枚数初期化
	m_nCroupiersHands = 0;

	// ディーラーの手札初期化
	m_cCroupiersHands[5][4] = {NULL};	// ぶっちゃけNULLは書かなくてもいいけどとりあえず書いちゃう💚

	// ディーラーの点数初期化
	m_nCroupiersPoints = 0;

	// ディーラーの状態初期化
	m_nCroupiersType = TYPE_NONE;
}

//**************************************************************************
//			更新処理関数
//**************************************************************************
void CCroupiers::Update()
{
	// ディーラーは無慈悲！！
	// 点数が「17」以上にならないとスタンドもできないッ！！
	if (m_nCroupiersPoints <= 17)
	{
		printf("ディーラー「責めます！！！」\n");
		m_nCroupiersType = TYPE_HIT;
	}
	else
	// それ以外は無条件で「スタンドッ！！！」
	{
		printf("ディーラー「やめまーす」\n");
		m_nCroupiersType = TYPE_STAND;
	}

	// 点数はとりあえず表示
	Point();


}

//**************************************************************************
//			描画処理関数
//**************************************************************************
void CCroupiers::Draw()
{
	// なんかいい感じで手札とかいろいろ表示
	printf("--------------------------------------------------------------\n");
	printf("ディーラー");

	if (m_nCroupiersType != TYPE_BURST)
	{
		// 手札に何があるか表示
		for (int i = 0; i < m_nCroupiersHands; i++)
		{
			printf(" [%s] | ", m_cCroupiersHands[i]);
		}

		// 点数を表示
		printf(" = %d", m_nCroupiersPoints);
	}
	else
	{
		printf("がバーストした！");
	}

	printf("\n--------------------------------------------------------------\n");
}

//**************************************************************************
//			手札の点数出す処理関数
//**************************************************************************
void CCroupiers::Point()
{
	int		nScoer = 0;			// 合計点数的なサムシング
	char	cNum[3];			// 手札の数値抜き取り用
	int		nNum[5];			// ↑をint型に変換したときの入れ物
	int		nACunt = 0;			// 「A」カウント用

	// とりあえず手札どんな感じか
	for (int i = 0; i < m_nCroupiersHands; i++)
	{
		// 数字部分だけ抜き取る
		for (int Cnt = 0; Cnt < 3; Cnt++)
		{
			cNum[Cnt] = m_cCroupiersHands[i][Cnt + 1];	// 柄を除外するために「+1」
		}

		// 絵柄なら「10」を入れる（アスキーコードの比較はこんな感じで書いてた気がする…ちょい不安…）
		if ( ( !strcmp(cNum, "J") ) ||
			 ( !strcmp(cNum, "Q") ) ||
			 ( !strcmp(cNum, "K") ) )
		{
			nNum[i] = 10;
		}
		// 「A」の場合
		else if (!strcmp(cNum, "A"))
		{
			nACunt++;
			nNum[i] = 1;	// 一旦、「1」足しとく
		}
		// 数字ならそのまま入れちゃう～
		else
		{
			// 計算できるようにintに変換
			nNum[i] = atoi(cNum);
		}

	}

	// 最終的な点数算出
	for (int i = 0; i < m_nCroupiersHands; i++)
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

		m_nCroupiersType = TYPE_BURST;		// バーストしたら「バースト」状態
	}

	// 変数に反映
	m_nCroupiersPoints = nScoer;
}

//**************************************************************************
//			手札セット処理関数
//**************************************************************************
void CCroupiers::SetHands(char NewCard[])
{
	// カードをセット
	strcpy(m_cCroupiersHands[m_nCroupiersHands] ,&NewCard[0]);

	// セットしたら手札増やす
	m_nCroupiersHands++;
}
