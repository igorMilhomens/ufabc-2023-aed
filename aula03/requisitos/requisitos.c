#include <stdlib.h>
#include "requisitos.h"

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {
    int qtdRequisitos = 0;
    Disciplina *retorno = NULL;
    while(disciplina->requisito != NULL){
        retorno = disciplina->requisito;
        qtdRequisitos++;
        disciplina = retorno;
    }
    *qtd = qtdRequisitos;
    return retorno;
}
//retornar dados da disciplina que é o requisito inicial (de acordo com o retorno da função)
// quantidade de disciplinas que são requisito (de acordo com o retorno da função)