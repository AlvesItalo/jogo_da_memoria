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



#endif