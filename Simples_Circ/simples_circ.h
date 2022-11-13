#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct lista 
{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa();
bool vazia (Lista* l);
Lista* insere_inicio (Lista* l, int i);
Lista* insere_fim (Lista* l, int i);
void imprime (Lista* l);
Lista* retira (Lista* l, int v);


Lista* busca (Lista* l, int v);
void size (Lista* l);
Lista* remove_inicio (Lista* l);
Lista* remove_fim (Lista* l);
void imprime_inicio (Lista* l);
void imprime_fim(Lista* l);
Lista* libera (Lista* l);
