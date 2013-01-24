#include <stdio.h>
#include <stdlib.h>


main(){
	
	int ano;

	printf("Digite o ano no formato AAAA\n");
	scanf("%d", &ano);
	while ((ano < 1000) || (ano > 9999)){			
			printf("Digite um ano valido, no formato solicitado AAAA, quantos digitos tem anos?\n");	
			scanf("%d", &ano);
	}	
	if((ano % 4 == 0) && (ano % 100 != 0) || (ano % 400 == 0))
		printf("%d e bisexto\n", ano);	
	
	else
	printf(" O ano %d nao %c bisexto\n", ano, 233);	
	
		
}


