#include "librank.h"

void grava_ranking(t_jogador player){
    int tam;

    FILE *arq = fopen("ranking.bin", "ab+");
    /*Mudar nome do arquivo gerado e passar caminho*/
	rewind(arq);
    fseek(arq, 0, SEEK_SET);
    tam = strlen(player.nome);
    fwrite(&player, sizeof(player.pontuacao) + tam, 1, arq);
    fflush(arq);
    fclose(arq);
}

t_jogador *le_ranking(){
	t_jogador *array_de_jogadores = NULL;
	t_jogador player;
	n=1;

	array_de_jogadores = malloc(n*sizeof(t_jogador));

	FILE *arq = fopen("ranking.bin", "rb+");
    /*Mudar nome do arquivo gerado e passar caminho*/
	rewind(arq);
	while(fread(&player, sizeof(t_jogador), 1, arq)){
		*(array_de_jogadores+n) = player;
		n++;
		array_de_jogadores = (t_jogador *) realloc(array_de_jogadores, n*sizeof(t_jogador));
	}	
	return array_de_jogadores;
}
