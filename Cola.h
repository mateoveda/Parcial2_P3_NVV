#pragma once

#ifndef U04_COLAS_COLA_COLA_H_
#include "Nodo.h"
#define U04_COLAS_COLA_COLA_H_
/*
PARA APUNTAR CON EL SET LO QUE VA ENTRE () ES UN PUNTERO
*/

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Cola {
private:
Nodo<T> *tope;
Nodo<T> *fondo;
public:
  Cola();

  ~Cola();

  void encolar(T dato);

  T desencolar();

  bool esVacia();

  void peek();

  void encolarConPrioridad(const T &elemento, int prioridad);//.

  void EncolarConPrioridad(T dato, int prioridad);
};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> Cola<T>::Cola() {
  tope=nullptr;
  fondo=nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> Cola<T>::~Cola() {
  while(fondo!=nullptr){
    desencolar();
  }
  delete fondo;
  delete tope;
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Cola<T>::encolar(T dato) {
  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->setDato(dato);
  nuevo->setSiguiente(nullptr);

  if(esVacia()){
    tope=nuevo;
  }else{
    fondo->setSiguiente(nuevo);
  }
  fondo=nuevo;
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Cola<T>::desencolar() {
  if(esVacia()){
    throw 404;
  }
  T dato=tope->getDato();
  Nodo<T> *aBorrar=tope;
  tope=tope->getSiguiente();

  if(tope==nullptr){
    fondo=nullptr;
  }

  delete aBorrar;
  return dato;

}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Cola<T>::esVacia() {
  return fondo==nullptr;
}

template <class T> void Cola<T>::peek() {
  if(esVacia()){
    throw 404;
  }
  return tope->getDato(); 
}

#endif // U04_COLAS_COLA_COLA_H_
