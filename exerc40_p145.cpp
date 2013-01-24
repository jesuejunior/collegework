#include <iostream>
#include <assert.h>
 using namespace std;

int primo(int num);
int divisivel(int num, int i);
int primos(int n1, int n2);
int prox_primo(int n);
void goldbach(int n);

int main(){

    for(int i=700;i<=1100; i+=2){
    cout << i << ": ";
    goldbach(i);
    cout << endl;
    }
}

int primo(int num){
    
    if (num < 2){
        return 0;
     }

    for(int i=2;i < num;i++){
        if(divisivel(num, i)){
          return 0;
        }
    }

    return 1;
}

int divisivel(int num, int i){
  return num%i == 0;
}

int primos(int n1, int n2){
  return primo(n1) && primo(n2);
}

int prox_primo(int n){
  int prox = n + 1;
  while(!primo(prox)){
    prox += 1;
  }
  return prox;
}

void goldbach(int n){
    int p1 = 2, p2 = 0;
    do {
        p1 = prox_primo(p1);
        p2 = n - p1;
    }
    while(!primos(p1,p2));

    cout << p1 << " + " << p2 << " = " << n << "(" << p1 + p2 <<  ")" << endl; 
}
