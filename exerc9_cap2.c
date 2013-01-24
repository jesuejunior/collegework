/* Escreva um programa que solicite ao usuario uma determinada */
/* data e a mostre em seguida no formato dd/mm/aaaa */

#include <stdio.h>
#include <stdlib.h>

main ()
{

  int dia, mes, ano, bis;

  printf ("Digite o dia:\n");
  scanf ("%d", &dia);
  while (dia > 31)
    {
      printf ("Digite um dia valido DD, quantos dias tem o mes?\n");
      scanf ("%d", &dia);
    }
  printf ("Digite a mes\n");
  scanf ("%d", &mes);
  while (mes > 12)
    {
      printf ("Digite um mes valido MM, quantos meses tem o ano?\n");
      scanf ("%d", &mes);
    }
  if (mes == 04 || mes == 06 || mes == 09 || mes == 11)

    printf ("Digite o ano no formato AAAA\n");
  scanf ("%d", &ano);
  while ((ano < 1000) || (ano > 9999))
    {
      printf
	("Digite um ano valido, no formato solicitado AAAA, quantos digitos tem anos?\n");
      scanf ("%d", &ano);
    }

  if ((ano % 4 == 0) && (ano % 100 != 0) || (ano % 400 == 0))
    printf ("%d e bisexto", ano);

  else
    printf ("A data e: %d/%d/%d", dia, mes, ano);

  getchar ();
  getchar ();
}
