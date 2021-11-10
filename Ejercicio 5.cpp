#include <iostream>
#include <string>


using namespace std;

struct nodo{
    int id;
    string name;
    string breed;
    float weight;
    int age;
    nodo *sig;
};

class ListaCircSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaCircSimple();
        ~ListaCircSimple();
        void eliminarListaCircRec(nodo *);
        void insertaNodo(void);
        void insInicio(int id, string nombre, string raza, float peso, int edad);
        void elRegistro(void);
        bool eliminar(void);
        void searchRegis(void);
        void buscar(int id);
        
};

ListaCircSimple::ListaCircSimple(void)
{
    pInicio = NULL;
}

ListaCircSimple::~ListaCircSimple()
{
    cout << "Destructor ejecutándose" << endl;
    if(pInicio){
        eliminarListaCircRec(pInicio);
        pInicio = NULL;
    }
}

void ListaCircSimple::eliminarListaCircRec(nodo *p){
    if(p->sig != pInicio)
        eliminarListaCircRec(p->sig);
    delete p;
}

void ListaCircSimple::insertaNodo(void)
{
    int id;
    string name;
    string breed;
    float weight;
    int age;


    cout<< "REGISTRO DE MASCOTA EN VETERINARIA" <<endl;
    cout<< "Digite el id de su mascota: ";
    cin>> id;
    cout<< "Digite su nombre: ";
    cin>> name;
    cout<< "Digite la raza de su mascota: ";
    cin>> breed;
    cout<< "Digite el peso de su mascota: ";
    cin>> weight;
    cout<< "Digite la edad de su mascota: ";
    cin>> age;

    insInicio(id, name, breed, weight, age);
}

void ListaCircSimple::insInicio(int id, string nombre, string raza, float peso, int edad)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->id = id;
    nuevo->name = nombre;
    nuevo->breed = raza;
    nuevo->weight = peso;
    nuevo->age = edad;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;
        while(saltarin->sig != pInicio){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}

void ListaCircSimple::elRegistro(void)
    {
        int dato = 0;
        bool aux;
        cout << "Ingrese el id que quiere eliminar" << endl;
        cin >> dato;
        aux = eliminar(dato);
        if (aux)
        {
            cout<< "El registro de la mascota se elimino" <<endl << endl;
        }else{
            cout<< "El registro con el id digitado no existe" << endl << endl;
        }
    }

void ListaCircSimple::searchRegis(void)
    {
        int dato = 0;
        bool aux;
        cout<< "Ingrese el id que desea buscar: " << endl;
        cin>> dato;
        buscar(dato);
    }

bool ListaCircSimple::eliminar(int dato)
    {
        if (!pInicio){
            return false;
        } else {
            nodo *s = pInicio, *p;
            if(s->id == dato){
                pInicio = pInicio->sig;
                delete s;
                return true;
            } else {
                while (s->sig && s->sig->id != dato)
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

    void ListaCircSimple::buscar(int dato)
    {
        if (!pInicio)
        {
            cout<< "La lista esta vacia";
        } else {
            nodo *s = pInicio, *p;
            if(s->id == dato){
                pInicio = pInicio->sig;
                cout<< "id: " << pInicio->id <<endl;
                cout<< "nombre: "<< pInicio->name <<endl;
                cout<< "raza: "<< pInicio->breed <<endl;
                cout<< "peso: "<< pInicio->weight <<endl;
                cout<< "edad: "<< pInicio->age <<endl;
            } else{
                while (s->sig && s->sig->id != dato)
                s = s->sig;
                if (!s->sig)
                {
                    cout << "No encontre el registro" <<endl;
                } else {
                    p = p->sig;
                    s->sig = s->sig->sig;
                    cout << "id: " << s->id <<endl;
                    cout << "nombre: " << s->name <<endl;
                    cout << "raza: " << s->breed <<endl;
                    cout << "peso: " << s->weight <<endl;
                    cout << "edad: " << s->age <<endl;
                }
            }
        }
    }

    int main(void)
{
    bool continuar = true;
    int opcion = 0;
    ListaCircSimple objListaCircSimple;
    cout << endl;
    cout << "ADMINISTRACIÓN DE VETERINARIA" << endl << endl;
    do{
        cout << "Agregar una nueva mascota." << endl;
        cout << "Mostrar una mascota." << endl;
        cout << "Borrar una mascota." << endl;
        cout << "Salir." << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            objListaCircSimple.insertaNodo();
            cout << "El registro de su mascota fue un exito!" <<endl;
            break;
        case 2:
            objListaCircSimple.searchRegis();
            break;
        case 3:
            objListaCircSimple.elRegistro();
            break;
        case 4:
            continuar = false;
            break;        
        default:
            cout << "La opcion seleccionada no es valida, intente de nuevo." << endl;
            break;
        }
    } while (continuar);
     
     return 0;
}
    
