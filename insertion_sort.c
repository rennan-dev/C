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

void insertion_sort(int vet[], int tam) {
    int copia, indice, i;

    for(i=1; i<tam; i++) {
        copia = vet[i];
        indice = i;

        while(indice>0 && vet[indice-1]>copia) {
            vet[indice] = vet[indice-1];
            indice--;
        }
        vet[indice] = copia;
    }
}

int main() {

    int tam=20;
    int vet[tam];

    inicializa(vet,tam);
    printf("\nVetor antes: ");
    imprimir(vet,tam);
    printf("\n\nVetor Depois: ");
    insertion_sort(vet,tam);
    imprimir(vet,tam);

    return 0;
}