#ifndef _LIB_LIBRANK_
	#define _LIB_LIBRANK_ 1

#include <stdio.h>
#include <stdlib.h>

typedef struct jogador{
	char nome[20];
	int score;
} t_jogador;

int ranking_princ(){
	FILE *arquivo;
	t_jogador *rank = NULL;

	t_jogador add;
	t_jogador add1;

	system("clear||cls");

	// ABRINDO ARQUIVO, E ENTAO TRANSFORMANDO-O EM BINARIO
	arquivo = fopen("binario.bat", "r+b");

	if(!arquivo){
		printf("Nao sera possivel criar o arquivo binario!\n");
		return 0;
	}
	fseek(arquivo, 0, SEEK_END);

	struct_qntd = ftell(arquivo)/sizeof(t_jogador);

	rank = (t_jogador *)malloc(ftell(arquivo));
	fseek(arquivo, 0, SEEK_SET);
	rewind(arquivo);

	for(cont_rank = 0; cont_rank < struct_qntd; cont_rank++){
		fread(rank+cont_rank, sizeof(t_jogador), 1, arquivo);
		printf("%s", rank[cont_rank].nome);
		printf(": %d\n", rank[cont_rank].score);
	}

	fclose(arquivo);
	return 0;

}

int salvar_ranking(){
	FILE *arquivo;
	t_jogador *rank = NULL, *x = NULL;

	system("clear||cls");

	arquivo = fopen("binario.bat", "r+b");

	if (!arquivo){
		printf("Nao sera possivel criar o arquivo binario!\n");
		return 0;
	}

	fseek(arquivo, 0, SEEK_END);

	struct_qntd = ftell(arquivo)/sizeof(t_jogador);

	if(!strcmp(modo, "Dois Jogadores")){
		rank = (t_jogador *)malloc(sizeof(t_jogador)*(struct_qntd+2));
	}
	else {
		rank = (t_jogador *)malloc(sizeof(t_jogador)*(struct_qntd+1));
	}

	x = (t_jogador *)malloc(ftell(arquivo));
	rewind(arquivo);

	for(cont_rank = 0; cont_rank < struct_qntd; cont_rank++){
		fread(rank+cont_rank, sizeof(t_jogador), 1, arquivo);
		strcpy(x[cont_rank].nome, rank[cont_rank].nome);
		x(cont_rank).score = rank[cont_rank].score;
	}

	for(cont_rank = 0; cont_rank < struct_qntd; cont_rank++){
		strcpy(rank[cont_rank].nome, x[cont_rank].nome);
		rank[cont_rank].score = x[cont_rank].score;
	}

	fclose(arquivo);

	arquivo = fopen("binario.bat", "w+b");

	if(!arquivo){
		printf("Nao sera possivel criar o arquivo binario!\n");
		return 0;
	}
	fseek(arquivo, 0, SEEK_SET);

	if(!strcmp(modo, "Dois Jogadores")){
		fflush(stdin);
		strcpy(rank[struct_qntd].nome, jogador1);
		rank[struct_qntd].score = score_jogador1;
		fflush(stdin);
		strcpy(rank[struct_qntd+1].nome, jogador2);
		rank[struct_qntd+1].score = score_jogador2;
		fwrite(rank, sizeof(t_jogador)*(struct_qntd+2), 1, arquivo);
	}
	else {
		fflush(stdin);
		strcpy(rank[struct_qntd].nome, jogador1);
		rank[struct_qntd].score = score_jogador1;
		fwrite(rank, sizeof(t_jogador)*(struct_qntd+1), 1, arquivo);
	}

	fclose(arquivo);


}

#endif
