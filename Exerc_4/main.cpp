#include <iostream>
#include<stdio.h>
#include<conio.h>
#include "ex_4.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	char caract;
	char texto; 
	int esc;
	int num = 0;
	
	cout << "Digite um texto ou a tecla ESC para encerrar:\n";
	
	while (esc != 27)
	{
		
		caract = getch();
		
		esc = getch();
		
		matriz_ascii(caract, &num);
		matriz_caractere(caract, &num);
		
	}
	
	cout << "Fim de programa, tecle ESC foi pressionada!";
	
	return 0;
}
