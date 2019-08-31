#include <iostream>
#include <vector>
#include "produto.hpp"

class Carrinho {
    private:
        std::vector<Produto> produtos;
        int quantidade;
        double valor_produtos;
        double desconto;
        double total;
        
    public:
        Carrinho();

        std::vector<Produto> get_produtos();
        int get_quantidade();
        double get_valor_produtos();
        double get_desconto();
        double get_total();
       
        void add_produto(Produto produto);
        void cancelar_compra();
        void finalizar_compra();
};