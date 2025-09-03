#pragma once
#include "Scene.h"
class SceneDev :
    public Scene
{
public:

	SceneDev();
	virtual ~SceneDev() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC Hdc) override;

protected:
	Pos _playerPos = { 300.f, 300.f };
	Pos _playerSize = { 100.f, 100.f };
	float _playerSpeed = 100.f;
};

