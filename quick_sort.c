#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int vet[], int tam) {
    int i;
    for(i=0; i<tam; i++) {
        printf("%i ", vet[i]);
    }
    printf("\n");
}

void inicializa(int vet[], int tam){
    srand(time(NULL));
    int i;

    for(i=0; i<tam; i++) {
        vet[i] = rand() % 100;
    }
}

int partition(int *vet, int inicio, int fim) {
    int pivo, i, j, temp;
    pivo = vet[fim];
    i = inicio-1;

    for(j=inicio; j<fim; j++) {
        if(vet[j]<=pivo) {
            i++;
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }
    temp = vet[i+1];
    vet[i+1] = vet[fim];
    vet[j] = temp;
    return i+1;
}

void quick_sort(int *vet, int inicio, int fim) {
    int meio=0;
    if(inicio<fim) {
        meio = partition(vet,inicio,fim);
        quick_sort(vet,inicio,meio-1);
        quick_sort(vet,meio+1,fim);
    }
}

int main() {

    int tam=20;
    int vet[tam];

    inicializa(vet,tam);
    printf("\nVetor antes: ");
    imprimir(vet,tam);
    printf("\n\nVetor Depois: ");
    quick_sort(vet,0,tam-1);
    imprimir(vet,tam);

    return 0;
}