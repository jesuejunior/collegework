#include <stdio.h>

main(){
   int vet0[6], vet1[6],i,p;
   printf("Digite os tres numeros\n");
   for(i=0;i<3;i++){
       scanf("%d",&vet0[i]);
       scanf("%d", &vet1[i]);                
   }   
   p = (vet0[0]*vet1[0]) + (vet0[1]*vet1[1]) + (vet0[2]*vet1[2]);
   
   printf("O produto escalar e: %d", p);  
    
 
  getch();
   
}   
       
       
