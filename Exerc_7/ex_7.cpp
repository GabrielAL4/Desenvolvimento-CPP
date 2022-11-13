#include <stdio.h>
#include<stdlib.h>
#include "ex_7.h"

Cadastro* cadastro_usuario(Cadastro *u, int *id)
{
	
	if (id == 0)
	{
		
		u = (Cadastro*) malloc(sizeof(Cadastro));
		
	}
	else
	{
		
		u = (Cadastro*) realloc(u, (*id + 1) * sizeof(Cadastro));
		
	}
	
	printf ("\nNome: ");
	scanf ("%s", &u[*id].nome);
	
	printf("\nRG: ");
	scanf ("%s", &u[*id].rg);
	
	printf("\nCPF: ");
	scanf("%s", &u[*id].cpf);
	
	printf ("\nEndereco: ");
	scanf("%s", &u[*id].endereco);
	
	*id = *id + 1;
	
	return u;
	
}

void exibir_usuario(Cadastro *u, int id)
{
	
	
	printf ("\nExibir cadastros");
	
	for (int i = 0;i < id; i++)
	{
		
		printf("\n%s\n", u[i].nome);
		printf ("%s\n", u[i].rg);
		printf("%s\n", u[i].cpf);
		printf("%s\n", u[i].endereco);
		
	}
	
}

void quantidade_usuario(int id)
{
	printf ("\nQuantidade de usuarios cadastrados: %d\n", id);
	
}

Cadastro* remover_usuario(Cadastro *u, int *id)
{
	if (*id > 0){
		
		u = (Cadastro*) realloc (u, (*id - 1) * sizeof(Cadastro));
		*id = *id - 1;
		printf ("Usuario removido com sucesso");
	}
	else
	{
		
		printf ("Nao existe usuario para remover");
		
	}
	return u;
		
}

Cadastro* arquivo_usuario(Cadastro *u, int *id, int a){
	
	for (int i = 0; i < id; i++)
	{
		
		fscanf(a, "%s | %s | %s | %s", &u[i].nome, &u[i].rg, &u[i].cpf, &u[i].endereco]);
		
	}
	
}
