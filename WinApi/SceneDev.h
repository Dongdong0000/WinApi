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

	virtual void PushObject(pair<int32, class Object*> Obj) override;

protected:

};

