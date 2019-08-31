#include "cliente.hpp"
#include <vector>

Cliente::Cliente() {
    this->cpf = "0";
    this->nome = "";
    this->idade = 0;
    this->email = "";
    this->socio = 0;
    categorias = {};
}
Cliente::~Cliente() {

}
Cliente::Cliente(std::string cpf, std::string nome, int idade, std::string email, int socio) {
    set_cpf(cpf);
    set_nome(nome);
    set_idade(idade);
    set_email(email);
    set_socio(socio);
}

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
int Cliente::get_socio() {
    return this->socio;
}
std::vector<std::string> Cliente::get_categorias() {
    return this->categorias;
}

void Cliente::set_cpf(std::string cpf) {
    this->cpf = cpf;
}
void Cliente::set_nome(std::string nome) {
    this->nome = nome;
}
void Cliente::set_idade(int idade) {
    this->idade = idade;
}
void Cliente::set_email(std::string email) {
    this->email = email;
}
void Cliente::set_socio(int socio) {
    if (socio == 1) {
        this->socio = socio;
    }
}
void Cliente::add_categoria(std::string categoria) {
    this->categorias.push_back(categoria);
}