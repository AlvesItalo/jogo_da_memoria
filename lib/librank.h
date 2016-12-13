#ifndef _LIB_LIBRANK_
	#define _LIB_LIBRANK_ 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Jogador{
	char nome[255];
	int pontuacao;
}t_jogador;

void grava_ranking(t_jogador player);
t_jogador *le_ranking();


#endif
