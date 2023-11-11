#include <stdio.h>

int main() {

    int num = 10, temp=5;
    int *p1, *p2;

    p1 = &num;
    p2 = &temp;

    *p2 = *p1;

    printf("\nnum: %i\ntemp: %i\n", num, temp);

    return 0;
}