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
int alterarPizza(PIZZAS *pizza,int *tamanho, int idAlt); //Função para alterar o cadastro de uma pizza
int removerPizza(PIZZAS *pizza,int *tamanho, int idRem); //Função remover pizza a partir de ID

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

    int escolha, cadastrar, tamanho = 0, id, alterar, remover;
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
            printf("Insira o id da pizza que gostaria de alterar: ");
            scanf("%d", &id);
            getchar();
            alterar = alterarPizza(pizza, &tamanho, id);
            if(alterar) {
                printf("Alteracao realizada com sucesso!");
            }
            break;
        case 3:
            printf("Qual o id da pizza que gostaria de remover?");
            scanf("%d", &id);
            getchar();
            remover = removerPizza(pizza, &tamanho,id);
            if(remover) {
                printf("Remocao realizada com sucesso!");
            }
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
//Cadastrar pizza
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
//Altera pizza pelo ID
int alterarPizza(PIZZAS *pizza,int *tamanho, int idAlt){
    for(int i = 0; i < *tamanho; i++) {
        if(pizza[i].id == idAlt){
            printf("Qual o novo nome da pizza?");
            fgets(pizza[i].nome,10,stdin);
            getchar();
    
            printf("Qual o novo valor da pizza?");
            scanf("%f", &pizza->valor);
            getchar();

            printf("Qual a nova descricao da pizza?");
            fgets(pizza[i].desc, 25, stdin);
            getchar();
            return 1;
        }
    }
    return 0;
} 
//Remover pizza pelo ID
int removerPizza(PIZZAS *pizza,int *tamanho, int idRem){
    for(int i = 0; i < *tamanho; i++) {
        if(pizza[i].id == idRem){
            pizza[i].id = 0;
            strcpy(pizza[i].nome, "");
            strcpy(pizza[i].desc, "");
            return 1;
        }
    }

    return 0;
}   

// ----------------------------
//        Seção Cliente
// ----------------------------
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