#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct rede{
    char codigo[20];
    int rg;
    char regiao[20];
    int tp;
    char tipo[20];
    int moradores;
    int it;
    char inter[20];
    int rd;
    char red[4];
    float conAno;
    float conMes;
    float conMor;
};


rede menorC;

void preencher(int n, int *cod,  rede *gs){
    *cod=230010;
    for(int i=0;i<n;i++){
        gs[i].rg=(rand()%3)+1;
        gs[i].tp=(rand()%2);
        gs[i].moradores=(rand()%6)+1;
        gs[i].it=(rand()%3);
        gs[i].rd=rand()%2;
        printf("%d", gs[i].rd);
        gs[i].conAno=(rand()%18)+6;

        gs[i].conMes=gs[i].conAno/12;
        gs[i].conMor=gs[i].conMes/gs[i].moradores;

        if(gs[i].rg==1){
            sprintf(gs[i].regiao, "Aroeira  ");
            if(gs[i].tp==0){
                sprintf(gs[i].codigo, "%dAC", i+(*cod));
            }
            if(gs[i].tp==1){
                sprintf(gs[i].codigo, "%dAA", i+(*cod));
            }
            
        }
        if(gs[i].rg==2){
            sprintf(gs[i].regiao, "Visconde ");
            if(gs[i].tp==0){
                sprintf(gs[i].codigo, "%dVC", i+(*cod));
            }
            if(gs[i].tp==1){
                sprintf(gs[i].codigo, "%dVA", i+(*cod));
            }

        }
        if(gs[i].rg==3){
            sprintf(gs[i].regiao, "Miramar  ");
            if(gs[i].tp==0){
                sprintf(gs[i].codigo, "%dMC", i+(*cod));
            }
            if(gs[i].tp==1){
                sprintf(gs[i].codigo, "%dMA", i+(*cod));
            }            
        }

        if(gs[i].tp==0){
            sprintf(gs[i].tipo, "Casa       ");
        }
        if(gs[i].tp==1){
            sprintf(gs[i].tipo, "Apartamento");
        }
        if(gs[i].it==0){
            sprintf(gs[i].inter, "Indiferente   ");
        }
        if(gs[i].it==1){
            sprintf(gs[i].inter, "Positivo      ");
        }
        if(gs[i].it==2){
            sprintf(gs[i].inter, "Negativo      ");
        }

        if(gs[i].rd==0){
            sprintf(gs[i].red, "Sim");
        }
        if(gs[i].rd==1){
            sprintf(gs[i].red, "Nao");  
        }

    }
}
q_3(int n, float *mediaConsPos, rede *gs){
	float totInterPos=0, totConsInterPos=0;
    for(int i=0; i<n;i++){
        
        if(gs[i].it==1){
            totInterPos++;
            totConsInterPos+=gs[i].conMes;
        }
    }
    *mediaConsPos=totConsInterPos/totInterPos;
}
void q_4(int n,rede *gs){	
	int menorCS=10000;
	for(int i=0; i<n; i++){
		if(gs[i].conMes<menorCS){
			menorCS=gs[i].conMes;
			menorC=gs[i]; 
		}
	}	
}

void q_5(int n, float *percIndf, rede *gs){	
	float totIndf=0;
	for(int i=0; i<n; i++){
		if(gs[i].it==0){
			totIndf++;
		}
	}	
    *percIndf=(totIndf/105)*100;
}
void q_6(int n, float *percNR, float *percPR, rede *gs){	
	float totredT=0, totredF=0, totNegat=0, totPos=0;
	for(int i=0; i<n; i++){
        
		if(gs[i].rd==0){
            totredT++;
            
            if(gs[i].it==2){
                totNegat++;
            } 
		}
        if(gs[i].rd==1){
            totredF++;
            if(gs[i].it==1){
                totPos++;
            } 
		}
	}	

    *percNR=(totNegat/totredT)*100;
    *percPR=(totPos/totredF)*100;
    
}

void apresentar(int n, int *cod, float *mediaConsPos, float *percIndf, float *percNR, float *percPR, rede *gs){
    for(int i=0;i<n;i++){
        printf("%s\t%s\t%s\t%d\t%s\t%s\t%.1f\t%.1f\n", gs[i].codigo, gs[i].regiao, gs[i].tipo, gs[i].moradores, gs[i].inter, gs[i].red, gs[i].conMes, gs[i].conMor);
    }
    printf("O consumo medio dos pesquisados com interesse positivo: %.1f\n", *mediaConsPos);
    printf("Percentual de pesquisados indiferentes a implantacao: %.1f%%\n", *percIndf);
    printf("O percentual de pesquisados negativos que tem rede instalada: %.1f%%\n", *percNR);
    printf("O percentual de pesquisados positivos que nao tem rede instalada: %.1f%%\n", *percPR);
}

void apresentarMenor(int n, rede *gs){
    for(int i=0;i<n;i++){
        
    }
    printf("O pesquisado de menor consumo com todos os seus dados: \n");
    printf("%s\t%s\t%s\t%d\t%s\t%s\t%.1f\t%.1f\n", menorC.codigo, menorC.regiao, menorC.tipo, menorC.moradores, menorC.inter, menorC.red, menorC.conMes, menorC.conMor);
}

void grava(int n, int *cod, float *mediaConsPos, float *percIndf, float *percNR, float *percPR, rede *gs){
    FILE *save_arq;
    save_arq = fopen("DadosRedeGas.txt","w");
    if(save_arq == NULL){
        printf("Erro na abertura do arquivo!");
    }
    int i;
   
    fprintf(save_arq,"Dados salvos Redes de Gás !\n");
    for(i=0;i<n;i++){
        fprintf(save_arq, "%s\t%s\t%s\t%d\t%s\t%s\t%.1f\t%.1f\n", gs[i].codigo, gs[i].regiao, gs[i].tipo, gs[i].moradores, gs[i].inter, gs[i].red, gs[i].conMes, gs[i].conMor);
    }
    fprintf(save_arq,"O consumo medio dos pesquisados com interesse positivo: %.1f\n", mediaConsPos);
    fprintf(save_arq,"Percentual de pesquisados indiferentes a implantacao: %.1f%%\n", percIndf);
    fprintf(save_arq,"O percentual de pesquisados negativos que tem rede instalada: %.1f%%\n", percNR);
    fprintf(save_arq,"O percentual de pesquisados positivos que nao tem rede instalada: %.1f%%\n", percPR);
    fprintf(save_arq,"=================================================================================================================================\n");
    fprintf(save_arq,"O pesquisado de menor consumo com todos os seus dados: \n");
    fprintf(save_arq,"%s\t%s\t%s\t%d\t%s\t%s\t%.1f\t%.1f\n", menorC.codigo, menorC.regiao, menorC.tipo, menorC.moradores, menorC.inter, menorC.red, menorC.conMes, menorC.conMor);

    
    fclose(save_arq);
    printf("Dados salvos no arquivo |DadosRedeGas.txt|");
}

int main(){
    rede gs[105]={0};
    int cod;
    float mediaConsPos, percIndf, percNR, percPR;
    srand(time(NULL));
    preencher(105, &cod, gs);
    q_3(105, &mediaConsPos, gs);
    q_4(105, gs);
    q_5(105, &percIndf, gs);
    q_6(105, &percNR, &percPR, gs);
    apresentar(105, &cod, &mediaConsPos, &percIndf, &percNR, &percPR, gs);
    apresentarMenor(105, gs);
    grava(105, &cod, &mediaConsPos, &percIndf, &percNR, &percPR, gs);

    return 0;
}