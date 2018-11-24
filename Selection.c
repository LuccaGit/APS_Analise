#include "vetor.h"
#define TAM 1000

long int qtdeInteracoes;

void main( int argc, char* argv[] ){

int end = 1, vet[TAM], aux, i = TAM-1 , j, indiceM, count;
    double tempoIni = (double) clock() / 1000000;

    FILE *arq;
    arq = fopen( argv[1], "r" );
    
    iniciaVetor(vet,arq);

    while(i >= 0){ //percorre o vetor nos 2 loops de trás para frente
        indiceM = i;
        for(j = i-1; j >= 0 ; j--){
            count++;
            if(vet[j] > vet[indiceM]){
                indiceM = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[indiceM];
        vet[indiceM] = aux;
        i--;
    }
    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",count);
    printf("\n---------------------------SelectionSort----------------------------------\n");

    // for(i = 0; i<TAM; i++){
    //     printf("%d \n",vet[i]);
    // }

}