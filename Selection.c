#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long int qtdeInteracoes;

void main( int argc, char* argv[] ){

int end = 1, vet[6] = {0,2,4,6,8,10}, maior = vet[0], aux, i = 5 , j;

    while(i >= 0){ //percorre o vetor nos 2 loops de trás para frente
        for(j = 5; j >= 0 ; j--){
            if(vet[j] > maior){
                maior = j;
            }
        }
        aux = vet[j];
        vet[j] = vet[maior];
        vet[maior] = aux;
        i--;
    }
    for(i = 0; i<6; i++){
        printf("%d \n",vet[i]);
    }

}