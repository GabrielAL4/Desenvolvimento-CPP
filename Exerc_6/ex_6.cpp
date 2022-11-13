#include <stdio.h>
#include <stdlib.h>
#include "ex_6.h"

Cadastro* cadastro_livro(Cadastro *u, int *n)
{
	if (n == 0)
	{
		u = (Cadastro*) malloc(sizeof(Cadastro));
	}
	else
	{
		u = (Cadastro*) realloc(u, (*n + 1) * sizeof(Cadastro));
	}
	
	printf ("\nNome: ");
	scanf ("%s", &u[*n].nome);
	
	printf("\nAutor: ");
	scanf ("%s", &u[*n].autor);
	
	printf ("\nCodigo: ");
	scanf ("%s", &u[*n].codigo);
	
	printf ("\nAno: ");
	scanf ("%s", &u[*n].ano);
	
	printf ("CADASTRO FEITO COM SUCESSO\n");
	
	*n = *n + 1;
	
	return u;
}

void exibir_livro (Cadastro *u, int n)
{
	printf ("\nExibir livros"); 
	
	for (int i = 0; i < n; i++)
	{
		printf ("\n%s |", u[i].codigo);
		printf ("%s | ", u[i].nome);
		printf ("%s |", u[i].autor);
		printf("%s\n", u[i].ano);
	}
}
