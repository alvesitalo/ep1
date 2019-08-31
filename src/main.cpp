#include <iostream>
#include <fstream>
#include "cliente.hpp"
#include "produto.hpp"
#include "carrinho.hpp"

void adiciona_cliente(std::string cpf) {
	std::string nome;
	int idade;
	std::string email;
	int socio;

	std::cout << "Nome: ";
	std::cin >> nome;
	
	std::cout << "Idade: ";
	std::cin >> idade;

	std::cout << "Email: ";
	std::cin >> email;

	std::cout << "Socio? (1 se sim, 0 se não): ";
	std::cin >> socio;

	Cliente pessoa(cpf, nome, idade, email, socio);

	std::ofstream clientes_out;
	clientes_out.open("clientes.data", std::ios::app);
	
	if (clientes_out.is_open()) {
		clientes_out << pessoa.get_cpf() << std::endl << pessoa.get_nome() << std::endl << pessoa.get_idade() << std::endl 
					 << pessoa.get_email() << std::endl << pessoa.get_socio() << std::endl << std::endl;
	}
	else {
		std::cout << "Acesso negado ao tentar salvar." << std::endl;
	}

	clientes_out.close();
}

void modo_venda(int &inicio) {
	std::cout << "Modo Venda" << std::endl << std::endl;
	
	std::string cpf;
	std::string nome;
	int idade;
	std::string email;
	int socio;
	std::string varredura;
	int cliente_existe = 0;

	Cliente pessoa;

	std::cout << "Insira o CPF do cliente: ";
	std::cin >> cpf;
	std::cout << std::endl;

	std::ifstream clientes_in;
	clientes_in.open("clientes.data");

	if (clientes_in.is_open()) {
		// O arquivo de clientes existe
		while (clientes_in >> varredura) {
			if (varredura == cpf) {
				cliente_existe = 1;

				clientes_in >> nome >> idade >> email >> socio;
				
				pessoa.set_cpf(cpf);
				pessoa.set_nome(nome);
				pessoa.set_idade((int)idade);
				pessoa.set_email(email);
				pessoa.set_socio((int)socio);

				break;
			}
		}

		if (cliente_existe) {
			// Venda
			std::cout << "Cliente: " << pessoa.get_nome() << std::endl << std::endl;
		}
		else {
			// Adiciona o novo cliente
			std::cout << "Nenhum cliente encontrado com esse CPF, deseja cadastrar um novo?" << std::endl;
			std::cout << "Digite 1 se sim, ou 2 para voltar a tela anterior." << std::endl << std::endl;

			int opcao = 0;
			std::cin >> opcao;
			
			switch (opcao) {
				default:
					while (opcao < 1 || opcao > 2) {
						std::cout << "Opcao invalida, tente novamente." << std::endl;
						std::cin.clear();
						std::cin.ignore();
						std::cin >> opcao;
					}
				case 1:
					adiciona_cliente(cpf);
					modo_venda(inicio);
					break;
				case 2:
					// Volta pra tela inicial
					inicio = 1;
					break;
			}
			
		}

		clientes_in.close();
	}
	else {
		// O arquivo de clientes nao existe
		adiciona_cliente(cpf);
		modo_venda(inicio);
	}
}

void modo_estoque(int &inicio) {
	std::cout << "Modo Estoque" << std::endl << std::endl;

	char produto[10];
	std::cout << "Insira o nome do produto: ";
	std::cin >> produto;
}

void modo_recomendacao(int &inicio) {
	std::cout << "Modo de Recomendacao" << std::endl << std::endl;

	char cliente[10];
	std::cout << "Insira o nome do cliente: ";
	std::cin >> cliente;
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