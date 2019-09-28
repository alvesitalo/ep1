#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include <climits>

#include "cliente.hpp"
#include "clientela.hpp"
#include "produto.hpp"
#include "estoque.hpp"
#include "carrinho.hpp"

class Programa {
    public:
        bool inicio;

        Programa();
        ~Programa();

        void menu();
        void modo_venda(Estoque &deposito);
        void modo_estoque(Estoque &deposito);
        void modo_recomendacao(Estoque &deposito);
        int getint(int min, int max);

};

#endif