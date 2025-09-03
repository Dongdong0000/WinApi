#include "pch.h"
#include "Core.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Core::Core()
{
}

Core::~Core()
{

}

void Core::Init(HWND Hwnd)
{
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(Hwnd);
	GET_SINGLE(SceneManager)->Init();

	_hwnd = Hwnd;
	_hdc = GetDC(_hwnd);
}


void Core::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Core::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFPS();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	{
		wstring str = format(L"FPS ( {0} ), Delta ( {1} ms )", fps, static_cast<int32>(deltaTime) * 1000);
		TextOut(_hdc, 1720, 10, str.c_str(), str.size());
	}

	GET_SINGLE(SceneManager)->Render(_hdc);

}
