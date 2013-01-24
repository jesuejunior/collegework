#include <stdio.h>
#include <stdlib.h>
//Testes no Windows: OK
//teste linux: OK

int main()
{
  FILE *arquivo;
  char nome[30]; //o arquivo deve estar no mesmo fdiretorio do arquivo .C
  int *valores = malloc(sizeof(int)*256); //array para guardar as somas

  //Inicializa os valores com 0
  int i;
  for (i=0;i<256;i++){
           valores[i]=0;
}
  printf("Nome do arquivo junto com a extensao Ex: teste.txt\n");
  printf("Qual o nome do arquivo: ");

  scanf("%s", &nome);
  system("cls"); //Caso for compilar no linux usar a biblioteca ncurses e  a funcao clrscr(); no lugar dessa
  arquivo=fopen(nome,"r");
  
  // testa se o arquivo foi aberto com sucesso
  if(arquivo != NULL){
  // usando um laco para ler o conteudo do arquivo
  int total=0,resto=0,c;
  while(!feof(arquivo)){
          c = fgetc(arquivo);
          valores[c]++;
          if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
           total++; // Faz a contagem do total de caracter existente no arquivo validando somente de A - Z e a - z e numeros
          }
          else
              resto++; //Faz a contagem de caracteres especiais inclusive espaco
          }
     
  printf("\t\t\tContador de caracteres de arquivos!\n");
  printf("\t\t\tCaracteres validos (A - Z) (a - z) (0 - 9)\n");
  printf("\t\t\tTotal de letras validas: %d\n",total);
  printf("\t\t\tCaracteres especiais: %d\n\n",resto);
  float master;
  for(i=0;i<256;i++){
        if((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')){
        master = ((float)valores[i]/total*100);        
          if( master != 0){          
           printf("O total de %c foi %.2f %%\n", i,master);               
}
}
}
    fclose(arquivo); // libera o ponteiro para o arquivo
  }
  else
    printf("Nao foi possivel abrir o arquivo.\n");
    
    printf("\n");
    printf("Developed by Jesu%c Junior\n", 130);
  getchar();
  getchar();
  return 0;
}
