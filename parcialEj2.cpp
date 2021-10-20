#include <iostream>

using namespace std;

int sumaRec(void);

int main()
{
    int total = 0;
    total = sumaRec();
    cout << "El total de su sumatoria es: " << total << endl;
    return 0;
}

int sumaRec(void)
{
    int a;
    cout << "Ingrese un numero, para finalizar ingrese -1" << endl;
    cin >> a;
    if(a == -1)
    {
        return 0;
    } else {
        return (a + sumaRec());
    }
}

