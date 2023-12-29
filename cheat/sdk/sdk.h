#pragma once

#define DECLARE_FUNCTION_POINTER(NAME, TYPE, ADDRESS) \
using NAME = TYPE; \
inline NAME NAME##_ptr = reinterpret_cast<NAME>(BASE_ADDRESS + ADDRESS);

namespace SDK
{
	const auto BASE_ADDRESS = reinterpret_cast<uintptr_t>(GetModuleHandleW(L"GameAssembly.dll"));
}

#include "MonoBehaviour.h"
#include "GhostTraits.h"
#include "GhostInfo.h"
#include "GhostAI.h"
