#include <iostream>
#include <iomanip>
#include "TabelaPeriodica.h"

namespace quimica {

	void TabelaPeriodica::adicionarElemento(const Atomo& atomo) {
		elementos.push_back(atomo);
		grupos[atomo.getGrupo()].push_back(atomo);
	}

	void TabelaPeriodica::exibirPorGrupo() const {
		for (const auto& par : grupos) {
			std::cout << "Grupo " << par.first << ":";
				for (const Atomo& a : par.second) {
					std::cout << std::setw(3) << a.getSimbolo()
						<< " (" << a.getNome() << "), Z=" << a.getNumeroAtomico()
						<< " - Família: " << a.getFamilia()
						<< ", Tipo: " << a.getTipo()
						<< ", Período: " << a.getPeriodo() << '\n';
				}
			std::cout << "--------------------------\n";
		}
	}

	void TabelaPeriodica::exibirTabelaPeriodica() const {
		std::cout << "===== TABELA PERIÓDICA (visão resumida) =====\n\n";
		for (int p = 0; p < 7; ++p) {
			std::cout << "Período " << (p + 1) << ":	";
			for (int g = 0; g < 18; ++g) {
				if (tabela[p][g])
					std::cout << std::setw(3) << tabela[p][g]->getSimbolo();
				else
					std::cout << " . ";
			}
			std::cout << '\n';
		}
		std::cout << "\nLegenda: Símbolos dos elementos por grupo e período\n";
	}

