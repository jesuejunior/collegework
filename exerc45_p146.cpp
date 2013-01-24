#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

class FelizPascoa {
public:

	void DataPascoa(int ano) {
		int a, b, c, d, e, f, g, h, i, k, m, l, mes, dia;
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

		cout << dia << "/" << mes << "/" << ano << endl;
	}

};

int main(int argc, char **argv) {

	int AnoPascoa;

	cout << "Digite um ano para saber a data da pascoa: ";
	cin >> AnoPascoa;

	FelizPascoa Coelho;
	Coelho.DataPascoa(AnoPascoa);

  getchar();
  getchar();

}
