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

void merge_sorte(int vet[], int tam, int ini, int fim) {
    int meio, i, j, k, aux[tam];

    if(ini<fim) {
        meio = (ini+fim)/2;
        merge_sorte(vet,tam,ini,meio);
        merge_sorte(vet,tam,meio+1,fim);

        //faz o merge ordenando os elementos
        i = ini;
        j = meio+1;
        k = ini;

        while(i<=meio && j<=fim) {
            if(vet[i] < vet[j]) {
                aux[k] = vet[i];
                i++;
            }else {
                aux[k] = vet[j];
                j++;
            }
            k++;
        }

        while(i<=meio) {
            aux[k] = vet[i];
            i++;
            k++;
        }
        while(j<=fim) {
            aux[k] = vet[j];
            j++;
            k++;
        }

        for(i=ini; i<=fim; i++) {
            vet[i] = aux[i];
        }
    }
}

int main() {

    int tam=20;
    int vet[tam];

    inicializa(vet,tam);
    printf("\nVetor antes: ");
    imprimir(vet,tam);
    printf("\n\nVetor Depois: ");
    merge_sorte(vet,tam,0,tam-1);
    imprimir(vet,tam);

    return 0;
}