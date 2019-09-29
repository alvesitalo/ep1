# LEIA ME - Programa de Venda v1.0

O Programa de Venda é um *software* para organização de vendas, clientes e estoque de produtos em um comércio.

## Dependências

Bibliotecas de C++ necessárias:

```
<climits>
<fstream>
<functional>
<iomanip>
<iostream>
<map>
<string>
<vector>
```

## Instalação

No terminal digite o seguinte comando:

```
make
```

E depois digite o outro comando:

```
make run
```

Se for feita alguma alteração nos arquivos, é necessário entrar com o seguinte comando antes dos outros anteriores:

```
make clean
```

## Utilização

### Menu

        ***************************************************
        *     Bem vindo ao seu Programa de Venda v1.0     *
        *             (c) 1991 - Ítalo Alves              *
        ***************************************************
    
        Para entrar no Modo Venda digite 1
        Para entrar no Modo Estoque digite 2
        Para entrar no Modo Recomendação digite 3
        Para mais informações abra o arquivo LEIAME.

* A tela inicial do programa é o **Menu**, nele você pode entrar em qualquer Modo: basta digitar o número correspondente e teclar *Enter*.
* Para todas as opções em qualquer Modo se digita o número e pressiona a tecla *Enter*.
 
------------


### 1. Modo Venda

    [Modo Venda]
    
        Produtos em estoque:
        
        Produto 1                     Valor: $10.00               Estoque: 5                   ID: 1
        Produto 2                     Valor: $5.00                Estoque: 2                   ID: 2
        Produto 3                     Valor: $1.99                Estoque: 10                  ID: 3
    
    Adicione produtos ao carrinho inserindo o código (ID)
    Digite somente 0 para ir ao carrinho.

* Ao entrar no **Modo Venda**, é exibido os produtos em estoque que estão prontos para a compra.
* Para adicionar o produto ao carrinho, digite o ID correspondente e tecle *Enter*.
* Digite 0 no lugar de ID do produto para ir ao carrinho.
<br>


        Insira o código do produto: 1
        Item 'Produto 1' adicionado.
    
        Insira o código do produto: 2
        Item 'Produto 2' adicionado.
    
        Insira o código do produto: 2
        Item 'Produto 2' acrescentado.
    
        Insira o código do produto: 0

* Após adicionar os produtos desejados e ter digitado 0, o carrinho é mostrado.
<br>


        Produtos no carrinho (2):

        Produto 1                     Valor: $10.00               Quantidade: 1                   ID: 1
        Produto 2                     Valor: $5.00                Quantidade: 2                   ID: 2                   

        Total: $15.00               Valor dos produtos: $15.00               Desconto: $0.00                

    Para seguir com o checkout digite 0
    Para voltar e continuar adicionando produtos, digite 1
    Para cancelar a compra e voltar ao menu, digite 2

* Assumindo que a compra está correta, digitando 0 é prosseguido o checkout.
<br>


    Insira o CPF do cliente: 1234 

    Cliente: Sem Nome
    Email: sem-nome@email.com
    Sócio com 15% de desconto

        Produtos no carrinho (2):

        Bolo de aniversario           Valor: $10.00               Quantidade: 1                   ID: 1                   
        Refri Sem Acucar              Valor: $5.00                Quantidade: 2                   ID: 2                   

        Total: $17.00               Valor dos produtos: $20.00               Desconto: $3.00                

    Escolha o método de pagamento:
    1 - Dinheiro
    2 - Cartão

* É solicitado o CPF do cliente, se ele tiver correto, será mostrará o carrinho; se não, o cliente será cadastrado.
* O CPF deve ser digitado por **apenas números**.
* Se o cliente for sócio, 15% de desconto será aplicado ao carrinho.
* Depois de mostrado o carrinho, é escolhido as formas de pagamento: Dinheiro ou Cartão.
<br>


    Digite o valor recebido: $

