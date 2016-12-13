#include "libio.h"

void exibe_matriz(int valor, int x, int y, int *matriz_fake){
	int i = 0, j = 0;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((i == x) && (j == y)){
				printf(">%d<", valor);
			}else{
				if(*(matriz_fake+((4*i)+j))){
					printf(" %d ", *(matriz_fake+((4*i)+j)));
				}else{
					printf(" X ");
				}
			}
		}
		printf("\n");
	}
}

void exibe_pontuacao(int jogador1, int jogador2){
	printf("Jogador 1:\tJogador 2:\n"
			"Pontuacao: %d\tPontuacao: %d\n", jogador1, jogador2);
}

int exibe_vencedor(int jogador1, int jogador2){
	if(jogador1 > jogador2){
		printf("O vencedor foi o jogador 1 com %d pontos.\n", jogador1);
		return jogador1;
	}else if(jogador1 < jogador2){
		printf("O vencedor foi o jogador 2 com %d pontos\n", jogador2);
		return jogador2;
	}else{
		printf("Empate! Jogue novamente.");
		return 0;
	}
}

void grava_valor(int valor, int x, int y, int *matriz_fake){
	*(matriz_fake+((4*x)+y)) = valor;
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
    int pontuacao_venc = 0;

    do{
        limpar_console();
        printf("-------Jogo da Memoria-------\n\n"
                "[1] - 1 Jogador\n"
                "[2] - 2 jogadores\n"
                "[3] - Ranking\n"
                "[4] - Creditos\n"
                "[0] - Sair\n"
                ">>> ");
        fflush(stdin);
        fgets(escolha, 4, stdin);

        switch(escolha[0]){
            case '0':
                exit(0);
                break;
            case '1':
                pontuacao_venc = um_jogador();
                if(pontuacao_venc){
                	printf("Gravou pontuacao");
                }
                break;
            case '2':
                pontuacao_venc = dois_jogadores();
                if(pontuacao_venc){
                	printf("Gravou pontuacao");
                }
                break;
            case '3':
                printf("rank\n");
                break;
            case '4':
            	creditos();
            	break;
       }
    }while(1);
}

int recebe_coord(int *x, int *y, int player, int coord_num, int *matriz_fake){
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

    *x = choice[0] - 49;
    *y = choice[1] - 49;

    if((*x >= 0 && *x <= 3) && (*y >= 0 && *y <= 3) && !(*(matriz_fake+((4**x)+*y)))){
        return SUCESSO;
    }else{
        *x = 0;
        *y = 0;
        return FRACASSO;
    }
}


