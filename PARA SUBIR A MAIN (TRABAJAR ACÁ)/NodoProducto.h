#include <string.h>
#include <iostream>
#include "Producto.h"
using namespace std;

class NodoProducto
{
private:
  Producto dato;
  NodoProducto *left, *right;

public:
  NodoProducto()
  {
    left = nullptr;
    right = nullptr;
  }

  NodoProducto(Producto d)
  {
    dato.nombre = d.nombre;
    dato.codigo = d.codigo;
    while(!d.depositos.esVacia()){
        dato.depositos.encolar(d.depositos.desencolar());
    }
    left = nullptr;
    right = nullptr;
  }

  Producto getDato() const
  {
    return dato;
  }
  
  string getNombre() const{
    return this-> dato.nombre;
  }

  string getCodigo() const{
    return this -> dato.codigo;
  }

  int getStocktotal(){
    int suma = 0;
    int auxi;
    Cola<int> aux;
    while(!dato.depositos.esVacia()){
        auxi = dato.depositos.desencolar();
        suma += auxi;
        aux.encolar(auxi);
    }
    while(!aux.esVacia()){
        dato.depositos.encolar(aux.desencolar());
    }
    return suma;
  }

  void setDato(Producto d)
  {
    this->dato.nombre = d.nombre;
    this->dato.codigo = d.codigo;
    while(!d.depositos.esVacia()){
        this->dato.depositos.encolar(d.depositos.desencolar());
    }
  }

  NodoProducto *getRight() const
  {
    return right;
  }

  void setRight(NodoProducto *r)
  {
    this->right = r;
  }
  NodoProducto *getLeft() const
  {
    return left;
  }

  void setLeft(NodoProducto *l)
  {
    this->left = l;
  }

  void printNodo(){
    cout<<"Nombre: "<<this->getNombre()<<"\n";
    cout<<"Codigo: "<<this->getCodigo()<<"\n";
    cout<<"Stock total: "<<this->getStocktotal()<<"\n";

  }
/*
   void print(bool esDerecho, string identacion) {
    if (right != NULL) {
        right->print(true, identacion + (esDerecho ? "     " : "|    "));
    }
    cout << identacion;
    if (esDerecho) {
        cout << " /";
    } else {
        cout << " \\";
    }
    cout << "-- ";
    cout << dato << endl;
    if (left != NULL) {
        left->print(false, identacion + (esDerecho ? "|    " : "     "));
    }
}
*/
  };