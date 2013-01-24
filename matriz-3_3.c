#include <stdio.h>
#include <stdlib.h>

int V[3][3];
int l=0,c=0;

int main(){

for(l=0;l<=2;l++)
    {
    for(c=0;c<=2;c++)
           {
             printf("Digite um valor para a linha %d coluna %d:",l+1,c+1);
             scanf("%d",&V[l][c]);
            }
}


for(l=0;l<=2;l++)
    {
   printf(" ");
   printf("\n");
   for(c=0;c<=2;c++)
   {
       printf("%d",V[l][c]);
       printf(" ");
    }
}
    getchar();
    getchar();
}
