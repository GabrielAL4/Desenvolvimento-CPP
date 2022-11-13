typedef struct 
{
	
	char nome[100];
	char rg[9];
	char cpf[11];
	char endereco[100];
	
} Cadastro;

Cadastro* cadastro_usuario (Cadastro *u, int *id);
void exibir_usuario(Cadastro *u, int id);
void quantidade_usuario(int id);
Cadastro* remover_usuario(Cadastro *u, int *id);
Cadastro* arquivo_usuario(Cadastro *u, int *id, int a);
