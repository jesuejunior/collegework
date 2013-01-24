#include <stdio.h>
#include <stdlib.h>

int **matriz;
int l=0,c=0,ccont=0, lcont=0, i;

int main(){


printf("Digite o numero de linhas:\n");
scanf("%d",&lcont);
printf("Digite o numero de colunas:\n");
scanf("%d",&ccont);

//primeira dimensão
matriz = malloc(sizeof(int *) * lcont);

//segunda dimensão
for (i=0;i<ccont;i++){
    matriz[i] = malloc(sizeof(int) * ccont);
 }


for(l=0;l<lcont;l++)
    {
    for(c=0;c<ccont;c++)
           {
             printf("Digite um valor para a linha %d coluna %d:",l+1,c+1);
             scanf("%d",&matriz[l][c]);
            }
}


for(l=0;l<lcont;l++)
    {
   printf(" ");
   printf("\n");
   for(c=0;c<ccont;c++)
   {
       printf("%d",matriz[l][c]);
       printf(" ");
    }
}
    getchar();
    getchar();
}
