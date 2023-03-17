#include <stdio.h>
void main ()
{
   int num;
   int result = 0;
   scanf("%d", &num);
   for(int i = 0; i<num; i++){
       int k;
       int aux = 1;


       scanf("%d", &k);
       while(aux<=k){
           aux*=2;
           if(aux == k){
           result++;
           }       
       }
      
   }
   printf("%d\n", result);
}
