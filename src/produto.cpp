#include <string>
#include <vector>
#include <fstream>

#include "produto.hpp"

Produto::Produto() {
    id = 0;
    nome = "";
    preco = 0.0;
    quantidade = 0;
    categorias = {};
}
Produto::Produto(int id, std::string nome, double preco, int quantidade, std::vector<std::string> categorias) {
    this->id = id;
    this->nome = nome;
    this->preco = preco;
    this->quantidade = quantidade;
    this->categorias = categorias;
}
Produto::~Produto() {

}

int Produto::get_id() {
    return this->id;
}
std::string Produto::get_nome() {
    return this->nome;
}
double Produto::get_preco() {
	return this->preco;
}
int Produto::get_quantidade() {
	return this->quantidade;
}
std::vector<std::string> Produto::get_categorias() {
	return this->categorias;
}

void Produto::set_id(int id) {
	this->id = id;
}
void Produto::set_nome(std::string nome) {
	this->nome = nome;
}
void Produto::set_preco(double preco) {
	if (preco >= 0.0)
		this->preco = preco;
}
void Produto::set_quantidade(int quantidade) {
	if (quantidade > 0)
		this->quantidade = quantidade;
}
void Produto::add_categoria(std::string categoria) {
	this->categorias.push_back(categoria);
}
