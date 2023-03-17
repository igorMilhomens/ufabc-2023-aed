#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

int main() {

    //char* exp = malloc(101*sizeof(char));
    char exp[101];
    //printf("digite a expressão\n");
    fgets(exp,101,stdin);
    int i=0;
    int controle = 0;
    char auxDesempilhar;
    
    PilhaDinamica *pilha = criar_pilha();

    while (exp[i] != '\0')
    {
        if(exp[i] == '['|| exp[i] == '(' || exp[i] == '{'){
            empilhar(pilha, exp[i]);
            controle++;
        }
        else if(exp[i] == ']'|| exp[i] == ')' || exp[i] == '}'){
            desempilhar(pilha, &auxDesempilhar);
            controle--;
            if(exp[i] == ']'){
                if(auxDesempilhar != '[' ){
                    printf("NAO");
                    return 0;
                }
            }
            else if(exp[i] == ')'){
                if(auxDesempilhar != '(' ){
                    printf("NAO");
                    return 0;
                }
            }
            else{
                if(auxDesempilhar != '{' ){
                    printf("NAO");
                    return 0;
                }
            }
        }
       i++;
    }
    //printf("Controle %d", controle);
   if(controle == 0){
       printf("SIM");
   }
   else{
       printf("NAO");
   }
   liberar_pilha(pilha);

    
    return 0;
}