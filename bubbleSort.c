#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {

    FILE *arquivo;
    arquivo = fopen(argv[1], "r");
    int count = 0;
    if(arquivo == NULL) {
        printf("arquivo nao encontrado \n");
        exit(0);
    }
    

    fclose(arquivo);
}