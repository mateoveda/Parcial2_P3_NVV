#include <iostream>
#include "ArbolProducto.h"
using namespace std;

int main(){
    ArbolProducto toby;
    NodoProducto tob;
    Producto to;
    string aux;
    int auxi;
    cout<<"codigo:\n";
    cin>>aux;
    to.codigo = aux;
    cout<<"nombre:\n";
    cin>>aux;
    to.nombre = aux;
    for(int i = 0; i < 5; i++){
        cout<<"entero N: "<<i<<endl;
        cin>>auxi;
        to.depositos.encolar(auxi);
    }
    //tob.setDato(to);
    toby.put(to);
    
    toby.print();
}

/*
    Producto prueba;
    int opcion;
    prueba.nombre = "Lola";
    prueba.codigo = "ibguiwrnuifdsbfiuds";
    for(int i = 0; i < 5; i++){
        prueba.depositos.encolar(i+1);
    }
    NodoProducto oficial(prueba);
    
    cout<<"los datos son: \n";
    cout<<oficial.getNombre()<<endl;
    cout<<oficial.getCodigo()<<endl;
    cout<<oficial.getStocktotal()<<endl;
    cout<<"Introducir el numero para saber el valor de x deposito en stock: \n";
    cin>>opcion;
    cout << oficial.getStockdeposito(opcion-1)<<endl;
    cout<<"Ahora usando lo que invente:\n";
    Producto lolo;
    lolo.nombre = "Lola";
    lolo.codigo = "ibguiwrnuifdsbfiuds";
    for(int i = 0; i < 5; i++){
        lolo.depositos.encolar(i+1);
    }
    //oficial.sumarNodo(lolo);
    cout<<"prueita: "<<oficial.getNombre()<<endl;

*/