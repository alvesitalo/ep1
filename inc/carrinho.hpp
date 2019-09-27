#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <iomanip>
#include <fstream>
#include "produto.hpp"

class Carrinho {
    private:
        std::vector<Produto *> produtos;
        double valor_produtos;
        double desconto;
        double total;
        
    public:
        Carrinho();
        ~Carrinho();

        std::vector<Produto *> get_produtos();
        double get_valor_produtos();
        double get_desconto();
        double get_total();
       
        void add_produto(Produto * produto);
		void add_valor_produto(int valor);
		void set_desconto(int desconto);
		void set_total(int total);

        void imprime_carrinho(bool socio);
        void atualiza_carrinho(int id, std::vector <Produto *> estoque);
        bool possui_estoque();
        void cancelar_compra();
        void finalizar_compra();
        
};

#endif