#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//Definindo as structs a serem utilizadas
typedef struct {
    int tel, numCasa;
    char nome[10], cid[25], rua[25], bairro[25];
}CLIENTES; CLIENTES cliente[100]; int tamanhoC = 0;

typedef struct {
    int id;
    float valor;
    char nome[10];
    char desc[25];
}PIZZAS; PIZZAS pizza[10]; int tamanhoP = 0, venda = 0; float montante = 0;

typedef struct {
    int id, idPizza, entrega, situ, telC, nota;
}PEDIDOS; PEDIDOS pedido[100]; int tamanhoPe = 0;
//Definindo as funções a serem utilizadas
//ADMIN (pizzaria)
int pizzariaSis(); //Função para alterar dados de pizzas e questões da entrega. Função para *ADMIN* 
int cadastroPizza(PIZZAS *pizza, int *tamanho); //Função para o cadastro de pizzas
int alterarPizza(PIZZAS *pizza,int *tamanho, int idAlt); //Função para alterar o cadastro de uma pizza
int removerPizza(PIZZAS *pizza,int *tamanho, int idRem); //Função remover pizza a partir de ID
void despachoPizza(PEDIDOS *pedido, int *tamanho); //Função que apresenta num de pedidos 
void exibirEntrega(PEDIDOS *pedido, int *tamanho); //Função para exibir as entregas a partir do id do entregador
void exibirMontante(int *venda, float *montate); //Exibir montante e total de pizzas vendidas

//USUARIO (cliente)
int clienteSis(); //Função para cadastrar clientes e fazer pedidos
int cadastroCliente(CLIENTES *cliente, int *tamanho); //Função para cadastrar os clientes
int alterarCliente(CLIENTES *cliente,int *tamanho, int telAlt); //Função para alterar dados do cliente
int removerCliente(CLIENTES *cliente, int *tamanho, int telRem); //Função para remover cliente a partir de ID
void menuPizzas(PIZZAS *pizza, int *tamanho); //Função ver menu de pizzas ordenadas pelo ID
int fazerPedido(PEDIDOS *pedido, PIZZAS *pizza, int *tamanhoPe, int *tamanhoPi, float *montante, int *venda); //Função para fazer um pedido
void receberPedido(PEDIDOS *pedido, int *tamanho); //Função para dar uma nota ao pedido

