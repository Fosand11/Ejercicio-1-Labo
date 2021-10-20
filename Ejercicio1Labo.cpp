#include <iostream>
#include <string>

using namespace std;

struct nodo{
    int carnet;
    string name;
    string lastName;
    int age;
    int telephoneNum;
    string email;

    nodo *sig;
};

class ListaSimple{
    private:
        nodo *pInicio;

    public:
        ListaSimple();

        void insRegistro(void);
        void insInicio(int, string, string, int, int, string);
        void mostrarLista(void);
        void eligeRegistro(void);
        bool eliminar(int datoB);

};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

void ListaSimple::insRegistro(void)
{
    int carnet;
    string name;
    string lastName;
    int age;
    int telephoneNum;
    string email;

    cout << "Inserte el carnet del estudiante: ";
    cin >> carnet;
    cout << "Inserte el nombre del estudiante: ";
    cin >> name;
    cout << "Inserte el apellido del estudiante: ";
    cin >> lastName;
    cout << "Inserte la edad del estudiante: ";
    cin >> age;
    cout << "Inserte el numero de telefono del estudiante: ";
    cin >> telephoneNum;
    cout << "Inserte el correo electronico del estudiante: ";
    cin >> email;

    insInicio(carnet, name, lastName, age, telephoneNum, email); 
}

void ListaSimple::insInicio(int carnet, string name, string lastName, int age, int telephoneNum, string email)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->carnet = carnet;
    nuevo->name = name;
    nuevo->lastName = lastName;
    nuevo->age = age;
    nuevo->telephoneNum = telephoneNum;
    nuevo->email = email;

    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::mostrarLista(void)
{
    nodo *saltarin;

    cout << endl;
    saltarin =pInicio;
    while(saltarin != NULL){
        cout << "El numero de carnet es: " << saltarin->carnet << endl;
        cout << "El nombre del estudiante es: " << saltarin->name << endl;
        cout << "El apellido del estudiante es: " << saltarin->lastName << endl;
        cout << "La edad del estudiante es: " << saltarin->age << endl;
        cout << "El numero de telefono del estudiante es: " << saltarin->telephoneNum << endl;
        cout << "El correo del estudiante es: " << saltarin->email << endl;
        saltarin = saltarin->sig;
    }
}

void ListaSimple::eligeRegistro(void)
{
    int dato = 0;
    bool aux;
    cout << "Ingrese el carnet del estudiante que desea declinar: " << endl; 
    cin >> dato;
    aux = eliminar(dato);
    if (aux)
    {
        cout << "EL REGISTRO DEL ESTUDIANTE FUE ELIMINADO" << endl << endl;
    }else{
        cout << "EL NUMERO DE CARNET QUE INGRESO NO SE ENCUENTRA" << endl << endl;
    }
     
}

bool ListaSimple::eliminar(int datoB)
{
    if(!pInicio){
        return false;
    } else {
        nodo *s = pInicio, *p;
        if(s->carnet == datoB) {
            pInicio = pInicio->sig;
            delete s;
            return true;

        } 
        else {
            while (s->sig && s->sig->carnet != datoB)
                s = s->sig;

                if (!s->sig)
                {
                    return false;
                } else {
                    p = p->sig;
                    s->sig = s->sig->sig;
                    delete p;
                    return true;
                }
        }
    }
}

int main(void)
{
    int aux = 0;
    bool ciclo = true;

    ListaSimple objListaSimple;
    
    while ( ciclo == true )
    {
        cout << "------------------------Registro de estudiantes------------------------" << endl;
        cout << "MENU" << endl;
        cout << "1- Ingrese un nuevo estudiante " << endl;
        cout << "2- Eliminar un estudiante " << endl;
        cout << "3- Mostrar todos los estudiants " << endl;
        cout << "4- Salir " << endl;

        cin >> aux;
        
        switch (aux)
        {
            case 1:
                objListaSimple.insRegistro();
                break;
            case 2:
                objListaSimple.eligeRegistro();
                break;
            case 3:
                objListaSimple.mostrarLista();
                break;
            case 4:
                cout << "Gracias " << endl;
                ciclo = false;
                break;        
            default:
                cout << "El dato ingresado es erroneo, por favor intentar nuevamente " << endl;
                break;
        }

    }    
    return 0;
}

