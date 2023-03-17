// #include "qtd_discos.h"
#include <stdlib.h>

void quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante) {
    // Código da função aqui
    int countA=0;
    int countB=0;
    int countC=0;
    int countD=0;
    int * quantFabricante = malloc(sizeof(int)*4);

    for(int i=0; i < n_discos; i++){
        if(discos[i][7]=='A'){
            countA++;
        }else if(discos[i][7]=='B'){
            countB++;
        }else if(discos[i][7]=='C'){
            countC++;
        }else{
            countD++;
        }
    }
    quantFabricante[0]= countA;
    quantFabricante[1]= countB;
    quantFabricante[2]= countC;
    quantFabricante[3]= countD;
    *quantidade_por_fabricante = quantFabricante;
    // free(quantFabricante);
    
}
void main(){
    char** mat;
    char a[]="Modelo_A2", b[]="Modelo_B2", c[]="Modelo_C1", d[]="Modelo_D1";
    mat = malloc(sizeof(char *)*4);

    for(int i=0;i<4;i++){
        mat[i] = malloc(sizeof(char)*11);
    }

    mat[0]=a;
    mat[1]=b;
    mat[2]=c;
    mat[3]=d;
    int num = 0;
    // for(int i=0;i<4;i++){
    //     printf("print mat %s\n",mat[i]);
    // }

    int ** result;
    result = malloc(sizeof(int *));
    // result[0] =malloc(sizeof(int)*4);
    // for(int i=0; i<4; i++){
    //     result[0][i] = num;
    //     num++;
    // }
    
    // for(int i=0;i<4;i++){
    //     printf("print result %d\n",result[0][i]);
    // }
    quantidade_discos(mat, 4, result);
    for(int i=0;i<4;i++){
        printf("print result %d\n",result[0][i]);
    }

}