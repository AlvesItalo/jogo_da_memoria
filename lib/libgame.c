#include "libgame.h"

int validar_escolha(int valor1, int valor2){
	if(valor1 == valor2){
		return 1;
	}else{
		return 0;
	}
}

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