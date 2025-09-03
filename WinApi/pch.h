#pragma once

#include <Windows.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <format>
#include "Enums.h"

#define _CRTDEBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

using namespace std;