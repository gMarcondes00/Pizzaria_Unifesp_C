#include <stdio.h>
#include <stdbool.h>
//Definindo as structs a serem utilizadas
typedef struct {
    int tel, numCasa;
    char nome[10], cid[25], rua[25], bairro[25];
}CLIENTE;

typedef struct {
    int id, valor;
    char nome[10];
    char desc[25];
}PIZZAS;

typedef struct {
    int id, idPizza, idEntrega, situ, telC, nota;
}PEDIDO;
//Definindo as funções a serem utilizadas
//ADMIN (pizzaria)
int pizzaria(); //Função para alterar dados de pizzas e questões da entrega. Função para *ADMIN* 
int cadastroPizza(); //Função para o cadastro de pizzas
//USUARIO (cliente)
int cliente(); //Função para cadastrar clientes e fazer pedidos

int main (){

    return 0;
}
//Função para escolher as opções em Pizzaria
int pizzaria(){
    int escolha;
    bool ficar = true;
    while(ficar){
        switch(escolha){
        case 1:
            cadastroPizza();
            break;
        case 2:
            alterarPizza();
            break;
        case 3:
            removerPizza();
            break;
        case 4:
            despachoPizza();
            break;
        case 5:
            exibirEntrega();
            break;
        case 6:
            exibirMontante();
            break;
        case 7:
            ficar = false;
            break;
        }
    }
    
    return 0;
}
//Função para escolher as opções em Cliente
int cliente(){
    int escolha;
    bool ficar = true;
    while(ficar){
        switch(escolha){
        case 1:
            cadastroCliente();
            break;
        case 2:
            alterarCliente();
            break;
        case 3:
            removerCliente();
            break;
        case 4:
            menuPizzas();
            break;
        case 5:
            fazerPedido();
            break;
        case 6:
            receberPedido();
            break;
        case 7:
            ficar = false;
            break;
        }
    }
    return 0;
}
// ----------------------------
//        Seção Pizzaria
// ----------------------------
