#include "pch.h"
#include "ResourceManager.h"
#include "LineMesh.h"

ResourceManager::~ResourceManager()
{
	for (auto& line : _lineMeshes)
	{
		delete line.second;
		line.second = nullptr;
	}
}

void ResourceManager::Init()
{
	LineMesh* mesh = new LineMesh();
	mesh->Load(L"Player.txt");

	_lineMeshes[L"Player"] = mesh;
}

LineMesh* ResourceManager::GetLineMesh(wstring Key)
{
	auto findIt = _lineMeshes.find(Key);
	if (findIt == _lineMeshes.end()) return nullptr;

	return findIt->second;
}
