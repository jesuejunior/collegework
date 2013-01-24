//Autor: JesueJunior
//Faca um programa em C que leia uma serie de numeros inteiros inseridos pelo teclado sendo zero o ultimo numero da serie.
// Deverao ser exibidos os seguintes elementos da serie:
//a) Total de elementos;
//b) Media dos Elementos;
//c) Porcentagem de Numeros Pares;
//d) Porcentagem de Numeros impares;
//compilado linux: OK
//compilado Windows: OK

#include <stdio.h>

main(){

    int numero = 1, add = 0, total = 0;
    float media = 0.000, par = 0, impar = 0;

    while (numero !=0){
        printf("Digite o numero desejado ou digite zero para vizualizar o resultado:\n");
        scanf("%d",&numero);
        add = add + numero;

        if (numero % 2 == 0 && numero != 0)
           {
            par=par +1;
           }
        else if (numero % 2 != 0)
                {
                impar=impar +1;
                }

    }

    total = (par+impar);
    media = (add/total);
    par = (100*par)/total;
    impar = (impar*100)/total;


    printf("Total de elementos: %d \n",total);
    printf("A media dos elementos e: %.2f\n",media);
    printf("A porcentagem de numeros pares e: %.2f\n",par);
    printf("A porcentagem de numeros impares e: %.2f\n",impar);


    getchar();
    getchar();
    return 0;

}
