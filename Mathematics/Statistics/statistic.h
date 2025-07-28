#pragma once
#include <vector>
#include <initializer_list>
#include "utils.h"

namespace math {

	class Statistics {
	private:
		std::vector<double> m_valores;
		double m_moda;
		double m_media;
		double m_mediana;
		double m_desvioPadrao;

	public:
		Statistics(std::initializer_list<double> valores);

		double getModa();
		double getMedia();
		double getMediana();
		double getDesvioPadrao();

		void imprimir() const;
	};

	// **************<<_USAGE_>>****************
	void _statisticsUsage();
} // namespace math

