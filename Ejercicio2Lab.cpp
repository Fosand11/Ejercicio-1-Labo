#include <iostream>
using namespace std;


int mcd(int a, int b){
    if(a == 0){
        return b;
    }else{
        return mcd(b % a, a);
    };
};

int main(){
    int a, b;
    cout << "Ingrese su primer numero: ";
    cin >> a;
    cout << "Ingrese su segundo numero: ";
    cin>> b;
    cout << "Su Maximo Comun Divisor (MCD) es: " << mcd(a, b);
    };