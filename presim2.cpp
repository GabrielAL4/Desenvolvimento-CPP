#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct plataformas{
        char nome[10];
        int cod;
        char tipo[12];
        int tp;
        int ano;
        char campo[10];
        int cp;
        int hc;
        int hp;
        float prod;
};
plataformas np[28]={0};

void preencher(int n, plataformas *np){
    for(int i=0; i<n; i++){
        np[i].cod=(rand()%50)+100;
        np[i].ano=(rand()%25)+1990;
        np[i].tp=(rand()%3)+1;
        np[i].cp=(rand()%3)+1;
        np[i].hc=(rand()%8860)+8760;
        np[i].hp=(rand()%1800)+1800;
        np[i].prod=(rand()%15000)+10000;

        if(np[i].tp==1){
            scanf(np[i].nome, "P%dPR", np[i].cod+i);
            scanf(np[i].tipo, "Prospecção  ");
        }
        if(np[i].tp==2){
            scanf(np[i].nome, "P%dPE", np[i].cod+i);
            scanf(np[i].tipo, "Perfuração  ");
        }
        if(np[i].tp==3){
            scanf(np[i].nome, "P%dEX", np[i].cod+i); 
            scanf(np[i].tipo, "Exploração  ");
        }

        if(np[i].cp==1){
            scanf(np[i].campo, "Marlim  ");
        }
        if(np[i].cp==2){
            scanf(np[i].campo, "Albacorra  ");
        }
        if(np[i].cp==3){
            scanf(np[i].campo, "Anchova  ");
        }
    }
}

void apresentar(int n, plataformas *np){
    for(int i=0; i<n; i++){
        printf("%s\t\n", np[i].nome);
    }

}



int main(){

    preencher(28, np);
    apresentar(28, np);




    return 0;
}

