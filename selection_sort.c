/*

#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Marca o início da execução do código

    // Seu código aqui

    end = clock(); // Marca o fim da execução do código

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calcula o tempo de CPU em segundos

    printf("Tempo de execucao: %f segundos\n", cpu_time_used);

    return 0;
}

*/

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

void selection_sort(int vet[], int tam) {
    int i, j, menor, temp;

    for(i=0; i<tam-1; i++) {
        menor = i;
        for(j=i+1; j<tam; j++) {
            if(vet[j] < vet[menor]) {
                menor = j;
            }
        }
        temp = vet[i];
        vet[i] = vet[menor];
        vet[menor] = temp;
    }
}

int main() {

    int tam=20;
    int vet[tam];

    inicializa(vet,tam);
    printf("\nVetor antes: ");
    imprimir(vet,tam);
    printf("\n\nVetor Depois: ");
    selection_sort(vet,tam);
    imprimir(vet,tam);

    return 0;
}