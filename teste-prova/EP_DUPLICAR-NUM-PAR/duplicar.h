typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *next, *prev;
};

void duplicar_pares1(LinkedNode *inicio);
void duplicar_pares2(DLinkedNode *inicio);