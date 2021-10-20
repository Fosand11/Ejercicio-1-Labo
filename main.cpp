#include "doble.hpp"

int menu(){
    int opcion = 0;
    cout << endl << "-------------------------Menu para hacer un pedido-------------------------" << endl;
    cout << endl << "1) Agregar un pedido." << endl;
    // cout << "2) Agregar una secuela." << endl;
    cout << "2) Mostrar cola de pedidos." << endl;
    // cout << "4) Mostrar saga de fin a inicio." << endl;
    cout << "3) Eliminar su pedido." << endl;
    // cout << "6) Buscar película." << endl;
    // cout << "7) Agregar película después de referencia." << endl;
    cout << "4) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble saga;
    
    bool continuar = true;
    Pedido p;
    Pedido pref;
    do{
        switch(menu()){
            case 1: //Agregar una precuela
                p = solicitarPedido();
                saga.insertFront(p);
                cout << "Su pedido fue almacenado correctamente!" << endl;
                break;
            // case 2: //Agregar una secuela
            //     p = solicitarPedido();
            //     saga.insertBack(p);
            //     cout << "Secuela almacenada exitosamente!" << endl;
            //     break;
            case 2: //Mostrar cola de pedidos
                saga.traversalForwardDirection();
                break;
            // case 4: //Mostrar saga de fin a inicio
            //     saga.traversalReverseDirection();
            //     break;
            case 3: //Eliminar un pedido
                if(saga.empty())
                    cout << "No hay pedidos para eliminar" << endl;
                else{
                    p = solicitarPedido();
                    saga.deleteItem(p);
                }
                break;
            // case 6: //Buscar una película
            //     if(saga.empty())
            //         cout << "No hay películas por buscar" << endl;
            //     else{
            //         p = solicitarPedido();
            //         cout << "Dicha película " << (saga.searchItem(p)?"SI":"NO");
            //         cout << " se encuentra en la saga." << endl;
            //     }
            //     break;
            // case 7: //Agregar una película después de referencia
            //     cout << "<Película a insertar>" << endl;
            //     p = solicitarPedido();
            //     cout << "<Película de referencia>" << endl;
            //     pref = solicitarPedido();
            //     saga.insertAfter(p, pref);
            //     cout << "Película almacenada exitosamente!" << endl;
            //     break;
            case 4: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
