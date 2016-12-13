#include "libio.h"


void exibe_matriz(int valor, int x, int y, int interruptor){
	int i = 0, j = 0;

	if(interruptor){
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
	}else{
		matriz_fake[x][y] = valor;
	}
}

void credito(){
	printf("Créditos:\n"
		"\tHenrique Luis: Biblioteca de ranking.\n\n"
		"\tItalo Alves: Gerencia, implementacao e revisao de codigo.\n\n"
		"\tLarissa Brandao: Biblioteca de logica do jogo.\n\n"
		"\tMatheus Hensley: Biblioteca de interface, logica do jogo \n\te revisao de codigo\n\n"
		"\tRafael Matheus: Biblioteca de interface.\n\n");
}
