#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float c;
float f;

main (){

printf("Digite uma temperatura em graus Celsius:");
scanf("%f", &c);

f = (c * 1.8 + 32);

printf("\nA temperatura convertida para Fahrenheit e:%.2f", f);


getchar();
getchar();

}
