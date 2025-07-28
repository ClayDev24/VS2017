#pragma once
#include "windowsWrapper.h"
#include "_colour.h"
#include "defines.h"

namespace math {

	// Valor absoluto (sem saída didática)
	static signed long _abs(const signed long &_n) {
		return (_n < 0) ? -_n : _n; // operador ternário
	}

	// Versão didática com impressão
	static signed long _absD(const signed long &_n) {
		signed long abs = (_n < 0) ? -_n : _n;
		std::cout << "|" << abs << "|" << std::endl;
		return abs;
	}

	// Exemplo de uso
	static void _absUsage() {
		utils::PrintColour_("<<__ABSOLUTE Value (ABS)__>>", FRI);

		P_(_abs(-2))
		P_(_abs(-1))
		P_(_abs(0))
		P_(_abs(1))
		P_(_abs(2))

		_absD(2);
		_absD(-2);
	}

} // namespace math
