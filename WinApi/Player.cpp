#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Bullet.h"
#include "Scene.h"
#include "SceneManager.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Init()
{
	Object::Init();

	_objectType = OBJECTTYPE::PLAYER;
	_pos = { 400, 400 };
	_size = { 100, 100 };
	_speed = 500.f;
}

void Player::Update()
{
	Object::Update();

	float delta = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos._x -= delta * _speed;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_pos._y -= delta * _speed;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos._x += delta * _speed;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_pos._y += delta * _speed;
	}
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		CreateBullet();
	}
}

void Player::Render(HDC Hdc)
{
	Object::Render(Hdc);

	float playerLeft = _pos._x - (_size._x / 2);
	float playerTop = _pos._y - (_size._y / 2);
	float playerRight = _pos._x + (_size._x / 2);
	float playerBottom = _pos._y + (_size._y / 2);

	Rectangle(Hdc, (int)playerLeft, (int)playerTop, (int)playerRight, (int)playerBottom);
}

void Player::CreateBullet()
{
	Bullet* newBullet = new Bullet();

	newBullet->SetPos({ _pos._x, _pos._y });

	GET_SINGLE(SceneManager)->GetCurrScene()->PushObject({ static_cast<int32>(OBJECTTYPE::PROJECTILE), newBullet } );
	
}