#include "pch.h"
#include "SceneDev.h"
#include "TimeManager.h"
#include "InputManager.h"

SceneDev::SceneDev()
{

}

SceneDev::~SceneDev()
{

}

void SceneDev::Init()
{

}

void SceneDev::Update()
{
	float delta = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_playerPos._x -= delta * _playerSpeed;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_playerPos._y -= delta * _playerSpeed;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_playerPos._x += delta * _playerSpeed;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_playerPos._y += delta * _playerSpeed;
	}
}

void SceneDev::Render(HDC Hdc)
{
	float playerLeft = _playerPos._x - (_playerSize._x / 2);
	float playerTop = _playerPos._y - (_playerSize._y / 2);
	float playerRight = _playerPos._x + (_playerSize._x / 2);
	float playerBottom = _playerPos._y + (_playerSize._y / 2);

	Rectangle(Hdc, (int)playerLeft, (int)playerTop, (int)playerRight, (int)playerBottom);
}