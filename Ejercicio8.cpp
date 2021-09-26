#include <iostream>

using namespace std;

void contador(int, int);

void contador(int a, int b){
    cout << b << endl;
    if(a == 1)
        if(b == 1)
            return;
        else   
            return contador(a, b-1);
    else   
        return contador(a-1, b+1);
}

int main(void){
    int a = 0;
    cout << "---------------Contador---------------" << endl;
    cout << "Inserte un numero: ";
    cin >> a;
    cout << "Su conteo es: "<< endl;
    contador(a, 1);
    cout << "--------------------------------------";
    return 0;
}

