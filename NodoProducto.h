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

  T getDato() const
  {
    return dato;
  }

  void setDato(T d)
  {
    this->dato = d;
  }

  NodoArbol *getRight() const
  {
    return right;
  }

  void setRight(NodoArbol *r)
  {
    this->right = r;
  }
  NodoArbol *getLeft() const
  {
    return left;
  }

  void setLeft(NodoArbol *l)
  {
    this->left = l;
  }

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

  };