#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
struct plataforma{
	char codigo[10];
	int tp;
	char tipo[20];
	int ano,cp;
	char campo[10];
	int hc,qtd_Horas,qtd_Horas_Paradas;
	float  prod,coeficiente;
};
float resp_Q2, mediaProdMarlim, mediaProdAlbacora, mediaProdRoncador, mediaProdFixa, mediaProdNavio, mediaProdSs;
int totMarlim, totAlbacora, totRoncador, totPMarlim, totPAlbacora, totPRoncador, totPFixa, totPNavioS,totPSS, totFixa, totNavio, totSs;
plataforma resp_q3;
plataforma auxiliar;

void preenche(int n, plataforma *plataformas){
	
	int i;
	for(i=0;i<n;i++){
		plataformas[i].tp=(rand()%3)+1;
		plataformas[i].ano=(rand()%20)+2000;
		plataformas[i].cp=(rand()%3)+1;
		plataformas[i].hc=rand()%2;
		plataformas[i].qtd_Horas_Paradas=rand()%3601;
		plataformas[i].prod=(rand()%1501)+1000;
		
		if(plataformas[i].tp==1){
			sprintf(plataformas[i].tipo,"      Fixa      ");
			sprintf(plataformas[i].codigo,"%dFX%.2d",i+101,plataformas[i].ano-2000);
			totFixa++; 
			totPFixa+=plataformas[i].prod;

		}
		if(plataformas[i].tp==2){
			sprintf(plataformas[i].tipo,"  Navio Sonda   ");
			sprintf(plataformas[i].codigo,"%dNS%.2d",i+101,plataformas[i].ano-2000);
			totNavio++;
			totPNavioS+=plataformas[i].prod;
		}
		if(plataformas[i].tp==3){      
			sprintf(plataformas[i].tipo,"Semi Submersivel");
			sprintf(plataformas[i].codigo,"%dSS%.2d",i+101,plataformas[i].ano-2000);
			totSs++;
			totPSS+=plataformas[i].prod;
		}
		
		if(plataformas[i].cp==1){
			sprintf(plataformas[i].campo,"Marlim  ");
			totMarlim++;
			totPMarlim+=plataformas[i].prod;
		}
		if(plataformas[i].cp==2){
			sprintf(plataformas[i].campo,"Albacora");
			totAlbacora++;
			totPAlbacora+=plataformas[i].prod;
		}
		if(plataformas[i].cp==3){
			sprintf(plataformas[i].campo,"Roncador");
			totRoncador++;
			totPRoncador+=plataformas[i].prod;
		}
		if(plataformas[i].hc==0)plataformas[i].qtd_Horas=8760;
		if(plataformas[i].hc==1)plataformas[i].qtd_Horas=17520;
		plataformas[i].coeficiente=(plataformas[i].prod/(plataformas[i].qtd_Horas-plataformas[i].qtd_Horas_Paradas))*1000;
	}	
}
void questao_2(int n,plataforma *plataformas){
	int i;
	float tot_HP_SS=0,tot_SS=0 ;
	
	for(i=0;i<n;i++){
		if(plataformas[i].tp==2 || plataformas[i].tp==3){
			tot_HP_SS+=plataformas[i].qtd_Horas_Paradas;
			tot_SS++;
		}
	}
	resp_Q2=tot_HP_SS/tot_SS;
}
void questao_3(int n,plataforma *plataformas){
	int i;
	
	float maior_coef=0;
	for(i=0;i<n;i++){
		if(plataformas[i].coeficiente>maior_coef){
			maior_coef=plataformas[i].coeficiente;
			resp_q3=plataformas[i];
		}
	}	
}
float questao_4(int n,plataforma *plataformas){
	int i;
	float perc_Ronc, tot_Ronc=0,tot_Ronc_M8;
	float per_marlim, tot_marlim=0, tot_marlim_m8;
	for( i=0;i<n;i++){
		if(plataformas[i].cp==3){
			tot_Ronc++;
			if(plataformas[i].qtd_Horas_Paradas<800){
				tot_Ronc_M8++;
			}
		}
		if(plataformas[i].cp==1){
			tot_marlim++;
			if(plataformas[i].qtd_Horas_Paradas<800){
				tot_marlim_m8++;
			}
		}
	}
	perc_Ronc=(	tot_Ronc_M8/tot_Ronc)*100;
	per_marlim=(tot_marlim_m8/tot_marlim)*100;
	return(perc_Ronc);
	return(per_marlim);
}

