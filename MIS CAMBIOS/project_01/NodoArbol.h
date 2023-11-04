#ifndef U05_ARBOL_ARBOL_NODOARBOL_H_
#define U05_ARBOL_ARBOL_NODOARBOL_H_

#include <string.h>
#include <iostream>
using namespace std;

template <class T>
class NodoArbol
{
private:
  T dato;
  NodoArbol *left, *right;

public:
  NodoArbol()
  {
    left = nullptr;
    right = nullptr;
  }

  NodoArbol(T d)
  {
    dato = d;
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


#endif // U05_ARBOL_ARBOL_NODOARBOL_H_
