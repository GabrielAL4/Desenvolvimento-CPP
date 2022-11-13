#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ex_6.h"

using namespace std;

void menu ()
{
	
	cout << "****CADASTRO DE LIVRO****" << endl;
	cout << "1- Cadastrar livro" << endl;
	cout << "2 - Consultar os livros" << endl;
	cout << "3 - Sair" << endl;
	
}


int main(int argc, char** argv) {
	
	int op; 
	Cadastro *livro = NULL;
	int num = 0;
	
	do
	{
		menu();
		cin >> op;
		switch (op)
		{
			case 1:
				livro = cadastro_livro(livro, &num);
				break;
			case 2:
				exibir_livro(livro, num);
				system ("PAUSE");
				break;
			case 3:
				cout << "Cadastro encerrado!" << endl;
				system ("PAUSE");
				break;
			default:
				system ("cls");
				cout << "Voce escolheu a opcao invalida!" << endl;
				system ("PAUSE");
				
		}
	}while (op != 3);
	
	return 0;
}
