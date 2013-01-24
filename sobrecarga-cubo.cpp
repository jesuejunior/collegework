#include <iostream>
#include <stdio.h>
using namespace std;

int cubo(int);
float cubo(float);
double cubo(double);

int main(){
    cout << cubo(999) << endl;
    cout << cubo(32.21) << endl;
    cout << cubo(double(4321.76)) << endl;

    getchar();
    getchar();
    return 0;

}

int cubo(int n){
    return n*n*n;
}

float cubo(float n){
    return n*n*n;
}

double cubo(double n){
    return n*n*n;
}
