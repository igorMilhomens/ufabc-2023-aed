// #include "fracoes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Fracao Fracao;
struct Fracao {
    int numerador, denominador;
};

Fracao somar(Fracao f1, Fracao f2) {
    Fracao resultado;
    int mmcDenominador = 0;
    int mcdResultado = 0;
    if(f1.denominador == f2.denominador){
        resultado.denominador = f1.denominador;
        resultado.numerador = f1.numerador+f2.numerador;
    }
    else{
        mmcDenominador = mmc(f1.denominador,f2.denominador);

        if(mmcDenominador == f1.denominador){
            resultado.denominador = mmcDenominador;
            resultado.numerador = f1.numerador+(f2.numerador*(mmcDenominador/f2.denominador));
        }
        else if(mmcDenominador == f2.denominador){
            resultado.denominador = mmcDenominador;
            resultado.numerador = f2.numerador+(f1.numerador*(mmcDenominador/f1.denominador));
        }
        else{
            resultado.denominador = mmcDenominador;
            resultado.numerador = (f1.numerador*(mmcDenominador/f1.denominador))+(f2.numerador*(mmcDenominador/f2.denominador));
        }
    }
    while (mcdResultado!=1)
    {
         mcdResultado = mdc(resultado.denominador,resultado.numerador);
        if(mcdResultado!=1){
            resultado.denominador /= mcdResultado;
            resultado.numerador /= mcdResultado;
        }
    }
    return resultado;
}

Fracao somar_vetor(Fracao f[], int n_fracoes) {
    int mcdResultado = 0;
    int init = 0;
    Fracao resultado;
    if(init == 0){
        resultado = somar(f[0],f[1]);
    }
    for(int i=2; i<n_fracoes; i++){
    resultado = somar(resultado,f[i]);
    }
    while (mcdResultado!=1)
    {
         mcdResultado = mdc(resultado.denominador,resultado.numerador);
        if(mcdResultado!=1){
            resultado.denominador /= mcdResultado;
            resultado.numerador /= mcdResultado;
        }
    }
    return resultado;
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    Fracao resultado;
    int mcdResultado;
   
    resultado.numerador =  f1.numerador*f2.numerador;
    resultado.denominador = f1.denominador*f2.denominador;

    while (mcdResultado!=1)
    {
         mcdResultado = mdc(resultado.denominador,resultado.numerador);
        if(mcdResultado!=1){
            resultado.denominador /= mcdResultado;
            resultado.numerador /= mcdResultado;
        }
    }
    
    return resultado;
   
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    int mcdResultado = 0;
    Fracao resultado;
    resultado.denominador = 1;
    resultado.numerador = 1;
    for(int i=0; i<n_fracoes; i++){
        resultado.numerador *=  f[i].numerador;
        resultado.denominador *= f[i].denominador;
    }
    while (mcdResultado!=1)
    {
         mcdResultado = mdc(resultado.denominador,resultado.numerador);
        if(mcdResultado!=1){
            resultado.denominador /= mcdResultado;
            resultado.numerador /= mcdResultado;
        }
    }
    return resultado;
}

//Algoritmo do MDC
int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//Algoritmo do MMC
int mmc(int a, int b){
    return a * (b / mdc(a, b));
}

int main(){
    Fracao e1 ;
    Fracao e2;
    Fracao r;

    e1.numerador = 15;
    e1.denominador = 20;
   
    e2.numerador = 12;
    e2.denominador = 60;
    
   r = somar(e1, e2) ;
    printf("resultado fração soma %d / %d\n", r.numerador, r.denominador);
    r = multiplicar(e1, e2) ;
    printf("resultado fração multiplica %d / %d\n", r.numerador, r.denominador);
    Fracao e[3];
    e[0].numerador = 15;
    e[0].denominador = 20;
   
    e[1].numerador = 12;
    e[1].denominador = 60;

    e[2].numerador = 5;
    e[2].denominador = 3;
    r = somar_vetor(e, 3) ;
    printf("resultado fração soma vetor %d / %d", r.numerador, r.denominador);
    r = multiplicar_vetor(e, 3) ;
    printf("resultado fração multiplicar vetor %d / %d", r.numerador, r.denominador);
    return 0;
}