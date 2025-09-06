#pragma once
#include "Scene.h"
class EditScene :
    public Scene
{
public:
	EditScene();
	virtual ~EditScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC Hdc) override;

	virtual void PushObject(pair<int32, class Object*> Obj) override;

private:
	vector<pair<POINT, POINT>> _lines;
	bool _setOrigin = true;
	POINT _lastPos = {};
};

