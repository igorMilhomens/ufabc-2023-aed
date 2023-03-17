#include "lista.h"
#include <stdlib.h>

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica {
   LinkedNode *topo;
};

PilhaDinamica *criar_pilha();
int empilhar(PilhaDinamica *pilha, char valor);
int desempilhar(PilhaDinamica *pilha, char *valor);
void liberar_pilha(PilhaDinamica *pilha);