#include <iostream>

using namespace std;

int bisexto(int num);
int valida_bisexto(int num);

int main(){

  int ano;  
  cout << "Digite o ano no formato AAAA" << endl;
	cin >> ano;
	while ((ano < 1000) || (ano > 9999)){			
		  cout << "Digite um ano valido, no formato solicitado AAAA, quantos digitos tem anos?" << endl;	
			cin >> ano;
	}	
	
  cout << bisexto(ano) << endl;
}

int bisexto(int num){  
    if(valida_bisexto(num)){
	    	return 1;	
    }
  
  return 0;	
  
}
int valida_bisexto(int num){
  return ((num % 4 == 0) && (num % 100 != 0) || (num % 400 == 0));
}
