//*************************************************************************
//			シーン切り替えマシーン[CSceneChanger.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			二重定義防止
//*************************************************************************
#ifndef _CSCENECHANGER_H_
#define _CSCENECHANGER_H_
#pragma once

//*************************************************************************
//			ファイルインクルード
//*************************************************************************
#include "CScene.h"

//*************************************************************************
//			クラス宣言
//*************************************************************************
class CSceneChanger
{
public:
	// コンストラクタ
	CSceneChanger();
	// デストラクタ
	~CSceneChanger();

	// 初期化処理関数
	virtual HRESULT Init(CScene *pScene);
	// 終了処理関数
	virtual void Uninit();
	// 更新処理関数
	virtual void Update();
	// 描画処理関数
	virtual void Draw();

	// シーン切り替え関数
	virtual void SceneChange(CScene *pNextScene);
	// 現在のシーン取得関数
	virtual CScene *GetScene() { return m_pScene; }

private:
	CScene *m_pScene;
	CScene *m_pNextScene;

};

#endif // _CSCENECHANGER_H_
