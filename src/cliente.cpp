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
				 std::map<std::string, int> categorias) {
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
std::map<std::string, int> Cliente::get_categorias() {
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
void Cliente::set_categorias(std::map<std::string, int> categorias) {
	this->categorias = categorias;
}

void Cliente::add_categoria(std::string cat, int qnt) {
	if (cat.size() > 1)
    	this->categorias[cat] = qnt;
}

void Cliente::add_categoria(std::vector<Produto *> carrinho) {
	int cat_quantidade;

	for (Produto * produto: carrinho) {
		for (std::string cat_produto: produto->get_categorias()) {
			cat_quantidade = categorias[cat_produto] + produto->get_quantidade();
			this->categorias[cat_produto] = cat_quantidade;
		}
	}
}

void Cliente::add_cliente(std::string cpf, std::string nome, int idade, std::string email, bool socio) {
	socio = (int)socio;

	std::ofstream clientes_out;
	clientes_out.open("assets/clientes.txt", std::ios::app);

	set_cpf(cpf);
    set_nome(nome);
    set_idade(idade);
    set_email(email);
    set_socio(socio);
	
	if (clientes_out.is_open()) {
		clientes_out << cpf << std::endl
					 << nome << std::endl
					 << idade << std::endl 
					 << email << std::endl
					 << socio << std::endl
					 << "-" << " 0" << std::endl << std::endl;
		
		std::cout << "Cadastro realizado e salvo." << std::endl << std::endl;
	}
	else {
		std::cout << "Acesso negado ao tentar salvar." << std::endl << std::endl;
	}

	clientes_out.close();
}

void Cliente::cadastro(std::string cpf) {
	std::string nome, email;
	int idade, socio;

	std::cout << "Nome Completo: ";
	std::cin.ignore();
	getline(std::cin, nome);
	
	std::cout << "Idade: ";
	std::cin >> idade;

	std::cout << "Email: ";
	std::cin >> email;

	std::cout << "Socio? (1 se sim, 0 se não): ";
	std::cin >> socio;
	std::cout << std::endl;
	
	add_cliente(cpf, nome, idade, email, socio);
}