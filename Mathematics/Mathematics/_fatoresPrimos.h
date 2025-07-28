#pragma once
#include "_colour.h"
#include "typedefs.h"

namespace math {
	// Todo n. composto pode ser escrito num produto em que só aparecem fatores primos, como 2, 3, 5...
	// Decomposição em fatores primos:
	static vetorULLng _fatoresPrimos(unsigned long long n) {
		vetorULLng fatores;
		for (unsigned long long i = 2; i * i <= n; ++i) {
			while (n % i == 0) {
				fatores.push_back(i);
				n /= i;
			}
		}
		if (n > 1) // O resto é primo
			fatores.push_back(n);
		return fatores;
	}
	// **************<<_USAGE_>>****************
	static void _fatoresPrimosUsage() {
		utils::PrintColour_("\n<<__TESTE DE FATORACAO PRIMA__>>", FYI);
		std::vector<unsigned long long> exemplos = { 2, 3, 10, 15, 28, 97, 100, 2589, 9876543210 };

		for (auto n : exemplos) {
			utils::PrintColour_("\nNumero:", FCI);
			P_(n);
			vetorULLng fatores = _fatoresPrimos(n);

			utils::PrintColour_("Fatores primos:", FGI);
			utils::_showVetor(fatores);

			std::cout << std::endl;
		}
	}
} // math