#pragma once
#include <string>

#include "sdk.h"

namespace SDK
{
	enum class GhostType: int32_t
	{
		Spirit,
		Wraith,
		Phantom,
		Poltergeist,
		Banshee,
		Jinn,
		Mare,
		Revenant,
		Shade,
		Demon,
		Yurei,
		Oni,
		Yokai,
		Hantu,
		Goryo,
		Myling,
		Onryo,
		TheTwins,
		Raiju,
		Obake,
		Mimic,
		Moroi,
		Deogen,
		Thaye,
	};

	inline std::string GhostTypeToString(GhostType ghostType)
	{
		switch (ghostType)
		{
		case GhostType::Spirit:
			return "Spirit";
		case GhostType::Wraith:
			return "Wraith";
		case GhostType::Phantom:
			return "Phantom";
		case GhostType::Poltergeist:
			return "Poltergeist";
		case GhostType::Banshee:
			return "Banshee";
		case GhostType::Jinn:
			return "Jinn";
		case GhostType::Mare:
			return "Mare";
		case GhostType::Revenant:
			return "Revenant";
		case GhostType::Shade:
			return "Shade";
		case GhostType::Demon:
			return "Demon";
		case GhostType::Yurei:
			return "Yurei";
		case GhostType::Oni:
			return "Oni";
		case GhostType::Yokai:
			return "Yokai";
		case GhostType::Hantu:
			return "Hantu";
		case GhostType::Goryo:
			return "Goryo";
		case GhostType::Myling:
			return "Myling";
		case GhostType::Onryo:
			return "Onryo";
		case GhostType::TheTwins:
			return "The Twins";
		case GhostType::Raiju:
			return "Raiju";
		case GhostType::Obake:
			return "Obake";
		case GhostType::Mimic:
			return "Mimic";
		case GhostType::Moroi:
			return "Moroi";
		case GhostType::Deogen:
			return "Deogen";
		case GhostType::Thaye:
			return "Thaye";
		default:
			return "Unknown";
		}
	}

	struct GhostTraits
	{
		GhostType GhostType_;
		GhostType MimicType;
		// don't care about the other ones
		void* Field2;
		void* Field3;
		int32_t Field4;
		bool Field5;
		void* Name;
		int32_t Field7;
		int Field8;
		bool Field9;
		int32_t Field10;
		int32_t Field11;
		bool Field12;
	};
}
