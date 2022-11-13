#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct plataforma{
    char tipo[17];
    char campo[9];
    int camp;
    int horasC;
    int hc;
    int hp;
    int prod;
    char codigo[12];
    float coeficiente;

};
int aux_ano[12]={0}, aux_tipo[12]={0}, aux_hp[12]={0};
float mediaPss=0,tot_f=0,tot_ns=0,tot_ss=0,med_f,med_ns,med_ss, percpm;
int maior=0;

void preenche(int n, plataforma *vtplat){

    for(int i=0; i<n; i++){
        aux_tipo[i]=(rand()%3)+1;
        aux_ano[i]=(rand()%20)+2000;
        vtplat[i].camp=(rand()%3)+1;
        vtplat[i].hc=rand()%2;
        vtplat[i].hp=rand()%3601;
        vtplat[i].prod=(rand()%1501)+1000;
        aux_hp[i]=vtplat[i].hp;

        if(aux_tipo[i]==1){
            sprintf(vtplat[i].tipo, "       Fixa     ");
            sprintf(vtplat[i].codigo, "%dFX%d",i+101, aux_ano[i]-2000);
            tot_f++;
        }
        if(aux_tipo[i]==2){
            sprintf(vtplat[i].tipo, "   Navio Sonda  ");
            sprintf(vtplat[i].codigo, "%dNS%d",i+101, aux_ano[i]-2000);
            tot_ns++;
        }
        if(aux_tipo[i]==3){
            sprintf(vtplat[i].tipo, "Semi Submersivel");
            sprintf(vtplat[i].codigo, "%dSS%d",i+101, aux_ano[i]-2000);
            tot_ss++;
        }

        if(vtplat[i].camp==1)sprintf(vtplat[i].campo, " Marlim ");
        if(vtplat[i].camp==2)sprintf(vtplat[i].campo, "Albacora");
        if(vtplat[i].camp==3)sprintf(vtplat[i].campo, "Roncador");

        if(vtplat[i].hc==0){
            vtplat[i].horasC=8760;
        }
        else{
            vtplat[i].horasC=17520;
        }
        vtplat[i].coeficiente=(vtplat[i].prod/(vtplat[i].horasC-aux_hp[i]))*1000;
    }
    med_f = tot_f/12;
    med_ns = tot_ns/12;
    med_ss = tot_ss/12;
}
void mpS(int n, plataforma *vtplat){
    int tplatss=0, thoraP=0;
    for(int i=0; i<n;i++){
        if(aux_tipo[i]==3){
            tplatss++;
            thoraP=thoraP+vtplat[i].hp;
        }
    }
    mediaPss=thoraP/tplatss;
}
void percRM(int n, plataforma *vtplat){
	int totplatM;
    for(int i=0; i<n; i++){
        if(vtplat[i].camp=!2){
            if(aux_hp[i]<800){
                totplatM++;
            }
        }
    }
    percpm=(totplatM/12)*100;
    printf("O percentual de Plataformas dos Campos de Roncador e Marlim com HP menor que 800: %.1f\n", percpm);

}

void maiorCoeficiente(int n, plataforma *vtplat){

    for (int i=0; i<n;i++)
	{
        if (vtplat[i].coeficiente>maior)
		{
            maior = i;
        }
    }
    printf("C?digo do maior Coeficiente:\n%s\t%s\t%d\t%s\t%d\t%d\t%d\t%.1f\n",vtplat[maior].codigo,vtplat[maior].tipo,aux_ano[maior],vtplat[maior].campo,vtplat[maior].horasC,vtplat[maior].hp,vtplat[maior].prod,vtplat[maior].coeficiente);		
}

void apresenta(int n, plataforma *vtplat){
	int i;
	for(i=0;i<n;i++){
		printf("%s\t%s\t%d\t%s\t%d\t%d\t%d\t%.1f\n",vtplat[i].codigo, vtplat[i].tipo, aux_ano[i], vtplat[i].campo, vtplat[i].horasC, vtplat[i].hp, vtplat[i].prod, vtplat[i].coeficiente);
	}
    printf("A media de Horas paradas das Plataformas do tipo Semi Submersivel foi de: %.1f\n", mediaPss);
    
    //printf("%d", vtplat[i].coeficiente);
}

int main(){
    srand(time(NULL));
    plataforma programa[12]={0};
    preenche(12, programa);
    mpS(12, programa);
    maiorCoeficiente(12, programa);
    apresenta(12, programa);
	maiorCoeficiente(12, programa);

    return 0;
}

