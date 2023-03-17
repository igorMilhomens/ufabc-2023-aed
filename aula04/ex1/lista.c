#include <stdio.h>
#include <stdlib.h>
// #include "lista.h"
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

int verificar_ordenacao(LinkedNode *inicio) {
    LinkedNode *atual = inicio;
    LinkedNode *proximoItem;
    
    while(atual != NULL){
        proximoItem = atual->next;
        if(proximoItem!=NULL){
            if(proximoItem->data < atual->data){
                return 0;
            }
        }
        atual = proximoItem;
    }
    return 1;
}

LinkedNode *inserir_final_r(LinkedNode *inicio, int valor) {
	if (inicio == NULL) {
		LinkedNode *novo = malloc(sizeof(LinkedNode));
		if (novo == NULL) return inicio;
		novo->data = valor;
		novo->next = NULL;
		return novo;
	}
	inicio->next = inserir_final_r(inicio->next, valor);
	return inicio;
}

int main() {
	LinkedNode *inicio = NULL;
    int init;
	
	inicio = inserir_final_r(inicio, 55);
	inicio = inserir_final_r(inicio, 22);
	inicio = inserir_final_r(inicio, 33);
	
	init = verificar_ordenacao(inicio);

	
	printf("%d", init);
	
	return 0;
}