#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long int qtdeInteracoes;

void main( int argc, char* argv[] ){

int end = 1, vet[6] = {0,2,4,6,8,10}, aux, i , j;

    for(i = 0; i<6; i++){
        aux = vet[i];
        while(j < end && aux == vet[i]){
            if(aux > vet[j]){
                vet[i] = vet[j];
                vet[j] = aux;
                aux = vet[j];
            }
            j++;
        }
        end++;
    }
    for(i = 0; i<6; i++){
        printf("%d \n",vet[i]);
    }
}