#pragma once
#include "Object.h"
class Bullet :
    public Object
{
public:
	Bullet();
	virtual ~Bullet() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC Hdc) override;

	void SetPos(Pos P) { _pos._x = P._x; _pos._y = P._y; }
};