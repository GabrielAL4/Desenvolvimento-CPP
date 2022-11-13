#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ex_3.h"
using namespace std;

int menu(){
	
	cout << "\n*** MENU ***" << endl;
	cout << "1 - Cadastrar numero: " << endl;
	cout << "2 - Exibir numero(s) cadastrado(s)" << endl;
	cout << "3 - Exibir quantidade de numeros cadastrados" << endl;
	cout << "4 - Remover o ultimo numero cadastrado" << endl;
	cout << "5 - Sair" << endl;
	
}

int main(int argc, char** argv) {
	
	int op;
	int *vetor = NULL; 
	int num = 0;
	
	do{
		menu();
		cin >> op;
		switch (op){
			case 1:
				vetor = cadastrar_numero(vetor, &num);
				break;
			case 2: 
				exibir_numero(vetor, num);
				break;
			case 3:
				quantidade_numero(num);
				break;
			case 4: 
				vetor = remover_numero(vetor, &num);
				break;
			default:
				system ("cls");
				printf ("Opcao incorreta, por favor, tentar novamente");
		}
		
		
	}while (op != 5);
	
	printf ("\nFim do programa!\n");
	system ("Pause");
	
	return 0;
}
