#include "estoque.hpp"

Estoque::Estoque() {
	carrega_produtos();
}
Estoque::~Estoque(){}

std::vector <Produto *> Estoque::get_produtos() {
    return this->produtos;
}

Produto * Estoque::get_produto(int id) {
    for (Produto * produto: get_produtos()) {
		if (id == produto->get_id()) {
			return produto;
		}
	}
	
	return new Produto;
}

void Estoque::carrega_produtos() {
    std::string nome, cat;
	int id, quantidade;
	double preco;
	std::vector <std::string> categorias;

	std::ifstream produtos_in;
	produtos_in.open("assets/produtos.txt");

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

			add_produto(new Produto(id, nome, preco, quantidade, categorias));
		}
	}
	else {
		std::cout << "Não é possivel abrir o arquivo de produtos." << std::endl;
		throw(-1);
	}
	
	produtos_in.close();
}

bool Estoque::produto_existe(int id) {
	for (Produto * produto: get_produtos()) {
		if (id == produto->get_id()) {
			return true;
		}
	}
	
	return false;
}

void Estoque::cadastrar_produto(int id) {
	std::string nome, categoria;
	double preco;
	int estoque;
	std::vector <std::string> categorias;

	std::cout << "Nome do produto: ";
	std::cin.ignore();
	getline(std::cin, nome);
	
	std::cout << "Preço: ";
	std::cin >> preco;

	std::cout << "Quantidade: ";
	std::cin >> estoque;

	std::cout << "Categoria(s): (Digite cada palavra separada por enter, digite 0 para terminar)" << std::endl;
	std::cin >> categoria;

	while (categoria != "0") {
		categorias.push_back(categoria);
		std::cin >> categoria;
	}

	std::cout << std::endl;
	
	add_produto(new Produto(id, nome, preco, estoque, categorias));
	atualiza_estoque();
}

void Estoque::add_produto(Produto * produto) {
    this->produtos.push_back(produto);
}

void Estoque::imprime_produtos(int modo) { 
    std::cout << "\tProdutos em estoque:" << std::endl << std::endl;

	for (Produto * produto: get_produtos()) {
        if (produto->get_estoque() > 0 || modo == 2) {
            std::cout << std::fixed << std::showpoint << std::setprecision(2)
                    << "\t" << std::left << std::setw(30)
                    << produto->get_nome()
                    << "Valor: $" << std::setw(20)
                    << produto->get_preco()
                    << "Estoque: " << std::setw(20)
                    << produto->get_estoque()
                    << "ID: "
                    << produto->get_id()
                    << std::endl;
        }
	}

	std::cout << std::endl;
}

void Estoque::atualiza_estoque() {
	bool escrita_realizada = true;
	
	std::ofstream produtos_out;
	produtos_out.open("assets/produtos.txt");

	for (Produto * produto: get_produtos()) {
		produto->set_estoque(produto->get_estoque() - produto->get_quantidade());
		
		if (produtos_out.is_open()) {
			produtos_out << std::fixed << std::showpoint << std::setprecision(2)
						 << produto->get_id() << std::endl
						 << produto->get_nome() << std::endl
						 << produto->get_preco() << std::endl
						 << produto->get_estoque() << std::endl;

			for (std::string cat: produto->get_categorias()) {
				produtos_out << cat << std::endl;
			}

			produtos_out << "-" << std::endl << std::endl;
		}
		else {
			escrita_realizada = false;
		}
	}

	if (!escrita_realizada) {
		std::cout << "Acesso negado ao tentar salvar. As alterações não foram salvas." << std::endl;
	}

	produtos_out.close();
}