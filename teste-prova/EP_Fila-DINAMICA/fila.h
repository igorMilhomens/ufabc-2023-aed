
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica {
   LinkedNode *inicio, *fim;
};

FilaDinamica *criar_fila();
int enfileirar(FilaDinamica *fila, int valor);
int desenfileirar(FilaDinamica *fila, int *valor);
void liberar_fila(FilaDinamica *fila);