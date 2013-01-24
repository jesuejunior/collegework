#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int soma(int a, int b)
{
    return(a+b);
}

int subtracao(int a, int b)
{
    return (a-b);
}

int multiplicacao(int a, int b)
{
    return (a*b);
}

int divisao(int a, int b)
{
    return (a/b);
}

int pegartodospokemons(int a, int b)
{

   printf("Digite o primeiro valor:\n");
   scanf("%d",&a);
   printf("Digite o segundo valor:\n");
   scanf("%d",&b);
   return;

}
main(){
    char oper;
    int a,b;
    printf("Digite a opção desejada: (+) Soma, (-) Subtracao, (x) Multiplicacao, (/) Divisao\n");
    scanf("%c",oper);
    if  (oper =='+'){

    pegartodospokemons(a,b);
    }
//    switch(oper)
//    {
//        case '+':
//
//    }


    printf("O resulta e: %d",soma(a,b));


   getchar();
}
