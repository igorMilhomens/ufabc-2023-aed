#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


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

int main(int argc, char const *argv[])
{
    int *qtd = malloc(sizeof(int));
    int *soma = malloc(sizeof(int));

    LinkedNode *inicio = NULL;
    int init;
	
	inicio = inserir_final_r(inicio, 55);
	inicio = inserir_final_r(inicio, 22);
	inicio = inserir_final_r(inicio, 33);
	
	contar(inicio, qtd, soma);

	
	printf("Quantidade = %d\n", *qtd);
    printf("Soma = %d\n", *soma);
    imprimir1(inicio);
    imprimir2(inicio);
	
	return 0;
}
