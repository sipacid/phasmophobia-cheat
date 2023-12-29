#pragma once
#include "sdk.h"

namespace SDK
{
	struct GhostInfoFields
	{
		MonoBehaviourPunFields _;
		GhostTraits GhostTraits; // very important 1!!!1
		// don't care about other fields
		//void* Field1;
		//void* Field2;
		//float Field3;
		//bool Field4;
	};

	struct GhostInfo
	{
		void* Clazz; // GhostInfo class
		void* Monitor; // Monitor Data
		GhostInfoFields Fields;
	};
}
