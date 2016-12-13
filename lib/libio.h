#ifndef _LIB_LIBIO_
	#define _LIB_LIBIO_ 1

#include <stdio.h>
#include <stdlib.h>
#include "librank.h"
#include "libgame.h"

#if defined(__MINGW32__) || defined(_MSC_VER)
	#define limpar_console() system("cls")
#else
	#define limpar_console() system("clear")
#endif

#define GRAVA 0
#define EXIBE 1
#define IGNORE 5

int menu();
void exibe_matriz(int valor, int x, int y, int interruptor);
int recebe_coord();
void credito();
void exibe_rank();

#endif
