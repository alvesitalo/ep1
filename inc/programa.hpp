#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include <iostream>

#include "cliente.hpp"
#include "clientela.hpp"
#include "produto.hpp"
#include "estoque.hpp"
#include "carrinho.hpp"

class Programa {
    private:
        bool inicio;
        
    public:
        Programa();
        ~Programa();

        void menu();
        void modo_venda();
        void modo_estoque();
        void modo_recomendacao();
        int getint(int min, int max);
        void run();

};

#endif