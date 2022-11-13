#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "simples_circ.h"

using namespace std;

Lista* inicializa(){
	
	return NULL;
	
}

bool vazia(Lista* l)
{
	return l == NULL;
}

//insere_inicio
Lista* insere_inicio(Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	
	if (vazia(l))
	{
		novo->prox = novo;
		return novo;
	}
	else
	{
		novo->prox = l->prox;
		l->prox = novo;
	}
	
	return l;
}

//insere_fim
Lista* insere_fim(Lista* l, int i)
{
	if (vazia(l))
	{
		return insere_inicio(l, i);
	}
	else
	{
		Lista* novo = (Lista*) malloc(sizeof(Lista));
		novo->info = i;
		
		novo->prox = l->prox;
		l->prox = novo;
		
		return novo;
	}
}

//Imprime
void imprime(Lista* l) 
{
	if (!vazia(l))
	{
		Lista* p = l->prox;
		cout << "Lista completa: ";
		
		do
		{
			printf ("%d - ", p->info);
			p = p->prox;
		}while (p != l->prox);
		
		printf ("\n");
	}
	
	else 
	{
		cout << "Lista vazia" << endl;
	}
}


//Retira um elemento
Lista* retira (Lista* l, int v)
{
	Lista* ant = NULL;
	
	Lista* p = l->prox;
	
	//Lista Vazia
	if (vazia(l))
	{
		cout << "Lista vazia!" << endl;
		return l;
	}
	
	//Procura elemento, guarda anterior 
	do 
	{
		//Garante travessia msm com um nó
		if (p->info == v)
		{
			break;
		}
		
		ant = p;
		p = p->prox;
	}while (p != l->prox);
	
	//Verificar se acha o elemento
	if (ant != NULL && p == l->prox)
	{
		return l; //Caso nao ache, retornar para a lista original
	}
	
	//Verifica se há apenas um 
	if(p == p->prox)
	{
		free (p);
		return NULL;
	}
	
	//Achar em uma lista 2 ou mais nós
	if (ant == NULL && p == l->prox)
	{
		l->prox = p->prox; //ultimo aponta para o segundo
		return l;
	}
	
	ant->prox = p->prox;
	
	if (p==l)
	{
		l = ant;
	}
	return l;
	free (p);
	
}

//Busca dado 
Lista* busca (Lista* l, int v)
{
	Lista* p = l->prox;
	
	do
	{
		
		if (p->info == v)
		{
			cout << "Esta na lista" << endl;
			return p;
		}
		else
		{
			p = p->prox;
		}
		
	}while(p!=l->prox);
	
	cout << "Nao esta na lista" << endl;
	return NULL;
}


//Tamanho 
void size (Lista* l)
{
	if(vazia(l))
	{
		cout << "Lista vazia!" << endl;
	}
	
	int cont = 0;
	Lista* p = l->prox;
	do
	{
		cont ++;
		p = p->prox;
	}while(p!=l->prox);
	
	
	printf ("Tamanho da lista: %d\n", cont);
}

//Remove inicio 

Lista* remove_inicio(Lista* l)
{
	
	if (!vazia(l))
	{
		Lista* p = l->prox;
		if (l!=l->prox)
		{
			l->prox = p->prox;
			cout << "Removido o primeiro dado" << endl;
			free(p);
			return l;
		}
		else 
		{
			cout << "Removido primeiro e unico dado" << endl;
			free(p);
			return NULL;
		}
	}
	else 
	{
		cout << "Vazia!!" << endl;
	}
		
}

//Remove fim
Lista* remove_fim(Lista* l)
{
	
	if (vazia(l))
	{
		cout << "Lista vazia!" << endl;
		return l;
	}
	
	if (l != l->prox)
	{
		Lista* ant = l->prox;
		
		while(ant->prox!=l)
		{
			ant = ant->prox;
		}
		
		ant->prox = l->prox;
		free(l);
		return ant;
	}
	else 
	{
		free(l);
		return NULL;
	}
	
}

//Imprime inicio
void imprime_inicio(Lista* l)
{
	Lista* p = l->prox;
	
	if (!vazia(l))
	{
		printf ("Valor do inicio: %d\n", p->info);
	}
	else
	{
		cout << "Lista vazia!" << endl;
	}
}

//Imprime fim
void imprime_fim (Lista* l)
{
	Lista* p = l;
	
	if (!vazia(l))
	{
		printf ("Valor do fim: %d\n", p->info);
	}
	else
	{
		cout << "Lista vazia!" << endl;
	}	
	
}

//Libera
Lista* libera (Lista* l)
{
	Lista* p = l->prox;
	Lista* aux = NULL;
	
	if (!vazia(l))
	{
		do
		{
			aux = p;
			p = p->prox;
			free(aux);
			//cout << "Lista apagada" << endl;
		
		}while (p != l->prox);
		
		return NULL;
	}
	else 
	{
		cout << "Lista ja esta vazia!" << endl;
		return l;
	}
}



