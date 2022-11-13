#include <stdio.h>
#include <stdlib.h>
#include "ex_3.h"


int* cadastrar_numero(int *vetor1, int *n)
{
	
	if (n == 0)
	{
		vetor1 = (int*) malloc(sizeof(int));
	}
	else
	{
		vetor1 = (int*) realloc (vetor1, (*n + 1) * sizeof(int));
	}
	
	printf ("\nCadastrar numero: ");
	scanf("%d", &vetor1[*n]);
	
	*n = *n + 1;
	
	return vetor1;
}

void exibir_numero (int *vetor1, int n)
{
	printf("Exibir numeros\n");
	
	for (int i = 0; i < n; i ++)
	{
		printf ("%d\n", vetor1[i]);
	}
}

void quantidade_numero (int n)
{
	printf ("\nTotal de numeros cadastrados: %d", n);
}

int* remover_numero (int* vetor1, int *n)
{
	if (*n > 0)
	{
		vetor1 = (int*) realloc(vetor1, (*n - 1) * sizeof(int));
		*n = *n - 1;
		printf ("Elemento removido com sucesso\n");
	}
	else 
	{
		printf ("Nao existe numero para ser removido");
	}
	
	return vetor1;
}
