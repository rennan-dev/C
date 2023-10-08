//Algoritmo que imprime todos os números que são multiplos de 3 e 5 no intervalo entre dois números

#include <stdio.h>
#include <stdlib.h>

void recursao(int num1, int num2) {
    if(num1 <= num2) {
        if(num1%3==0 && num1%5==0) {
            printf("%i ", num1);
        }
        num1++;
        recursao(num1,num2);
    }
    
}

int main() {

    int num1, num2;
    scanf("%i%i", &num1, &num2);

    if(num1>num2) {
        int aux=num1;
        num1 = num2;
        num2 = aux;
    }

    recursao(num1,num2);  

    return 0;
}