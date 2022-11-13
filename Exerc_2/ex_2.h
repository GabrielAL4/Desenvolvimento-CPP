//ex_2.h

int mostrar_vetor(int *vetor1){
	for (int i = 0; i < 10; i ++)
	{
		printf ("%d \t ", vetor1[i]);
	}
}
int mostrar_impar(int *vetor1){
	for (int i = 0; i < 10; i ++)
	{
		if (vetor1[i]%2 != 0)
		{
			printf ("%d \t", vetor1[i]);
		}
	}
}

int mostrar_par(int *vetor1){
	for (int i = 0; i < 10; i ++)
	{
		if (vetor1[i] % 2 == 0)
		{
			printf ("%d \t", vetor1[i]);
		}
	}
}

