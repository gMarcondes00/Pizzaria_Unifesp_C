#include <stdio.h>
//Definindo as structs a serem utilizadas
struct Cliente {
    int tel, numCasa;
    char nome[10], cid[25], rua[25], bairro[25];
};

struct Pizzas {
    int id, valor;
    char nome[10];
    char desc[25];
};

struct Pedido {
    int id, idPizza, idEntrega, situ, telC, nota;
};
//Definindo as funções a serem utilizadas
void pizzaria(); //Função para alterar dados de pizzas e questões da entrega. Função para *ADMIN* 
void cliente(); //Função para cadastrar clientes e fazer pedidos

int main (){

    return 0;
}