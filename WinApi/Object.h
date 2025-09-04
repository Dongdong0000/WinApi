#pragma once

enum class OBJECTTYPE
{
	NONE = 0,
	PLAYER = 1,
	MONSTER = 2,
	PROJECTILE = 3,

};

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC Hdc) abstract;

protected:
	OBJECTTYPE _objectType = OBJECTTYPE::NONE;
	Pos _pos = {};
	Pos _size = {};
	float _speed = 100.f;

};

