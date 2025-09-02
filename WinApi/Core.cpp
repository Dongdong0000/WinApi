#include "pch.h"
#include "Core.h"

Core::Core()
{
}

Core::~Core()
{
}

void Core::Init(HWND Hwnd)
{
	_hwnd = Hwnd;
	_hdc = GetDC(_hwnd);
}

void Core::Update()
{
}

void Core::Render()
{
	Rectangle(_hdc, 100, 100, 300, 300);
}
