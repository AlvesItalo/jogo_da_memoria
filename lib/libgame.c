#include "libgame.h"

/*testa se o usuario acertou o par*/
int validar_escolha(int valor1, int valor2){
	if(valor1 == valor2){
		return 1;
	}else{
		return 0;
	}
}

void limpa_matriz_fake(){
	int i = 0, j = 0;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			matriz_fake[i][j] == 0;
		}
	}
}

/*preenche uma matriz 4X4 com pares de 1 a 8*/
void preenche_matriz(int *matriz){
	int i = 0, j = 0, k = 1, l = 1;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(i<2){
				*(matriz+((4*i)+j)) = k;
				k++;
			}else{
				*(matriz+((4*i)+j)) = l;
				l++;
			}
		}
	}
}

/*randomiza os elementos de uma matriz 4X4*/
void mexe_mexe_mainha(int * matriz){
	int i = 0, j = 0, k = 0, l = 0, aux = 0;

	srand(time(NULL));

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			k = rand() % 4;
			l = rand() % 4;
			aux = *(matriz+((4*i)+j));
			*(matriz+((4*i)+j)) = *(matriz+((4*k)+l));
			*(matriz+((4*k)+l)) = aux;
		}
	}
}

int dois_jogadores(){
	int *matriz = NULL;
	int pontuacao_jog1 = 0, pontuacao_jog2 = 0, pontuacao_total = 0, i = 0, j = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, status = 1, acertou = 0;

	matriz = (int *) malloc(16*sizeof(int));

	limpa_matriz_fake();
	preenche_matriz(matriz);
	mexe_mexe_mainha(matriz);

	/*loop da partida*/
	while(1){
		/*Jogador 1*/
		do{
			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(IGNORE, IGNORE, IGNORE);

				status = recebe_coord(&x1, &y1, 1, 1);
			}while(status);

			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(*(matriz+(4*x1)+y1), x1, y1);	

				status = recebe_coord(&x2, &y2, 1, 2);
				if((x1 == x2) && (y1 == y2)){status = 1;}

			}while(status);		

				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);	
				exibe_matriz(*(matriz+(4*x2)+y2), x2, y2);
				
			acertou = validar_escolha(*(matriz+(4*x1)+y1), *(matriz+(4*x2)+y2));

			if(acertou){
				grava_valor(*(matriz+(4*x1)+y1), x1, y1);
				grava_valor(*(matriz+(4*x2)+y2), x2, y2);

				pontuacao_jog1+=10;

				pontuacao_total = pontuacao_jog1+pontuacao_jog2;
				if(pontuacao_total>70){
					free(matriz);
					return exibe_vencedor(pontuacao_jog1, pontuacao_jog2);
				}

				printf("Pressione [Enter] para continuar.");
				getchar();
				fflush(stdin);

			}else{
				printf("Pressione [Enter] para dar vez ao próximo jogador.");
				getchar();
				fflush(stdin);
			}

		}while(acertou);

		/*Jogador 2*/
		do{
			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(IGNORE, IGNORE, IGNORE);

				status = recebe_coord(&x1, &y1, 2, 1);
			}while(status);

			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(*(matriz+(4*x1)+y1), x1, y1);

				status = recebe_coord(&x2, &y2, 2, 2);
				if((x1 == x2) && (y1 == y2)){status = 1;}

			}while(status);	

				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);	
				exibe_matriz(*(matriz+(4*x2)+y2), x2, y2);

			acertou = validar_escolha(*(matriz+(4*x1)+y1), *(matriz+(4*x2)+y2));

			if(acertou){
				grava_valor(*(matriz+(4*x1)+y1), x1, y1);
				grava_valor(*(matriz+(4*x2)+y2), x2, y2);

				pontuacao_jog2+=10;

				pontuacao_total = pontuacao_jog1+pontuacao_jog2;
				if(pontuacao_total>70){
					free(matriz);
					return exibe_vencedor(pontuacao_jog1, pontuacao_jog2);
				}

				printf("Pressione [Enter] para continuar.");
				getchar();

			}else{
				printf("Pressione [Enter] para dar vez ao próximo jogador.");
				getchar();
			}

		}while(acertou);
	}
	/*fim do loop da partida*/
}

