#include "produto.hpp"

#include <fstream>
#include <iomanip>

void carrega_produtos(std::vector <Produto *> &estoque) {
	std::string nome, cat;
	int id, quantidade;
	double preco;
	std::vector<std::string> categorias;

	std::ifstream produtos_in;
	produtos_in.open("inc/produtos.txt");

	if (produtos_in.is_open()) {
		while (produtos_in >> id) {

			produtos_in.ignore();
			getline(produtos_in, nome);
			
			produtos_in >> preco >> quantidade >> cat;

			categorias.clear();

			while (cat != "-") {
				categorias.push_back(cat);
				produtos_in >> cat;
			}

			estoque.push_back(new Produto(id, nome, preco, quantidade, categorias));
		}
	}
	
	produtos_in.close();
}

void imprime_produtos(std::vector <Produto *> estoque) {
	std::cout << "Produtos em estoque (" << estoque.size() << "):" << std::endl << std::endl;

	for (Produto * p: estoque) {
		std::cout << std::left
				  << std::setw(30)
				  << p->get_nome()
				  << "Quantidade: "
				  << std::setw(20)
				  << p->get_quantidade()
				  << "ID: "
				  << p->get_id()
				  << std::endl;
	}

	std::cout << std::endl;
}