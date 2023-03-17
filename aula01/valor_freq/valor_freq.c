#include "valor_freq.h"

int valor_frequente(int v[], int n) {
    // Código da função aqui
    int result = 0;
    int aux = 0;
    int auxMax = 0;
    for (int i = 0; i < n; i++)
    {
        aux=0;
        for (int j = 0; j < n; j++)
        {
            if(v[i]==v[j]){
                aux++;
            }
        }
        if(auxMax<aux){
            auxMax = aux;
            result = v[i];
        }
    }

    return result;
    
}