void mediaDeProd(int n, plataforma *plataformas){
	mediaProdMarlim=totPMarlim/totMarlim;
	mediaProdAlbacora=totPAlbacora/totAlbacora;
	mediaProdRoncador=totPRoncador/totRoncador;

}
void ordenar(int n, plataforma *plataformas){
	for(int i=0; i<n;i++){
		for(int j=0; j<i; j++){
			if(plataformas[i].coeficiente<plataformas[j].coeficiente){
				auxiliar=plataformas[i];
				plataformas[i]=plataformas[j];
				plataformas[j]=auxiliar;
			}
		}
	}
	for(int i=0; i<n;i++){
		printf("%s\t%s\t%d\t%s\t%d\t%d\t%.0f\t%.1f\n",plataformas[i].codigo,plataformas[i].tipo,plataformas[i].ano,plataformas[i].campo,plataformas[i].qtd_Horas,plataformas[i].qtd_Horas_Paradas,plataformas[i].prod,plataformas[i].coeficiente);
	}
}
void mediaProdTipo(int n, plataforma *plataformas){
	mediaProdFixa=totPFixa/totFixa;
	mediaProdNavio=totPNavioS/totNavio;
	mediaProdSs=totPSS/totSs;

}
void apresenta(int n,plataforma *plataformas, float r4){
	int i;
	for(i=0;i<n;i++){
		printf("%s\t%s\t%d\t%s\t%d\t%d\t%.0f\t%.1f\n",plataformas[i].codigo,plataformas[i].tipo,plataformas[i].ano,plataformas[i].campo,plataformas[i].qtd_Horas,plataformas[i].qtd_Horas_Paradas,plataformas[i].prod,plataformas[i].coeficiente);
	}
	printf("=====================================================================================\n");
	printf("A media de Horas paradas das Plataformas do tipo Semi Submersivel:%.1f\n",resp_Q2);
	printf("=====================================================================================\n");
	printf("Plataforma de Maior coeficiente:\n");
	printf("%s\t%s\t%d\t%s\t%d\t%d\t%.0f\t%.1f\n",resp_q3.codigo,resp_q3.tipo,resp_q3.ano,resp_q3.campo,resp_q3.qtd_Horas,resp_q3.qtd_Horas_Paradas,resp_q3.prod,resp_q3.coeficiente);
	printf("=====================================================================================\n");
	printf("Resposta questao 4 %.1f\n",r4);
	//printf("Resposta questao 4 %.1f\n",r4m);
	printf("A media de producao dos campos Marlim foi de: %.1f\n\n", mediaProdMarlim);
	printf("A media de producao dos campos Albacora foi de: %.1f\n", mediaProdAlbacora);
	printf("A media de producao dos campos Roncador foi de: %.1f\n", mediaProdRoncador);
	printf("=====================================================================================\n");
	printf("                          A media de producao de cada tipo\n");
	printf("A media de producao de plataformas Fixa: %.1f\n", mediaProdFixa);
	printf("A media de producao dos Navios Sondas: %.1f\n", mediaProdNavio);
	printf("A media de producao das plataformas Semi Submersivais: %.1f\n", mediaProdSs);

}

int main(){
	srand(time(NULL));
	float resp_q4, resp_q4m;
	plataforma plataformas[12];
	preenche(12, plataformas);
	questao_2(12, plataformas);
	questao_3(12, plataformas);
	resp_q4=questao_4(12, plataformas);
	resp_q4m=questao_4(12, plataformas);
	mediaDeProd(12, plataformas);
	mediaProdTipo(12, plataformas);
	apresenta(12, plataformas,resp_q4);
	ordenar(12, plataformas);
	
	return 0;
}