#ifndef _LIB_LIBGAME_
	#define _LIB_LIBGAME_ 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libio.h"

#define LINHAS 4
#define	COLUNAS 4

int um_jogador();
int dois_jogadores();
int validar_escolha();
void limpa_matriz_fake();
void preenche_matriz(int *matriz);
void mexe_mexe_mainha(int * matriz);
int comp_coord(int *x, int *y, int *matriz); 

#endif