#include <stdio.h>
#include <conio.h>

int main()
{
	char letra;
	
	while (letra != 27){
		
		printf ("Digite alguma tecla ou tecle ESC para sair: \n\n");
		
		letra = getch();
		
		printf ("Caractere: %c ; Dec. ASCII: %d \n\n", letra, letra);
	
	}
	
	printf ("******Programa encerrado!******");
	
	return 0;
		
	
}
