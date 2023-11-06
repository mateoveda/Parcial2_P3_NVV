#pragma oncea

#ifndef U03_PILAS_PILA_PILA_H_
#define U03_PILAS_PILA_PILA_H_
#include "nodo.h"

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Pila {
private:
  Nodo<T> *tope;
public:
  Pila();

  ~Pila();

  void push(T dato);

  T pop();

  bool esVacia();

  T peek();
};

/**
 * Constructor de la clase Pila
 * @tparam T
 */
template <class T> Pila<T>::Pila() {
  tope = nullptr;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Pila<T>::~Pila() {
  while(!esVacia()){
    pop();
  }
  delete tope;
}

/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Pila<T>::push(T dato) {
  Nodo<T> *nuevo;
  nuevo = new Nodo<T>;
  nuevo -> setDato(dato);

  nuevo -> setSiguiente(tope);//estaba dato reemplace por nuevo
  tope = nuevo;
}

/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> //Aca estamos obteniendo el dato y lo estamos sacando
T Pila<T>::pop() {
  if(esVacia()){
    throw 404;
  }
  T dato = tope->getDato();//estamos creando el dato, no creandolo como tal sino dandole un lugar distinto en la memoria
  Nodo<T> *aBorrar = tope;
  tope = tope->getSiguiente();
  delete aBorrar;
  return dato;
  
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Pila<T>::esVacia() {

  return tope==nullptr;
}
/**
 * Responde con el último elemento de la pila sin sacarlo
 * @tparam 
 * @return tope
 */
template <class T> T Pila<T>::peek() {
  if(esVacia()){
    throw 404;
  }
 
  return tope->getDato();
}



#endif // U03_PILAS_PILA_PILA_H_
