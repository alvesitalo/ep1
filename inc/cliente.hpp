#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>
#include <vector>

class Cliente {
    private:
        std::string cpf;
        std::string nome;
        int idade;
        std::string email;
        int socio;
        std::vector<std::string> categorias;

    public:
        Cliente();
        ~Cliente();
        Cliente(std::string cpf, std::string nome, int idade, std::string email, int socio);

        std::string get_cpf();
        std::string get_nome();
        int get_idade();
        std::string get_email();
        int get_socio();
        std::vector<std::string> get_categorias();

        void set_nome(std::string nome);
        void set_cpf(std::string cpf);
        void set_idade(int idade);
        void set_email(std::string email);
        void set_socio(int socio);
        void add_categoria(std::string categoria);
};

#endif