int main (){
    int escolha;
    bool ficar = true;
    while(ficar){
        printf("Para acessar o sistema da pizzaria - 1\nPara acessar o sistema de clientes - 2\nPara sair - 3\n\n");
        scanf("%d", &escolha);
        switch(escolha){
        case 1:
            pizzariaSis();
            break;
        case 2:
            clienteSis();
            break;
        case 3:
            ficar = false;
            break;
        default:
            printf("Sistema nao encontrado");
            break;
        }
    }
    return 0;
}
// ----------------------------
//        Seção Pizzaria
// ----------------------------
//Função para escolher as opções em Pizzaria
int pizzariaSis(){
    int escolha, cadastrar, id, alterar, remover;
    bool ficar = true;
    
    while(ficar){
        printf("Selecione uma das opcoes:\n1- Cadastrar pizzas\n2- Alterar dados da pizza\n3- Remover uma pizza\n4- Despacho da pizza\n5- Exibir entregador\n6- Exibir montate\n7- Sair\n\n");

        scanf("%d", &escolha);
        getchar();
        switch(escolha){
        case 1:
            cadastrar = cadastroPizza(pizza, &tamanhoP);
            if(cadastrar) {
                printf("Cadastro realizado com sucesso!\n");
            }
            break;
        case 2:
            printf("Insira o id da pizza que gostaria de alterar: ");
            scanf("%d", &id);
            getchar();
            alterar = alterarPizza(pizza, &tamanhoP, id);
            if(alterar) {
                printf("Alteracao realizada com sucesso!\n");
            }
            break;
        case 3:
            printf("Qual o id da pizza que gostaria de remover?");
            scanf("%d", &id);
            getchar();
            remover = removerPizza(pizza, &tamanhoP,id);
            if(remover) {
                printf("Remocao realizada com sucesso!\n");
            }
            break;
        case 4:
            despachoPizza(pedido, &tamanhoPe);
            break;
        case 5:
            exibirEntrega(pedido, &tamanhoPe);
            break;
        case 6:
            exibirMontante(&venda, &montante);
            break;
        case 7:
            return escolha;
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
    return 0;
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
    scanf("%[^\n]", pizza[*tamanho].nome);
    getchar();
    
    printf("Qual o valor da pizza?");
    scanf("%f", &pizza[*tamanho].valor);
    getchar();

    printf("Qual a descricao da pizza?");
    scanf("%[^\n]", pizza[*tamanho].desc);
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
//Despacho da pizza
void despachoPizza(PEDIDOS *pedido, int *tamanho) {
    int despache;
    printf("Id dos Pedidos:\n");
    for(int i = 0; i < *tamanho; i++) {
        printf("%d\n", pedido[i].id);
    }
    printf("Qual pedido despachar? ");
    scanf("%d", &despache);
    for(int i = 0; i < *tamanho; i++) {
        if(despache == pedido[i].id){
            pedido[i].entrega = rand() % 10;
            pedido[i].situ = 2;
        }
    }
    printf("\nPedido Despachada\n");
}

void exibirEntrega(PEDIDOS *pedido, int *tamanho) {
    for (int i = 0; i < *tamanho; i++) {
        if (pedido[i].situ > 1) {
            int entregas = 0;
            int entregador = pedido[i].entrega;
            
            for (int j = 0; j < *tamanho; j++) {
                if (entregador == pedido[j].entrega) {
                    entregas++;
                }
            }
            
            printf("O entregador com ID %d tem %d entregas\n", entregador, entregas);
        }
    }
}
//Exibir montate e total de pizzas vendidas
void exibirMontante(int *venda,float *montante) {
    printf("\n%d pizzas vendidas\n%f valor em caixa", *venda, *montante);
}
// ----------------------------
//        Seção Cliente
// ----------------------------
//Função para escolher as opções em Cliente
int clienteSis(){
    int tel, cadastrar, alterar, remover;
    int escolha;
    bool ficar = true;
    
    while(ficar){
        printf("Selecione uma das opcoes:\n1- Cadastrar cliente\n2- Alterar dados do cliente\n3- Remover um cliente\n4- Menu de pizzas\n5- Fazer um pedido\n6- Pedido recebido\n7- Sair\n\n");
        scanf("%d", &escolha);
        switch(escolha){
        case 1:
            cadastrar = cadastroCliente(cliente, &tamanhoC); 
            if(cadastrar){
                printf("Cliente cadastrado com sucesso!\n");
            }
            break;
        case 2:
            printf("Qual o numero do cliente que gostaria de alterar?");
            scanf("%d", &tel);
            alterar = alterarCliente(cliente, &tamanhoC, tel);
            if(alterar) {
                printf("Alterado com sucesso!\n");
            }
            break;
        case 3:
            printf("Qual o numero do cliente que gostaria de remover?");
            scanf("%d", &tel);
            remover = removerCliente(cliente, &tamanhoC, tel);
            if(remover){
                printf("Removido com sucesso\n");
            }
            break;
        case 4:
            menuPizzas(pizza, &tamanhoP);
            break;
        case 5:
        //int fazerPedido(PEDIDOS *pedido, PIZZAS *pizza, int *tamanhoPe, int *tamanhoPi, float *montante);
            fazerPedido(pedido, pizza, &tamanhoPe, &tamanhoP, &montante, &venda);
            break;
        case 6:
            receberPedido(pedido, &tamanhoPe);
            break;
        case 7:
            return escolha;
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
    return 0;
}

//Função cadastrar cliente
int cadastroCliente(CLIENTES *cliente, int *tamanho) {
    int tel;
    printf("Qual o telefone do cliente?");
    scanf("%d", &tel);
    getchar();
    //Verificar se há algum telefone igual
    for(int i = 0; i < *tamanho; i++){
        if(cliente[i].tel == tel){
            printf("Telefone ja cadastrado!");
            return 0;
        }
    }
    //Feita a verificação, associar os valores do cliente
    cliente[*tamanho].tel = tel;
    printf("Qual o nome do cliente?");
    scanf("%[^\n]", cliente[*tamanho].nome);
    getchar();
    
    printf("Qual a cidade do cliente?");
    scanf("%[^\n]", cliente[*tamanho].cid);
    getchar();

    printf("Qual a rua do cliente?");
    scanf("%[^\n]", cliente[*tamanho].rua);
    getchar();

    printf("Qual o bairro do cliente?");
    scanf("%[^\n]", cliente[*tamanho].bairro);
    getchar();

    printf("Qual o numero da casa?");
    scanf("%d", &cliente[*tamanho].numCasa);
    getchar();

    (*tamanho)++;
    return 1;    

    return 0;
}
//Alterar dados do cliente
int alterarCliente(CLIENTES *cliente,int *tamanho, int telAlt) {
    for(int i = 0; i < *tamanho; i++) {
        if(cliente[i].tel == telAlt){
            printf("Qual o nome do cliente?");
            scanf("%[^\n]", cliente[i].nome);
            getchar();
    
            printf("Qual a cidade do cliente?");
            scanf("%[^\n]", cliente[i].cid);
            getchar();

            printf("Qual a rua do cliente?");
            scanf("%[^\n]", cliente[i].rua);
            getchar();

            printf("Qual o bairro do cliente?");
            scanf("%[^\n]", cliente[i].bairro);
            getchar();

            printf("Qual o novo valor da pizza?");
            scanf("%d", &cliente->numCasa);
            getchar();

            return 1;
        }
    }   

    return 0;
}
//Remover cliente
int removerCliente(CLIENTES *cliente, int *tamanho, int telRem) {
    for(int i = 0; i < *tamanho; i++) { // char nome[10], cid[25], rua[25], bairro[25];
        if(cliente[i].tel == telRem){
            cliente[i].tel = 0;
            cliente[i].numCasa = 0;
            strcpy(cliente[i].nome, "");
            strcpy(cliente[i].cid, "");
            strcpy(cliente[i].rua, "");
            strcpy(cliente[i].bairro, "");
            return 1;
        }
    }
    return 0;
}
//Menu de pizzas
void menuPizzas(PIZZAS *pizza, int *tamanho) {
    int menor;
    //ordenando de forma crescente pelo ID
    for(int i = 0; i < *tamanho - 1; i++) {
        menor = pizza[i].id;
        for (int j = i + 1; j < *tamanho; j++) {
            if (pizza[j].id < pizza[menor].id) {
                menor = j;
            }
        }
        PIZZAS cresc = pizza[menor];
        pizza[menor] = pizza[i];
        pizza[i] = cresc;
    }
    //imprimindo em ordem crescente
    for(int i = 0; i < *tamanho; i++) {
        printf("ID: %d\n", pizza[i].id);
        printf("Valor: %.2f\n", pizza[i].valor);
        printf("Nome: %s\n", pizza[i].nome);
        printf("Descricao: %s\n", pizza[i].desc);
    }
}
//int fazerPedido(PEDIDOS *pedido, PIZZAS *pizza, int *tamanhoPe, int *tamanhoPi, float *montante);
int fazerPedido(PEDIDOS *pedido, PIZZAS *pizza, int *tamanhoPe, int *tamanhoPi, float *montante, int *venda) {
    int tel, idPizza;
    printf("Qual o telefone do cliente? ");
    scanf("%d", &tel);
    printf("Qual o ID da pizza? ");
    scanf("%d", &idPizza);
    pedido[*tamanhoPe].telC = tel;
    pedido[*tamanhoPe].idPizza = idPizza;
    pedido[*tamanhoPe].situ = 1;
    pedido[*tamanhoPe].entrega = 0;
    pedido[*tamanhoPe].id = *tamanhoPe;
    pedido[*tamanhoPe].nota = 0;

    for(int i = 0; i < *tamanhoPi; i++){
        if(idPizza == pizza[i].id) {
            (*montante) += pizza[i].valor;
        }
    }
    (*venda)++;
    (*tamanhoPe)++;
    printf("\nPedido Realizado\n");
    return 0;
}
//Receber e dar uma nota ao pedido
void receberPedido(PEDIDOS *pedido, int *tamanho) {
    int id, nota;
    printf("Qual o id do pedido recebido?");
    scanf("%d", &id);
    for(int i = 0; i < *tamanho; i++) {
        if(id == pedido[i].id) {
            pedido[i].situ = 3;
            printf("Qual a nota a ser dada? ");
            scanf("%d", &nota);
            pedido[i].nota = nota;
        }
    }
    printf("\nPedido Recebido\n");
}