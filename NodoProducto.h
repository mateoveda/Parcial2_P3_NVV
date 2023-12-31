#pragma once
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
  /**
   *Es el constructor por defecto 
  */
  NodoProducto()
  {
    left = nullptr;
    right = nullptr;
  }


  /**
   * Es el constructor en donde yo ya le paso una estructura producto. 
  */
  NodoProducto(Producto& d)
  {
    dato.grupo = d.grupo; //COMENTARIO
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

  
  /**
 * Retorna el nombre de como se llama el dato en el arbol
 * @return nombre
 */
  string getNombre() const{
    return this-> dato.nombre;
  }

  /**
 * Retorna el grupo donde está el dato en el arbol
 * @return nombre
 */
  string getGrupo() const{
    return this-> dato.grupo; //COMENTARIO
  }

  /**
 * Retorna el nombre de cuál es el código de ese producto
 * @return codigo
 */
  string getCodigo() const{
    return this -> dato.codigo;
  }

  /**
 * Retorna el stock total del nodo, o sea la suma total de la cola
 * @return int suma
 */
  int getStocktotal(){
    int suma = 0;
    Cola<int> aux;
    while(!dato.depositos.esVacia()){
        int auxi = dato.depositos.desencolar();
        suma += auxi;
        aux.encolar(auxi);
    }
    while(!aux.esVacia()){
      dato.depositos.encolar(aux.desencolar());
    }
    return suma;
  }

  /**
 * Retorna el stock del nodo en determinado depósito
 * @return int aux.desencolar()
 */
  int getStockdeposito(int pos){
    int posA = 0;
    Cola<int> aux;
    while(!dato.depositos.esVacia()){
      int au = dato.depositos.desencolar();
      aux.encolar(au);
    }

    while (!aux.esVacia() && posA < pos) { //posA <= pos
        dato.depositos.encolar(aux.desencolar());
        posA++;
    }
    int auxi = aux.desencolar();
    dato.depositos.encolar(auxi);
    while(!aux.esVacia()){
      dato.depositos.encolar(aux.desencolar());
    }
    return auxi;
  }

  /**
 * Es un void, que agarra una estructura tipo Producto
 * y simplemente se la asigna al nodo.
 */
  void setDato(Producto& d)
  {
    this->dato.nombre = d.nombre;
    this->dato.grupo = d.grupo;
    this->dato.codigo = d.codigo;
    while(!d.depositos.esVacia()){
        this->dato.depositos.encolar(d.depositos.desencolar());
    }
    
  }

  /**
 * Devuelve el puntero de la raíz derecha
 * @return right
 */
  NodoProducto *getRight() const
  {
    return right;
  }

  /**
 * introduce el puntero de la raíz derecha
 */
  void setRight(NodoProducto *r)
  {
    this->right = r;
  }

  /**
 * Devuelve el puntero de la raíz izquierda
 * @return left
 */
  NodoProducto *getLeft() const
  {
    return left;
  }

  /**
 * Introduce el puntero de la raíz izquierda
 */
  void setLeft(NodoProducto *l)
  {
    this->left = l;
  }

  /**
 * Imprime los datos del nodo.
 */
  void printNodo(){
    cout<<"Grupo: "<<this->getGrupo()<<"\n";
    cout<<"Nombre: "<<this->getNombre()<<"\n";
    cout<<"Codigo: "<<this->getCodigo()<<"\n";
    cout<<"Stock total: "<<this->getStocktotal()<<"\n";
    cout<<"\n";
  }

  /**
 * Imprime los datos del nodo.
 */
  void printNodoDepo(int n){
    cout<<"Grupo: "<<this->getNombre()<<"\n";
    cout<<"Nombre: "<<this->getNombre()<<"\n";
    cout<<"Codigo: "<<this->getCodigo()<<"\n";
    cout<<"Stock total: "<<this->getStocktotal()<<"\n";
    cout<<"Stock total por deposito "<<n+1<<": "<<this->getStockdeposito(n)<<"\n";  //n-1 tendria que ser n?
    cout<<"\n";
  }
};