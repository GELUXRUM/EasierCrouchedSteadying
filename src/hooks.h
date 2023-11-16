#pragma once

#include "ConfigParser.h"

extern ModConfigs iniData;
extern RE::ActorValueInfo* avActionPoints;

namespace HookLineAndSinker
{
	void RegisterHook(F4SE::Trampoline& trampoline);
}
