#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

void feriados(int ano);

int main(int argc, char **argv) {

	int ano;

	cout << "Digite um ano para saber a data dos feriados: ";
	cin >> ano;

  feriados(ano);

  getchar();
  getchar();

}


void feriados( int ano) {
		int a, b, c, d, e, f, g, h, i, k, m, l, dia, mes;
		a = ano % 19;
		b = ano / 100;
		c = ano % 100;
		d = b / 4;
		e = b % 4;
		f = (b + 8) / 25;
		g = (b - f + 1) / 3;
		h = (19 * a + b - d - g + 15) % 30;
		i = c / 4;
		k = c % 4;
		l = (32 + 2 * e + 2 * i - h - k) % 7;
		m = (a + 11 * h + 22 * l) / 451;
		mes = (h + l - 7 * m + 114) / 31;
		dia = ((h + l - 7 * m + 114) % 31) + 1;
    
	  cout << "Sexta Feira Santa        : " << ((h+l-7*m+114-2)%31)+1 << "/" << ((h+l-7*m+114)/31) << "/" << ano << endl;
    cout << "Terca-feira de Carnaval  : " << ((h+l-7*m+114-47)%31)+1 << "/" << ((h+l-7*m+114)/31)-1 << "/" << ano << endl;
    cout << "Corpus Christi           : " << ((h+l-7*m+114+60)%31)+2 << "/" << ((h+l-7*m+114)/31)+2 << "/" << ano << endl;	

}


