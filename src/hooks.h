#pragma once

#include "ConfigParser.h"

extern ModConfigs iniData;

namespace HookLineAndSinker
{
	void RegisterHook(F4SE::Trampoline& trampoline);
}
