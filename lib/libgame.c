#include "libgame.h"

int validar_escolha(int valor1, int valor2){
	if(valor1 == valor2){
		return 1;
	}else{
		return 0;
	}
}