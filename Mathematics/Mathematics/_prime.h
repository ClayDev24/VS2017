#pragma once
#include <iostream>
#include "defines.h"
#include "typedefs.h"
#include "_colour.h"

namespace math {
	// Número PRIMO=> Apenas 2 divisores (ele próprio eo o n.1).
	// Número COMPOSTO=> Apresenta mais de dois divisores. O contrá rio do n. PRIMO.
	// Se um n. é < 121 e não é divisível por 2, 3, 5 e 7 é de antemão  um n. PRIMO.
	// Se um n. é < 289 e não é divisível por 2, 3, 5, 7, 11 e 13 não é um n. PRIMO.

	// Algoritmo mais rápido:
	// Para determinar se um certo número inteiro é primo basta dividí-lo por
	// todos os primos menores ou iguais a sua raiz quadrada.
	static bool _prime(unsigned long long n) {
		if (n < 2) return false;
		if (n == 2) return true;
		if (n % 2 == 0) return false;

		unsigned long long raiz = static_cast<unsigned long long>(std::sqrt(n));
		for (unsigned long long i = 3; i <= raiz; i += 2)
			if (n % i == 0)
				return false;
		return true;
	}

	// **************<<_USAGE_>>****************
	static void _primeUsage() {
		utils::PrintColour_("<<__Numeros Primos__>>", FRI);
		//utils::dicShow("mathematics", "Números Primos");

		utils::PrintColour_("\nEste algoritmo testa os ns. primos positivos entre 1 e 18.446.744.073.709.551.615\n", BBI);
		utils::PrintColour_("Maior n. primo possivel por este algoritmo:\n", BYI);
		//P_(_prime(18446744073709551557))

		utils::PrintColour_("Testando ns. primos de 1 a n:\n", BYI);
		// Teste aqui qualquer n.:
		P_(_prime(25))
			int total = 0;
		//for(unsigned long u=0; u<294967294; u++)

		for (unsigned long numero = 0; numero < 100; numero++)
			if (_prime(numero))
				P_(numero);// total++;

		//utils::_showVetor(v);
		//P_(v.size())
		//P_(total)
	}
} // math