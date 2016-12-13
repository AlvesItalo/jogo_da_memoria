#include "librank.h"

void grava_ranking(t_jogador player){
    int tam;

    FILE *arq = fopen("teste.bin", "ab+");/*Mudar nome do arquivo gerado e passar caminho*/
    rewind(arq);
    fseek(arq, 0, SEEK_SET);
    tam = strlen(player.nome);
    fwrite(&player, sizeof(player.pontuacao) + tam, 1, arq);
    fflush(arq);
    fclose(arq);
}
