#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

class Product {
public:
	std::string nome;
	double preco;

	Product(std::string n, double p) : nome(n), preco(p) {}
};

class Carrinho {
private:
	std::vector<Product> produtos;

public:
	// Construtor usando initializer_list com objetos Produto
	Carrinho(std::initializer_list<Product> lista) {
		for (const auto& item : lista) {
			produtos.push_back(item);
		}
	}

	void exibirCarrinho() const {
		std::cout << "Itens no carrinho:\n";
		for (const auto& p : produtos) {
			std::cout << "- " << p.nome << ": R$" << p.preco << "\n";
		}
	}
};

// **************<<_USAGE_>>****************
void _objectsUsage() {

	Carrinho meuCarrinho({
		Product("Notebook", 4500.00),
		Product("Mouse", 150.00),
		Product("Teclado", 300.00)
		});

	meuCarrinho.exibirCarrinho();

}