	void TabelaPeriodica::preencherAutomaticamente() {
		std::vector<Atomo> dados = {
			Atomo(1, "H", "Hidrogênio", "Não-metal", 1, 1, "Não-metal"),
			Atomo(2, "He", "Hélio", "Gases Nobres", 18, 1, "Gás Nobre"),
			Atomo(3, "Li", "Lítio", "Metais Alcalinos", 1, 2, "Metal"),
			Atomo(4, "Be", "Berílio", "Alcalino-terrosos", 2, 2, "Metal"),
			Atomo(5, "B", "Boro", "Semimetal", 13, 2, "Semimetal"),
			Atomo(6, "C", "Carbono", "Não-metal", 14, 2, "Não-metal"),
			Atomo(7, "N", "Nitrogênio", "Não-metal", 15, 2, "Não-metal"),
			Atomo(8, "O", "Oxigênio", "Não-metal", 16, 2, "Não-metal"),
			Atomo(9, "F", "Flúor", "Halogênios", 17, 2, "Não-metal"),
			Atomo(10, "Ne", "Neônio", "Gases Nobres", 18, 2, "Gás Nobre"),
			Atomo(11, "Na", "Sódio", "Metais Alcalinos", 1, 3, "Metal"),
			Atomo(12, "Mg", "Magnésio", "Alcalino-terrosos", 2, 3, "Metal"),
			Atomo(13, "Al", "Alumínio", "Metal", 13, 3, "Metal"),
			Atomo(14, "Si", "Silício", "Semimetal", 14, 3, "Semimetal"),
			Atomo(15, "P", "Fósforo", "Não-metal", 15, 3, "Não-metal"),
			Atomo(16, "S", "Enxofre", "Não-metal", 16, 3, "Não-metal"),
			Atomo(17, "Cl", "Cloro", "Halogênios", 17, 3, "Não-metal"),
			Atomo(18, "Ar", "Argônio", "Gases Nobres", 18, 3, "Gás Nobre"),
			Atomo(19, "E19", "Elemento19", "Metais Alcalinos", 1, 2, "Metal"),
			Atomo(20, "E20", "Elemento20", "Alcalino-terrosos", 2, 2, "Metal"),
			Atomo(21, "E21", "Elemento21", "Outros", 3, 2, "Metal"),
			Atomo(22, "E22", "Elemento22", "Outros", 4, 2, "Metal"),
			Atomo(23, "E23", "Elemento23", "Outros", 5, 2, "Metal"),
			Atomo(24, "E24", "Elemento24", "Outros", 6, 2, "Metal"),
			Atomo(25, "E25", "Elemento25", "Outros", 7, 2, "Metal"),
			Atomo(26, "E26", "Elemento26", "Outros", 8, 2, "Metal"),
			Atomo(27, "E27", "Elemento27", "Outros", 9, 2, "Metal"),
			Atomo(28, "E28", "Elemento28", "Outros", 10, 2, "Metal"),
			Atomo(29, "E29", "Elemento29", "Outros", 11, 2, "Metal"),
			Atomo(30, "E30", "Elemento30", "Outros", 12, 2, "Metal"),
			Atomo(31, "E31", "Elemento31", "Outros", 13, 2, "Semimetal"),
			Atomo(32, "E32", "Elemento32", "Outros", 14, 2, "Semimetal"),
			Atomo(33, "E33", "Elemento33", "Outros", 15, 2, "Não-metal"),
			Atomo(34, "E34", "Elemento34", "Outros", 16, 2, "Não-metal"),
			Atomo(35, "E35", "Elemento35", "Halogênios", 17, 2, "Não-metal"),
			Atomo(36, "E36", "Elemento36", "Gases Nobres", 18, 2, "Não-metal"),
			Atomo(37, "E37", "Elemento37", "Metais Alcalinos", 1, 3, "Metal"),
			Atomo(38, "E38", "Elemento38", "Alcalino-terrosos", 2, 3, "Metal"),
			Atomo(39, "E39", "Elemento39", "Outros", 3, 3, "Metal"),
			Atomo(40, "E40", "Elemento40", "Outros", 4, 3, "Metal"),
			Atomo(41, "E41", "Elemento41", "Outros", 5, 3, "Metal"),
			Atomo(42, "E42", "Elemento42", "Outros", 6, 3, "Metal"),
			Atomo(43, "E43", "Elemento43", "Outros", 7, 3, "Metal"),
			Atomo(44, "E44", "Elemento44", "Outros", 8, 3, "Metal"),
			Atomo(45, "E45", "Elemento45", "Outros", 9, 3, "Metal"),
			Atomo(46, "E46", "Elemento46", "Outros", 10, 3, "Metal"),
			Atomo(47, "E47", "Elemento47", "Outros", 11, 3, "Metal"),
			Atomo(48, "E48", "Elemento48", "Outros", 12, 3, "Metal"),
			Atomo(49, "E49", "Elemento49", "Outros", 13, 3, "Semimetal"),
			Atomo(50, "E50", "Elemento50", "Outros", 14, 3, "Semimetal"),
			Atomo(51, "E51", "Elemento51", "Outros", 15, 3, "Não-metal"),
			Atomo(52, "E52", "Elemento52", "Outros", 16, 3, "Não-metal"),
			Atomo(53, "E53", "Elemento53", "Halogênios", 17, 3, "Não-metal"),
			Atomo(54, "E54", "Elemento54", "Gases Nobres", 18, 3, "Não-metal"),
			Atomo(55, "E55", "Elemento55", "Metais Alcalinos", 1, 4, "Metal"),
			Atomo(56, "E56", "Elemento56", "Alcalino-terrosos", 2, 4, "Metal"),
			Atomo(57, "E57", "Elemento57", "Outros", 3, 4, "Metal"),
			Atomo(58, "E58", "Elemento58", "Outros", 4, 4, "Metal"),
			Atomo(59, "E59", "Elemento59", "Outros", 5, 4, "Metal"),
			Atomo(60, "E60", "Elemento60", "Outros", 6, 4, "Metal"),
			Atomo(61, "E61", "Elemento61", "Outros", 7, 4, "Metal"),
			Atomo(62, "E62", "Elemento62", "Outros", 8, 4, "Metal"),
			Atomo(63, "E63", "Elemento63", "Outros", 9, 4, "Metal"),
			Atomo(64, "E64", "Elemento64", "Outros", 10, 4, "Metal"),
			Atomo(65, "E65", "Elemento65", "Outros", 11, 4, "Metal"),
			Atomo(66, "E66", "Elemento66", "Outros", 12, 4, "Metal"),
			Atomo(67, "E67", "Elemento67", "Outros", 13, 4, "Semimetal"),
			Atomo(68, "E68", "Elemento68", "Outros", 14, 4, "Semimetal"),
			Atomo(69, "E69", "Elemento69", "Outros", 15, 4, "Não-metal"),
			Atomo(70, "E70", "Elemento70", "Outros", 16, 4, "Não-metal"),
			Atomo(71, "E71", "Elemento71", "Halogênios", 17, 4, "Não-metal"),
			Atomo(72, "E72", "Elemento72", "Gases Nobres", 18, 4, "Não-metal"),
			Atomo(73, "E73", "Elemento73", "Metais Alcalinos", 1, 5, "Metal"),
			Atomo(74, "E74", "Elemento74", "Alcalino-terrosos", 2, 5, "Metal"),
			Atomo(75, "E75", "Elemento75", "Outros", 3, 5, "Metal"),
			Atomo(76, "E76", "Elemento76", "Outros", 4, 5, "Metal"),
			Atomo(77, "E77", "Elemento77", "Outros", 5, 5, "Metal"),
			Atomo(78, "E78", "Elemento78", "Outros", 6, 5, "Metal"),
			Atomo(79, "E79", "Elemento79", "Outros", 7, 5, "Metal"),
			Atomo(80, "E80", "Elemento80", "Outros", 8, 5, "Metal"),
			Atomo(81, "E81", "Elemento81", "Outros", 9, 5, "Metal"),
			Atomo(82, "E82", "Elemento82", "Outros", 10, 5, "Metal"),
			Atomo(83, "E83", "Elemento83", "Outros", 11, 5, "Metal"),
			Atomo(84, "E84", "Elemento84", "Outros", 12, 5, "Metal"),
			Atomo(85, "E85", "Elemento85", "Outros", 13, 5, "Semimetal"),
			Atomo(86, "E86", "Elemento86", "Outros", 14, 5, "Semimetal"),
			Atomo(87, "E87", "Elemento87", "Outros", 15, 5, "Não-metal"),
			Atomo(88, "E88", "Elemento88", "Outros", 16, 5, "Não-metal"),
			Atomo(89, "E89", "Elemento89", "Halogênios", 17, 5, "Não-metal"),
			Atomo(90, "E90", "Elemento90", "Gases Nobres", 18, 5, "Não-metal"),
			Atomo(91, "E91", "Elemento91", "Metais Alcalinos", 1, 6, "Metal"),
			Atomo(92, "E92", "Elemento92", "Alcalino-terrosos", 2, 6, "Metal"),
			Atomo(93, "E93", "Elemento93", "Outros", 3, 6, "Metal"),
			Atomo(94, "E94", "Elemento94", "Outros", 4, 6, "Metal"),
			Atomo(95, "E95", "Elemento95", "Outros", 5, 6, "Metal"),
			Atomo(96, "E96", "Elemento96", "Outros", 6, 6, "Metal"),
			Atomo(97, "E97", "Elemento97", "Outros", 7, 6, "Metal"),
			Atomo(98, "E98", "Elemento98", "Outros", 8, 6, "Metal"),
			Atomo(99, "E99", "Elemento99", "Outros", 9, 6, "Metal"),
			Atomo(100, "E100", "Elemento100", "Outros", 10, 6, "Metal"),
			Atomo(101, "E101", "Elemento101", "Outros", 11, 6, "Metal"),
			Atomo(102, "E102", "Elemento102", "Outros", 12, 6, "Metal"),
			Atomo(103, "E103", "Elemento103", "Outros", 13, 6, "Semimetal"),
			Atomo(104, "E104", "Elemento104", "Outros", 14, 6, "Semimetal"),
			Atomo(105, "E105", "Elemento105", "Outros", 15, 6, "Não-metal"),
			Atomo(106, "E106", "Elemento106", "Outros", 16, 6, "Não-metal"),
			Atomo(107, "E107", "Elemento107", "Halogênios", 17, 6, "Não-metal"),
			Atomo(108, "E108", "Elemento108", "Gases Nobres", 18, 6, "Não-metal"),
			Atomo(109, "E109", "Elemento109", "Metais Alcalinos", 1, 7, "Metal"),
			Atomo(110, "E110", "Elemento110", "Alcalino-terrosos", 2, 7, "Metal"),
			Atomo(111, "E111", "Elemento111", "Outros", 3, 7, "Metal"),
			Atomo(112, "E112", "Elemento112", "Outros", 4, 7, "Metal"),
			Atomo(113, "E113", "Elemento113", "Outros", 5, 7, "Metal"),
			Atomo(114, "E114", "Elemento114", "Outros", 6, 7, "Metal"),
			Atomo(115, "E115", "Elemento115", "Outros", 7, 7, "Metal"),
			Atomo(116, "E116", "Elemento116", "Outros", 8, 7, "Metal"),
			Atomo(117, "E117", "Elemento117", "Outros", 9, 7, "Metal"),
			Atomo(118, "E118", "Elemento118", "Outros", 10, 7, "Metal"),
		};

		for (const auto& a : dados) {
			adicionarElemento(a);
			int p = a.getPeriodo() - 1;
			int g = a.getGrupo() - 1;
			if (p >= 0 && p < 7 && g >= 0 && g < 18) {
				tabela[p][g] = &elementos.back();
			}
		}
	}

} // quimica
