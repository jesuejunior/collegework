/* Escreva um programa que solicite ao usário uma determinada */ 
/* data e a mostre em seguida no formato dd/mm/aaaa */

#include <stdio.h>
#include <stdlib.h>

main(){
	
	int d, m, a;

	printf("Digite o ano no formato AAAA\n");
	scanf("%d", &a);
	while (a > 9999){
		printf("Digite um ano valido, no formato solicitado AAAA, quantos digitos tem os anos?\n");	
		scanf("%d", &d);
	}


	printf("Digite a mes\n");
	scanf("%d", &m);
	while (m > 12){
		printf("Digite um mes valido MM, quantos meses tem o ano?\n");	
		scanf("%d", &m);
	}	
		printf("Digite o dia:\n");
	scanf("%d", &d);
	while (d > 31){
		printf("Digite um dia valido DD, quantos dias tem o mes?\n");	
		scanf("%d", &d);
	}	
	printf("A data e: %d/%d/%d", d, m, a);

	getchar();
	getchar();
}

