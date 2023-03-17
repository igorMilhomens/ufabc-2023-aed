// #include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido) {
    // Código da função aqui
    int acumulador = 0;
    int ultimaPosicao = 0;
    int auxVar = 0;
    int* novoVet = malloc(sizeof(int));
    for(int i=0; i<n_compactado; i++){
        if(i%2!=0){
            ultimaPosicao= acumulador;
            acumulador += vetor[i];
            novoVet = realloc(novoVet, acumulador*sizeof(int));
            for(int j=ultimaPosicao;j< acumulador;j++){
                novoVet[j] = auxVar;
            }
            
        }
        else{
            auxVar = vetor[i];
        }
    }
    *n_expandido = acumulador;
    return novoVet;
}

int main(){
    int v[8] = {10 ,5 ,50 ,2 ,10 ,3 ,90 , 1};
    int* pt;
    pt=v;
    int n=8;
    int n1=0;
    int* n_exp = &n1;
    int* result  = malloc(11*sizeof(int));;

    result = expandir_vetor(pt, n, n_exp);

    printf("Valor n: %d\n",n);

    printf("Valor n_exp: %d\n",*n_exp);
    
    for(int i=0; i<*n_exp;i++){
        printf("%d ",result[i]);
    }

    return 0;

}