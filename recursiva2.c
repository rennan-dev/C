#include <stdio.h>

int loop(int n) {

    if(n==0) {
        return 1;
    }else {
         
        loop(n-1);
        printf("%i ", n); 
    }
}

int main() {
    
    loop(10);

    return 0;
} 