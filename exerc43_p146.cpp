#include <iostream>
#include <stdio.h>

using namespace std;

int juliana(int dia, int mes, int ano);
void dia_semana (int num);

int main(){

  int dia, mes, ano, num;
  cout << "Digite o dia no formato DD " << endl;
  cin >> dia;
  cout << "Digite o mes no formato MM " << endl;
  cin >> mes;
  cout << "Digite o ano no formato AAAA " << endl;
  cin >> ano;
  cout << "Data Juliana: " << juliana(dia, mes, ano) << endl; 
  cout << "Dia da semana: ";
  dia_semana((juliana(dia, mes, ano)%7));
  
  getchar();
  getchar();

}

int juliana(int dia, int mes, int ano){
  return (1461*(ano + 4800 +( mes - 14 ) / 12)) / 4 + (367 *(mes -2 -12 *((mes - 14 ) / 12))) / 12 - (3 *((ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;
}


void dia_semana(int num){ 
    char *dias[] = {"Segunda-feira", "Terca-feira", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};
    cout <<  dias[num] << endl; 
}
