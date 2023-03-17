// #include "freq_str.h"


void frequencia_string(const char *str, const char *texto, int *qtd) {
    // Código da função aqui
    int j=0;
    int contador=0;
    int aux=0;
    int guardaAux=1;
    char * palavra;
    char * txt;
    for(int i = 0; texto[i] != '\0'; i++){
        palavra = toupper(str[j]);
        txt = toupper(texto[i]);

        if (palavra == txt )
        {
            if(guardaAux){
                aux = i+1;
                guardaAux = 0;
            }
            j += 1;
            if (str[j] == '\0')
            {
                contador += 1;
                j = 0;
                i = aux;
                guardaAux = 1;
            }
        }
        else
        {
            j = 0;
            guardaAux = 1;
        }
    }
    *qtd = contador;
}

int main(){
    char* str;
    char* texto;
    int* qtd;
    int n=0;
    qtd = &n;
    char* palavra = "ABCA";
    char* strTexto = "abcdeABCaBcAbcAbCABcabCaBCde";

    str = palavra;
    texto = strTexto;
    
    frequencia_string(str, texto, qtd);

    printf("quantidade %d", *qtd);

    return 0;
}