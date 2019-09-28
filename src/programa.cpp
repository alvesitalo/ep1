#include "programa.hpp"

Programa::Programa() {
    inicio = true;
}
Programa::~Programa() {}

void Programa::menu() {
    // Carrega o estoque utilizado em qualquer modo do programa
    Estoque deposito;

    std::cout << "***************************************************" << std::endl;
    std::cout << "*     Bem vindo ao seu Programa de Venda v1.0     *" << std::endl;
    std::cout << "*             (c) 1991 - Ítalo Alves              *" << std::endl;
    std::cout << "***************************************************" << std::endl << std::endl;

    std::cout << "Para entrar no Modo Venda digite 1" << std::endl;
    std::cout << "Para entrar no Modo Estoque digite 2" << std::endl;
    std::cout << "Para entrar no Modo Recomendação digite 3" << std::endl;
    std::cout << "Para mais informações abra o arquivo LEIAME." << std::endl;
    std::cout << std::endl;

    switch (getint(1, 3)) {
        case 1:
            modo_venda(deposito);
            break;
        case 2:
            modo_estoque(deposito);
            break;
        case 3:
            modo_recomendacao(deposito);
            break;
    }
}

void Programa::modo_venda(Estoque &deposito) {
    std::cout << "[Modo Venda]" << std::endl << std::endl;
    
	// Inicia o carrinho e mostra apenas produtos com estoque maior que 0 (modo 1)
    Carrinho cesta;

    deposito.imprime_produtos(1);

    std::cout << "Adicione produtos ao carrinho inserindo o código (ID)" << std::endl;
    std::cout << "Digite somente 0 para ir ao carrinho." << std::endl << std::endl;

    int opcao = 1, id = 1;

    while (opcao != 0) {
        while (id != 0) {
            std::cout << "Insira o código do produto: ";
            id = getint(0, INT_MAX);

            if (id != 0)
                cesta.atualiza_carrinho(id, deposito.get_produtos());
            else
                cesta.imprime_produtos(false);
        }

        if (cesta.get_produtos().size() >= 1) 
            std::cout << "Para seguir com o checkout digite 0" << std::endl;
        
        std::cout << "Para voltar e continuar adicionando produtos, digite 1" << std::endl;
        std::cout << "Para cancelar a compra e voltar ao menu, digite 2" << std::endl;

        switch (getint(0, 2)) {
            case 0:
                // Procede o checkout apenas se houver produtos no carrinho
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
                opcao = 0;
                cesta.cancelar_compra();
                menu();
                break;
        }
    }
    
    // Compra encerrada caso não exista itens suficientes no estoque
    if (!cesta.possui_estoque()) {
        std::cout << "Compra cancelada: Não há items suficientes em estoque" << std::endl;
        cesta.cancelar_compra();
        modo_venda(deposito);
    }

    // Identificação do cliente
    Clientela clientes;
    std::string cpf;

    do {
        std::cout << "Insira o CPF do cliente: ";
	    std::cin >> cpf;
	    std::cout << std::endl;
    
        if (!clientes.cliente_existe(cpf)) {
            std::cout << "Nenhum cliente encontrado com esse CPF, deseja cadastrar um novo?" << std::endl;
            std::cout << "Digite 1 se sim, ou 0 para digitar novamente." << std::endl << std::endl;
            
            switch (getint(0, 1)) {
                case 0:
                    break;
                case 1:
                    clientes.cadastrar_cliente(cpf);
                    break;
            }
        }
    
    } while (!clientes.cliente_existe(cpf));
    
    // Cliente identificado
    Cliente * pessoa = clientes.get_cliente(cpf);

    std::cout << "Cliente: " << pessoa->get_nome() << std::endl;
    std::cout << "Email: " << pessoa->get_email() << std::endl;

    if (pessoa->is_socio())
        std::cout << "Sócio com 15% de desconto" << std::endl;

    std::cout << std::endl;

    cesta.imprime_produtos(pessoa->is_socio());

    // Pagamento
    std::cout << "Escolha o método de pagamento:" << std::endl;
    std::cout << "1 - Dinheiro" << std::endl;
    std::cout << "2 - Cartão" << std::endl;

    double dinheiro = 0.0;

    switch (getint(1, 2)) {
        case 1:
        // Dinheiro
            while (dinheiro < cesta.get_total()) {
                std::cout << "Digite o valor recebido: $";
                std::cin >> dinheiro;
            }

            std::cout << std::endl;
            std::cout << "Troco: $" << dinheiro - cesta.get_total() << std::endl;
            
            pessoa->add_categorias(cesta.get_produtos());
            clientes.atualiza_clientela();
            deposito.atualiza_estoque();
            
            cesta.finalizar_compra();
            break;
        case 2:
        // Cartão
            dinheiro = cesta.get_total();

            std::cout << "Insira ou passe cartão..." << std::endl;
            std::cout << "$" << dinheiro << " pagos" << std::endl;
            
            pessoa->add_categorias(cesta.get_produtos());
            clientes.atualiza_clientela();
            deposito.atualiza_estoque();
            
            cesta.finalizar_compra();
            break;
    }
}

