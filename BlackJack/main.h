//*************************************************************************
//			メイン[main.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************
#define _CRT_SECURE_NO_WARNINGS

//*************************************************************************
//			二重定義防止
//*************************************************************************
#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_


//*************************************************************************
//			ファイルインクルード
//*************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

//**************************************************************************
//			マクロ定義
//**************************************************************************
#define			SCREEN_WIDTH	(640)	// スクリーン横幅サイズの指定
#define			SCREEN_HEIGHT	(480)	// スクリーン縦幅サイズの指定
#define			CARD_MAX		(52)	// デッキのトランプの枚数
#define			HAND_MAX		(1)		// 手札の最高枚数

//*************************************************************************
//			列挙体定義
//*************************************************************************
// 状態の列挙
typedef enum
{
	TYPE_NONE = 0,
	TYPE_HIT,
	TYPE_STAND,
	TYPE_BURST,
	TYPE_WIN,
	TYPE_DRAW,
	TYPE_LOSE,
	TYPE_MAX
}TYPE;


#endif _MAIN_H_	// 二十定義防止終わり