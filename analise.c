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

    printf("tempo de execucao = %f Segundos\n",tempo);
    printf("quantidade de instrucoes = %d Instrucoes\n",count);
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
                count++;
                if(vet[j] > vet[j + 1]){
                    breaker = 0;
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
    printf("---------------------------SelectionSort----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;
    int aux, i = tamanho-1 , j, indiceM, count = 0;
     while(i >= 0) {
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

}

int merge(int *vet, int esq, int meio, int dir) {

    int meioEsq = meio - esq + 1; 
    int meioDir =  dir - meio; 
    int vetEsq[meioEsq], vetDir[meioDir]; 
    int count = 0;
    for (int i = 0; i < meioEsq; i++){
        count++;
        vetEsq[i] = vet[esq + i]; 
    }

    for (int j = 0; j < meioDir; j++) {
        count++;
        vetDir[j] = vet[meio + 1+ j]; 
    }

    int i = 0;
    int j = 0;
    int k = esq;
    while (i < meioEsq && j < meioDir) { 
        count++;
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
        count++;
        vet[k] = vetEsq[i]; 
        i++; 
        k++; 
    } 
    while (j < meioDir) { 
        count++;
        vet[k] = vetDir[j]; 
        j++; 
        k++; 
    }
    return count;
}

int countMerge = 0;
void mergeSort(int *vet, int esq, int dir) {
    countMerge += 1;
    if (esq < dir) { 

        int meio = esq+(dir-esq)/2; 

        mergeSort(vet, esq, meio); 
        mergeSort(vet, meio+1, dir); 
  
        countMerge += merge(vet, esq, meio, dir); 
    } 
}

void buildMerge(int *vet, int esq, int dir) {

    printf("---------------------------MergeSort----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;

    mergeSort(vet, esq, dir);

    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",countMerge);
    printf("\n---------------------------MergeSort----------------------------------\n");
}

int countHeap = 0;
void heapify(int *vet, int n, int i) { 
    int maior = i; // Inicializa maior como raiz 
    int e = 2*i + 1; // esquerda = 2*i + 1 
    int d = 2*i + 2; // direita = 2*i + 2 
    int aux;
    countHeap ++;

    if (e < n && vet[e] > vet[maior]) {
        maior = e; 
    }

  
    if (d < n && vet[d] > vet[maior]) {
        maior = d; 
    }

  
    if (maior != i) { // troca
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;

        heapify(vet, n, maior); 
    } 
} 

void heapSort(int *vet, int n) { 
    int aux;
    countHeap ++;
        
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vet, n, i); 
    }

    
    for (int i=n-1; i>=0; i--) { 
        aux = vet[i];
        vet[i] = vet[0];
        vet[0] = aux;

        heapify(vet, i, 0); 
    } 
} 

void buildHeap(int *vet, int n){
    printf("---------------------------HeapSort----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;

    heapSort(vet, n); 
    
    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",countHeap);
    printf("\n---------------------------HeapSort-------------------------------\n");

}

int countQuick = 0;
int particiona (int *vet, int menor, int maior) { 
    int pivo = vet[maior], aux;    // pivo 
    int i = (menor - 1);  // Index of smaller element 
  
    for (int j = menor; j <= maior- 1; j++){
        countQuick ++;
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
  
void quickSort(int *vet, int menor, int maior){ 
    int aux;
    if (menor < maior){ 
        int aux = particiona(vet, menor, maior); 
  
        quickSort(vet, menor, aux - 1); 
        quickSort(vet, aux + 1, maior); 
    } 
}

void buildQuick (int *vet, int menor, int maior) {
    printf("---------------------------QuickSort----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;

    quickSort(vet, menor, maior); 
    
    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",countQuick);
    printf("\n---------------------------QuickSort-------------------------------\n");
}

int countBin = 0;
int buscaBinaria(int *vet, int esq, int dir, int elemento) {
    countBin++;
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

void buildBuscaBinaria(int *vet, int esq, int dir, int elemento) {
    printf("---------------------------Busca-Binaria----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;

    int val = buscaBinaria(vet, esq, dir, elemento); 
    
    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",countBin);
    printf("Resultado da Busca = %d \n", val);
    printf("\n---------------------------Busca-Binaria-------------------------------\n");
}

typedef struct {
    int maxVector;
    int ini;
    int fim;
} retorno;

int countMax = 0;
retorno * maxSubvetor(int *vet, int tamanho) {

    retorno *ret = (retorno*) malloc(sizeof(retorno));
    int maxVector = vet[0];
    int max;
    int ini = 0;
    int fim = 0;
    for(int i = 0; i < tamanho; i++) {
        max = 0;
        for(int j = i; j < tamanho; j++) {
            max+= vet[j];
            countMax++;
            if(maxVector < max) {
                maxVector = max;
                ini = i;
                fim = j;
            }
        }
    }
    ret->maxVector = maxVector;
    ret->ini = ini;
    ret->fim = fim;

    return ret;
}

void buildMaxSubvetor(int *vet, int tamanho) {
    printf("---------------------------Subvetor-Maximo----------------------------------\n\n");
    double tempoIni = (double) clock() / 1000000;

    retorno* ret = maxSubvetor(vet, tamanho); 
    
    double tempoFim = (double) clock () / 1000000;
    float tempo = tempoFim - tempoIni;

    printf("Tempo de execucao = %f Segundos\n",tempo);
    printf("Quantidade de instrucoes = %d Instrucoes\n",countMax);
    printf("max = %d, ini = %d, fim = %d \n", ret->maxVector, ret->ini, ret->fim);
    printf("\n---------------------------Subvetor-Maximo-------------------------------\n");
}

void main(int argc, char *argv[]) {
    FILE *arquivo;
    arquivo = fopen(argv[1], "r");
    if(arquivo == NULL) {
        printf("arquivo nao encontrado \n");
        exit(0);
    }

    int vetor1[TAMANHO], vetor2[TAMANHO], vetor3[TAMANHO], vetor4[TAMANHO], vetor5[TAMANHO], vetor6[TAMANHO], vetor7[TAMANHO], vetor8[TAMANHO], vetor9[TAMANHO];

    iniciaVetor(vetor1, arquivo);
    iniciaVetor(vetor2, arquivo);
    iniciaVetor(vetor3, arquivo);
    iniciaVetor(vetor4, arquivo);
    iniciaVetor(vetor5, arquivo);
    iniciaVetor(vetor6, arquivo);
    iniciaVetor(vetor7, arquivo);
    iniciaVetor(vetor8, arquivo);
    iniciaVetor(vetor9, arquivo);

    // for(int i = 0; i < TAMANHO; i++){
    //     printf("vet1 = %d \n", vetor1[i]);
    //     printf("vet2 = %d \n", vetor2[i]);
    //     printf("vet3 = %d \n", vetor3[i]);
    // }

    bubbleSort(vetor1, TAMANHO);
    bubbleSortOtimizado(vetor2, TAMANHO);
    insertionSort(vetor3, TAMANHO);
    SelectionSort(vetor4, TAMANHO);
    buildMerge(vetor5, 0, TAMANHO);
    buildHeap(vetor6, TAMANHO);
    buildQuick (vetor7, 0, TAMANHO);
    buildBuscaBinaria(vetor8, 0, TAMANHO, 986);
    buildMaxSubvetor(vetor9, TAMANHO);
    
    fclose(arquivo);

}