* Se o método escolhido for Dinheiro, o atendente digitará o dinheiro recebido.
* Logo após, será mostrado o troco.
<br>


    Compra realizada! Obrigado pela preferência.

* Se o método escolhido for Cartão, é solicitado que se passe o cartão e logo a compra é finalizada.
* As categorias de cada produto e a quantidade são adicionadas ao cliente que fez a compra.
* O estoque dos produtos é alterado.

------------


### 2. Modo Estoque
    
    [Modo Estoque]

        Produtos em estoque:

        Produto 1                     Valor: $10.00               Estoque: 1                   ID: 1
        Produto 2                     Valor: $5.00                Estoque: 2                   ID: 2

    Insira o código do produto: 

* Ao entrar no **Modo Estoque**, é exibido todos os produtos que existem no estoque.
* Para cadastrar um novo produto, digite um ID diferente dos produtos mostrados.
* Para fazer modificações em um produto, como alterar estoque ou valor, digite o ID do produto.
<br>


    Item: Produto 1
    Preço: $10.00
    Quantidade no estoque: 1
    Categoria(s): categoria1, categoria2, categoria3.

    Alterar o nome: digite 1
    Alterar o preço: digite 2
    Alterar o estoque: digite 3
    Digite 0 para voltar ao menu.

* Com o produto identificado é possível fazer as modificações, exemplo: Alterar o nome, digitando 1
<br>


    1

    Novo nome: Produto 1234

    Alterar o nome: digite 1
    Alterar o preço: digite 2
    Alterar o estoque: digite 3
    Digite 0 para voltar ao menu.

* Após fazer a alteração as opções aparecerão novamente, se tiver concluído basta digitar 0 e voltar ao **Menu**
	
------------


### 3. Modo Recomendação
 
    [Modo de Recomendação]

    Insira o CPF do cliente: 1234

    Cliente: Sem Nome
    Idade: 32

    Produtos recomendados para o cliente:

    Organizados por categoria mais comprada e ordem alfabética:
    - Produto 1
    - Produto 2
    - Produto 3

* No **Modo Recomendação**, é sugerido ao cliente alguns produtos que podem ser de interesse, de acordo com as categorias mais compradas por ele anteriormente.
* É exibido até 10 produtos organizados pela relevância e por ordem lexicográfica.
* Para isso, digite o número do CPF do cliente.
<br>


    [Modo de Recomendação]

    Insira o CPF do cliente: 4321

    Nenhum cliente encontrado com esse CPF
    Digite 0 para ir ao menu, ou 1 para digitar novamente.

* Caso não exista um cliente com o CPF informado, é exibida uma mensagem de erro.
<br>

## Resolvendo erros

####  Não é possivel abrir o arquivo de clientes
- Significa que o *software* não foi capaz de encontrar o arquivo de clientes.
    Crie um arquivo vazio **clientes.txt** na pasta **assets**/

#### Não é possivel abrir o arquivo de produtos

- Significa que o *software* não foi capaz de encontrar o arquivo de produtos.
    Crie um arquivo vazio **produtos.txt** na pasta **assets**/

#### Acesso negado ao tentar salvar. As alterações não foram salvas

- O *software* **não possui permissões de pasta** no local onde foi baixado, para salvar ou editar arquivos.
    Copie o programa para outro local ou revise as permissões

#### Cliente ou Produto não encontrados quando se tem certeza do seu ID

- Pode ser um erro de digitação ou de caracteres inválidos.
    Abra o arquivo **clientes.txt** ou **produtos.txt** e revise os dados

## Changelog

1.0:

* Correção de alguns *bugs*.
* Documentação na pasta doc.

## Créditos

Autores:

- Ítalo Alves - 180113666

Proposta do EP1: https://gitlab.com/oofga/eps/eps_2019_2/ep1
Repositório do EP1: https://gitlab.com/italooko/ep1/

## Licença

[GPL v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html)