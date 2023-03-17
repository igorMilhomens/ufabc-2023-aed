#include <stdio.h>
int main ()
{
    int num;
    int result = 0;

    scanf("%d", &num);
    int vet[num];
    int aux = 0;
    int aux1 = 0;
    int cont = 0;
    int  maiorTamanho = 0;
    int maiorInicio = 0;
    int maiorFim = 0;
    int inicioCont = 1;

    for(int i = 0; i<num; i++){

        scanf("%d", &vet[i]);
        if(inicioCont){
            
            if(i>0){
                aux = i-1;
            }
            else{
                aux = i;
            }
            inicioCont=0;
        }
        if(i>0){
            if(vet[i-1]<vet[i]){
                cont++;
                if(i==num-1 && cont>maiorTamanho){
                    maiorInicio = aux;
                    maiorFim = i;
                }
            }
            else{
                if(cont>maiorTamanho){
                    maiorTamanho = cont;
                    maiorInicio = aux;
                    maiorFim = i-1;
                    inicioCont = 1;
                    cont = 0;
                }
                else{
                    inicioCont = 1;
                    cont = 0;
                }
            }     
        }
               
    }

    for(int i = maiorInicio; i<= maiorFim; i++){
        i== maiorFim ? printf("%d",vet[i]): printf("%d ",vet[i]);
    }

    return 0; 
}
