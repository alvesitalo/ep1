#include "carrinho.hpp"

Carrinho::Carrinho() {
	produtos = {};
	valor_produtos = 0.0;
	desconto = 0.0;
	total = 0.0;
}
Carrinho::~Carrinho() {}

double Carrinho::get_valor_produtos() {
    return this->valor_produtos;
}

double Carrinho::get_desconto() {
    return this->desconto;
}

double Carrinho::get_total() {
    return this->total;
}

void Carrinho::add_valor_produto(int valor) {
	this->valor_produtos += valor;
}

void Carrinho::set_desconto(int desconto) {
	this->desconto = desconto;
}

void Carrinho::set_total(int total) {
	this->total = total;
}

void Carrinho::imprime_produtos(bool socio) {
	std::cout << "\tProdutos no carrinho (" << get_produtos().size() << "):" << std::endl << std::endl;

	for (Produto * produto: this->produtos) {
		std::cout << std::fixed << std::showpoint << std::setprecision(2)
				  << "\t" << std::left << std::setw(30)
				  << produto->get_nome()
				  << "Valor: $" << std::setw(20)
				  << produto->get_preco()
				  << "Quantidade: " << std::setw(20)
				  << produto->get_quantidade()
				  << "ID: " << std::setw(20)
				  << produto->get_id()
				  << std::endl;
	}
	
	std::cout << std::endl;

	if (socio) {
		set_desconto(get_valor_produtos() * 0.15);
	}
	
	set_total(get_valor_produtos() - get_desconto());

	std::cout << std::fixed << std::showpoint << std::setprecision(2) 
			  << "\t" << std::left
			  << "Total: $" << std::setw(20)
			  << get_total()
			  << "Valor dos produtos: $" << std::setw(20)
			  << get_valor_produtos()
			  << "Desconto: $" << std::setw(20)
			  << get_desconto()
			  << std::endl;

	std::cout << std::endl;
}

void Carrinho::atualiza_carrinho(int id, std::vector <Produto *> estoque) {
	bool produto_existe = false;
	bool produto_repetido = false;

	for (Produto * produto: estoque) {
		if (produto->get_id() == id) {
			produto_existe = true;

			for (Produto * carrinho: get_produtos()) {
				if (produto->get_id() == carrinho->get_id()) {
					produto_repetido = true;

					carrinho->add_quantidade();
					add_valor_produto(carrinho->get_preco());
					
					std::cout << "Item '" << carrinho->get_nome() << "' acrescentado." << std::endl << std::endl;
					break;
				}
			}

			if (!produto_repetido) {
				if (produto->get_estoque() > 0) {
					add_produto(produto);
					add_valor_produto(produto->get_preco());
					
					std::cout << "Item '" << produto->get_nome() << "' adicionado." << std::endl << std::endl;
					break;
				}
				else {
					produto_existe = false;
				}
			}
		}
	}

	if (!produto_existe) {
		std::cout << "Não existe este item no estoque."  << std::endl << std::endl;
	}
}

bool Carrinho::possui_estoque() {
	for (Produto * produto: get_produtos()) {
		if (produto->get_quantidade() > produto->get_estoque())
			return false;
	}

	return true;
}

void Carrinho::cancelar_compra() {
	this->produtos.clear();
	std::cout << "Carrinho encerrado." << std::endl << std::endl;
}

void Carrinho::finalizar_compra() {
	this->produtos.clear();
	std::cout << "Compra realizada! Obrigado pela preferência." << std::endl << std::endl;
}