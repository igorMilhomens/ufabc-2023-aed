// #include <qtd_palavras_frase.h>
#include <stdio.h>

void imprimir_qtd_palavras(char texto[]) ;

int main(){
    imprimir_qtd_palavras("Algoritmos   e   Estruturas de Dados I. Nessa disciplina,     serao vistas estruturas de dados como   listas, pilhas, filas e arvores  .   Tambem serao vistos algoritmos de  busca  e  ordenacao.");
  return 0;
}

void imprimir_qtd_palavras(char texto[]) {
  // Código da função 
  int i = 0;
  int auxLetra = 0;
  int quantPalavra = 0;
  int n;

  while(texto[i] != '\0'){
    if(texto[i] != ' ' && texto[i] != '\n' && texto[i] != '.'  ){
      auxLetra ++;
    }
    if(texto[i]==' ' && auxLetra>0){
      quantPalavra ++;
      auxLetra = 0;
    }
    else if((texto[i]=='.' && auxLetra>0)||(texto[i+1]=='\0' && auxLetra>0)){
      quantPalavra ++;
      printf("%d\n", quantPalavra);
      quantPalavra = 0;
      auxLetra = 0;
    }else if(texto[i]=='.'){
      printf("%d\n", quantPalavra);
      quantPalavra = 0;
      auxLetra = 0;
    }
    i++;
  }
}
