#include <iostream>

using namespace std;

int juliana(int dia, int mes, int ano);
int convert(int data);

int main(){

  int dia, mes, ano;
  cout << " Digite o dia no formato DD " << endl;
  cin >> dia;
  cout << " Digite o mes no formato MM " << endl;
  cin >> mes;
  cout << " Digite o ano no formato AAAA " << endl;
  cin >> ano;
  
  cout << juliana(dia, mes, ano) << endl;
}

int juliana(int dia, int mes, int ano){
  return (1461*(ano + 4800 +( mes - 14 ) / 12)) / 4 + (367 *( mes -2 -12 *(( mes - 14 ) / 12))) / 12 - (3 *(( ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;


}
