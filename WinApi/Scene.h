#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC Hdc) abstract;

protected:
	// 0 : None, 1 : Player, 2 : Monster, 3 : Projectile
	vector<pair<int32,class Object*>> _objectList;
};