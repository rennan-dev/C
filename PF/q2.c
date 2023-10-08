//algoritmo que ordena do maior para o menor tres números digitados pelo usuário

#include <stdio.h>

void ordena(int *a, int *b, int *c) {
    int aux=0;
    if(*a<*b) {
        aux=*a;
        *a=*b;
        *b=aux;
    }
    if(*a<*c) {
        aux=*a;
        *a=*c;
        *c=aux;
    }
    if(*b<*c) {
        aux=*b;
        *b=*c;
        *c=aux;
    }
}

int main() {

    int a,b,c;
    scanf("%i%i%i", &a,&b,&c);

    ordena(&a,&b,&c);

    printf("%i %i %i", a,b,c);

    return 0;
}