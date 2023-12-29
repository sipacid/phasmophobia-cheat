#include "pch.h"

#include <cstdio>
#include <iostream>
#include <ostream>

#include "sdk/sdk.h"

HMODULE hHackModule = nullptr;
HANDLE hHackThread = nullptr;
SDK::GhostAI* ghostAI = nullptr;
bool shouldPrint = false;

void hkGhostAI_Start(SDK::GhostAI* _ghostAI, void* methodInfo)
{
	// Saving ghostAI pointer
	ghostAI = _ghostAI;
	shouldPrint = true;

	// Calling original function
	SDK::GhostAI_Start_ptr(ghostAI, methodInfo);
}

DWORD WINAPI HackThread()
{
	// Beep boop I'm a console
	FILE* f;
	AllocConsole();
	freopen_s(&f, "CONOUT$", "w", stdout);

	// Detouring GhostAI.Start
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&reinterpret_cast<PVOID&>(SDK::GhostAI_Start_ptr), hkGhostAI_Start);
	DetourTransactionCommit();

	// No exiting the cheat yet
	while (true)
	{
		/// oooooo spooky ghost
		if (shouldPrint && ghostAI)
		{
			if (const auto ghostInfo = ghostAI->Fields.GhostInfo)
			{
				// if name is a nullptr then the ghost type isn't valid yet
				if (ghostInfo->Fields.GhostTraits.Name)
				{
					const auto ghostType = ghostInfo->Fields.GhostTraits.GhostType_;
					std::cout << "Ghost type: " << GhostTypeToString(ghostType) << std::endl;
					shouldPrint = false;
				}
			}
		}

		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}

		Sleep(100);
	}

	// Un-detouring GhostAI.Start
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&reinterpret_cast<PVOID&>(SDK::GhostAI_Start_ptr), hkGhostAI_Start);
	DetourTransactionCommit();

	// Bye bye console
	FreeConsole();

	CloseHandle(hHackThread);
	FreeLibraryAndExitThread(hHackModule, 0);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReasonForCall, LPVOID lpReserved)
{
	if (ulReasonForCall == DLL_PROCESS_ATTACH)
	{
		hHackModule = hModule;
		hHackThread = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(HackThread), hModule, 0,
		                           nullptr);
	}

	return TRUE;
}
