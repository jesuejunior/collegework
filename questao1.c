#include <stdio.h>
//Autor: jesuejunior
//Questão 1 da prova paratica.

main (){

float cateto_a,cateto_b,area;

    printf("\t\tDecobrir %crea de um dado tri%cngulo retangulo.\n\n",160,131);
    printf("Digite o valor do cateto A: ");
    scanf("%f",&cateto_a);
    printf("Digite o valor do cateto B: ");
    scanf("%f",&cateto_b);

    area=(cateto_a*cateto_b)/2;

    printf("A %crea do tri%cngulo %c: %.2f",160,131,130,area);

    getchar();
    getchar();

}
