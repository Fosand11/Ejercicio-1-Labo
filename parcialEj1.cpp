#include <iostream>

using namespace std;

void ordenar(int*, int*, int*);

int main(void)
{
    int a = 0, b=0, c=0;
    cout << "INGRESE SUS 3 ARGUMENTOS (NUMEROS):" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    ordenar(&a, &b, &c);
    cout <<"Su mayor numero es: " << a << endl;
    cout <<"Su numero mediano es: " << b << endl;
    cout <<"Su menor numero es: " << c << endl;
    return 0;
}

void ordenar(int *mayor, int *med, int *menor){
    int aux = 0;
    int aux2 = 0;

    if(*mayor > *med && *mayor > *menor){
        *mayor = *mayor;
        if(*med > *menor){
            *med = *med;
            *menor = *menor;
        } else{
            aux = *med;
            *med = *menor;
            *menor = aux;
        }
    }

    if(*med > *mayor && *med > *menor){
        aux = *mayor;
        *mayor = *med;
        *med = aux;
        if(*med > *menor){
            *med = *med;
            *menor = *menor;
        } else {
            aux = *med;
            *med = *menor;
            *menor = aux;
        }
    }

    if(*menor > *mayor && *menor > *med){
        aux = *mayor;
        *mayor = *menor;
        aux2 = *med;
        *med = aux;
        *menor = aux2;

        if(*med > *menor){
            *med = *med;
            *menor = *menor;
        } else {
            aux = *med;
            *med = *menor;
            *menor = aux;
        }
    }
};