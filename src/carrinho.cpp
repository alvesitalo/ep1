#include "carrinho.hpp"

Carrinho::Carrinho() {
	produtos = {};
	quantidades = {};
	valor_produtos = 0.0;
	desconto = 0.0;
	total = 0.0;
}
Carrinho::~Carrinho(){

}

std::vector<Produto> Carrinho::get_produtos() {
    return this->produtos;
}
std::vector<int> Carrinho::get_quantidade() {
    return this->quantidades;
}
double Carrinho::get_valor_produtos() {
    return this->valor_produtos;
}
double Carrinho::get_desconto() {
    return this->desconto;
}
double Carrinho::get_total() {
    return this->total;
}

void Carrinho::add_produto(Produto produto) {
    this->produtos.push_back(produto);
}
void Carrinho::add_quantidade(int quantidade) {
	this->quantidades.push_back(quantidade);
}
void Carrinho::set_valor_produtos(int valor) {
	this->valor_produtos = valor;
}
void Carrinho::set_desconto(int desconto) {
	this->desconto = desconto;
}
void Carrinho::set_total(int total) {
	this->total = total;
}
void Carrinho::cancelar_compra() {

}
void Carrinho::finalizar_compra() {

}