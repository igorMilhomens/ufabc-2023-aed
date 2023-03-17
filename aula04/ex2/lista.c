#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void contar(LinkedNode *inicio, int *qtd, int *soma) {
    LinkedNode* atual = inicio;
    int contar = 0;
    int valorTotal =0;

    while (atual!=NULL)
    {
        contar ++;
        valorTotal += atual->data;
        atual = atual->next;
    }
    *qtd = contar;
    *soma = valorTotal; 
}

void imprimir1(LinkedNode *inicio) {
    // Impressao nao deve incluir espaco apos ultimo caractere
    // Deve ser incluido um \n ao final da impressao

    LinkedNode* atual = inicio;
    while(atual!= NULL){
        atual->next==NULL ? printf("%d\n", atual->data) : printf("%d ", atual->data);
        atual = atual->next;
    }
}

void imprimir2(LinkedNode *inicio) {
    // Impressao nao deve incluir espaco apos ultimo caractere
    // Deve ser incluido um \n ao final da impressao
    
    //criar nova lista esta dando estouro de memoria
    int count = 0;
    LinkedNode* atual = inicio;
    while(atual!= NULL){
        count ++;
        atual=atual->next;
    }
    int *vetor = malloc(count*sizeof(int));

    LinkedNode *novo = inicio;
    
    int i = 0;
    while(novo!= NULL){
        vetor[i] = novo->data;
        i++;
        novo = novo->next;
    }
    for (int i = count-1; i >=0; i--)
    {
        i==0 ? printf("%d\n", vetor[i]) : printf("%d ", vetor[i]);
    }

    free(vetor);
}