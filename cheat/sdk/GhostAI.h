#pragma once
#include "sdk.h"

namespace SDK
{
	struct GhostAIFields
	{
		MonoBehaviourFields _;
		void* Field0;
		int32_t Field1;
		void* Field2;
		GhostInfo* GhostInfo; // Only field we care about
		// don't care about other fields
	};

	struct GhostAI
	{
		void* Clazz; // GhostAI class
		void* Monitor; // Monitor Data
		GhostAIFields Fields;
	};

	DECLARE_FUNCTION_POINTER(GhostAI_Start, void(*)(GhostAI* ghostAI, void* methodInfo), 0x158C940);
}
