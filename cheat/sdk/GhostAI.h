#pragma once
#include "sdk.h"

namespace SDK
{
	enum class GhostState : int32_t
	{
		Idle,
		Wander,
		Hunting,
		FavoriteRoom,
		Light,
		Door,
		Throwing,
		FuseBox,
		Appear,
		DoorKnock,
		WindowKnock,
		CarAlarm,
		Flicker,
		CCTV,
		RandomEvent,
		GhostAbility,
		Mannequin,
		TeleportObject,
		Interact,
		SummoningCircle,
		MusicBox,
		Dots,
		Salt
	};

	struct GhostAIFields
	{
		MonoBehaviourFields _;
		void* Field0;
		GhostState Field1;
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
