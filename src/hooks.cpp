#include "hooks.h"

namespace HookLineAndSinker
{
	typedef __m128(Actor_CombatFormulasCalcScopeSteadyActionPointDrainSig)(RE::Actor*, float, int64_t, int64_t);
	REL::Relocation<Actor_CombatFormulasCalcScopeSteadyActionPointDrainSig> OriginalFunction;

	// a_unk1 is probably a delta variable to ensure correct amounts are drained per second
	__m128 HookedActor_CombatFormulasCalcScopeSteadyActionPointDrain(RE::Actor* a_actor, float a_unk1, int64_t a_unk2, int64_t a_unk3)
	{
		if (a_actor->IsSneaking()) {
			return OriginalFunction(a_actor, a_unk1 * iniData.fCrouchedSteadyMult, a_unk2, a_unk3);
		}

		return OriginalFunction(a_actor, a_unk1, a_unk2, a_unk3);
	}

	void RegisterHook(F4SE::Trampoline& trampoline) {
		REL::Relocation<Actor_CombatFormulasCalcScopeSteadyActionPointDrainSig> callLocation{ REL::ID(355149), 0x3D };
		OriginalFunction = trampoline.write_call<5>(callLocation.address(), &HookedActor_CombatFormulasCalcScopeSteadyActionPointDrain);
	}
}
