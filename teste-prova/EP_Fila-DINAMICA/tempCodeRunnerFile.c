
FilaDinamica *criar_fila() {
    FilaDinamica* fila = malloc(sizeof(FilaDinamica));

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

int enfileirar(FilaDinamica *fila, int valor) {
    LinkedNode* node = malloc(sizeof(LinkedNode));
    if (node == NULL){
        return 0;
    }

    node->data = valor;
    node->next = NULL;
    
    if(fila->inicio == NULL){
        fila->inicio = node;
        fila->fim = node;
    }
    else{
        fila->fim->next = node;
        fila->fim = node;
    }
    
    return 1;
}

int desenfileirar(FilaDinamica *fila, int *valor) {
    if(fila->inicio == NULL){
        return 0;
    }

    LinkedNode* atual = fila->inicio;
    *valor = fila->inicio->data;

    fila->inicio = fila->inicio->next;
    free(atual);
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return 1;
}

void liberar_fila(FilaDinamica *fila) {
    LinkedNode* atual = fila->inicio;
    while(atual!=NULL){
        LinkedNode *noAtual = atual;
        atual = atual->next;
        free(noAtual);
    }
    free(fila);
}