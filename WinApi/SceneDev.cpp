#include "pch.h"
#include "SceneDev.h"
#include "Player.h"

SceneDev::SceneDev()
{

}

SceneDev::~SceneDev()
{
	for (auto& object : _objectList)
	{
		delete object.second;
		object.second = nullptr;
	}
}

void SceneDev::Init()
{
	_objectList.push_back({ (int32)OBJECTTYPE::PLAYER, new Player() });

	for (auto it = _objectList.begin(); it < _objectList.end(); it++)
	{
		it->second->Init();
	}
}

void SceneDev::Update()
{
	vector<pair<int32, class Object*>> temp = _objectList;
	for (auto it = temp.begin(); it < temp.end(); it++)
	{
		it->second->Update();
	}
}

void SceneDev::Render(HDC Hdc)
{
	for (auto it = _objectList.begin(); it < _objectList.end(); it++)
	{
		it->second->Render(Hdc);
	}
}

void SceneDev::PushObject(pair<int32, class Object*> Obj)
{
	Scene::PushObject(Obj);
	_objectList.push_back({ Obj.first, Obj.second });
}
