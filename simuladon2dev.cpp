#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct servico{
    char codigo[10];

    char setor[12];
    int set;
    int idade;
    char sexo[10];
    int sx;
    int nota;
    char retor[10];
    int ret;
    char tipo[10];
    int tp;
};
servico menorNota;
servico dig[123]={0};

int cod;
float percRad, mediaNP, PercNPlano;

void preencher(int n, servico *dig){
    cod=(rand()%99)+1001;
    for(int i=0;i<n;i++){
        dig[i].set=(rand()%3)+1;
        dig[i].idade=(rand()%52)+18;
        dig[i].sx=rand()%2;
        dig[i].tp=rand()%2;
        dig[i].nota=rand()%101;
        dig[i].ret=rand()%3;

        if(dig[i].set==1){
            sprintf(dig[i].setor,"Radiologia  ");
            if(dig[i].tp==0){
            sprintf(dig[i].codigo,"%dRPA", cod+i);
            }
            if(dig[i].tp==1){
            sprintf(dig[i].codigo,"%dRPL", cod+i);
            }
        }
        if(dig[i].set==2){
            sprintf(dig[i].setor,"Ultrassom  ");
            if(dig[i].tp==0){
            sprintf(dig[i].codigo,"%dUPA", cod+i);
            }
            if(dig[i].tp==1){
            sprintf(dig[i].codigo,"%dUPL", cod+i);
            }
        }
        if(dig[i].set==3){
            sprintf(dig[i].setor,"Tomografia  ");
            if(dig[i].tp==0){
            sprintf(dig[i].codigo,"%dTPA", cod+i);
            }
            if(dig[i].tp==1){
            sprintf(dig[i].codigo,"%dTPL", cod+i);
            }
        }

        if(dig[i].tp==0){
            sprintf(dig[i].tipo,"Particular   ");
        }
        if(dig[i].tp==1){
            sprintf(dig[i].tipo,"Plano        ");
        }

        if(dig[i].sx==0){
            sprintf(dig[i].sexo,"Masculino    ");
        }
        if(dig[i].sx==1){
            sprintf(dig[i].sexo,"Feminino     ");
        }

        if(dig[i].ret==0){
            sprintf(dig[i].retor,"Sim     ");
        }
        if(dig[i].ret==1){
            sprintf(dig[i].retor,"Nao     ");
        }
        if(dig[i].ret==2){
            sprintf(dig[i].retor,"Talvez  ");
        }
	}
}

void percR(int n, servico *dig){
    int totRad=0, totPrad=0;
    for(int i=0; i<n;i++){
        if(dig[i].set==1){
            totRad++;
            if(dig[i].nota>70){
                totPrad++;
            }
        }
    }
    percRad=(totPrad/totRad)*100;
}
void mediaPart(int n, servico *dig){   
    int totCpart, totNpart; 
    for(int i=0;i<n;i++){
        if (dig[i].tp==0){
            totCpart++;
            totNpart+=dig[i].nota;   
        }    
    }
    mediaNP=totNpart/totCpart;
}

void PlanoNR(int n, servico *dig){
    int totPlano, totNPlano;
    for (int i=0;i<n;i++){
        if(dig[i].tp==1){
            totPlano++;
            if(dig[i].ret==1){
                totNPlano++;
            }
        }
    }
    PercNPlano=(totNPlano/totPlano)*100;
}

void menorN(int n,servico *dig){	
	float menorNt=0;
	for(int i=0;i<n;i++){
		if(dig[i].nota<menorNt){
			menorNt=dig[i].nota;
			menorNota=dig[i];
		}
	}	
}

void apresenta(int n, servico *dig){
    for(int i=0; i<n;i++){
        printf("%s\t\t%s\t%s\t%d\t%s\t%d\t%s\n", dig[i].codigo, dig[i].setor, dig[i].tipo, dig[i].idade, dig[i].sexo, dig[i].nota, dig[i].retor);
    }
    printf("Percentual clientes do setor de Radiologia que deu notas maiores que 70: %.1f%%\n", percRad);
    printf("A media das notas dadas pelos clientes Particulares: %.1f\n", mediaNP);
    printf("Percentual de clientes do tipo Plano que indicaram que retornariam Nao: %.1f%%\n", PercNPlano);
    printf("A menor nota foi de: \n");
    printf("%s\t\t%s\t%s\t%d\t%s\t%d\t%s\n", menorNota.codigo, menorNota.setor, menorNota.tipo, menorNota.idade, menorNota.sexo, menorNota.nota, menorNota.retor);
}


int main(){
    srand(time(NULL));
    preencher(123, dig);
    percR(123, dig);
    mediaPart(123, dig);
    PlanoNR(123, dig);
    menorN(123,dig);
    apresenta(123, dig);


    return 0;
}
