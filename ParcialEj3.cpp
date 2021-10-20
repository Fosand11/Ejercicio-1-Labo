#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class listSimp{

    private:
        nodo *pInicio;
    
    public:
        listSimp();
        void insertNodo(void);
        void insInicio(int);
        void mayEdad(void);
};

listSimp::listSimp(void)
{
    pInicio = NULL;
}

void listSimp::insertNodo(void)
{
    int dato;

    cout << "Inserte una edad valida de una persona o Ctrl-z para terminar: ";
    while(cin >> dato){
        if (dato < 1 || dato > 99 )
        {
            cout << "Esa edad no es valida, por favor intente de nuevo" << endl;
            insertNodo();
        }
        
        insInicio(dato);
        cout << "Inserte una edad valida de una persona o Ctrl-z para terminar: ";
    }
}

void listSimp::insInicio(int dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void listSimp::mayEdad(void)
{
    nodo *edades;

    int mayor = 0;
    cout << endl;
    edades = pInicio;
    while(edades != NULL){
        if ( edades->dato > mayor && edades->dato <= 99 )
        {        
            mayor = edades->dato;
        }
        edades = edades->sig;
    }
    cout << "La persona que cuenta con la mayor edad es: " << mayor << endl; 
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRADOR DE EDADES" << endl << endl;

    listSimp objlistSimp;

    cout << "Insertar las edades de las personas: " << endl;
    objlistSimp.insertNodo();

    objlistSimp.mayEdad();

    cout << endl;
    return 0;
}
