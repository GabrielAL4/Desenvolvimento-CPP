#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ex_7.h"

using namespace std;

void menu() {
	
	cout << "\n\n*****Escolha opcao*****:\n";
	cout << "1 - Cadastro de usuario" << endl;
	cout << "2 - Exibir informacoes dos usuarios" << endl;
	cout << "3 - Exibir a quantidade de cadastrados" << endl;
	cout << "4 - Remover o ultimo cadastro" << endl; 
	cout << "5 - Carregar base de dados do arquivo" << endl;
	
}

int main(int argc, char **argv) {
	
	int i;
	int op;
	Cadastro *usuario = NULL;
	int num = 0;
	
	FILE *arq;
		char ch;
		
		if ((arq = fopen("arquivo.txt", "r")) == NULL)
		{
			printf ("Erro na abertura do arquivo\n");
			return -1;
		}
		
	ch = getc(arq);
	
	
	do{
		
		menu();
		cin >> op;
		switch(op){
			
			case 1:
				usuario = cadastro_usuario(usuario, &num);
				break;
			case 2:
				exibir_usuario(usuario, num);
				break;
			case 3:
				quantidade_usuario(num);
				break;
			case 4:
				remover_usuario(usuario, &num);
				break;
			case 5:
				usuario = arquivo_usuario(usuario, &num, &arq);
				system("PAUSE");
				break;
			default:
				system("cls");
				cout << "Voce digitou opcao invalida!";
				system ("PAUSE");
			
		}
	}while(op != 6);
	
	fclose (arq);
	
	return 0;
}

