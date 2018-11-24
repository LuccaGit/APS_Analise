#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void iniciaVetor(int *vet, FILE *arquivo){
    int i = 0;
    char caracter[20];
    
    while (fgets(caracter, 20, arquivo) != NULL){
        vet[i] = atoi(caracter);
        i++;
    }
}
