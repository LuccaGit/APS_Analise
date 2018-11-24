#include "vetor.h"
#define TAMANHO 1000


void bubbleSort(int *vet,int tamanho) {
    printf("---------------------------bubbleSort----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;
    int aux, count = 0;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(vet[i] < vet[j]){
                count++;
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("tempo de execucao = %f Segundos\n",tempo);
    printf("quantidade de instrucoes = %d Instrucoes\n",count);
    printf("\n---------------------------bubbleSort----------------------------------\n");
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
    bubbleSort(vetor,TAMANHO);
    fclose(arquivo);

}