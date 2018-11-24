#include "vetor.h"

void main(int argc, char *argv[]) {

    FILE *arquivo;
    arquivo = fopen(argv[1], "r");
    int count = 0;
    if(arquivo == NULL) {
        printf("arquivo nao encontrado \n");
        exit(0);
    }

    int vetor[1000], i = 0;
    char caracter[20];
    
    iniciaVetor(vetor,arquivo);
        
    fclose(arquivo);
}