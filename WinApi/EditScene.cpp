#include "pch.h"
#include "EditScene.h"
#include "InputManager.h"

EditScene::EditScene()
{
}

EditScene::~EditScene()
{
}

void EditScene::Init()
{
	Scene::Init();
}

void EditScene::Update()
{
	Scene::Update();

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

		if (_setOrigin)
		{
			_lastPos = mousePos;
			_setOrigin = false;
		}
		else
		{
			_lines.push_back({ _lastPos, mousePos });
			_lastPos = mousePos;
		}
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::RightMouse))
		_setOrigin = true;

}

void EditScene::Render(HDC Hdc)
{
	Scene::Render(Hdc);
}

void EditScene::PushObject(pair<int32, class Object*> Obj)
{
	Scene::PushObject(Obj);
}
