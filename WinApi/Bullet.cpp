#include "pch.h"
#include "Bullet.h"
#include "TimeManager.h"

Bullet::Bullet()
{
	_objectType = OBJECTTYPE::PROJECTILE;
	_size = { 10, 10 };
	_speed = 2000.f;
}

Bullet::~Bullet()
{
	delete this;
}

void Bullet::Init()
{
	Object::Init();

}

void Bullet::Update()
{
	Object::Update();
	_pos._y -= GET_SINGLE(TimeManager)->GetDeltaTime() * _speed;
}

void Bullet::Render(HDC Hdc)
{
	Object::Render(Hdc);

	Ellipse(Hdc, static_cast<int>(_pos._x - _size._x), static_cast<int>(_pos._y - _size._y),
		static_cast<int>(_pos._x + _size._x), static_cast<int>(_pos._y + _size._y));
}
