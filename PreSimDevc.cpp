#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct ordem{
    char codigo[10];
    int cod;
    char tipoServ[13];
    int tp;
    char data[10];
    int mes;
    int dia;
    int qtdHoras;
    float valorServ;
};
ordem maiorC;
ordem od[42]={0};

float percM40=0, mediaT, mediaHM, mediaHR;
int totMenor40=0, totHoras, totHorasM, totHorasR, totEM, totER;
void preencher(int n, ordem *od){
    for (int i=0; i<n;i++){
        od[i].cod=(rand()%1000)+1000;
        od[i].tp=rand()%2;
        od[i].qtdHoras=(rand()%80)+20;
        if(od[i].tp==0){
            sprintf(od[i].codigo,"OS%dM", od[i].cod+i);
            sprintf(od[i].tipoServ,"Manutencao  ");
            
        }
        if(od[i].tp==1){
            sprintf(od[i].codigo,"OS%dR", od[i].cod+i);
            sprintf(od[i].tipoServ,"  Reparo    ");
            
        }        
    }
}
void data(int n, ordem *od){

    for (int i=0; i<n;i++){
        od[i].mes=(rand()%3)+8;

        if(od[i].mes==8){
            od[i].dia=(rand()%31)+1;
            sprintf(od[i].data,"%d/%d", od[i].dia, od[i].mes);
        }
        if(od[i].mes==9){
            od[i].dia=(rand()%30)+1;
            sprintf(od[i].data,"%d/%d", od[i].dia, od[i].mes);
        }
        if(od[i].mes==10){
            od[i].dia=(rand()%31)+1;
            sprintf(od[i].data,"%d/%d", od[i].dia, od[i].mes);
        }
    }
}
void Valor_Serv(int n, ordem *od){
    
    for (int i=0; i<n;i++){
        if(od[i].tp==0){
            od[i].valorServ=(od[i].qtdHoras*100)+500;
        }
        if(od[i].tp==1){
            od[i].valorServ=(od[i].qtdHoras*150)+750;
        }
    }
}
void m40s(int n, ordem *od){
    for (int i=0; i<n;i++){
        if(od[i].qtdHoras<40){
            totMenor40++;
            percM40=(totMenor40*100)/42;
        }
        
    }

}
void mediasH(int n, ordem *od){
    for (int i=0; i<n;i++){
        totHoras+=od[i].qtdHoras;
        mediaT=totHoras/42;
        if(od[i].tp==0){
            totHorasM+=od[i].qtdHoras;
            totEM++;
            mediaHM=totHorasM/totEM;
        }
        if(od[i].tp==1){
            totHorasR+=od[i].qtdHoras;
            totER++;
            mediaHR=totHorasR/totER;
        }
    }
}
void maiorCust(int n,ordem *od){	
	float maior_custo=0;
	for(int i=0;i<n;i++){
		if(od[i].valorServ>maior_custo){
			maior_custo=od[i].valorServ;
			maiorC=od[i];
		}
	}	
}
void imprimir(int n, ordem *od){
    for (int i=0; i<n;i++){
        printf("%s\t\t%s\t%s\t\t%d\t%.1f\n", od[i].codigo, od[i].tipoServ, od[i].data, od[i].qtdHoras, od[i].valorServ);
    }
    printf("=====================================================================================\n");
}

void apresentarRes(int n, ordem *od){
    for(int i=0;i<n;i++){
    }
    printf("O percentual de empresas com quantidade de horas menor que 40 foi de: %.0f%%\n",percM40);
    printf("=====================================================================================\n");
    printf("A media de horas das OS de Manutencao foram de: %.1f\n", mediaHM);
    printf("A media de horas das OS de Reparo foram de: %.1f\n", mediaHR);
    printf("A media de horas das OS totais foram de: %.1f\n", mediaT);
    printf("=====================================================================================\n");
    printf("                           OS de maior valor \n");
    printf("%s\t\t%s\t%s\t\t%d\t%.1f\n", maiorC.codigo, maiorC.tipoServ, maiorC.data, maiorC.qtdHoras, maiorC.valorServ);
}
void grava(int n, ordem *od){
    FILE *od_arq; 
	od_arq = fopen("arquivo_os.txt", "w");
	if(od_arq == NULL){
		printf("Erro na abertura do arquivo!");
	}
	int i;
	fprintf(od_arq, "=====================================================================================\n");
	for(i=0;i<n;i++){
		fprintf(od_arq,"%s\t\t%s\t%s\t\t%d\t%.1f\n", od[i].codigo, od[i].tipoServ, od[i].data, od[i].qtdHoras, od[i].valorServ);
	}
	fprintf(od_arq,"=====================================================================================\n");
    fprintf(od_arq,"O percentual de empresas com quantidade de horas menor que 40 foi de: %.0f%%\n",percM40);
    fprintf(od_arq,"=====================================================================================\n");    
    fprintf(od_arq,"A media de horas das OS de Manutencao foram de: %.1f\n", mediaHM);
    fprintf(od_arq,"A media de horas das OS de Reparo foram de: %.1f\n", mediaHR);
    fprintf(od_arq,"A media de horas das OS totais foram de: %.1f\n", mediaT);
    fprintf(od_arq,"=====================================================================================\n");
    fprintf(od_arq,"                           OS de maior valor \n");
    fprintf(od_arq,"%s\t\t%s\t%s\t\t%d\t%.1f\n", maiorC.codigo, maiorC.tipoServ, maiorC.data, maiorC.qtdHoras, maiorC.valorServ);
    fprintf(od_arq,"=====================================================================================\n");
	fprintf(od_arq,"Dados gravados com sucesso!");
	fclose(od_arq);
}

int main(){
    srand(time(NULL));
    preencher(42, od);
    data(42, od);
    Valor_Serv(42, od);
    m40s(42, od);
    mediasH(42, od);
    maiorCust(42, od);
    imprimir(42, od);
    apresentarRes(42, od);
    grava(42, od);

    return 0;
}
