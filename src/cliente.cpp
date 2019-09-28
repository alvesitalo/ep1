#include "cliente.hpp"

Cliente::Cliente() {
    cpf = "0000";
    nome = "Sem nome";
    idade = 1;
    email = "sem-nome@email.com";
    socio = false;
    categorias = {};
}
Cliente::Cliente(std::string cpf, std::string nome, int idade, std::string email, bool socio,
				 std::map <std::string, int> categorias) {
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->email = email;
    this->socio = socio;
    this->categorias = categorias;
}
Cliente::~Cliente() {}

std::string Cliente::get_cpf() {
    return this->cpf;
}

std::string Cliente::get_nome() {
    return this->nome;
}

int Cliente::get_idade() {
    return this->idade;
}

std::string Cliente::get_email() {
    return this->email;
}

bool Cliente::is_socio() {
    return this->socio;
}

std::map <std::string, int> Cliente::get_categorias() {
    return this->categorias;
}

void Cliente::set_cpf(std::string cpf) {
    if (cpf.size() > 3)
        this->cpf = cpf;
}

void Cliente::set_nome(std::string nome) {
    this->nome = nome;
}

void Cliente::set_idade(int idade) {
    if (idade > 0)
        this->idade = idade;
}

void Cliente::set_email(std::string email) {
    this->email = email;
}

void Cliente::set_socio(int socio) {
    if (socio == 1)
        this->socio = true;
}

void Cliente::set_categorias(std::map <std::string, int> categorias) {
	this->categorias = categorias;
}

void Cliente::add_categoria(std::string cat, int qnt) {
	if (cat.size() > 1)
    	this->categorias[cat] = qnt;
}

void Cliente::add_categorias(std::vector <Produto *> carrinho) {
    int cat_quantidade;

	for (Produto * produto: carrinho) {
		for (std::string cat_produto: produto->get_categorias()) {
			cat_quantidade = categorias[cat_produto] + produto->get_quantidade();
			this->categorias[cat_produto] = cat_quantidade;
		}
	}
}

void Cliente::get_recomendacao(std::vector <Produto *> estoque) {
    // Ordenação das categorias por número de compras e não por ordem alfabética
    std::multimap <int, std::string,  std::greater <int>> cat_sorted;

    for (auto cat: get_categorias()) {
        cat_sorted.insert(std::make_pair(cat.second, cat.first));
    }

    // Produtos armazenados pelas categorias mais compradas
    std::map <std::string, int> produtos;

    for (auto cat_cliente: cat_sorted) {
        for (Produto * produto: estoque) {
            for (std::string cat_produto: produto->get_categorias()) {
                if (cat_cliente.second == cat_produto) {
                    if (produtos.size() <= 10) {
                        produtos[produto->get_nome()] = cat_cliente.first;
                    }
                    break;
                }
            }
        }
    }

    // Produtos ordenados por categoria e ordem alfabética
    std::multimap <int, std::string,  std::greater <int>> produtos_sorted;

    for (auto produto: produtos) {
        produtos_sorted.insert(std::make_pair(produto.second, produto.first));
    }
    
    // Retorna a recomendação de produtos, pode ser conferido pelo índice produtos.first 
    std::cout << "Organizados por categoria mais comprada e ordem alfabética:" << std::endl;

    for (auto produtos: produtos_sorted) {
        std::cout << "- " << produtos.second << std::endl;
    }

    std::cout << std::endl;
}