typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void contar(LinkedNode *inicio, int *qtd, int *soma);
void imprimir1(LinkedNode *inicio);
void imprimir2(LinkedNode *inicio);