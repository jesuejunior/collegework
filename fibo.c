#include <stdio.h>
int fib(int n);
main()
{ int x,i;
  printf("Entre com o numero\n");
  scanf("%d",&x);
  for(i=1;i<=x;i++)
	 {printf("%d\n", fib(i));};
	
}
	int fib(int n)
	{if(n==0)
	{return 1;}
	else
	{return fib(n-1)+fib(n-2); };};


