#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <map>
#include <functional>

#include "produto.hpp"

class Cliente {
    private:
        std::string cpf;
        std::string nome;
        int idade;
        std::string email;
        bool socio;
        std::map <std::string, int> categorias;

    public:
        Cliente();
        Cliente(std::string cpf, std::string nome, int idade, std::string email, bool socio,
                std::map <std::string, int> categorias);
        ~Cliente();

        std::string get_cpf();
        std::string get_nome();
        int get_idade();
        std::string get_email();
        bool is_socio();
        std::map <std::string, int> get_categorias();

        void set_nome(std::string nome);
        void set_cpf(std::string cpf);
        void set_idade(int idade);
        void set_email(std::string email);
        void set_socio(int socio);
        void set_categorias(std::map <std::string, int> categorias);

        void add_categoria(std::string cat, int qnt);
        void add_categorias(std::vector <Produto *> carrinho);

        void get_recomendacao(std::vector <Produto *> estoque);
        
};

#endif