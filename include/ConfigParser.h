#pragma once

#include "SimpleIni.h"

class ModConfigs
{
public:
	ModConfigs()
	{
		fCrouchedSteadyMult = 0.5f;
	}

	void LoadConfigs(CSimpleIniA &a_ini)
	{
		a_ini.LoadFile("Data\\F4SE\\Plugins\\GLXRM_EasierCrouchedSteadying.ini");

		fCrouchedSteadyMult = std::stof(a_ini.GetValue("General", "fCrouchedSteadyMult", "0.5"));
		
		a_ini.Reset();
	}

public:
	float fCrouchedSteadyMult;
};
