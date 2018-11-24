#include "vetor.h"
#define TAM 1000

long int qtdeInteracoes;

void main( int argc, char* argv[] ){

int end = 1, vet[TAM], aux, i = TAM-1 , j, indiceM;

    FILE *arq;
    arq = fopen( argv[1], "r" );
    
    iniciaVetor(vet,arq);

    while(i >= 0){ //percorre o vetor nos 2 loops de trás para frente
        indiceM = i;
        for(j = i-1; j >= 0 ; j--){
            if(vet[j] > vet[indiceM]){
                indiceM = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[indiceM];
        vet[indiceM] = aux;
        i--;
    }
    
    for(i = 0; i<TAM; i++){
        printf("%d \n",vet[i]);
    }

}