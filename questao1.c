#include <stdio.h>
#include <stdlib.h>

int subconjunto(int vet[], int tam) {

    int i, max_global, max_atual;
    max_global = max_atual = vet[0];

    printf("\n\nVetor: ");
    for(i=1; i<tam; i++) {
        max_atual = (vet[i] > max_atual + vet[i]) ? vet[i] : max_atual + vet[i];

        if(max_atual > max_global) {
            max_global = max_atual;
            printf("%i ", vet[i]);
        }
    }

    return max_global;
}

int main() {

    int tam, i;
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

    printf("\nSoma maxima: %i\n", subconjunto(vet,tam));

    return 0;
}