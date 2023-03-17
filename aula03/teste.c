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



int verificar_ordenacao(DiscoVoador *discos, int n_discos) {
    // Código da função aqui
    int resultado;
    int modelo1= 0;
    int modelo2= 0;
    int planeta= 0;
    int autonomia= 0;
    int controle;
    int controle1;
    int controle2;

    for(int i = 0; i<n_discos-1; i++){
        controle = 0;
        controle1 = 0;

        while(discos[i].modelo[controle]!='\0' && discos[i+1].modelo[controle]!='\0'){

            if(discos[i].modelo[controle] == discos[i+1].modelo[controle]){
                controle++;
                if(discos[i].modelo[controle] == '\0' && discos[i+1].modelo[controle]!='\0'){
                    modelo1++;
                }
                else if(discos[i].modelo[controle]!='\0' && discos[i+1].modelo[controle]=='\0'){
                    modelo2++;
                }
            }
            else if (discos[i].modelo[controle] < discos[i+1].modelo[controle]){
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

        while(discos[i].planeta[controle1]!='\0' && discos[i+1].planeta[controle1]!='\0'){

            if(discos[i].planeta[controle1] == discos[i+1].planeta[controle1]){
                controle1++;
                if(discos[i].planeta[controle1] == '\0' && discos[i+1].planeta[controle1]!='\0'){
                    planeta++;
                }
                else if(discos[i].planeta[controle1]=='\0' && discos[i+1].planeta[controle1]=='\0'){
                    if(discos[i].autonomia>=discos[i+1].autonomia){
                        planeta++;
                    }
                }
                else if(discos[i].planeta[controle1] != '\0' && discos[i+1].planeta[controle1]=='\0'){
                    break;
                }
            }
            else if (discos[i].planeta[controle1] < discos[i+1].planeta[controle1]){
                planeta++;
                controle1++;
                break;
            }
        }  
        
        if(discos[i].autonomia<discos[i+1].autonomia){
            autonomia++;
        }
        else if(discos[i].autonomia==discos[i+1].autonomia){
            controle2 = 0;
            while(discos[i].planeta[controle2]!='\0' && discos[i+1].planeta[controle2]!='\0'){

                if(discos[i].planeta[controle2] == discos[i+1].planeta[controle2]){
                    controle2++;
                    if(discos[i].planeta[controle2] == '\0' && discos[i+1].planeta[controle]!='\0'){
                        autonomia++;
                    }
                    else if(discos[i].planeta[controle2] != '\0' && discos[i+1].planeta[controle2]=='\0'){
                        break;
                    }
                }
                else if (discos[i].planeta[controle2] < discos[i+1].planeta[controle2]){
                    autonomia++;
                    break;
                }
            }   
        }
        free(discos[i]); 
    }
    free(discos);
    if(modelo1 == n_discos-1){
        return 1;
    }else if(modelo2 == n_discos-1){
        return 2;
    }
    else if(planeta == n_discos-1){
        return 3;
    }
    else if(autonomia == n_discos-1){
        return 4;
    }
    else{
        return 0;
    }
}

int main(){
    DiscoVoador *discos= malloc(8*sizeof(DiscoVoador));
    DiscoVoador disco1,disco2,disco3,disco4,disco5,disco6,disco7,disco8;

    disco1.modelo="DiscoF";
    disco1.planeta="Jupiter";
    disco1.autonomia=30;

    disco2.modelo="DiscoD"  ;
    disco2.planeta="Marte";
    disco2.autonomia=31;

    disco3.modelo="DiscoE"  ;
    disco3.planeta="Marte";
    disco3.autonomia=40;

    disco4.modelo="DiscoC"  ;
    disco4.planeta="Marte";
    disco4.autonomia=50;

    disco5.modelo="DiscoH";  
    disco5.planeta="Saturno";
    disco5.autonomia=50;

    disco6.modelo="DiscoG"  ;
    disco6.planeta="Saturno";
    disco6.autonomia=200;

    disco7.modelo="DiscoA"  ;
    disco7.planeta="Terra";
    disco7.autonomia=500;

    disco8.modelo="DiscoB";
    disco8.planeta="Terra";
    disco8.autonomia=700;

    discos[0] = disco1;
    discos[1] = disco2;
    discos[2] = disco3;
    discos[3] = disco4;
    discos[4] = disco5;
    discos[5] = disco6;
    discos[6] = disco7;
    discos[7] = disco8;
    
    printf("resultado: %d\n", verificar_ordenacao(discos, 8));
    return 0;
}