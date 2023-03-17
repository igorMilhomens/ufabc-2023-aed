#include <stdlib.h>
#include "fila.h"



void print_fila(FilaDinamica* fila){ 
    LinkedNode* cur = fila->inicio;
    if(fila->inicio!=NULL){
        while (cur!= NULL)
        {
        printf("%d ", cur->data);
        cur= cur->next;
        }
        printf("\n");
    }
    else{
        printf("Lista vazia ");
    }
}

int main(int argc, char const *argv[])
{
    FilaDinamica* fila = criar_fila();
    int * num = malloc(sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        enfileirar(fila, i+1);
        
    }

    print_fila(fila);
    for (int i = 0; i < 5; i++)
    {
        desenfileirar(fila, num);
        
    }
    print_fila(fila);

    liberar_fila(fila);
    print_fila(fila);

    return 0;
}
