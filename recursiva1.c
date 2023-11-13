#include <stdio.h>

int fatorial(int fat) {

    if(fat == 1) {
        return 1;

    }else{
        return fat * fatorial(fat-1);  
    }
    
}

int main() {

    int fat;

    scanf("%i", &fat);
    
    printf("%i\n", fatorial(fat));
    
    return 0;
}