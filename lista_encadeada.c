#include <stdio.h>
#include <stdlib.h>
//#include "conio.h"

struct elemento
{
   	int valor;
    struct elemento *prox;
};

void main()
	{
    int j,q=0;
    struct elemento *inicio,*p1,*p2;
    inicio=(struct elemento *)malloc(sizeof(struct elemento));
    inicio->prox=NULL;
    printf("Entre o primeiro valor\n");
    scanf("%d",&j);
    inicio->valor=j;
    do
   	{
	    printf("\nEntre o proximo valor\n");
	    scanf("%d",&j);
	    p1=(struct elemento *)malloc(sizeof(struct elemento));
	    p1->valor=j;
        p1->prox=inicio;
	    inicio=p1;
	    printf("\n\tsituacao\n");
	    for(p1=inicio;p1 != NULL;p1=p1->prox)
	    printf("\n\t%d\n",p1->valor);
        printf("\n\tDeseja continuar? 1=sim 0=nao\n");
        scanf("%d",&q);
   	}
       while(q>0);
   }
