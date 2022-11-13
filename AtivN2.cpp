#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct familia{
    char codigo[6];
    int cod;
    int membros;
    char tipo[10];
    int tp;
    int beneficio;
    float rendaF, rendaP;
    char sit[10];
};
float percMsol;
void preencher(int n, familia *fal){
    for(int i=0;i<n;i++){
        fal[i].membros=(rand()%6)+1;
        fal[i].tp=rand()%4;
        fal[i].beneficio=(rand()%4)+1;
        fal[i].rendaF=(rand()%3550)+450;
        fal[i].rendaP=fal[i].rendaF/fal[i].membros;
    

        sprintf(fal[i].codigo, "%d", i+1001);

        if(fal[i].tp==0){
            sprintf(fal[i].tipo, "EFC   ");
        }
        if(fal[i].tp==1){
            sprintf(fal[i].tipo, "ConPs ");
        }
        if(fal[i].tp==2){
            sprintf(fal[i].tipo, "TrInf ");
        }
        if(fal[i].tp==3){
            sprintf(fal[i].tipo, "MEI   ");
        }
    }
}

void situacao(int n, familia *fal){

    for(int i=0; i<n;i++){
        if (fal[i].rendaF <= 3135){
			if (fal[i].tp == 1){
				sprintf(fal[i].sit, "Sim    ");
			}
			else if (fal[i].tp == 2){
				sprintf(fal[i].sit, "Sim    ");
			}
			else if (fal[i].tp == 3){
				sprintf(fal[i].sit, "Sim    ");
			}
			else if (fal[i].beneficio == 1){
				sprintf(fal[i].sit, "Sim    ");
			}
			else{
				sprintf(fal[i].sit, "Nao    ");
			}
		}
		
		else if (fal[i].rendaP <= 522.50){
			
			if (fal[i].tp == 1){
				sprintf(fal[i].sit, "Sim    ");
			}
			else if (fal[i].tp == 2){
				sprintf(fal[i].sit, "Sim    ");
			}
			else if (fal[i].tp == 3){
				sprintf(fal[i].sit, "Sim    ");
			}	
			else if (fal[i].beneficio == 1){
				sprintf(fal[i].sit, "Sim    ");
			}
			else{
				sprintf(fal[i].sit, "Nao    ");
			}	
		}
		
		else {
			sprintf(fal[i].sit, "Nao    ");
		}		
	}	
    }

void percM(int n, familia *fal){
    int totsolM=0;
    for(int i=0; i<n;i++){
	    if(fal[i].rendaP>=522.5){
	        totsolM++;
	    }
	    percMsol=(totsolM*75)/100;
	}
}	

void imprimir(int n, familia *fal){
    for(int i=0; i<n;i++){
        printf("%s\t%d\t%s\t%d\t%.1f\t\t%.1f\t%s\n", fal[i].codigo, fal[i].membros, fal[i].tipo, fal[i].beneficio, fal[i].rendaF, fal[i].rendaP, fal[i].sit );
    }
    printf("=====================================================================================\n");
    printf("Percentual de solicitantes com renda por pessoa acima de meio salario minimo: %.0f%%\n", percMsol);
}
int main(){
    srand(time(NULL));
    familia fal[75];
    situacao(75, fal);
    preencher(75, fal);
    percM(75, fal);
    imprimir(75, fal);

    return 0;
}