//*************************************************************************
//			�V�[���؂�ւ��}�V�[��[CSceneChanger.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			��d��`�h�~
//*************************************************************************
#ifndef _CSCENECHANGER_H_
#define _CSCENECHANGER_H_
#pragma once

//*************************************************************************
//			�t�@�C���C���N���[�h
//*************************************************************************
#include "CScene.h"

//*************************************************************************
//			�N���X�錾
//*************************************************************************
class CSceneChanger
{
public:
	// �R���X�g���N�^
	CSceneChanger();
	// �f�X�g���N�^
	~CSceneChanger();

	// �����������֐�
	virtual HRESULT Init(CScene *pScene);
	// �I�������֐�
	virtual void Uninit();
	// �X�V�����֐�
	virtual void Update();
	// �`�揈���֐�
	virtual void Draw();

	// �V�[���؂�ւ��֐�
	virtual void SceneChange(CScene *pNextScene);
	// ���݂̃V�[���擾�֐�
	virtual CScene *GetScene() { return m_pScene; }

private:
	CScene *m_pScene;
	CScene *m_pNextScene;

};

#endif // _CSCENECHANGER_H_
