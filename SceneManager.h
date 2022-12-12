#pragma once

class SceneManager final{
private:
	//�R���X�g���N�^��private�ɂ���
	SceneManager();
	//�f�X�g���N�^��private�ɂ���
	~SceneManager();
public:
	//�R�s�[�R���X�g���N�^�𖳗��ɂ���
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳗��ɂ���
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

	int GetSceneNo();
private:
	int sceneNo=0;
};
