#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#define U05_ARBOL_ARBOL_ARBOLBINARIO_H_

#include "NodoArbol.h"

template <class T> class ArbolBinario {
protected:
  NodoArbol<T> *root;
private:
  T search(T dato, NodoArbol<T> *r);
  bool searchB(T dato, NodoArbol<T> *r);
  NodoArbol<T> *put(T dato, NodoArbol<T> *r);
  NodoArbol<T> *remove(T dato, NodoArbol<T> *r);
  NodoArbol<T> *findMaxAndRemove(NodoArbol<T> *r, bool *found);
  void preorder(NodoArbol<T> *r);
  void inorder(NodoArbol<T> *r);
  void postorder(NodoArbol<T> *r);
  NodoArbol<T> *espejito(NodoArbol<T> *r);
  int contarPorNivel(int n, int nAct, NodoArbol<T> *r);

public:
  ArbolBinario();

  void put(T dato);

  void putt(T dato, NodoArbol<T>*r);

  T search(T dato);

  bool searchB(T dato);

  void remove(T dato);

  void preorder();

  void inorder();

  void postorder();

  ~ArbolBinario();

  bool esVacio();

  void print();

  void espejar();

  int contarPorNivel(int nivel);
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T> ArbolBinario<T>::ArbolBinario() {
  root=nullptr;
}

/**
 * Destructor del Arbol
 */
template <class T> ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T> T ArbolBinario<T>::search(T dato) {

  return search(dato,root);
}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T> bool ArbolBinario<T>::searchB(T dato) {

  return searchB(dato,root);
}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T> T ArbolBinario<T>::search(T dato, NodoArbol<T> *r) {
  
  if(r==nullptr){
    throw 404;//condicion base, si llego a esto que te tire un error
  }

  if(r->getDato()==dato){
    return r->getDato();
  }

  if(r->getDato()>dato){
    return(search(dato, r->getLeft()));
  }

  else{
    return(search(dato, r->getRight()));
  }
}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira unn false, y si esta un true
 * @param clave Valor a buscar
 * @return true o false
 */
template <class T> 
bool ArbolBinario<T>::searchB(T dato, NodoArbol<T> *r) {
  
  if(r==nullptr){
    return false;;//condicion base, si llego a esto que te tire un error
  }

  if(r->getDato()==dato){
    return true;
  }

  if(r->getDato()>dato){
    return(searchB(dato, r->getLeft()));
  }

  else{
    return(searchB(dato, r->getRight()));
  }
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T> void ArbolBinario<T>::put(T dato) {
  root=put(dato, root);
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */

template <class T>
NodoArbol<T> *ArbolBinario<T>::put(T dato, NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return new NodoArbol<T>(dato);
  }

  if (r->getDato() == dato)
  {
    throw 200;
  }

  if (r->getDato() > dato)
  {
    r->setLeft(put(dato, r->getLeft()));
  }
  else
  {
    r->setRight(put(dato, r->getRight()));
  }

  return r;
}



/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T>
void ArbolBinario<T>::remove(T dato){
  root = remove(dato, root);
}

template <class T>
NodoArbol<T> *ArbolBinario<T>::remove(T dato, NodoArbol<T> *r)
{
  NodoArbol<T> *aux;

  if (r == nullptr)
  {
    throw 404;
  }

  if (r->getDato() == dato)
  {

    if (r->getLeft() == nullptr && r->getRight() == nullptr)
    {
      delete r;
      return nullptr;
    }
    else if (r->getLeft() != nullptr && r->getRight() == nullptr)
    {
      aux = r->getLeft();
      delete r;
      return aux;
    }
    else if (r->getLeft() == nullptr && r->getRight() != nullptr)
    {
      aux = r->getRight();
      delete r;
      return aux;
    }
    else if (r->getLeft() != nullptr && r->getRight() != nullptr)
    {

      if (r->getLeft()->getRight() != nullptr)
      {
        // Aca tenemos que buscar el valor maximo
        bool found;
        aux = findMaxAndRemove(r->getLeft(), &found);
        aux->setRight(r->getRight());
        aux->setLeft(r->getLeft());
      }
      else
      {
        aux = r->getLeft();
        r->getLeft()->setRight(r->getRight());
      }
      delete r;
      return aux;
    }
  }
  else if (r->getDat() > dato)
  {
    r->setLeft(remove(dato, r->getLeft()));
  }
  else
  {
    r->setRight(remove(dato, r->getRight()));
  }

  return r;
}



template <class T>
NodoArbol<T> *ArbolBinario<T>::findMaxAndRemove(NodoArbol<T> *r, bool *found)
{
  NodoArbol<T> ret;
  *found = false;

  if (r->getRight() == nullptr)
  {
    *found = true;
    return r;
  }

  ret = findMaxAndRemove(r->getRight(), found);
  if (*found)
  {
    r->setRight(ret);
    *found = false;
  }

  return ret;
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T> bool ArbolBinario<T>::esVacio() { 
  return root == nullptr; 
  }

/**
 * Recorre un árbol en preorden
 */
template <class T>
void ArbolBinario<T>::preorder()
{
  preorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  std::cout << r->getDato() << " ";
  preorder(r->getLeft());
  preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template <class T>
void ArbolBinario<T>::inorder()
{
  inorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  inorder(r->getLeft());
  std::cout << r->getDato() << " ";
  inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template <class T>
void ArbolBinario<T>::postorder()
{
  postorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::postorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  postorder(r->getLeft());
  postorder(r->getRight());
  std::cout << r->getDato() << " ";
}

/**
 * Muestra un árbol por consola
 */
template <class T>
void ArbolBinario<T>::print()
{
  if (root != NULL)
    root->print(false, "");
}


/**
 * Permite espejar un arbol binario
 * 
*/
template <class T>
NodoArbol<T> *ArbolBinario<T>::espejito(NodoArbol<T> *r){
  if(!r){
    return nullptr;
  }
  NodoArbol<T> *aux = r->getLeft();
  r->setLeft(r->getRight());
  r->setRight(aux);

  //Aplico la recursividad
  espejito(r -> getLeft());
  espejito(r -> getRight());

  return r;
}
/*
aux = r -> right;
  r -> right = r -> left;
  r -> left = aux;
  delete aux;
  espejito(r -> left);
  espejito(r -> right);
*/

/**
 * Permite espejar un arbol binario
 * 
*/
template <class T>
void ArbolBinario<T>::espejar(){
  root = espejito(root);
}

template <class T> 
int ArbolBinario<T>::contarPorNivel(int nivel) {
    return contarPorNivel(nivel,0,root);
}

template <class T> 
int ArbolBinario<T>::contarPorNivel(int n, int nAct, NodoArbol<T> *r) {
    if(n==nAct){
        if(r!= nullptr){
            return 1;
        }
        else {
            return 0;
        }
    } else {
        if(nAct>n){
            return 0;
        } else if(r== nullptr){
            return 0;
        }
    }

    return contarPorNivel(n,nAct+1,r->getLeft()) + contarPorNivel(n,nAct+1,r->getRight());
}


#endif // U05_ARBOL_ARBOL_ARBOLBINARIO_H_

/*
Casos para borrar datos:
1. un extremo sin hijos (hoja)
2. lo borro pero tiene un hijo, entonces solo lo reemplazo y muevo la hoja
3. buscamos el mas grande de todo lo que esta a la izquierda
*/

