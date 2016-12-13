#include "libio.h"


void exibe_matriz(int valor, int x, int y){
	int i = 0, j = 0;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((i == x) && (j == y)){
				printf(">%d<", valor);
			}else{
				if(matriz_fake[i][j]){
					printf(" %d ", matriz_fake[i][j]);
				}else{
					printf(" X ");
				}
			}
		}
		printf("\n");
	}
}

void grava_valor(int valor, int x, int y){
	matriz_fake[x][y] = valor;
}

void credito(){
	printf("Créditos:\n"
		"\tHenrique Luis: Biblioteca de ranking.\n\n"
		"\tItalo Alves: Gerencia, implementacao e revisao de codigo.\n\n"
		"\tLarissa Brandao: Biblioteca de logica do jogo.\n\n"
		"\tMatheus Hensley: Biblioteca de interface, logica do jogo \n\te revisao de codigo\n\n"
		"\tRafael Matheus: Biblioteca de interface.\n\n");
}

/*modificar posteriormente com as chamadas das funções*/
void menu(){
    char escolha[4];

    do{
        limpar_console();
        printf("-------Jogo da Memoria-------\n\n"
                "[1] - 1 Jogador\n"
                "[2] - 2 jogadores\n"
                "[3] - Ranking\n"
                "[0] - Sair\n"
                ">>> ");
        fflush(stdin);
        fgets(escolha, 4, stdin);

        switch(escolha[0]){
            case '0':
                exit(0);
                break;
            case '1':
                printf("Um jogador!");
                break;
            case '2':
                printf("Dois jogadores!");
                break;
            case '3':
                printf("Ranking!");
                break;
       }
    }while(1);
}

int recebe_coord(int *x, int *y, int player, int coord_num){
    int i = 0, j = 0, k = 0, tam = 0;
    char choice[10];

    printf("Jogador %d, insira o %d° par de coordenadas x, y.\n>>> ", player, coord_num);
    fflush(stdin);
    fgets(choice, 10, stdin);
    tam = strlen(choice);

    for(i = 0; i < tam; i++){
        if(choice[i] != ' '){
            choice[j] = choice[i];
            j++;
        }
    }
    choice[j] = '\0';

    tam = strlen(choice);

    for(i = 0; i < tam; i++){
        if(choice[i] != ','){
            choice[k] = choice[i];
            k++;
        }
    }
    choice[k] = '\0';

    *x = choice[0] - 48;
    *y = choice[1] - 48;

    if(*x >= 1 && *x <= 4){
        if(*y >= 1 && *y <= 4){
            *x -= 1;
            *y -= 1;
            return SUCESSO;
        }else{
            *x = 0;
            *y = 0;
            return FRACASSO;
        }
    }else{
        *x = 0;
        *y = 0;
        return FRACASSO;
    }
}
