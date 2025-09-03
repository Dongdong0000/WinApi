#pragma once

enum SCENE {
	DEV,
	LOBBY,

};

class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC Hdc);

	class Scene* ChangeScene(pair<class Scene*, SCENE>& Curr, SCENE Next);

private:
	pair <class Scene*, SCENE> _currScene = {};
	unordered_map<SCENE, Scene*> _sceneList;

};

