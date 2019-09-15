#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <iostream>
#include <vector>
#include "produto.hpp"

class Carrinho {
    private:
        std::vector<Produto> produtos;
        std::vector<int> quantidades;
        double valor_produtos;
        double desconto;
        double total;
        
    public:
        Carrinho();
        ~Carrinho();

        std::vector<Produto> get_produtos();
        std::vector<int> get_quantidade();
        double get_valor_produtos();
        double get_desconto();
        double get_total();
       
        void add_produto(Produto produto);
		void add_quantidade(int quantidade);
		void set_valor_produtos(int valor);
		void set_desconto(int desconto);
		void set_total(int total);
        void cancelar_compra();
        void finalizar_compra();
        
};

#endif