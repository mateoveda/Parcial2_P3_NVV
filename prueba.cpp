#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "NodoProducto.h"
using namespace std;

int main(int argc, char **argv){

    cout << "La cantidad de argumentos es:\n";
    for(int i = 0; i < argc; i++){
        cout << "Argumento " << i << ": " << argv[i] <<endl;
    }

    /*
    Producto prueba;
    prueba.nombre = "Lola";
    prueba.codigo = "ibguiwrnuifdsbfiuds";
    for(int i = 0; i < 5; i++){
        prueba.depositos.encolar(i);
    }
    NodoProducto oficial(prueba);

    cout<<"los datos son: \n";
    cout<<oficial.getNombre()<<endl;
    cout<<oficial.getCodigo()<<endl;
    cout<<oficial.getStocktotal()<<endl;

    cout<<"Ahora usando lo que invente:\n";
    oficial.printNodo();
    */
}