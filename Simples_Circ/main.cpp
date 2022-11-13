#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "simples_circ.h"

using namespace std;

int menu()
{
	int op;
	
	cout << "****MENU****" << endl;
	cout << "1 - Insere no inicio: " << endl;
	cout << "2 - Insere no fim: " << endl;
	cout << "3 - Imprime: " << endl;
	cout << "4 - Retira valor desejado: " << endl;
	
	//Continuacao
	
	cout << "5 - Busca valor na lista: " << endl;
	cout << "6 - Retorna tamanho da lista: "<< endl;
	cout << "7 - Retira valor inicio: " << endl;
	cout << "8 - Retira valor fim: " << endl;
	cout << "9 - Imprimi no-dado no inicio da lista: "<< endl;
	cout << "10 - Imprimi no-dado no fim da lista: " << endl;
	cout << "11 - Libera lista: "<< endl;
	cout << "12 - Sair" << endl;
	cout << "****ESCOLHA UMA DAS OPCOES ACIMA****" << endl;
	cin >> op;
	
	return op;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Lista* l;
	
	l = inicializa();
	
	int i, num, op;
	
	do
	{
		op = menu();
		
		switch(op)
		{
			case 1:
				//Insere inicio
				cout << "Numero para inserir: ";
				cin >> i;
				l = insere_inicio(l, i);
				break;
			case 2:
				//Insere fim
				cout << "Numero para inserir no fim: ";
				cin >> i;
				l = insere_fim(l, i);
				break;
			case 3:
				//Imprime
				imprime (l);
				
				system ("PAUSE");
				break;
			case 4:
				//Retira valor
				imprime (l);
				cout << "Numero para retirar da lista: ";
				cin >> num;
				
				l = retira (l, num);
				
				imprime (l);
				
				system ("PAUSE");
				break;
			case 5:
				//Busca valor
				cout << "Digite um valor para pesquisar: ";
				cin >> num;
				
				busca(l, num);
				
				system("PAUSE");
				break;
			case 6:
				//Tamanho
				size(l);
				
				system("PAUSE");
				break;
			case 7:
				//Remove inicio
				l = remove_inicio(l);
				
				system("PAUSE");
				break;
			case 8:
				//Remove fim
				l = remove_fim(l);
				
				system("PAUSE");
				break;
			case 9:
				//Imprime inicio
				imprime_inicio(l);
				
				system("PAUSE");
				break;
			case 10:
				//Imprime fim
				imprime_fim(l);
				
				system("PAUSE");
				break;
			case 11:
				//Libera
				l = libera(l);
				
				system("PAUSE");
				break;
			case 12:
				//Fim
				cout << "Saindo do programa...." << endl;
				
				system ("PAUSE");
				break;
			default:
				cout << "Valor invalido!" << endl;
				system ("PAUSE");
		}
	}
	
	while (op!=12);
	return 0;
}
