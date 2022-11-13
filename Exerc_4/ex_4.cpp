#include<stdio.h>
#include<conio.h>
#incluce "ex_4.h"

char matriz_ascii (char *t, int *n){
	
	t = (char*) malloc (sizeof(char));
	
	if (t == NULL){
		
		printf ("Sem memoria suficiente");
		
		t[*n] = c;
		*n = *n +1;
		
		return t;
		
	}
	else
	{
		
		t = (char*) realloc (t, (*n +1) * sizeof (char));
		
		t[*n] == c;
		*n = *n +1;
		
		return t;
		
	}
	
}

char matriz_caractere(char *t)
{
	
	for (i = 0; i < num; i++)
	printf ("%c", texto[i]);
	printf("\n");
	
}
