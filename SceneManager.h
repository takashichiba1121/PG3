#pragma once

class SceneManager final{
private:
	//コンストラクタをprivateにする
	SceneManager();
	//デストラクタをprivateにする
	~SceneManager();
public:
	//コピーコンストラクタを無料にする
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無料にする
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

	int GetSceneNo();
private:
	int sceneNo=0;
};
