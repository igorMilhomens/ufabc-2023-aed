// #include "funcao_param_referencia.h"
#include <stdio.h>

void funcao(int a, int b, int *resultado) {
    // Código da função aqui
    int calculo=0;
    int resultadoFinal = 0;

    for(int i=1; i<=a; i++){
        calculo = 0;
        for(int j=1; j<=b;j++){
            calculo = calculo+((i*j)+10);
        }
        resultadoFinal = resultadoFinal+(calculo*5*i) ;
    }
    *resultado = resultadoFinal;

    printf("resultado final %d\n", *resultado);
}

int main(){
    int* ponteiro;
    printf("ponteiro %p\n", ponteiro);
    funcao(2,3,ponteiro);
}