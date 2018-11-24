#include "vetor.h"
#define TAM 1000

void main( int argc, char* argv[] ){

int end = 1, vet[TAM], aux, i = TAM-1 , j, indiceM, count;
    double tempoIni = (double) clock() / 1000000;

    FILE *arq;
    arq = fopen( argv[1], "r" );
    
    iniciaVetor(vet,arq);

void bubbleSortOtimizado(int *vet, int tamanho) {
    printf("------------------------bubbleSort-Otimizado-----------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;
    int aux, count = 0, breaker = 0;
    for(int i = 0; i < tamanho; i++){
        if(breaker == 0){
            breaker = 1;
            for(int j = 0; j < tamanho - i - 1; j++){
                if(vet[j] > vet[j + 1]){
                    breaker = 0;
                    count++;
                    aux = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = aux;
                }
            }
        }
        
    }

    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("tempo de execucao = %f Segundos\n",tempo);
    printf("quantidade de instrucoes = %d Instrucoes\n",count);
    printf("------------------------bubbleSort-Otimizado-----------------------------\n\n");
    for(int i = 0; i < tamanho; i++){
        printf("|%d|\n", vet[i]);
    }
}

void insertionSort(int *vet, int tamanho) {
    printf("---------------------------InsertionSort----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;
    int key, j, count = 0;
    for (int i = 1; i < tamanho; i++){ 
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
    printf("\n---------------------------InsertionSort----------------------------------\n");

}

void SelectionSort(int *vet, int tamanho) {
    int i
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