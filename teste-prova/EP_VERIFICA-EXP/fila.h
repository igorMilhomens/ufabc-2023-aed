#include "lista.h"
#include <stdlib.h>

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica {
   LinkedNode *inicio, *fim;
};

FilaDinamica *criar_fila();
int enfileirar(FilaDinamica *fila, int valor);
int desenfileirar(FilaDinamica *fila, int *valor);
void liberar_fila(FilaDinamica *fila);