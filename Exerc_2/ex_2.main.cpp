#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ex_2.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
	
	cout << "\n\n*****Escolha opcao*****:\n";
	cout << "1- Exibir vetor informado" << endl;
	cout << "2- Exibir elementos impares armazenados no vetor" << endl;
	cout << "3- Exibir elementos pares no vetor" << endl;
	cout << "4- Encerrar o programa" << endl;
	cout << "Escolha uma das opcoes acima: "; 
	
}


int main(int argc, char** argv) {
	
	int i;
	int vetor[10];
	int op;
	
	for (i = 0; i < 10; i++)
	{
		printf("Digite os vetores: ");
		scanf("%d", &vetor[i]);
	}
	
	do{	
		menu();
		cin >> op;
		switch(op){
		
		case 1:
			mostrar_vetor(vetor);
			break;
		case 2:
			mostrar_impar(vetor);
			break;
		case 3:
			mostrar_par(vetor);
			break;
		default:
			system("cls");
			printf ("Voce digitou %d. Esta e uma opcao invalida! \n", op);
			system("PAUSE");
	}
		
	}while (op != 4);
	
	printf ("\nFim do programa!\n");
	system ("Pause");
	
	return 0;
}
