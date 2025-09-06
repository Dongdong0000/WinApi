#include "pch.h"
#include "EditScene.h"
#include "InputManager.h"

EditScene::EditScene()
{
}

EditScene::~EditScene()
{
}

void EditScene::Init()
{
	Scene::Init();
}

void EditScene::Update()
{
	Scene::Update();

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

		if (_setOrigin)
		{
			_lastPos = mousePos;
			_setOrigin = false;
		}
		else
		{
			_lines.push_back({ _lastPos, mousePos });
			_lastPos = mousePos;
		}
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::RightMouse))
		_setOrigin = true;

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::S))
	{
		wofstream file;
		file.open(L"Unit.txt");

		int32 minX = INT32_MAX;
		int32 maxX = INT32_MIN;
		int32 minY = INT32_MAX;
		int32 maxY = INT32_MIN;

		for (auto& line : _lines)
		{
			POINT from = line.first;
			POINT to = line.second;

			minX = min(min(minX, from.x), to.x);
			maxX = max(max(maxX, from.x), to.x);
			minY = min(min(minY, from.y), to.y);
			maxY = max(max(minY, from.y), to.y);
		}

		int midX = (minX + maxX) / 2;
		int midY = (minY + maxY) / 2;

		file << static_cast<int32>(_lines.size()) << '\n';
		for (auto& line : _lines)
		{
			POINT from = line.first; from.x -= midX; from.y -= midY;
			POINT to = line.second; to.x -= midX; to.y -= midY;

			wstring str = format(L"({0},{1})->({2},{3})", from.x, from.y, to.x, to.y);
			file << str << '\n';
		}

		file.close();

		_lines.clear();
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::D))
	{
		wifstream file;
		file.open(L"Unit.txt");

		int32 count;
		file >> count;

		_lines.clear();

		for (int32 i = 0; i < count; i++)
		{
			POINT from;
			POINT to;

			wstring str;
			file >> str;
			swscanf_s(str.c_str(), L"(%d,%d ) -> (%d,%d)", &from.x, &from.y, &to.x, &to.y);

			from.x += 800;
			to.x += 800;
			from.y += 600;
			to.y += 600;

			_lines.push_back({ from, to });
			_setOrigin = true;
		}
		file.close();
	}
}

void EditScene::Render(HDC Hdc)
{
	Scene::Render(Hdc);

	for (auto& line : _lines)
	{
		POINT pt1 = line.first;
		POINT pt2 = line.second;

		Pos pos1 = { (float)pt1.x, (float)pt1.y };
		Pos pos2 = { (float)pt2.x, (float)pt2.y };

		MoveToEx(Hdc, pt1.x, pt1.y, nullptr);
		LineTo(Hdc, pt2.x, pt2.y);
	}
}

void EditScene::PushObject(pair<int32, class Object*> Obj)
{
	Scene::PushObject(Obj);
}
