#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <string>
#include <vector>

class Produto {
    private:
        int id;
        std::string nome;
        double preco;
        int quantidade;
        std::vector<std::string> categorias;

    public:
        Produto();
        Produto(int id, std::string nome, double preco, int quantidade, std::vector<std::string> categorias);
        ~Produto();

        int get_id();
        std::string get_nome();
        double get_preco();
        int get_quantidade();
        std::vector<std::string> get_categorias();
        
        void set_id(int id);
        void set_nome(std::string nome);
        void set_preco(double preco);
        void set_quantidade(int quantidade);
        void add_categoria(std::string categoria);

};

#endif