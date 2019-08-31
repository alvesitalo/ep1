#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <string>
#include <vector>

class Produto {
    private:
        std::string nome;
        long long id;
        double preco;
        std::vector<std::string> categorias;
        int quantidade;

    public:
        Produto();
        ~Produto();

        std::string get_nome();
        long long get_id();
        double get_preco();
        std::vector<std::string> get_categorias();
        int get_quantidade();
        
        void set_nome(std::string nome);
        void set_id(long long id);
        void set_preco(double preco);
        void add_categoria(std::string categoria);
        void set_quantidade(int quantidade);
};

#endif