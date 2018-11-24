#include "vetor.h"
#define TAM 1000

void main( int argc, char* argv[] ){

    double tempoIni = (double) clock() / 1000000;
    int end = 1, vet[1000], aux, aux2, i , j, k = 0, key, count;

    FILE *arq;
    arq = fopen( argv[1], "r" );

    iniciaVetor(vet,arq);

    for (i = 1; i <TAM; i++){ 
        key = vet[i]; 
        j = i-1; 
        while (j >= 0 && vet[j] > key){ 
            count++;
            vet[j+1] = vet[j]; 
            j = j-1; 
        }
        vet[j+1] = key; 
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