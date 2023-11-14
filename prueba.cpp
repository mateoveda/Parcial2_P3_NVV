#include <iostream>
#include "ArbolProducto.h"
using namespace std;

int main(){
    ArbolProducto toby;
    Producto to, ma, pa;
    string aux;
    int auxi;
    cout<<"codigo: ";
    cin>>aux;
    to.codigo = aux;
    cout<<"nombre: ";
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

    cout<<"codigo: ";
    cin>>aux;
    ma.codigo = aux;
    cout<<"nombre: ";
    cin>>aux;
    ma.nombre = aux;
    for(int i = 0; i < 5; i++){
        cout<<"entero N: "<<i<<endl;
        cin>>auxi;
        ma.depositos.encolar(auxi);
    }
    toby.put(ma);

    cout<<"codigo: ";
    cin>>aux;
    pa.codigo = aux;
    cout<<"nombre: ";
    cin>>aux;
    pa.nombre = aux;
    for(int i = 0; i < 5; i++){
        cout<<"entero N: "<<i<<endl;
        cin>>auxi;
        pa.depositos.encolar(auxi);
    }
    toby.put(pa);
    toby.inorder();
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