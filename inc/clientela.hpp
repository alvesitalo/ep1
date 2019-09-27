#ifndef CLIENTELA_HPP
#define CLIENTELA_HPP

#include "cliente.hpp"

class Clientela {
    private:
        std::vector<Cliente *> clientes;
        
    public:
        Clientela();
        ~Clientela();

        std::vector<Cliente *> get_clientes();

        void add_cliente(Cliente * pessoa);
        void carrega_clientes();
        bool cliente_existe(std::string cpf);
        void atualiza_recomendacao();
        
};

#endif