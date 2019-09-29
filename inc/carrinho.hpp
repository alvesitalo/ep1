#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include "produto.hpp"
#include "estoque.hpp"

class Carrinho: public Estoque {
    private:
        double valor_produtos;
        double desconto;
        double total;
        
    public:
        Carrinho();
        ~Carrinho();

        double get_valor_produtos();
        double get_desconto();
        double get_total();

		void add_valor_produto(int valor);
		void set_desconto(int desconto);
		void set_total(int total);

        void imprime_produtos(bool socio);
        void atualiza_carrinho(int id, std::vector <Produto *> estoque);
        bool possui_estoque();
        void cancelar_compra();
        void finalizar_compra();
        
};

#endif