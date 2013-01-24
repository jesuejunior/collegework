#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

     int achei = 0;
     int numero = 2;
     int n =1;
     int corte =1;
     int falta;

	while((numero % 2 == 0) || (numero < 0 || numero == 1)){
	     printf("Insira um numero impar e positivo:\n");
	     scanf("%d", &numero);
	}

	while(!achei){
	int i = 0;
	for(i=0; i<corte; i++){
		if (!achei){
			achei = (n == numero);
		}
		
		if (achei){
				
			falta = (corte -i - 1);
			int ultimo = (n + falta * 2);
			printf("A soma dos ultimos tres numeros e: %d\n ", (3 * ultimo - 6));	
			break;		
		}
		n+=2;	

	}	
	corte += 2;	
	}
   
    getch();
}

