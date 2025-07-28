#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <map>

// Função utilitária para verificar espaço em branco de forma segura
inline bool is_whitespace(char ch) {
	return std::isspace(static_cast<unsigned char>(ch));
}

// Verifica se a linha é uma chave (inicia com número e não tem tab)
bool isKeyLine(const std::string& line) {
	if (line.empty()) return false;
	if (is_whitespace(line[0])) return false;
	return std::isdigit(static_cast<unsigned char>(line[0]));
}

// Função de busca por palavra-chave no dicionário
template <typename MapType>
std::string search(const MapType& dicionario, const std::string& chave) {
	auto it = dicionario.find(chave);
	return it != dicionario.end() ? it->second : "Palavra-chave não encontrada.";
}

int main() {
	std::ifstream file("_investment.h");
	if (!file) {
		std::cerr << "Erro ao abrir o arquivo.\n";
		return 1;
	}

	std::unordered_map<std::string, std::string> dict;
	std::string line, currentKey;

	while (std::getline(file, line)) {
		if (isKeyLine(line)) {
			currentKey = line;
			dict[currentKey] = "";  // inicia com valor vazio
		}
		else if (!currentKey.empty() && !line.empty() && is_whitespace(line[0])) {
			dict[currentKey] += line;// +'\n';
		}
	}

	// Exibir o resultado
	for (const auto& pair : dict) {
		const auto& key = pair.first;
		const auto& value = pair.second;
		std::cout << "\nChave: " << key << "\n";
		//std::cout << "Valor:\n" << value;
	}

	std::cout << "Resultado: " << search(dict, "6. Criptomoedas") << std::endl;

	return 0;
}
