#include<stdio.h>
#include<stdlib.h>

void mediaPonderada(){
    float n1, n2,  media;

    printf("Qual a nota 1?");
    scanf("%f", & n1);
    printf("Qual a nota 2?");
    scanf("%f", & n2);

    media= ((n1*4)+(n2*6))/10;

    printf("A media foi de %f", media);



}
int main(){
    mediaPonderada();


    return 0;
}