#include <stdlib.h>
#include "intercalar.h"

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2) {
    // Código da função aqui
    LinkedNode * lista1 = inicio1;
    LinkedNode * lista2 = inicio2 ;
    LinkedNode * ultimo ;
    LinkedNode novaLista ;
    ultimo = &novaLista;
    novaLista.next = NULL;
    
    while( lista1 != NULL && lista2!= NULL){
        
        if (lista1->data < lista2->data)
        {
            ultimo->next = lista1;
            ultimo = lista1; 
            lista1 = lista1->next;
        }
        else
        {
            ultimo->next = lista2;
            ultimo = lista2; 
            lista2 = lista2->next;
        }
    }
    if(lista1 == NULL){
        ultimo->next = lista2;
    }
    else{
        ultimo->next = lista1;
    } 
    return novaLista.next;

}
