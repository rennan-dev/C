#include <stdio.h>

int somaInplicita(int a, int b) {

    if(a == b) {
        return a;

    }else if(a<b) {
        return a + somaInplicita(a+1, b);
    }else {
        return a + somaInplicita(a-1, b);
    }
}

int main() {

    printf("%i ", somaInplicita(10, 15));

    return 0;
}