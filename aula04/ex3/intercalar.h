typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2);