#include <stdio.h>

int maioria(int vet[], int tam) {

    int maior=0, i, j;

    for(i=0; i<tam; i++) {
        for(j=i; j<tam; j++) {
            if(vet[i]==vet[j]) {
                maior++;
            }
        }
        if(maior > (float)tam/2) {
            return vet[i];
        }
        maior=0;
    }
    return 0;

}

int main() {

    int nums, tam, i;

    printf("\nEscreva o tamanho do vetor: ");
    scanf("%i", &tam);
    int vet[tam];

    printf("\n\nEscreva o elementos do vetor: ");
    for(i=0; i<tam; i++) {
        scanf("%i", &vet[i]);
    }

    if(maioria(vet,tam)==0) {
        printf("\nO vetor nao possui um elemento de maioria.\n");
    }else {
        printf("\nO elemento de maioria eh: %i\n", maioria(vet,tam));
    }

    return 0;
}