#ifndef _LIB_LIBRANK_
	#define _LIB_LIBRANK_ 1

#include <stdio.h>
#include <stdlib.h>

typedef struct jogador{
	char nome[20];
	int score;
} t_jogador;

int ranking_princ();
int salvar_ranking();

#endif
