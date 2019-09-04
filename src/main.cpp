#include "cliente.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
#include <iostream>
#include <fstream>

void adiciona_cliente(std::string cpf, Cliente &pessoa) {
	std::string nome;
	int idade;
	std::string email;
	int socio;
	
	pessoa.set_cpf(cpf);

	std::cout << "Nome Completo: ";
	std::cin.ignore();
	getline(std::cin, nome);
	pessoa.set_nome(nome);
	
	std::cout << "Idade: ";
	std::cin >> idade;
	pessoa.set_idade((int)idade);

	std::cout << "Email: ";
	std::cin >> email;
	pessoa.set_email(email);

	std::cout << "Socio? (1 se sim, 0 se não): ";
	std::cin >> socio;
	pessoa.set_socio((int)socio);
	std::cout << std::endl;
	
	std::ofstream clientes_out;
	clientes_out.open("doc/clientes.data", std::ios::app);
	
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

int verifica_cliente(std::string cpf, Cliente &pessoa) {
	std::string nome;
	int idade;
	std::string email;
	int socio;
    std::string varredura;

	int cliente_existe;

    std::ifstream clientes_in;
	clientes_in.open("doc/clientes.data");

	if (clientes_in.is_open()) {
		// O arquivo de clientes existe
		while (clientes_in >> varredura) {
			if (varredura == cpf && varredura.size() > 3) {
				clientes_in.ignore();
				
				getline(clientes_in, nome);
				clientes_in >> idade >> email >> socio;

				pessoa.set_cpf(cpf);
				pessoa.set_nome(nome);
				pessoa.set_idade((int)idade);
				pessoa.set_email(email);
				pessoa.set_socio((int)socio);

				cliente_existe = 1;
				break;
			}
		}
		
		clientes_in.close();

		if (cliente_existe) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		// O arquivo nao existe, entao nenhum cliente existe tambem
		return 0;
	}
}

void modo_venda(int &inicio) {
	std::cout << "Modo Venda" << std::endl << std::endl;
	
	std::string cpf;
	std::cout << "Insira o CPF do cliente: ";
	std::cin >> cpf;
	std::cout << std::endl;

	Cliente pessoa;

	if (!verifica_cliente(cpf, pessoa)) {
		std::cout << "Nenhum cliente encontrado com esse CPF, deseja cadastrar um novo?" << std::endl;
		std::cout << "Digite 1 se sim, ou 2 para voltar a tela anterior." << std::endl << std::endl;

		int opcao = 0;
		std::cin >> opcao;
		std::cout << std::endl;
		
		switch (opcao) {
			default:
				while (opcao < 1 || opcao > 2) {
					std::cout << "Opcao invalida, tente novamente." << std::endl;
					std::cin.clear();
					std::cin.ignore();
					std::cin >> opcao;
				}
			case 1:
				adiciona_cliente(cpf, pessoa);
				break;
			case 2:
				// Volta pra tela inicial
				inicio = 1;
				break;
		}
		
	}
	
	std::cout << "Cliente: " << pessoa.get_nome() << std::endl;
}

void modo_estoque(int &inicio) {
	std::cout << "Modo Estoque" << std::endl << std::endl;

	char produto[10];
	std::cout << "Insira o nome do produto: ";
	std::cin >> produto;

	inicio = 0;
}

void modo_recomendacao(int &inicio) {
	std::cout << "Modo de Recomendacao" << std::endl << std::endl;

	char cliente[10];
	std::cout << "Insira o nome do cliente: ";
	std::cin >> cliente;

	inicio = 0;
}

int main() {
	int inicio = 0;

	do {
		inicio = 0;

		std::cout << "***************************************************" << std::endl;
		std::cout << "*     Bem vindo ao seu Programa de Venda v1.0     *" << std::endl;
		std::cout << "*             (c) 1991 - Italo Alves              *" << std::endl;
		std::cout << "***************************************************" << std::endl << std::endl;

		int opcao = 0;
		std::cout << "Para entrar no Modo Venda digite 1" << std::endl;
		std::cout << "Para entrar no Modo Estoque digite 2" << std::endl;
		std::cout << "Para entrar no Modo Recomendacao digite 3" << std::endl;
		std::cout << "Para mais informacoes abra o arquivo LEIAME." << std::endl << std::endl;
		std::cin >> opcao;

		switch (opcao) {
			default:
				while (opcao < 1 || opcao > 3) {
					std::cout << "Opcao invalida, tente novamente." << std::endl;
					std::cin.clear();
					std::cin.ignore();
					std::cin >> opcao;
				}
			case 1:
				modo_venda(inicio);
				break;
			case 2:
				modo_estoque(inicio);
				break;
			case 3:
				modo_recomendacao(inicio);
				break;
		}

	} while (inicio != 0);

	return 0;
}