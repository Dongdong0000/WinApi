#include "pch.h"
#include "LineMesh.h"
#include "InputManager.h"

LineMesh::LineMesh()
{
}

LineMesh::~LineMesh()
{
}

void LineMesh::Save(wstring Path)
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::S))
	{
		wofstream file;
		file.open(Path);

		for (auto& line : _lines)
		{
			POINT from = line.first;
			POINT to = line.second;
		}


		file << static_cast<int32>(_lines.size()) << '\n';
		for (auto& line : _lines)
		{
			POINT from = line.first;
			POINT to = line.second;

			wstring str = format(L"({0},{1})->({2},{3})", from.x, from.y, to.x, to.y);
			file << str << '\n';
		}

		file.close();

		_lines.clear();
	}
}

void LineMesh::Load(wstring Path)
{
	wifstream file;
	file.open(Path);

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

		_lines.push_back({ from, to });
	}
	file.close();
}
