#include <stdlib.h>
#include "duplicar.h"

void duplicar_pares1(LinkedNode *inicio) {
    LinkedNode *atual = inicio;
    while (atual!=NULL)
    {
        if (atual->data%2 == 0)
        {
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            novo->data = atual->data;
            novo->next = atual->next;
            atual->next = novo;
            atual = novo->next;
        }
        else{
            atual=atual->next;
        }
    }
    
}

void duplicar_pares2(DLinkedNode *inicio) {
    DLinkedNode *atual = inicio;
    while (atual!=NULL)
    {
        if (atual->data%2 == 0)
        {
            DLinkedNode *novo = malloc(sizeof(LinkedNode));
            novo->data = atual->data;
            novo->next = atual->next;
            novo->prev = atual;
            if(atual->next !=NULL){
                    atual->next->prev = novo;
            }      
            atual->next = novo;
            atual = novo->next;
        }
        else{
            atual=atual->next;
        }
    }
}