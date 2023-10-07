#include <stdio.h>
#include <stdlib.h>

void giraArray(int vet[], int tam, int k) {

    while(k>tam) {
        k = k - tam;
    }

    int i, j;
    for(i=0, j=k-1; i<tam; i++,j++) {
        
        if(j==tam) {
            j=0;
        }
        printf("%i ", vet[j]);
    }
}

int main() {

    int tam, k, i;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%i", &tam);
    if(tam<=0) {
        exit(0);
    }


    int vet[tam];
    printf("\nDigite os elementos do vetor: ");
    for(i=0; i<tam; i++) {
        scanf("%i", &vet[i]);
    }

    printf("\nDigite quantas vezes ele ira girar para a direita: ");
    scanf("%i", &k);

    printf("\n--------------------------------------\nVetor: ");
    if(k>0) {
        giraArray(vet,tam,k);
    }else {
        printf("\nEntrada invalida");
    }
    printf("\n--------------------------------------");

    return 0;
}