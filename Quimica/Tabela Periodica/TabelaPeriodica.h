#pragma once
#include <vector>
#include <map>
#include <string>
#include <memory> // para std::unique_ptr
#include "atomo.h"

namespace quimica {

	class TabelaPeriodica {
	private:
		std::vector<Atomo> elementos;
		std::map<int, std::vector<Atomo>> grupos;
		Atomo* tabela[7][18] = {};

	public:
		void adicionarElemento(const Atomo& atomo);
		void exibirPorGrupo() const;
		void preencherAutomaticamente();
		void exibirTabelaPeriodica() const;
	};

} // quimica

