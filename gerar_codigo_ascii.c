#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i=0;
  while(i < 256)
  {
     printf("%c[ %d]\n",i,i);
       i++;
  }
  getchar();
  getchar();
}
