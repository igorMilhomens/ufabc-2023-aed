
#include <stdio.h>
#include <stdlib.h>




int* cria_vetor(int n){
   int* vetor= malloc(n*sizeof(int));


   for(int i=0; i<n;i++){
       vetor[i] = rand();
   }
   return vetor;
}
void imprime_vetor(int* v, int n){
   for(int i=0; i<n;i++){
       printf("%d ",v[i]);
   }
   printf("\n");
}


int main(int argc, char const *argv[]){
  
   int* v = cria_vetor(5);
   imprime_vetor(v,5);
   free(v);
   return 0;
}
