#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <iostream>
#include <vector>
#include "produto.hpp"

class Estoque {
    protected:
        std::vector <Produto *> produtos;
        
    public:
        Estoque();
        ~Estoque();

        std::vector <Produto *> get_produtos();
        Produto * get_produto(int id);
        void carrega_produtos();
        
        bool produto_existe(int id);
        void cadastrar_produto(int id);
        void add_produto(Produto * produto);
        void imprime_produtos(int modo);
        void atualiza_estoque();
        
};

#endif