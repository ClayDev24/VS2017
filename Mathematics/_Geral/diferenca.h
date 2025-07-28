#pragma once
#include "windowsWrapper.h"
#include "utils.h"

namespace diferenca {

	enum class Tipo : int { PARES = 1, MISTOS = 2, IMPARES = 3 };

	static bool ehImpar(int n) {
		return n % 2 != 0;
	}

	static int ajustarParidade(int n, bool deveSerImpar) {
		bool impar = ehImpar(n);
		if (deveSerImpar  && !impar) return n + 1;
		if (!deveSerImpar && impar) return n + 1;
		return n;
	}

	static void _numeros(const int& _sz, const Tipo& _tp) {
		for (int i = 0; i < _sz; i++) {
			int n1 = utils::_random(2, 100000);
			int n2 = utils::_random(2, 100000);

			switch (_tp) {
			case Tipo::PARES:
				n1 = ajustarParidade(n1, false);
				n2 = ajustarParidade(n2, false);
				break;
			case Tipo::IMPARES:
				n1 = ajustarParidade(n1, true);
				n2 = ajustarParidade(n2, true);
				break;
			case Tipo::MISTOS:
				if (ehImpar(n1) == ehImpar(n2)) {
					n2 += 1; // garante que um seja par e outro ímpar
				}
				break;
			}

			const int resultado = n1 - n2;
			std::cout << n1 << " - " << n2 << " = " << resultado << std::endl;
			utils::PrintColour_((resultado % 2 == 0 ? "PAR!\n" : "IMPAR!\n"),
				resultado % 2 == 0 ? FGI : FRI);
		}
	}
}

static void _diferencaUsage() {
	utils::PrintColour_("Diferença entre PARES é sempre PAR:\n", FRI);
	diferenca::_numeros(10, diferenca::Tipo::PARES);

	utils::PrintColour_("Diferença entre ÍMPARES é sempre PAR:\n", FRI);
	diferenca::_numeros(10, diferenca::Tipo::IMPARES);

	utils::PrintColour_("Diferença entre PARES E ÍMPARES é sempre ÍMPAR:\n", FRI);
	diferenca::_numeros(10, diferenca::Tipo::MISTOS);
}
