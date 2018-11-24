#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void iniciaVetor(int *vet, FILE *arquivo){
    int i = 0;
    char caracter[20];
    
    while (fgets(caracter, 20, arquivo) != NULL){
        printf("caracter = %s ", caracter);
        vet[i] = atoi(caracter);
        printf("inteiro = %d \n", vet[i]);
        i++;
    }
}
