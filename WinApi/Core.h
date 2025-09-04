#pragma once
class Core
{
public:
	Core();
	~Core();

public:
	void Init(HWND Hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};

	RECT _rect = {};
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {}; 
};