#include "pch.h"
#include "SceneDev.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Player.h"

SceneDev::SceneDev()
{

}

SceneDev::~SceneDev()
{
	for (auto it = _objectList.begin(); it < _objectList.end(); )
	{
		_objectList.erase(it);
		it++;
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
	for (auto it = _objectList.begin(); it < _objectList.end(); it++)
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