int um_jogador(){
	int *matriz = NULL;
	int pontuacao_jog1 = 0, pontuacao_jog2 = 0, pontuacao_total = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, status = 1, acertou = 0;

	matriz = (int *) malloc(16*sizeof(int));

	limpa_matriz_fake();
	preenche_matriz(matriz);
	mexe_mexe_mainha(matriz);

	/*Loop da partida*/
	while(1){
		/*Jogador 1*/
		do{
			acertou = 0;
			/*primeiras coordenadas*/
			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(IGNORE, IGNORE, IGNORE);

				status = recebe_coord(&x1, &y1, 1, 1);

			}while(status);
			/*segundas coordenadas*/
			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(*(matriz+(4*x1)+y1), x1, y1);	

				status = recebe_coord(&x2, &y2, 1, 2);
				if((x1 == x2) && (y1 == y2)){status = 1;}

			}while(status);		

			limpar_console();
			exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);	
			exibe_matriz(*(matriz+(4*x2)+y2), x2, y2);
				
			acertou = validar_escolha(*(matriz+(4*x1)+y1), *(matriz+(4*x2)+y2));

			if(acertou){
				grava_valor(*(matriz+(4*x1)+y1), x1, y1);
				grava_valor(*(matriz+(4*x2)+y2), x2, y2);
				pontuacao_jog1+=10;

				pontuacao_total = pontuacao_jog1+pontuacao_jog2;
				if(pontuacao_total>70){

					limpar_console();
					exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
					exibe_matriz(IGNORE, IGNORE, IGNORE);

					free(matriz);

					return exibe_vencedor(pontuacao_jog1, pontuacao_jog2);
					
				}

				printf("Pressione [Enter] para continuar.");
				getchar();
				fflush(stdin);

			}else{
				printf("Pressione [Enter] para dar vez ao próximo jogador.");
				getchar();
				fflush(stdin);
			}
		}while(acertou);

		/*Jogador 2*/
		do{
			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(IGNORE, IGNORE, IGNORE);

				status = comp_coord( &x1, &y2);
			}while(status);

			printf("Pressione [Enter] para ver o que o computador escolheu.");
			getchar();
			fflush(stdin);

			do{
				limpar_console();
				exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
				exibe_matriz(*(matriz+(4*x1)+y1), x1, y1);

				status = comp_coord(&x2, &y2);
				if((x1 == x2) && (y1 == y2)){status = 1;}

			}while(status);	

			printf("Pressione [Enter] para ver o que o computador escolheu.");
			getchar();
			fflush(stdin);

			limpar_console();
			exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);	
			exibe_matriz(*(matriz+(4*x2)+y2), x2, y2);

			acertou = validar_escolha(*(matriz+(4*x1)+y1), *(matriz+(4*x2)+y2));

			if(acertou){
				grava_valor(*(matriz+(4*x1)+y1), x1, y1);
				grava_valor(*(matriz+(4*x2)+y2), x2, y2);

				pontuacao_jog2+=10;

				pontuacao_total = pontuacao_jog1+pontuacao_jog2;
				if(pontuacao_total>70){

					limpar_console();
					exibe_pontuacao(pontuacao_jog1, pontuacao_jog2);
					exibe_matriz(IGNORE, IGNORE, IGNORE);

					free(matriz);
					return exibe_vencedor(pontuacao_jog1, pontuacao_jog2);
				}

				printf("Pressione [Enter] para continuar.");
				getchar();
				fflush(stdin);

			}else{
				printf("Pressione [Enter] para para jogar.");
				getchar();
				fflush(stdin);
			}
		}while(acertou);
	}/*fim do loop da partida*/
}

int comp_coord(int *x, int *y){

	srand((unsigned) time(NULL));

	*x = rand() % 4;
	*y = rand() % 4;


	if((*x >= 1 && *x <= 4) && (*y >= 1 && *y <= 4) && !(matriz_fake[*x-1][*y-1])){
        *x -= 1;
        *y -= 1;
        return SUCESSO;
    }else{
        *x = 0;
        *y = 0;
        return FRACASSO;
    }
}


