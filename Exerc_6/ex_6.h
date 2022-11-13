typedef struct 
{
	char nome [100];
	char autor [100];
	char codigo[100];
	char ano [4];
} Cadastro;

Cadastro* cadastro_livro(Cadastro *u, int *n);
void exibir_livro(Cadastro *u, int n);
