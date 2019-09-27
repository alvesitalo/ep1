#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <iostream>
#include <vector>
#include "produto.hpp"

class Estoque {
    private:
        std::vector<Produto *> produtos;
        
    public:
        Estoque();
        ~Estoque();

        std::vector<Produto *> get_produtos();

        void add_produto(Produto * produto);
        void carrega_produtos();
        void imprime_produtos();
        void atualiza_estoque();
        
};

#endif