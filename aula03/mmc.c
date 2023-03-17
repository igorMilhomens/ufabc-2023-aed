#include <stdio.h>
#include <stdlib.h>
 
//Algoritmo de Euclides iterativo
int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//Algoritmo do MMC
int mmc(int a, int b){
    return a * (b / mdc(a, b));
}
//Testes
int main() {
    printf("MMC\n");
    printf("mmc(20, 18) = %d\n", mmc(20, 18));
     printf("mdc(20, 18) = %d\n", mdc(20, 18));
      printf("mdc(10, 9) = %d\n", mdc(10,9 ));
     
    printf("mdc(1335, 180) = %d\n", mdc(1335, 180));
    printf("mmc(30, 60) = %d\n", mmc(30, 60));
    printf("mmc(60, 100) = %d\n", mmc(60, 100));
    printf("mmc(36, 14) = %d\n", mmc(36, 14));
    return 0;
}