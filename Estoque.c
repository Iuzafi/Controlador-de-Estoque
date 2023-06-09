#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

struct {
    int qtd;
    int id;
    float preco;
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
	
	system("cls");
    for (i = 0; i <= 30; i++) {            
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
            printf(" PRECO DO PRODUTO: ");
            scanf("%f", &produto[i].preco);
            break;
        }
    }
    system("cls");
    sleep(1);
    printf("\n PRODUTO ADICIONADO!\n");
}

void rmvproduto() {
	int i, id;
	
	system("cls");
	printf(" DIGITE O ID DO PRODUTO: ");
	scanf("%d", &id);
	for (i = 0; i <= 30; i++){
		if (id == produto[i].id) {
			memset(produto[i].nome, 0, sizeof(produto[i].nome));
			memset(produto[i].marca, 0, sizeof(produto[i].marca));
			produto[i].id = 0;
			produto[i].qtd = 0;
			produto[i].preco = 0;
			system("cls");
		}
		else {
			system("cls");
			printf("\n PRODUTO NAO ENCONTRADO.\n");
		}
	}
}

void consultproduto() {
	int i, id, op;
	bool valido = false;
	
	system("cls");
	while (!valido) {
    	printf(" DIGITE O ID DO PRODUTO: ");
    	scanf("%d", &id);
    	for (i = 0; i <= 30; i++) {
    		if (id == produto[i].id) {
    			printf("\n NOME DO PRODUTO: %s", produto[i].nome);
    			printf(" MARCA DO PRODUTO: %s", produto[i].marca);
    			printf(" ID DO PRODUTO: %d\n", produto[i].id);
    			printf(" QUANTIDADE DO PRODUTO: %d\n\n", produto[i].qtd);
    			printf(" DESEJA CONSULTAR OUTRO PRODUTO?\n");
    			printf(" [1] SIM    [2] NAO\n");
    			scanf("%d", &op);
    			if (op == 1) {
    			    break;
    			} else {
    			    valido = true;
    			}
    		}
    	}
    	if (!valido) {
    		system("cls");
    		sleep(2);
    		printf("\n PRODUTO NAO ENCONTRADO.\n");
    		printf(" DIGITE UM PRODUTO CADASTRADO.\n\n");
    	}
	}
}
   
int main() {
    
    int op;

    menu();
    op = ler_opcao();
    
    switch(op) {
        case 1:
            addproduto();
            sleep(1);
			printf("\n RETORNANDO AO MENU...\n");
			sleep(2);
			system("cls"); 
            return main();
        case 2:        	
        	rmvproduto();
			sleep(1);
			printf("\n RETORNANDO AO MENU...\n");
			sleep(2);
			system("cls");        	
        	return main();
        case 3:
			consultproduto();
			sleep(1);
			printf("\n");
        case 4:        
        break;
    }
return 0;
}
