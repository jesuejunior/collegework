#include <stdio.h>
#include <stdlib.h>
//Teste Linux: OK
//Teste windows: OK

struct _Node {
    int valor;
    struct _Node *prox;
};

typedef struct _Node Node;

Node *criar_lista(){
  Node *m;
  m=malloc(sizeof(Node));
  m->prox=NULL;
  return m;
}

int insere(Node *raiz, int n){
  int inseriu = 0;
  Node *novo=criar_lista();
  Node *atual=raiz;
  novo->valor=n;
  while(atual->prox!=NULL){

      if(n < atual->prox->valor){
        //printf("Inserindo: %d, antes do %d\n", n, atual->prox->valor); //usado somente para verificar se os valores estavam corretos
         novo->prox=atual->prox;
         atual->prox=novo;
         inseriu = 1;
         break;
      }else if (n == atual->prox->valor){
        printf("Este valor ja existe: %d\n", n);
        return 0;
      }
    atual=atual->prox;

   }
   if (!inseriu){
    //printf("Inserindo ultimo elemento: %d\n", novo->valor); //usado somente para verificar se os valores estavam corretos
    atual->prox = novo;
   }
  return 0;
}

void dump(Node *raiz){
    Node *atual;
    atual=raiz;
    while(atual->prox!=NULL){
        atual=atual->prox;
        printf(" %d ",atual->valor, atual->prox);
    }
}

int main(){
    int num,s;
    Node *n=criar_lista();

    do{
        printf("Digite o valor: ");
        scanf("%d",&num);
        insere(n,num);
        dump(n);
    printf("\nDigite (1) para inserir outro valor\n");
    printf("Digite (0) para ver o resultado\n");
    scanf("%d",&s);
    }
    while(s != 0);
  //dump(n);
  getchar();
  getchar();
  return 0;
}
