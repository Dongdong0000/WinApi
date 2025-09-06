#pragma once

enum SCENE {
	DEV,
	LOBBY,
	EDIT
};

class SceneManager
{
	DECLARE_SINGLE(SceneManager);
	~SceneManager();

public:
	void Init();
	void Update();
	void Render(HDC Hdc);

	class Scene* ChangeScene(pair<class Scene*, SCENE>& Curr, SCENE Next);
	class Scene* GetCurrScene() { return _currScene.first; }

private:
	pair <class Scene*, SCENE> _currScene = {};
	unordered_map<SCENE, Scene*> _sceneList;

};

