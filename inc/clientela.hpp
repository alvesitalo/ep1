#ifndef CLIENTELA_HPP
#define CLIENTELA_HPP

#include "cliente.hpp"

class Clientela {
    private:
        std::vector <Cliente *> clientes;
        
    public:
        Clientela();
        ~Clientela();

        std::vector <Cliente *> get_clientes();
        Cliente * get_cliente(std::string cpf);
        void carrega_clientes();
        
        bool cliente_existe(std::string cpf);
        void cadastrar_cliente(std::string cpf);
        void add_cliente(Cliente * pessoa);
        void atualiza_clientela();
        
};

#endif