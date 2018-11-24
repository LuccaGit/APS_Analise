#include "vetor.h"
#define TAM 1000

int count = 0;

void heapify(int vet[], int n, int i) 
{ 
    int maior = i; // Inicializa maior como raiz 
    int e = 2*i + 1; // esquerda = 2*i + 1 
    int d = 2*i + 2; // direita = 2*i + 2 
    int aux;
    count ++;

    if (e < n && vet[e] > vet[maior]) 
        maior = e; 
  
    if (d < n && vet[d] > vet[maior]) 
        maior = d; 
  
    if (maior != i) 
    { // troca
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;

        heapify(vet, n, maior); 
    } 
} 


void heapSort(int vet[], int n) 
{ 
    int aux;
    count ++;
        
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(vet, n, i); 
    
    for (int i=n-1; i>=0; i--) 
    { 
        aux = vet[i];
        vet[i] = vet[0];
        vet[0] = aux;

        heapify(vet, i, 0); 
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

    heapSort(vet, TAM); 
    
    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",count);
    printf("\n---------------------------End-HeapSort-------------------------------\n");

    // for(i = 0; i<TAM; i++){
    //     printf("%d \n",vet[i]);
    // }
}