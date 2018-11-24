#include "vetor.h"
#define TAM 1000

int count = 0;

int particiona (int vet[], int menor, int maior) 
{ 
    int pivo = vet[maior], aux;    // pivo 
    int i = (menor - 1);  // Index of smaller element 
  
    for (int j = menor; j <= maior- 1; j++){ 
        if (vet[j] <= pivo) 
        { 
            i++; 
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        } 
    } 
    aux = vet[i + 1];
    vet[i +1] = vet[maior];
    vet[maior] = aux;
    return (i + 1); 
} 
  
void quickSort(int vet[], int menor, int maior){ 
    int aux;
    if (menor < maior){ 
        int aux = particiona(vet, menor, maior); 
  
        quickSort(vet, menor, aux - 1); 
        quickSort(vet, aux + 1, maior); 
    } 
} 

int main( int argc, char* argv[] ) 
{ 
    int vet[TAM], i;
    FILE *arq;
    arq = fopen( argv[1], "r" );
    
    iniciaVetor(vet,arq);

    printf("\n---------------------------HeapSort----------------------------------\n");
    double tempoIni = (double) clock() / 1000000;

    quickSort(vet, 0, TAM-1); 

    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    // printf("Quantidade de instrucoes = %d Instrucoes\n",count);
    printf("\n---------------------------End-HeapSort-------------------------------\n");

    for(i = 0; i<TAM; i++){
        printf("%d \n",vet[i]);
    }

    return 0; 
} 