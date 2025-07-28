#pragma once
#include <iostream>
#include <initializer_list>

class Soma {
private:
	int total;

public:
	// Construtor com initializer_list
	Soma(std::initializer_list<int> numeros) {
		total = 0;
		for (int num : numeros) {
			total += num;
		}
	}

	void mostrarResultado() const {
		std::cout << "Soma total: " << total << std::endl;
	}
};

// **************<<_USAGE_>>****************
void _in_constyructorUsage() {

	Soma s({ 10, 20, 30, 40 });
	Soma s2{ 10, 20, 30, 40 };

	s.mostrarResultado();
	s2.mostrarResultado();

}