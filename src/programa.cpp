#include <limits>

#include "programa.hpp"

Programa::Programa() {
    inicio = false;
}
Programa::~Programa() {}

void Programa::menu() {
    std::cout << "***************************************************" << std::endl;
    std::cout << "*     Bem vindo ao seu Programa de Venda v1.0     *" << std::endl;
    std::cout << "*             (c) 1991 - Italo Alves              *" << std::endl;
    std::cout << "***************************************************" << std::endl << std::endl;

    std::cout << "Para entrar no Modo Venda digite 1" << std::endl;
    std::cout << "Para entrar no Modo Estoque digite 2" << std::endl;
    std::cout << "Para entrar no Modo Recomendacao digite 3" << std::endl;
    std::cout << "Para mais informacoes abra o arquivo LEIAME." << std::endl;
    std::cout << std::endl;

    switch (getint(1, 3)) {
        case 1:
            modo_venda();
            break;
        case 2:
            modo_estoque();
            break;
        case 3:
            modo_recomendacao();
    }
}

void Programa::modo_venda() {
    std::cout << "[Modo Venda]" << std::endl << std::endl;

	Clientela clientes;	
	
	std::string cpf;
	std::cout << "Insira o CPF do cliente: ";
	std::cin >> cpf;
	std::cout << std::endl;

    bool cliente_existe;
    
	if (!clientes.cliente_existe(cpf)) {
		std::cout << "Nenhum cliente encontrado com esse CPF, deseja cadastrar um novo?" << std::endl;
		std::cout << "Digite 1 se sim, ou 0 para voltar a tela anterior." << std::endl << std::endl;
		
		switch (getint(0, 1)) {
            case 0:
				inicio = true;
				break;
			case 1:
				//pessoa.cadastro(cpf);
		}
	}
    else {
        Cliente pessoa;
        //pessoa.set_cliente(clientes.get_clientes());

        Carrinho cesta;

        std::cout << "Cliente: " << pessoa.get_nome() << std::endl;
        std::cout << "Email: " << pessoa.get_email() << std::endl;
        
        if (pessoa.is_socio())
            std::cout << "Socio com 15% de desconto" << std::endl;
        
        std::cout << std::endl;

        Estoque deposito;
        deposito.imprime_produtos();

        std::cout << "Adicione produtos ao carrinho inserindo o codigo (ID)" << std::endl;
        std::cout << "Digite somente 0 para ir ao carrinho." << std::endl << std::endl;
        
        int opcao = 1, id = 1;

        while (opcao != 0) {
            while (id != 0) {
                std::cout << "Insira o codigo do produto: ";
                id = getint(0, std::numeric_limits<int>::max());

                if (id != 0)
                    cesta.atualiza_carrinho(id, deposito.get_produtos());
                else
                    cesta.imprime_carrinho(pessoa.is_socio());
            }

            if (cesta.get_produtos().size() >= 1) 
                std::cout << "Para seguir com o checkout digite 0" << std::endl;
            
            std::cout << "Para voltar e continuar adicionando produtos, digite 1" << std::endl;
            std::cout << "Para cancelar a compra e voltar ao Modo Venda, digite 2" << std::endl;

            switch (getint(0, 2)) {
                case 0 :
                    if (cesta.get_produtos().size() >= 1) {
                        opcao = 0;
                        break;
                    }
                    else {
                        break;
                    }
                case 1:
                    id = 1;
                    break;
                case 2:
                    cesta.cancelar_compra();
                    modo_venda();
            }
        }

        if (cesta.possui_estoque()) {
            std::cout << "Escolha o metodo de pagamento:" << std::endl;
            std::cout << "1 - Dinheiro" << std::endl;
            std::cout << "2 - Cartao" << std::endl;

            double dinheiro = 0.0;

            switch (getint(1, 2)) {
                case 1:
                    while (dinheiro < cesta.get_total()) {
                        std::cout << "Digite o valor recebido: $";
                        std::cin >> dinheiro;
                    }
                    
                    pessoa.add_categoria(cesta.get_produtos());
                    clientes.atualiza_recomendacao();

                    std::cout << std::endl;
                    std::cout << "Troco: $" << dinheiro - cesta.get_total() << std::endl;

                    deposito.atualiza_estoque();
                    cesta.finalizar_compra();

                    break;
                case 2:
                    dinheiro = cesta.get_total();

                    pessoa.add_categoria(cesta.get_produtos());
                    clientes.atualiza_recomendacao();

                    for(auto cat: pessoa.get_categorias()) {
                        std::cout << "Pessoa:" << cat.first << " " << cat.second << std::endl;
                    }

                    std::cout << "Insira ou passe cartao..." << std::endl;
                    std::cout << "$" << dinheiro << " pagos" << std::endl;

                    deposito.atualiza_estoque();
                    cesta.finalizar_compra();
            }
        }
        else {
            std::cout << "Compra cancelada: Nao ha items suficientes em estoque" << std::endl;
            cesta.~Carrinho();
            cesta.cancelar_compra();
            modo_venda();
        }
    }
}

void Programa::modo_estoque() {
    std::cout << "[Modo Estoque]" << std::endl << std::endl;
}

void Programa::modo_recomendacao() {
    std::cout << "[Modo de Recomendacao]" << std::endl << std::endl;
}

int Programa::getint(int min, int max) {
    int opcao;
    std::cin >> opcao;

    while (opcao < min || opcao > max) {
       std::cout << "Opcao invalida, tente novamente." << std::endl;
       std::cin.clear();
       std::cin.ignore();
       std::cin >> opcao;
    }
    
    std::cout << std::endl;

    return opcao;
}

void Programa::run() {
    do {
        inicio = false;
		menu();
	} while (inicio);
}
