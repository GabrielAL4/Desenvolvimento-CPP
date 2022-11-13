#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

	struct analiseDados{
        char porteEmpresa[20], codigo[20], ramoAtividade[20], local[20], tipoEmpresa[20];
        int dias;
        float valor;
    };
	
    void codigo(analiseDados *empreendedores){
    	int auxl=0, auxt=0;
    	auxt=(rand()%3)+1;
        auxl=rand()%2;
        
 		for(int i=0; i<180;i++){
		
			if(auxt==1){
				sprintf(empreendedores[i].codigo,"%dIND%d", i+265, i);
				sprintf(empreendedores[i].tipoEmpresa,"IND");
				sprintf(empreendedores[i].ramoAtividade,"Industrial");
			}
			if(auxt==2){
				sprintf(empreendedores[i].codigo,"%dCOM%d", i+265, i);
				sprintf(empreendedores[i].tipoEmpresa,"COM");
				sprintf(empreendedores[i].ramoAtividade,"Comercial");
		
			}
			if(auxt==3){
				sprintf(empreendedores[i].codigo,"%dSER%d", i+265, i);
				sprintf(empreendedores[i].tipoEmpresa,"SER");
				sprintf(empreendedores[i].ramoAtividade,"Servicos");
			}
			printf("%s\t%s%d\n", empreendedores[i].codigo, empreendedores[i].ramoAtividade, auxt);
		}
	}

	void tipoEmpresa(analiseDados *empreendedores){
		srand(time(NULL));
		char porteEmpresa[20];
		int nFunc;
		nFunc=(rand()%99)+1;
		
		for(int i; i<180;i++){
		
			if(empreendedores[i].tipoEmpresa== "SER" || empreendedores[i].tipoEmpresa== "COM"){
			
				if(nFunc<=9){
					sprintf(porteEmpresa, "  ME  ");
				}
				if(nFunc>9 && nFunc<=49){
					sprintf(porteEmpresa, "  EPP ");
				
				}
				if(nFunc>49 && nFunc<=99){
					sprintf(porteEmpresa, "  EMP ");
				
				}
				if(nFunc>=100){
					sprintf(porteEmpresa, "Grande");
				}
			}
			if(empreendedores[i].tipoEmpresa== "IND" ){
			
				if(nFunc<=19){
					sprintf(porteEmpresa, "  ME  ");
				}
				if(nFunc>19 && nFunc<=99){
					sprintf(porteEmpresa, "  EPP ");
				
				}
				if(nFunc>99 && nFunc<=499){
					sprintf(porteEmpresa, "  EMP ");
				
				}
				if(nFunc>=500){
					sprintf(porteEmpresa, "Grande");
				}
			}
		printf("%s\t\n", porteEmpresa);		
		}
	}
    
int main(){
    srand(time(NULL));
    analiseDados empreendedores[180]={0};
	
	codigo(empreendedores);

	tipoEmpresa(empreendedores);
	

    

    return 0;

}
