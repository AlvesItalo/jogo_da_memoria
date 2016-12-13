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