//*************************************************************************
//			ディーラー[CCroupiers.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			二重定義防止
//*************************************************************************
#ifndef _CCROUPIERS_H_
#define _CCROUPIERS_H_
#pragma once

//*************************************************************************
//			ファイルインクルード
//*************************************************************************
#include "main.h"

//*************************************************************************
//			クラス宣言
//*************************************************************************
class CCroupiers
{
public:
	CCroupiers() {};
	~CCroupiers() {};

	void Init();						// 初期化処理
	void Update();						// 更新処理
	void Draw();						// 描画処理

	void Point();						// 手札の点数出す処理

	void SetHands(char NewCard[]);		// 新しい手札用関数
	void SetCroupiersHands(int Hand)	// 手札枚数セット
	{ 
		m_nCroupiersHands = Hand;
	};

	// ディーラーの状態を返す
	TYPE GetCroupiersType() { return m_nCroupiersType; }
	// ディーラーの点数を返す
	int GetCroupiersPoint() { return m_nCroupiersPoints; }

private:
	int		m_nCroupiersHands;			// ディーラーの手札枚数
	char	m_cCroupiersHands[5][4];	// ディーラーの手札
	int		m_nCroupiersPoints;			// ディーラーの点数
	TYPE	m_nCroupiersType;			// ディーラーの状態

};


#endif // _CCROUPIERS_H_


