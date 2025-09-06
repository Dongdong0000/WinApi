#include "pch.h"
#include "SceneManager.h"
#include "EditScene.h"
#include "Scene.h"
#include "SceneDev.h"
#include "SceneLobby.h"

SceneManager::~SceneManager()
{
	for_each(_sceneList.begin(), _sceneList.end(), [=](pair<int32, class Scene*> scene) { delete scene.second; });

	for (int i = 0; i < _sceneList.size(); i++)
	{
		_sceneList.erase(_sceneList.begin()->first);
	}
}

void SceneManager::Init()
{
	_currScene = { new EditScene(), SCENE::EDIT };
	_sceneList[SCENE::EDIT] = _currScene.first;

	_currScene.first->Init();
}

void SceneManager::Update()
{
	_currScene.first->Update();
}

void SceneManager::Render(HDC Hdc)
{
	_currScene.first->Render(Hdc);
}

Scene* SceneManager::ChangeScene(pair<class Scene*, SCENE>& Curr, SCENE Next)
{
	// ���� ���� ������ �ȵǾ� �ִٸ�, ����
	if (_sceneList.find(Curr.second) != _sceneList.end()) { _sceneList[Curr.second] = Curr.first; }

	// ������ ���� ����Ǿ� �ִٸ�, �ҷ�����
	if (_sceneList.find(Next) != _sceneList.end()) { return _sceneList[Next]; }

	// ������ ���� ������ �ȵǾ� �ִٸ�, ���� ����
	pair <class Scene*, SCENE> newScene = {};
	if (Next == SCENE::DEV) { newScene = { new SceneDev(), SCENE::DEV }; }
	if (Next == SCENE::LOBBY) { newScene = { new SceneLobby(), SCENE::LOBBY }; }

	_sceneList[SCENE::DEV] = newScene.first;
	_currScene = newScene;

	return _currScene.first;
}