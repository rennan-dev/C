//SOMATÓRIO

#include <stdio.h>

int somatorio(int n) {

    if(n==6) {
        return 6;
    }else {
        return n + somatorio(n+1);
    }
}

int main() {

    printf("%i ", somatorio(1));

    return 0;
}

