#ifndef _LIB_LIBIO_
	#define _LIB_LIBIO_ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librank.h"
#include "libgame.h"

#if defined(__MINGW32__) || defined(_MSC_VER)
	#define limpar_console() system("cls")
#else
	#define limpar_console() system("clear")
#endif

#define IGNORE 5
#define SUCESSO 0
#define FRACASSO 1

void menu();
void exibe_matriz(int valor, int x, int y, int *matriz_fake);
void grava_valor(int valor, int x, int y, int *matriz_fake);
int recebe_coord(int *x, int *y, int player, int coord_num, int *matriz_fake);
void creditos();
void exibe_rank(t_jogador *array_de_jogadores);
void exibe_pontuacao(int jogador1, int jogador2);
int exibe_vencedor(int jogador1, int jogador2);

#endif
