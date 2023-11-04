#include "Lista.h"
#include <iostream>
using namespace std;

int main(){
    Lista<int> lista;
    lista.insertarPrimero(25);
    lista.imprimir();
    lista.insertarUltimo(78);
    lista.imprimir();
    lista.insertar(1,-56);
    lista.imprimir();
    lista.insertar(2,25);
    lista.imprimir();
    lista.insertarUltimo(-125);
    lista.imprimir();
}