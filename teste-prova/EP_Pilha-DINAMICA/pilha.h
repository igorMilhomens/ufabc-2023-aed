#include "lista.h"
#include <stdlib.h>

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica {
   LinkedNode *topo;
};

PilhaDinamica *criar_pilha();
int empilhar(PilhaDinamica *pilha, int valor);
int desempilhar(PilhaDinamica *pilha, int *valor);
void liberar_pilha(PilhaDinamica *pilha);