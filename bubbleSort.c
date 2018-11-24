#include "vetor.h"
#define TAMANHO 1000


void bubbleSort(int *vet, int tamanho) {
    printf("---------------------------bubbleSort----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;
    int aux, count = 0;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
                count++;
            if(vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",count);
    printf("\n---------------------------bubbleSort----------------------------------\n");
}

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
    for(int i = 0; i < TAMANHO; i++){
        printf("|%d|\n", vet[i]);
    }
}

void merge(int *vet, int esq, int meio, int dir) {

    int meioEsq = meio - esq + 1; 
    int meioDir =  dir - meio; 
    int vetEsq[meioEsq], vetDir[meioDir]; 

    for (int i = 0; i < meioEsq; i++) 
        vetEsq[i] = vet[esq + i]; 
    for (int j = 0; j < meioDir; j++) 
        vetDir[j] = vet[meio + 1+ j]; 
  
    int i = 0;
    int j = 0;
    int k = esq;
    while (i < meioEsq && j < meioDir) { 
        if (vetEsq[i] <= vetDir[j]) { 
            vet[k] = vetEsq[i]; 
            i++; 
        } else { 
            vet[k] = vetDir[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < meioEsq) { 
        vet[k] = vetEsq[i]; 
        i++; 
        k++; 
    } 
    while (j < meioDir) { 
        vet[k] = vetDir[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int *vet, int esq, int dir) { 
    if (esq < dir) { 

        int meio = esq+(dir-esq)/2; 

        mergeSort(vet, esq, meio); 
        mergeSort(vet, meio+1, dir); 
  
        merge(vet, esq, meio, dir); 
    } 
} 

int buscaBinaria(int *vet, int esq, int dir, int elemento) {
    if(dir >= esq) {
        int meio = esq + (dir - esq)/2;
        if (vet[meio] == elemento) {
            return meio;
        }
        if(vet[meio] > elemento) {
            return buscaBinaria(vet, esq, meio-1, elemento);
        }
        if(vet[meio] < elemento) {
            return buscaBinaria(vet, meio+1, dir, elemento);
        }
    }
    return -1;

}

void main(int argc, char *argv[]) {
    FILE *arquivo;
    arquivo = fopen(argv[1], "r");
    if(arquivo == NULL) {
        printf("arquivo nao encontrado \n");
        exit(0);
    }

    int vetor[TAMANHO], i = 0, count;

    iniciaVetor(vetor,arquivo);
    mergeSort(vetor, 0, TAMANHO - 1);
    for(int i = 0; i < TAMANHO; i++) {
        printf("|%d|\n", vetor[i]);
    }
    int elemento = buscaBinaria(vetor,0 , TAMANHO-1, 1001);
    printf("elemento = %d \n", elemento);
    fclose(arquivo);

}