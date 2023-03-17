#include <stdlib.h>
#include <stdio.h>
#include "duplicar.h"

LinkedNode *add_list(LinkedNode *list, int value){ 
    if(list == NULL){
        LinkedNode *novo = malloc(sizeof(LinkedNode));
        if(novo == NULL){
            return list;
        }
        novo->data = value;
        novo->next = NULL;
        return novo;
    }
    list->next = add_list(list->next, value);
    return list;
}

DLinkedNode *add_list_dupla(DLinkedNode *list, int value){ 
    if(list == NULL){
        DLinkedNode *novo = malloc(sizeof(DLinkedNode));
        if(novo == NULL){
            return list;
        }
        novo->data = value;
        novo->next = NULL;
        novo->prev = list;
        return novo;
    }
    list->next = add_list(list->next, value);
    return list;
}

void print_list(LinkedNode *list){
    LinkedNode *atual = list;
    printf("Lista:");
    if(list == NULL){
        printf("Lista vazia");
    }
    else{
        while (atual!=NULL)
        {
           printf("%d ",atual->data);
           atual = atual->next;
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    LinkedNode *lista = NULL;
    DLinkedNode *dLista = NULL;

    lista = add_list(lista,10);
    lista = add_list(lista,11);
    lista = add_list(lista,12);

    dLista = add_list_dupla(dLista,20);
    dLista = add_list_dupla(dLista,21);
    dLista = add_list_dupla(dLista,22);

    print_list(lista);

    duplicar_pares1(lista);

    print_list(lista);

    print_list(dLista);

    duplicar_pares2(dLista);

    print_list(dLista);

    return 0;
}

