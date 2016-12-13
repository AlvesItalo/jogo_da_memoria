#ifndef _LIB_LIBGAME_
	#define _LIB_LIBGAME_ 1

#include <stdio.h>
#include <stdlib.h>
#include "libio.h"

#define LINHAS 4
#define	COLUNAS 4

int um_jogador();
int dois_jogadores();
int validar_escolha();
void preenche_matriz(int *matriz);
void mexe_mexe_mainha(int * matriz);
void limpa_matriz_fake();
void comp_coord(int *x, int *y); 

#endif