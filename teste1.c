#include <stdio.h>

int main() {

    int num, valor;
    int *p;

    num = 55;
    p = &num;
    valor = *p;
    printf("\na=%i\nb=%i\np=%p\n", num,valor,p);

    return 0;
}