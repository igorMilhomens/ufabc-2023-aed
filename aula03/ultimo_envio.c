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
    // Código da função aqui
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
    // Código da função aqui
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
