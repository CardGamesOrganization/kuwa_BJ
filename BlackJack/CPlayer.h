//*************************************************************************
//			プレイヤー[CPlayer.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			二重定義防止
//*************************************************************************
#ifndef _CPLAYER_H_
#define _CPLAYER_H_
#pragma once

//*************************************************************************
//			ファイルインクルード
//*************************************************************************
#include "main.h"

//*************************************************************************
//			クラス宣言
//*************************************************************************
class CPlayer
{
public:
	CPlayer() {};
	~CPlayer() {};

	void Init();						// 初期化処理
	void Update();						// 更新処理
	void Draw();						// 描画処理

	void Point();						// 手札の点数出す処理

	void SetHands(char NewCard[]);		// 新しい手札用関数
	void SetCroupiersHands(int Hand)	// 手札枚数セット
	{
		m_nPlayerHands = Hand;
	};

	// プレイヤーの状態を返す
	TYPE GetPlayerType() {	return m_nPlayerType;}
	// プレイヤーの状態設定
	void SetPlayerType(TYPE Type) { m_nPlayerType = Type; }
	// プレイヤーの点数取得関数
	int GetPlayerPoints() { return m_nPlayerPoints; }
	// プレイヤー名を返す関数
	char GetPlayerName() { return m_cPlayerName[0]; }

private:

	char	m_cPlayerName[256];			// プレイヤーの名前
	int		m_nPlayerHands;				// プレイヤーの手札枚数
	char	m_cPlayerHands[5][4];		// プレイヤーの手札
	int		m_nPlayerPoints;			// プレイヤーの点数
	TYPE	m_nPlayerType;				// プレイヤーの状態

};


#endif // _CPLAYER_H_