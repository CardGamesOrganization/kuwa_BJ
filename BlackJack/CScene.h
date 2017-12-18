//*************************************************************************
//			シーン統括[CScene.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			二重定義防止
//*************************************************************************
#ifndef _CSCENE_H_
#define _CSCENE_H_
#pragma once

//*************************************************************************
//			ファイルインクルード
//*************************************************************************
#include "main.h"

//*************************************************************************
//			列挙体定義
//*************************************************************************
// シーンの定義
// いつもは「PHASE」って書くけど流行りわかんないし今回は「SCENE」
// なんちゃってUnityｗｗｗ
enum SCENE_MODE 
{
	SCENE_MODE_NONE = 0,
	SCENE_MODE_TITLE,
	SCENE_MODE_GAME,
	SCENE_MODE_RESULT,
	SCENE_MODE_MAX,
};

//*************************************************************************
//			前方宣言
//*************************************************************************
class CSceneChanger;

//*************************************************************************
//			クラス宣言
//*************************************************************************
class CScene
{
public:

	// コンストラクタ
	CScene(CSceneChanger *pSceneChanger) : m_pSceneChanger(pSceneChanger) {}
	// デストラクタ
	~CScene();
	// 初期化処理関数
	virtual HRESULT Init(void) = 0;
	// 終了処理関数
	virtual void Uninit(void) = 0;
	// 更新処理関数
	virtual void Update(void) = 0;
	// 描画処理関数
	virtual void Draw(void) = 0;

	// フェーズモードの取得
		virtual SCENE_MODE GetMode() { return m_nSceneMode; }
	// フェーズモードのセット
	virtual void SetMode(SCENE_MODE nPhaseMode) { m_nSceneMode = nPhaseMode; }

private:
	CSceneChanger *m_pSceneChanger;
	SCENE_MODE m_nSceneMode;

};

#endif // _CSCENE_H_