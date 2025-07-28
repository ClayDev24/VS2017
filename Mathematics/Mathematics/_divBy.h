#pragma once
#include "windowsWrapper.h"
#include "_colour.h"
#include "defines.h"
#include "..\..\Utilidades\Utilidades\_require.h"
#include "..\..\Utilidades\Utilidades\_showVetor.h"

namespace math {

	static bool _divBy(unsigned int _n, int _by) {
		REQUIRE(_by != 0); // evitar divisão por zero
		return !(_n%_by);
	}
	// **************<<_USAGE_>>****************
	static void _divByUsage() {
		utils::PrintColour_("<<__DIVISIBILIDADE Usage__>>", FBI);
		//utils::dicShow("mathematics", "Divisibilidade");

		P_(_divBy(99, 9))
		P_(_divBy(97, 9))
		P_(_divBy(12, 2))
		P_(_divBy(11, 2))
	}

} // math
