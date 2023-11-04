#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_
#include <iostream>
#include "Nodo.h"
using namespace std;

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */

template <class T>
class Lista
{
private:
  Nodo<T> *inicio;

public:
  Lista();

  Lista(const Lista<T> &li);

  ~Lista();

  bool esVacia();

  int getTamanio();

  void insertar(int pos, T dato);

  void insertarPrimero(T dato);

  void insertarUltimo(T dato);

  void remover(int pos);

  T getDato(int pos);

  void reemplazar(int pos, T dato);

  void vaciar();

  void imprimir();

  void fnInvierte();
  
  void insertarAfter(int, T, T);

  void insertarAfter2(int, int);

  void concatenar(Lista<T> &lista2);

  void CambioInicio(int pos);
};

/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T>
Lista<T>::Lista() {
  inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T>
Lista<T>::Lista(const Lista<T> &li)
{
  inicio = li.inicio;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T>
Lista<T>::~Lista() {}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> // MATEO: Solo necesitamos saber si el Nodo de inicio apunta al vacío (NULL PTR)
bool Lista<T>::esVacia()
{
  return inicio == nullptr;
  /*
  Es igual a
  if(inicio==nullptr){
    return true;
  }else{
    return false;
  }
  */
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T>
int Lista<T>::getTamanio()
{
  /*
  podemos usar un contador que cuente la cantidad de veces que vamos cambiando de direcciones
  lo inicializamos con un auxiliar que en realidades un puntero, que comienza apuntando al inicio
  */
  Nodo<T> *aux = inicio;
  int tam = 0;
  /*
  Usamos While por que no queremos que haga una primera condicion, con un for necesitamos dsaber la cantidad
  */
  while (aux != nullptr)
  {
    aux = aux->getSiguiente();
    tam++;
  }
  return tam;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T>
void Lista<T>::insertar(int pos, T dato)
{
  Nodo<T> *aux = inicio;
  int posActual = 0;
  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->setDato(dato);
  // smart pointer es el nuevo programa de c++ para crear punteros
  if (pos == 0)
  {
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }
  while (aux != nullptr && posActual < pos - 1)
  {
    // siempre lo primero que tienen que programar es la condición que te permita salir del While
    aux = aux->getSiguiente();
    posActual++;
  }
  if (aux == nullptr)
  {
    throw 404; // esto hace que tire un error
  }

  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T>
void Lista<T>::insertarPrimero(T dato)
{
  insertar(0, dato);
}

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T>
void Lista<T>::insertarUltimo(T dato)
{
  Nodo<T> *aux = inicio;
  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->setDato(dato);

  if (aux == nullptr) // Null pointer
  {
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }

  while (aux->getSiguiente() != nullptr)
  {
    aux = aux->getSiguiente();
  }

  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T>
void Lista<T>::remover(int pos)
{
  Nodo<T> *aux = inicio, *aBorrar;
  int posActual = 0;
  if (pos == 0)
  {
    inicio = inicio->getSiguiente(); //se cambio un set por un get
    delete aux;
    return;
  }

  while (aux != nullptr && posActual < pos - 1)
  {
    aux = aux->getSiguiente();
    posActual++;
  }
  if (aux == nullptr)
  {
    throw 404;
  }

  aBorrar = aux->getSiguiente(); //Se cambió un set por un get
  aux->setSiguiente(aBorrar->getSiguiente());
  delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T>
T Lista<T>::getDato(int pos)
{
  Nodo<T> *aux = inicio, *aBorrar;
  int posActual = 0;

  while (aux != nullptr && posActual < pos)
  {
    aux = aux->getSiguiente();
    posActual++;
  }
  if (aux == nullptr)
  {
    throw 404;
  }

  return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T>
/*
void Lista<T>::reemplazar(int pos, T dato)
{
  Nodo<T> *aux = inicio, *aBorrar;
  int posActual = 0;

  while (aux != nullptr && posActual < pos)
  {
    aux = aux->getSiguiente();
    posActual++;
  }
  if (aux == nullptr)
  {
    throw 404;
  }

  aux->reemplazar();
}
*/
void Lista<T>::reemplazar(int pos, T dato) {
    Nodo<T> *aux= inicio;
    int posAct=0;

    while(aux!= nullptr && posAct<pos){
        aux= aux-> getSig();
        posAct++;
    }

    if(aux== nullptr){
        throw 404;
    }

    return aux-> setDato(dato);
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T>
void Lista<T>::vaciar()
{
  Nodo<T> *aux = inicio, *aBorrar;

  while (aux != nullptr)
  {
    aBorrar = aux;
    aux = aux->getSiguiente();
    delete aBorrar;
  }
  inicio = nullptr;
}

template <class T>
void Lista<T>::imprimir()
{
  Nodo<T> *aux = inicio;
  while (aux != nullptr)
  {
    std::cout << aux->getDato() << " -> ";
    aux = aux->getSiguiente();
  }
  std::cout << "NULL." << std::endl;
}

template <class T>
void Lista<T>::fnInvierte()
{
  Nodo<T> *aux = inicio, *ant = nullptr, *sig= inicio;

  if(esVacia()){
        return;
    }

    sig= sig-> getSiguiente();

    while(sig != nullptr){
        aux-> setSiguiente(ant);

        ant= aux;
        aux= sig;
        sig= sig-> getSiguiente();
    }
    aux-> setSiguiente(ant);
    inicio= aux;
}

template<class T>
void Lista<T>::insertarAfter2(int oldValue, int newValue){
  Nodo<T> *aux = inicio;
  int contador = 0;

  while(aux!=nullptr && contador < 2){
    if(aux->getDato() == oldValue){
      contador++;
    }
    aux = aux->getSiguiente();
  }
  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->setDato(newValue);
  nuevo->SetSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

/**
 * Reemplaza un dato con otro luego de las n repeticiones de otro dato
 * @tparam T
 * @param reemp dato a insertar
 * @param base dato a verificar las repeticiones
 * @param n cantidad de repeticiones del dato base
 */
template <class T> 
void Lista<T>::insertarAfter(int n, T base, T reemp){
    Nodo<T> *aux= inicio;
    int cont=0;

    while(aux!= nullptr){
        if(aux-> getDato() == base){
            cont++;
        }
        if(cont== n){
            break;
        }
        aux= aux-> getSiguiente();
    }

    if(aux== nullptr){
        throw 404;
    }

    Nodo<T> *nuevo= new Nodo<T>;
    nuevo-> setDato(reemp);
    nuevo-> setSiguiente(aux-> getSiguiente());
    aux-> setSiguiente(nuevo);
}
/*
template <class T> 
Lista<T> *unir(const Lista<T> &lisA, const Lista<T> &lisB) {//Explicación de la declaracion abajo
  int aux1, aux2;
  Nodo<T> *aux= lisA.inicio;
  if (*aux== nullptr){
        lisA.inicio= lisB.inicio;
    }
  aux1= lisA.getTamanio();
  aux2= lisB.getTamanio();
  lisA.insertarUltimo(lisB.inicio);
  return new Lista<T>(lisA);
}
*/


#endif // U02_LISTAS_LISTA_LISTA_H_

template <class T> 
void Lista<T>::CambioInicio(int pos){
  Nodo<T> *aux = inicio, *reemplazar;
  int posActual=0;
  if(pos==0){
    return;
  }
  while(aux != nullptr && posActual < pos-1){
    posActual++;
    aux = aux->getSiguiente();
  }
  reemplazar = aux->getSiguiente();
  if(aux==nullptr||reemplazar==nullptr){
    throw 404;
  }
  aux->setSiguiente(reemplazar->getSiguiente());
  reemplazar->setSiguiente(inicio);
  inicio=reemplazar;
}