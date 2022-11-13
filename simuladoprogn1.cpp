#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct empreendedor{
    char ramo[10];
	int ra;
	char porte[5];
	int orig;
	char origem[10];
	int nFunc;
	char ativo[3];
	int at;
	int anoCria;
	char codigo[8];
	int anoEnc;
};

void principal(int n, empreendedor *vemp){
    int i;
    for (i=0; i<n;i++){
        vemp[i].ra= (rand()%3)+1;
        vemp[i].orig= rand()%2;
        vemp[i].nFunc= (rand()%99)+1;
        vemp[i].anoCria= (rand()%20)+2000;
        vemp[i].at= rand()%2;
        if(vemp[i].ra==1){
            sprintf(vemp[i].codigo,"%dIND", i+265);
            sprintf(vemp[i].ramo, "INDUSTRIAL");
        }
        if(vemp[i].ra==2){
            sprintf(vemp[i].codigo,"%dCOM", i+265);
            sprintf(vemp[i].ramo, "COMERCIAL ");
        }
        if(vemp[i].ra==3){
            sprintf(vemp[i].codigo,"%dSER", i+265);
            sprintf(vemp[i].ramo, "SERVICOS  ");
        }

        if(vemp[i].orig==0){
            sprintf(vemp[i].origem,"Macae ");
        }
        if(vemp[i].orig==1){
            sprintf(vemp[i].origem,"Regiao");
        }

        if(vemp[i].at==0){
            sprintf(vemp[i].ativo,"NAO");
        }
        if(vemp[i].at==1){
            sprintf(vemp[i].ativo,"SIM");
        }
        vemp[i].anoEnc=0;
    }
}

void porte(int n, empreendedor *vemp){
    int i;
    for (i=0;i<n;i++){
        if(vemp[i].ra==1){
            if(vemp[i].nFunc<20){
                sprintf(vemp[i].porte,"ME  ");
            }
            else{
                sprintf(vemp[i].porte,"EPP ");
            }
        }
        else{
            if(vemp[i].nFunc<10){
                sprintf(vemp[i].porte,"ME  ");
            }
            if((vemp[i].nFunc>=10) && (vemp[i].nFunc<50)){
                sprintf(vemp[i].porte,"EPP ");
            }
            if(vemp[i].nFunc>49){
                sprintf(vemp[i].porte,"EMP ");
            }
        }
    }
}

void empEncerradas(int n,empreendedor *vemp){
    int i, auxp, auxs;
    for(i=0;i<n;i++){
        if(vemp[i].at==0){
            auxp=2020-vemp[i].anoCria+1;
            auxs=rand()%auxp;
            vemp[i].anoEnc=vemp[i].anoCria+auxs;
        }
    }

}

void show(int n,empreendedor *vemp){
	int i;
	for(i=0;i<n;i++){
		printf("%s\t%s\t%d\t%s\t%s\t%d\t%s\t%d\n",vemp[i].codigo,vemp[i].ramo,vemp[i].nFunc,vemp[i].porte,vemp[i].origem,vemp[i].anoCria,vemp[i].ativo,vemp[i].anoEnc);
	}
}

int main(){

    empreendedor empresa[180];
	principal(180, empresa);
	porte(180, empresa);
	empEncerradas(180, empresa);
	show(180, empresa);




    return 0;
}