#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include "Statistic.h"

// Estatística DESCRITIVA=> Média, mediana, moda e desvio padrão:
namespace math {

	// Construtor: recebe uma lista de valores e armazena de forma ordenada.
	// A ordenação é útil especialmente para o cálculo da mediana.
	Statistics::Statistics(std::initializer_list<double> valores)
		: m_valores(valores), m_moda(0), m_media(0), m_mediana(0), m_desvioPadrao(0) {
		std::sort(m_valores.begin(), m_valores.end());
	}

	// Moda: valor que mais se repete na amostra.
	// A moda é útil para identificar a concentração de dados em torno de certos valores.
	double Statistics::getModa() {
		std::map<double, int> freq;
		for (double val : m_valores)
			++freq[val];

		int maxFreq = 0;
		for (const auto&[valor, f] : freq)
			if (f > maxFreq) {
				maxFreq = f;
				m_moda = valor;
			}

		return m_moda;
	}

	// Média aritmética: soma de todos os valores dividida pela quantidade de elementos.
	// Representa o "centro" da distribuição dos dados.
	double Statistics::getMedia() {
		m_media = std::accumulate(m_valores.begin(), m_valores.end(), 0.0) / m_valores.size();
		return m_media;
	}

	// Mediana: valor central da amostra ordenada.
	// Se o número de elementos for ímpar, retorna o valor central.
	// Se for par, retorna a média dos dois valores centrais.
	double Statistics::getMediana() {
		size_t sz = m_valores.size();
		if (sz % 2 == 1)
			m_mediana = m_valores[sz / 2];
		else
			m_mediana = (m_valores[sz / 2 - 1] + m_valores[sz / 2]) / 2;
		return m_mediana;
	}

	// Desvio padrão: medida da dispersão dos dados em relação à média.
	// Fórmula: sqrt( (1/n) * ∑(xi - média)² )
	// Um desvio padrão alto indica dados mais espalhados.
	double Statistics::getDesvioPadrao() {
		double media = getMedia();
		double soma = 0.0;
		for (double val : m_valores)
			soma += std::pow(val - media, 2);
		m_desvioPadrao = std::sqrt(soma / m_valores.size());
		return m_desvioPadrao;
	}

	// Método auxiliar: imprime os valores armazenados.
	void Statistics::imprimir() const {
		std::cout << "Valores: ";
		for (double val : m_valores)
			std::cout << val << " ";
		std::cout << "\n";
	}

	// **************<<_USAGE_>>****************
	void _statisticsUsage() {
		Statistics s1{ 2.0, 2.0, 11.0, 4.0, 7.0, 3.0, 3.0, 5.0, 5.0, 5.0 };

		s1.imprimir();

		std::cout << "Moda         : " << s1.getModa() << "\n";
		std::cout << "Média        : " << s1.getMedia() << "\n";
		std::cout << "Mediana      : " << s1.getMediana() << "\n";
		std::cout << "Desvio padrão: " << s1.getDesvioPadrao() << "\n";
	}

} // namespace math