void Programa::modo_estoque(Estoque &deposito) {
    std::cout << "[Modo Estoque]" << std::endl << std::endl;

    // Mostra todo o estoque, incluindo produtos com estoque igual a 0 (modo 2)
    deposito.imprime_produtos(2);

    // Identificação do produto
    int id;

    do {
        std::cout << "Insira o código do produto: ";
	    std::cin >> id;
	    std::cout << std::endl;
    
        if (!deposito.produto_existe(id)) {
            std::cout << "Nenhum produto encontrado com esse ID, deseja cadastrar um novo?" << std::endl;
            std::cout << "Digite 1 se sim, ou 0 para digitar novamente." << std::endl << std::endl;
            
            switch (getint(0, 1)) {
                case 0:
                    break;
                case 1:
                    deposito.cadastrar_produto(id);
                    break;
            }
        }
    
    } while (!deposito.produto_existe(id));

    // Produto identificado
    Produto * item = deposito.get_produto(id);
    unsigned cat_count = 1;

    std::cout << "Item: " << item->get_nome() << std::endl;
    std::cout << "Preço: $" << item->get_preco() << std::endl;
    std::cout << "Quantidade no estoque: " << item->get_estoque() << std::endl;
    std::cout << "Categoria(s): ";
    
    for (std::string categoria: item->get_categorias()) {
        if (cat_count < item->get_categorias().size()) {
            std::cout << categoria << ", ";
        }
        else {
            std::cout << categoria << ".";
        }
        cat_count++;
    }

    std::cout << std::endl << std::endl;

    // Realiza as modificações necessárias no produto
    bool edicao = true;

    while (edicao) {
        std::cout << "Alterar o nome: digite 1" << std::endl;
        std::cout << "Alterar o preço: digite 2" << std::endl;
        std::cout << "Alterar o estoque: digite 3" << std::endl;
        std::cout << "Digite 0 para voltar ao menu." << std::endl;

        std::string nome;
        double preco;
        int estoque;

        switch (getint(0, 3)) {
            case 1:
                std::cout << "Novo nome: ";
                std::cin.ignore();
                getline(std::cin, nome);
                std::cout << std::endl;

                item->set_nome(nome);
                break;
            case 2:
                std::cout << "Novo preço: $";
                std::cin >> preco;
                std::cout << std::endl;

                item->set_preco(preco);
                break;
            case 3:
                std::cout << "Novo estoque: ";
                std::cin >> estoque;
                std::cout << std::endl;

                item->set_estoque(estoque);
                break;
            case 0:
            // Volta ao menu principal
                edicao = false;
                break;
        }

        deposito.atualiza_estoque();
    }
}

void Programa::modo_recomendacao(Estoque &deposito) {
    std::cout << "[Modo de Recomendação]" << std::endl << std::endl;

    // Identificação do cliente
    Clientela clientes;
    std::string cpf;

    do {
        std::cout << "Insira o CPF do cliente: ";
	    std::cin >> cpf;
	    std::cout << std::endl;
    
        if (!clientes.cliente_existe(cpf)) {
            std::cout << "Nenhum cliente encontrado com esse CPF" << std::endl;
            std::cout << "Digite 0 para ir ao menu, ou 1 para digitar novamente." << std::endl << std::endl;
            
            switch (getint(0, 1)) {
                case 0:
                    menu();
                    break;
                case 1:
                    break;
            }
        }
    
    } while (!clientes.cliente_existe(cpf));

    // Cliente é identificado
    Cliente * pessoa = clientes.get_cliente(cpf);

    std::cout << "Cliente: " << pessoa->get_nome() << std::endl;
    std::cout << "Idade: " << pessoa->get_idade() << std::endl << std::endl;

    // Retorna a recomendação de acordo com as categorias mais compradas
    std::cout << "Produtos recomendados para o cliente:" << std::endl << std::endl;
    pessoa->get_recomendacao(deposito.get_produtos());

    inicio = false;
}

int Programa::getint(int min, int max) {
    int opcao;
    std::cin >> opcao;

    while (opcao < min || opcao > max) {
       std::cout << "Opcao inválida, tente novamente." << std::endl;
       std::cin.clear();
       std::cin.ignore();
       std::cin >> opcao;
    }
    
    std::cout << std::endl;
    return opcao;
}