#include<stdio.h>
#include<stdlib.h>

struct {
    int qtd;
    int id;
    char nome[40];
    char marca[40];
} produto[30];


void menu() {
    printf("[ CONTROLADOR DE ESTOQUE ]\n\n");
    printf("[ 1 ] ADCIONAR UM PRODUTO\n");
    printf("[ 2 ] REMOVER UM PRODUTO\n");
    printf("[ 3 ] CONSULTAR UM PRODUTO\n");
    printf("[ 4 ] EDITAR UM PRODUTO\n\n");
    }
    
int ler_opcao() {
    int op, valido = 0;
    while (valido == 0) {
        scanf(" %d", &op);
        if (op >= 1 && op <= 4) {
            valido = 1;
            return op;
        } else {
            system("cls");
            menu();
            printf(" OPCAO INVALIDA!\n\n");
        }
    }
}

void addproduto() {
	int i;
	
    for (i = 0; i < 30; i++) {            
        if (produto[i].id == 0) {
        	fflush(stdin);
            printf(" NOME DO PRODUTO: ");
            fgets(produto[i].nome, 40, stdin);
            printf(" MARCA DO PRODUTO: ");
            fgets(produto[i].marca, 40, stdin);
            printf(" INSIRA O ID DO PRODUTO: ");
            scanf("%d", &produto[i].id);
            printf(" QUANTIDADE DO PRODUTO: ");
            scanf(" %d", &produto[i].qtd);
            break;
        }
    }
}
   
int main() {
    
    int op;

    menu();
    op = ler_opcao();
    
    switch(op) {
        case 1:
            system("cls");
            addproduto();
            system("cls");
            printf(" PRODUTO ADICIONADO!\n");
            return main();
        case 2:
        case 3:
        case 4:        
        break;
    }
    return 0;
}