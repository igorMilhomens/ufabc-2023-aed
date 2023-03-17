// #include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct DiscoVoador DiscoVoador;
struct DiscoVoador {
    char *modelo;
    char *planeta;
    int autonomia;
};
// 1: ordenação pelo modelo (ordem lexicográfica crescente);
// 2: ordenação pelo modelo (ordem lexicográfica decrescente);
// 3: ordenação pelo planeta (ordem lexicográfica crescente) e, em caso de empate, pela autonomia (ordem decrescente);
// 4: ordenação pelo autonomia (ordem crescente) e, em caso de empate, pelo planeta (ordem lexicográfica crescente) e, em caso de empate em autonomia e planeta, ordenação pelo modelo (ordem lexicográfica crescente).


//ordena autonomia
int ordena_autonomia(DiscoVoador *discos, int n_discos){
    char* palavraPlaneta1;
    char* palavraPlaneta2;
    int valorAutonomia1;
    int valorAutonomia2;
    int controle;
    int autonomia= 0;
    for(int i = 0; i<n_discos-1; i++){
        palavraPlaneta1 = discos[i].planeta;
        palavraPlaneta2 = discos[i+1].planeta;
        valorAutonomia1 = discos[i].autonomia;
        valorAutonomia2 = discos[i+1].autonomia;

        if(valorAutonomia1<valorAutonomia2){
            autonomia++;
        }
        else if(valorAutonomia1==valorAutonomia2){
            controle = 0;
            while(palavraPlaneta1[controle]!='\0' && palavraPlaneta2[controle]!='\0'){

                if(palavraPlaneta1[controle] == palavraPlaneta2[controle]){
                    controle++;
                    if(palavraPlaneta1[controle] == '\0' && palavraPlaneta2[controle]!='\0'){
                        autonomia++;
                    }
                    // else if(palavraPlaneta1[controle] != '\0' && palavraPlaneta2[controle]=='\0'){
                    //     break;
                    // }
                    else if(palavraPlaneta1[controle] == '\0' && palavraPlaneta2[controle]=='\0'){
                        autonomia++;
                    }
                }
                else if (palavraPlaneta1[controle] < palavraPlaneta2[controle]){
                    autonomia++;
                    controle++;
                    break;
                }
                else{
                    controle++;
                }
            }   
        }
    }
        
    if(autonomia == n_discos-1){
        return 4;
    }
    else{
        return 0;
    }
}
//ordena autonomia


//ordena planeta
int ordena_planeta(DiscoVoador *discos, int n_discos){
    char* palavraPlaneta1;
    char* palavraPlaneta2;
    int valorAutonomia1;
    int valorAutonomia2;
    int controle;
    int planeta= 0;

    for(int i = 0; i<n_discos-1; i++){
        palavraPlaneta1 = discos[i].planeta;
        palavraPlaneta2 = discos[i+1].planeta;
        valorAutonomia1 = discos[i].autonomia;
        valorAutonomia2 = discos[i+1].autonomia;

        controle = 0;

        while(palavraPlaneta1[controle]!='\0' && palavraPlaneta2[controle]!='\0'){

            if(palavraPlaneta1[controle] == palavraPlaneta2[controle]){
                controle++;
                if(palavraPlaneta1[controle] == '\0' && palavraPlaneta2[controle]!='\0'){
                    planeta++;
                }
                else if(palavraPlaneta1[controle]=='\0' && palavraPlaneta2[controle]=='\0'){
                    if(valorAutonomia1>=valorAutonomia2){
                        planeta++;
                    }
                }
                // else if(palavraPlaneta1[controle] != '\0' && palavraPlaneta2[controle]=='\0'){
                //     break;
                // }
            }
            else if (palavraPlaneta1[controle] < palavraPlaneta2[controle]){
                planeta++;
                controle++;
                break;
            }
            else{
                controle++;
            }
        }   
    }
    if(planeta == n_discos-1){
        return 3;
    }
    else{
        return 0;
    }
}
//ordena planeta

//modelo
int ordena_modelo(DiscoVoador *discos, int n_discos){
    char* palavraModelo1;
    char* palavraModelo2;
    int modelo1= 0;
    int modelo2= 0;
    int controle;

    for(int i = 0; i<n_discos-1; i++){
        palavraModelo1 = discos[i].modelo;
        palavraModelo2 = discos[i+1].modelo;

        controle = 0;

        while(palavraModelo1[controle]!='\0' && palavraModelo2[controle]!='\0'){

            if(palavraModelo1[controle] == palavraModelo2[controle]){
                controle++;
                if(palavraModelo1[controle] == '\0' && palavraModelo2[controle]!='\0'){
                    modelo1++;
                }
                else if(palavraModelo1[controle]!='\0' && palavraModelo2[controle]=='\0'){
                    modelo2++;
                }
            }
            else if (palavraModelo1[controle] < palavraModelo2[controle]){
                modelo1++;
                controle++;
                break;
            }
            else{
                modelo2++;
                controle++;
                break;
            }
        }   
    }
    if(modelo1 == n_discos-1){
        return 1;
    }else if(modelo2 == n_discos-1){
        return 2;
    }
    else{
        return 0;
    }
}
//modelo

int verificar_ordenacao(DiscoVoador *discos, int n_discos) {
    // Código da função aqui
    int resultado =0;

    resultado = ordena_modelo(discos,n_discos);
    if(resultado == 0){
        resultado = ordena_planeta(discos,n_discos);
        if(resultado == 0){
            resultado = ordena_autonomia(discos,n_discos);
        }
    }
    return resultado;
}

int main(){
    DiscoVoador *discos= malloc(8*sizeof(DiscoVoador));
    DiscoVoador disco1,disco2,disco3,disco4,disco5,disco6,disco7,disco8;

    disco1.modelo="DiscoF";
    disco1.planeta="Terra";
    disco1.autonomia=20;

    disco2.modelo="DiscoD"  ;
    disco2.planeta="Terra";
    disco2.autonomia=25;

    disco3.modelo="DiscoE"  ;
    disco3.planeta="Marte";
    disco3.autonomia=40;

    disco4.modelo="DiscoC"  ;
    disco4.planeta="Marte";
    disco4.autonomia=40;

    disco5.modelo="DiscoH";  
    disco5.planeta="Marte";
    disco5.autonomia=90;

    disco6.modelo="DiscoG"  ;
    disco6.planeta="Saturno";
    disco6.autonomia=90;

    disco7.modelo="DiscoA"  ;
    disco7.planeta="Saturno";
    disco7.autonomia=150;

    disco8.modelo="DiscoB";
    disco8.planeta="Terra";
    disco8.autonomia=500;

    discos[0] = disco1;
    discos[1] = disco2;
    discos[2] = disco3;
    discos[3] = disco4;
    discos[4] = disco5;
    discos[5] = disco6;
    discos[6] = disco7;
    discos[7] = disco8;
    
    printf("resultado: %d\n", verificar_ordenacao(discos, 8));
    free(discos);
    return 0;
}