#include "numeros_matriz.h"

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas]) {
    // Código da função aqui
    int valorRemovido = m[l][c];
    m[l][c] = 0;
    if(l==0 ){
        if(c == 0){
            if(m[l][c+1] == valorRemovido){
                remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
            }
            if(m[l+1][c] == valorRemovido){
                remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
            }
        }else if(c == n_colunas-1){
            if(m[l][c-1] == valorRemovido){
                remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
            }
            if(m[l+1][c] == valorRemovido){
                remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
            }
        }
        else{
            if(m[l][c+1] == valorRemovido){
                remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
            }
            if(m[l][c-1] == valorRemovido){
                remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
            }
            if(m[l+1][c] == valorRemovido){
                remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
            }
        }
        
    }else if(l==n_linhas-1){
        if(c == 0){
            if(m[l][c+1] == valorRemovido){
                remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
            }
            if(m[l-1][c] == valorRemovido){
                remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
            }
        }else if(c == n_colunas-1){
            if(m[l][c-1] == valorRemovido){
                remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
            }
            if(m[l-1][c] == valorRemovido){
                remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
            }
        }
        else{
            if(m[l][c+1] == valorRemovido){
                remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
            }
            if(m[l][c-1] == valorRemovido){
                remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
            }
            if(m[l-1][c] == valorRemovido){
                remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
            }

        }

    }else{
        if(c == 0){
            if(m[l][c+1] == valorRemovido){
                remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
            }
            if(m[l+1][c] == valorRemovido){
                remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
            }
            if(m[l-1][c] == valorRemovido){
                remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
            }
            
        }else if(c == n_colunas-1){
            if(m[l][c-1] == valorRemovido){
                remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
            }
            if(m[l+1][c] == valorRemovido){
                remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
            }
            if(m[l-1][c] == valorRemovido){
                remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
            }

        }
        else{
            if(m[l][c+1] == valorRemovido){
                remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
            }
            if(m[l][c-1] == valorRemovido){
                remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
            }
            if(m[l+1][c] == valorRemovido){
                remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
            }
            if(m[l-1][c] == valorRemovido){
                remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
            }
        }
    }

}


// for(int i=0; i < n_linhas; i++){
//         for(int j=0; j < n_colunas; j++){
//             i== n_linhas-1 ? print("%d",m[i][j]): print("%d ",m[i][j]);
//         }
//     }
