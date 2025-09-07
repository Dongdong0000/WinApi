#pragma once

class LineMesh;

class ResourceManager
{
	DECLARE_SINGLE(ResourceManager)
	~ResourceManager();

public:
	void Init();

	LineMesh* GetLineMesh(wstring Key);

private:
	unordered_map<wstring, LineMesh*> _lineMeshes;
};

