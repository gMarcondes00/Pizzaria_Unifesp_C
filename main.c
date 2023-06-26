#include <stdio.h>
#include <stdbool.h>
//Definindo as structs a serem utilizadas
typedef struct {
    int tel, numCasa;
    char nome[10], cid[25], rua[25], bairro[25];
}CLIENTES;

typedef struct {
    int id;
    float valor;
    char nome[10];
    char desc[25];
}PIZZAS;

typedef struct {
    int id, idPizza, idEntrega, situ, telC, nota;
}PEDIDOS;
//Definindo as funções a serem utilizadas
//ADMIN (pizzaria)
void pizzariaSis(); //Função para alterar dados de pizzas e questões da entrega. Função para *ADMIN* 
int cadastroPizza(PIZZAS *pizza, int *tamanho); //Função para o cadastro de pizzas
//USUARIO (cliente)
void clienteSis(); //Função para cadastrar clientes e fazer pedidos

int main (){
    PEDIDOS pedido;

    int escolha;
    printf("Para acessar o sistema da pizzaria - 1\nPara acessar o sistema de clientes - 2\n\n");
    scanf("%d", &escolha);
    switch(escolha){
        case 1:
            pizzariaSis();
            break;
        case 2:
            clienteSis();
            break;
        default:
            printf("Sistema nao encontrado");
            break;
    }

    return 0;
}
// ----------------------------
//        Seção Pizzaria
// ----------------------------
//Função para escolher as opções em Pizzaria
void pizzariaSis(){
    PIZZAS pizza[10];

    int escolha, cadastrar, tamanho = 0;
    bool ficar = true;
    
    while(ficar){
        printf("Selecione uma das opcoes:\n1- Cadastrar pizzas\n2- Alterar dados da pizza\n3- Remover uma pizza\n4- Despacho da pizza\n5- Exibir entregador\n6- Exibir montate\n7- Sair\n\n");

        scanf("%d", &escolha);
        switch(escolha){
        case 1:
            cadastrar = cadastroPizza(pizza, &tamanho);
            if(cadastrar) {
                printf("Cadastro realizado com sucesso!");
            }
            break;
        case 2:
            //alterarPizza();
            break;
        case 3:
            //removerPizza();
            break;
        case 4:
            //despachoPizza();
            break;
        case 5:
            //exibirEntrega();
            break;
        case 6:
            //exibirMontante();
            break;
        case 7:
            ficar = false;
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
    printf("Teste");
    for(int i = 0; i < tamanho; i++) {
        printf("Testando: %s\n", pizza[i].desc);
        printf("Testando: %s\n", pizza[i].nome);
        printf("Testando: %f\n", pizza[i].valor);
        printf("Testando: %d\n", pizza[i].id);
    }
}

int cadastroPizza(PIZZAS *pizza, int *tamanho){ 
    int id;
    printf("Qual o id da nova pizza?");
    scanf("%d", &id);
    getchar();
    //Verificar se há algum id igual
    for(int i = 0; i < *tamanho; i++) {
        if(id == pizza[i].id){
            printf("id ja cadastrado!");
            return 0;
        }
    }
    //Feita a verificação, alocar os novos valores
    pizza[*tamanho].id = id;
    printf("Qual o nome da pizza?");
    scanf("%[^\n]", &pizza[*tamanho].nome);
    getchar();
    
    printf("Qual o valor da pizza?");
    scanf("%f", &pizza[*tamanho].valor);
    getchar();

    printf("Qual a descricao da pizza?");
    scanf("%[^\n]", &pizza[*tamanho].desc);
    getchar();

    (*tamanho)++;
    return 1;
}
//Função para escolher as opções em Cliente
void clienteSis(){
    CLIENTES cliente;
    int escolha;
    bool ficar = true;
    scanf("%d", &escolha);
    while(ficar){
        switch(escolha){
        case 1:
            //cadastroCliente();
            break;
        case 2:
            //alterarCliente();
            break;
        case 3:
            //removerCliente();
            break;
        case 4:
            //menuPizzas();
            break;
        case 5:
            //fazerPedido();
            break;
        case 6:
            //receberPedido();
            break;
        case 7:
            ficar = false;
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
}

// ----------------------------
//        Seção Cliente
// ----------------------------