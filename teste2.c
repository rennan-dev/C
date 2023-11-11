#include <stdio.h>

int main() {

    int num = 55;
    int *p;

    p = &num;

    *p += 1;

    printf("\n%i\n", num);

    return 0;
}