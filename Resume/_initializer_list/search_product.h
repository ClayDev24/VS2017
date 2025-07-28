#pragma once
#include "objects.h"

// Class Product defined in objects.h

class Loja {
private:
	std::vector<Product> produtos;

public:
	// Construtor com initializer_list
	Loja(std::initializer_list<Product> lista) {
		for (const auto& prod : lista) {
			produtos.push_back(prod);
		}
	}

	// Função para exibir todos os produtos
	void exibirProdutos() const {
		std::cout << "Lista de produtos:\n";
		for (const auto& p : produtos) {
			std::cout << "- " << p.nome << " : R$" << p.preco << "\n";
		}
	}

	// Função para buscar um produto pelo nome
	Product* buscarProduto(const std::string& nomeBusca) {
		for (auto& p : produtos) {
			if (p.nome == nomeBusca) {
				return &p;
			}
		}
		return nullptr; // se não encontrou
	}
};

void _search_productUsage() {

	Loja minhaLoja{
		{"Teclado", 120.50},
		{"Mouse", 80.00},
		{"Monitor", 999.99},
		{"Cadeira Gamer", 1500.00}
	};

	minhaLoja.exibirProdutos();

	std::string nomeBusca;
	std::cout << "\nDigite o nome do produto que deseja buscar: ";
	std::getline(std::cin, nomeBusca);

	Product* resultado = minhaLoja.buscarProduto(nomeBusca);

	if (resultado) {
		std::cout << "Produto encontrado: " << resultado->nome << " - R$" << resultado->preco << "\n";
	}
	else {
		std::cout << "Produto não encontrado.\n";
	}

}
