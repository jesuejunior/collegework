#include <stdio.h>

int main ()
{
  
	float num1, num2;
	char calc;
	
	printf("Digite o primeiro numero:\n");
	scanf("%f", %num1);
	printf("Digite o segundo numero:\n");
	scanf("%f", %num2);  
 
 	printf ("Selecione a operacao\n");
	printf ("(A)dicao.\n");
	printf ("(S)ubtracao.\n");
	printf ("(D)ivisao.\n");
	printf ("(M)ultiplicacao.\n");
	printf ("Digite a letra correspondente a operacao desejada:\n");
	scanf ("%s", &calc);
  
	switch (calc)
	    {
    		case 'A':
		printf ("A soma %f + %f = %f\n", num1, num2, num1 + num2);
      		break;
    		
		case 'S':
      		printf ("A subtracao %f - %f = %f\n", num1, num2, num1 - num2);
      		break;
    
		case 'D':
      		printf ("A divisao %f / %f = %f\n", num1, num2, num1 / num2);
      		break;
    		
		case 'M':
      		printf ("A multiplicacao de %f * %f = %f\n", num1, num2, num1 * num2);
      		break;
    		
		default:
		printf ("Erro\n");
      		break;
    
		}
  
	printf ("\n\n\n");
	printf ("Developed by JesueJunior\n");
	getch ();
	return 0;

}


