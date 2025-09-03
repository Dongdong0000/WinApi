#pragma once
#include "Scene.h"
class SceneLobby :
    public Scene
{
public:

	SceneLobby();
	virtual ~SceneLobby() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC Hdc) override;
};

