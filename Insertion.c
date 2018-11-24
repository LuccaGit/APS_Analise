#include "vetor.h"
#define TAM 1000

long int qtdeInteracoes;

void main( int argc, char* argv[] ){

int end = 1, vet[1000], vet2[6] = {10,8,6,4,2,0}, aux, aux2, i , j, k = 0, key;

    FILE *arq;
    arq = fopen( argv[1], "r" );

    iniciaVetor(vet,arq);

    for (i = 1; i <TAM; i++){ 
        key = vet[i]; 
        j = i-1; 
        
        while (j >= 0 && vet[j] > key){ 
            vet[j+1] = vet[j]; 
            j = j-1; 
        }
        vet[j+1] = key; 
    }

    for(i = 0; i<TAM; i++){
        printf("%d \n",vet[i]);
    }
}