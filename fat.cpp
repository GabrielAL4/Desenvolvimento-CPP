//Cálculo de fatorial com função recursiva
#include <stdio.h>
float fatorial(int n); //protótipo da função fatorial
main(){
    int numero;
    float f;
    printf("Digite o numero que deseja calcular o fatorial: ");
    scanf("%d",&numero);
    f = fatorial(numero); //chamada da função fatorial
    printf("Fatorial de %d = %.0f",numero,f);
}
//Função recursiva que calcula o fatorial de um numero inteiro n
float fatorial(int n){
    int a;
    float vfat;
    if ( n <= 1 ) //Caso base: fatorial de n <= 1 retorna 1
        return (1);
    else {
        a=n-1;
        vfat = n + fatorial((n-1)*(n-1)*(n-1)); //Chamada recursiva
        return (vfat);
    }
}