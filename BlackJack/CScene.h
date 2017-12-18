//*************************************************************************
//			�V�[������[CScene.h]
//			Toshiki Kuwazoe
//			2017/8/20
//*************************************************************************

//*************************************************************************
//			��d��`�h�~
//*************************************************************************
#ifndef _CSCENE_H_
#define _CSCENE_H_
#pragma once

//*************************************************************************
//			�t�@�C���C���N���[�h
//*************************************************************************
#include "main.h"

//*************************************************************************
//			�񋓑̒�`
//*************************************************************************
// �V�[���̒�`
// �����́uPHASE�v���ď������Ǘ��s��킩��Ȃ�������́uSCENE�v
// �Ȃ񂿂����Unity������
enum SCENE_MODE 
{
	SCENE_MODE_NONE = 0,
	SCENE_MODE_TITLE,
	SCENE_MODE_GAME,
	SCENE_MODE_RESULT,
	SCENE_MODE_MAX,
};

//*************************************************************************
//			�O���錾
//*************************************************************************
class CSceneChanger;

//*************************************************************************
//			�N���X�錾
//*************************************************************************
class CScene
{
public:

	// �R���X�g���N�^
	CScene(CSceneChanger *pSceneChanger) : m_pSceneChanger(pSceneChanger) {}
	// �f�X�g���N�^
	~CScene();
	// �����������֐�
	virtual HRESULT Init(void) = 0;
	// �I�������֐�
	virtual void Uninit(void) = 0;
	// �X�V�����֐�
	virtual void Update(void) = 0;
	// �`�揈���֐�
	virtual void Draw(void) = 0;

	// �t�F�[�Y���[�h�̎擾
		virtual SCENE_MODE GetMode() { return m_nSceneMode; }
	// �t�F�[�Y���[�h�̃Z�b�g
	virtual void SetMode(SCENE_MODE nPhaseMode) { m_nSceneMode = nPhaseMode; }

private:
	CSceneChanger *m_pSceneChanger;
	SCENE_MODE m_nSceneMode;

};

#endif // _CSCENE_H_