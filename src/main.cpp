#include "cliente.hpp"
#include "produto.hpp"
#include "carrinho.hpp"

void modo_venda(int &inicio) {
	std::cout << "Modo Venda" << std::endl << std::endl;
	
	Cliente pessoa;
	std::string cpf, nome, email;
	int idade, socio;

	std::cout << "Insira o CPF do cliente: ";
	std::cin >> cpf;
	std::cout << std::endl;

	if (!pessoa.cliente_existe(cpf)) {
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
				
				pessoa.add_cliente(cpf, nome, idade, email, socio);

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

	int id;
	std::cout << "Insira o codigo do produto: ";
	std::cin >> id;

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