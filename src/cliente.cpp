#include <vector>
#include <iostream>
#include <fstream>

#include "cliente.hpp"

Cliente::Cliente() {
    this->cpf = "0000";
    this->nome = "";
    this->idade = 1;
    this->email = "";
    this->socio = 0;
    this->categorias = {};
}
Cliente::~Cliente() {

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
        this->socio = socio;
}
void Cliente::add_categoria(std::string categoria) {
    this->categorias.push_back(categoria);
}

bool Cliente::cliente_existe(std::string cpf) {
	std::string nome, email;
	int idade, socio;

    std::string varredura;
	int cliente_existe = 0;
	
	std::ifstream clientes_in;
	clientes_in.open("inc/clientes.txt");

	if (clientes_in.is_open()) {
		// O arquivo de clientes existe
		while (clientes_in >> varredura) {
			if (varredura == cpf && varredura.size() > 3) {
				clientes_in.ignore();
				
				getline(clientes_in, nome);
				clientes_in >> idade >> email >> socio;

				set_cpf(cpf);
				set_nome(nome);
				set_idade((int)idade);
				set_email(email);
				set_socio((int)socio);

				cliente_existe = 1;
				break;
			}
		}
		
		clientes_in.close();

		if (cliente_existe) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		// O arquivo nao existe, entao nenhum cliente existe tambem
		return false;
	}
}

void Cliente::add_cliente(std::string cpf, std::string nome, int idade, std::string email, int socio) {

	std::ofstream clientes_out;
	clientes_out.open("inc/clientes.txt", std::ios::app);

	set_cpf(cpf);
    set_nome(nome);
    set_idade((int)idade);
    set_email(email);
    set_socio((int)socio);
	
	if (clientes_out.is_open()) {
		clientes_out << cpf << std::endl << nome << std::endl << idade << std::endl 
					 << email << std::endl << socio << std::endl << std::endl;
		
		std::cout << "Cadastro realizado e salvo." << std::endl << std::endl;
	}
	else {
		std::cout << "Acesso negado ao tentar salvar." << std::endl << std::endl;
	}

	clientes_out.close();
}