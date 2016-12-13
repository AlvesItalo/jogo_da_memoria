#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void teste(){
    srand(time(NULL));
    int vetor[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int i, j, k;

    for(i = 0; i < 8; i++){
        j = rand() % 8;
        k = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = k;
    }

    for(i = 0; i < 8; i++){
        printf("%d\n", vetor[i]);
    }
}

int main(){
    teste();
}
