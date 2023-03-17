#include "intercalar.h"
#include <stdio.h>


LinkedNode *add_list(LinkedNode *list, int value){
    if(list == NULL){
        LinkedNode *novo = malloc(sizeof(LinkedNode));
        if(novo == NULL) {
            return list;
        }
        novo->data = value;
        novo->next = NULL;
        return novo;
    }
    list->next = add_list(list->next,value);
    return list;
}

void print_list(LinkedNode *list){
    if(list == NULL){
        printf("Lista vazia");
    }
    else{
        LinkedNode* atual = list;
        while(atual!= NULL){
            atual->next==NULL ? printf("%d\n", atual->data) : printf("%d ", atual->data);
            atual = atual->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    LinkedNode *inicio1 = NULL;
    LinkedNode *inicio2 = NULL;
    inicio1 = add_list(inicio1, 11);
	inicio1 = add_list(inicio1, 12);
	inicio1 = add_list(inicio1, 13);
    inicio1 = add_list(inicio1, 14);

    inicio2 = add_list(inicio2, 11);
	inicio2 = add_list(inicio2, 12);
	inicio2 = add_list(inicio2, 13);
    inicio2 = add_list(inicio2, 14);
    inicio2 = add_list(inicio2, 15);

    print_list(intercalar_listas(inicio1, inicio2));

    return 0;
}