#include <iostream>
#include <stdio.h>
using namespace std;

class Calculadora // Definindo a classe
{
   private:
           float a,b; // Membros
           
   public:
          void init(float n1,float n2)  // Método de inicialização
          {
             a=n1;    b=n2;   
          }
          
          void operacao(char op) // Método que aplicará a operação pedida
          {
              switch(op)
             {
                case '+':
                     cout << a << " + " << b << " = " << a+b << endl;
                     break;
                case '-':
                     cout << a << " - " << b << " = " << a-b << endl;
                     break;
                case '*':
                     cout << a << " * " << b << " = " << a*b << endl;
                     break;
                case '/':
                     cout << a << " / " << b << " = " << a/b << endl;
                     break;
             }
          }               
};

main()
{
   float a,b;
   char op;
   
   cout << "Digite o primeiro numero da operacao." << endl;
   cin >> a;
   cout << "Digite o operador. (Ex: + , - , * , / )." << endl;
   cin >> op;
   cout << "Digite o segundo numero da operacao." << endl;
   cin >> b;
   Calculadora x; // Objeto da classe Calculadora
   x.init(a,b);
   x.operacao(op);
   getchar();
   getchar();
}       
