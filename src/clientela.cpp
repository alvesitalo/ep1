#include "clientela.hpp"

Clientela::Clientela() {
	carrega_clientes();
}
Clientela::~Clientela() {}

std::vector<Cliente *> Clientela::get_clientes() {
    return this->clientes;
}

void Clientela::add_cliente(Cliente * pessoa) {
    this->clientes.push_back(pessoa);
}

void Clientela::carrega_clientes() {
    std::string cpf, nome, email;
	int idade, socio;

	std::map<std::string, int> categorias;
	std::string cat;
	int qnt;
	
	std::ifstream clientes_in;
	clientes_in.open("assets/clientes.txt");

	if (clientes_in.is_open()) {
		while (clientes_in >> cpf) {
			clientes_in.ignore();
			getline(clientes_in, nome);

			clientes_in >> idade >> email >> socio >> cat >> qnt;

			categorias.clear();

			while (cat != "-") {
				categorias.insert(make_pair(cat, qnt));
				clientes_in >> cat >> qnt;
			}

			this->clientes.push_back(new Cliente(cpf, nome, idade, email, socio, categorias));
		}
	}
	else {
		std::cout << "Nao e possivel abrir o arquivo de clientes." << std::endl;
	}
	
	clientes_in.close();
}

bool Clientela::cliente_existe(std::string cpf) {
	for (Cliente * cliente: get_clientes()) {
		if (cpf == cliente->get_cpf()) {

			pessoa->set_cpf(cliente->get_cpf());
			pessoa->set_nome(cliente->get_nome());
			pessoa->set_idade(cliente->get_idade());
			pessoa->set_email(cliente->get_email());
			pessoa->set_socio(cliente->is_socio());
			pessoa->set_categorias(cliente->get_categorias());

			return true;
		}
	}

	return false;
}

void Clientela::atualiza_recomendacao() {
	bool escrita_realizada = true;
	
	std::ofstream clientes_out;
	clientes_out.open("assets/clientes.txt");

	for (Cliente * cliente: get_clientes()) {		
		if (clientes_out.is_open()) {
			clientes_out << cliente->get_cpf() << std::endl
						 << cliente->get_nome() << std::endl
						 << cliente->get_idade() << std::endl
						 << cliente->get_email() << std::endl
						 << (int)cliente->is_socio() << std::endl;

			for (auto cat: cliente->get_categorias()) {
				clientes_out << cat.first << " " << cat.second << std::endl;
			}

			clientes_out << "-" << " 0" << std::endl << std::endl;
		}
		else {
			escrita_realizada = false;
		}

		for(auto cat: cliente->get_categorias()) {
			std::cout << "Cliente:" << cat.first << " " << cat.second << std::endl;
		}
	}

	if (!escrita_realizada) {
		std::cout << "Acesso negado ao tentar salvar." << std::endl;
	}

	clientes_out.close();

}