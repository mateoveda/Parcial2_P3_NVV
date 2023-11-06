#include "NodoProducto.h"

class ArbolProducto{
protected:
  NodoProducto *root;
private:
  string search(Producto dato, NodoProducto *r);
  bool searchB(Producto dato, NodoProducto *r);
  NodoProducto *put(Producto dato, NodoProducto *r);
  NodoProducto *remove(Producto dato, NodoProducto *r);
  NodoProducto *findMaxAndRemove(NodoProducto *r, bool *found);
  void preorder(NodoProducto *r);
  void inorder(NodoProducto *r);
  void postorder(NodoProducto *r);
  int contarPorNivel(int n, int nAct, NodoProducto *r);

public:
  ArbolProducto();

  void put(Producto dato);

  void putt(Producto dato, NodoProducto*r);

  string search(Producto dato);

  bool searchB(Producto dato);

  void remove(Producto dato);

  void preorder();

  void inorder();

  void postorder();

  ~ArbolProducto();

  bool esVacio();

  void print();

  int contarPorNivel(int nivel);
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
ArbolProducto::ArbolProducto() {
  root=nullptr;
}

/**
 * Destructor del Arbol
 */
ArbolProducto::~ArbolProducto() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
string ArbolProducto::search(Producto dato) {

  return search(dato,root);
}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
 bool ArbolProducto::searchB(Producto dato) {

  return searchB(dato,root);
}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
 string ArbolProducto::search(Producto dato, NodoProducto *r) {
  
  if(r==nullptr){
    throw 404;//condicion base, si llego a esto que te tire un error
  }

  if(r->getNombre()==dato.nombre){
    return r->getNombre();
  }

  if(r->getNombre()>dato.nombre){
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
 
bool ArbolProducto::searchB(Producto dato, NodoProducto *r) {
  
  if(r==nullptr){
    return false;;//condicion base, si llego a esto que te tire un error
  }

  if(r->getNombre()==dato.nombre){
    return true;
  }

  if(r->getNombre()>dato.nombre){
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
 void ArbolProducto::put(Producto dato) {
  root=put(dato, root);
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */


NodoProducto *ArbolProducto::put(Producto dato, NodoProducto *r)
{
  if (r == nullptr)
  {
    return new NodoProducto(dato);
  }

  if (r->getNombre() == dato.nombre)
  {
    throw 200;
  }

  if (r->getNombre() > dato.nombre)
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

void ArbolProducto::remove(Producto dato){
  root = remove(dato, root);
}


NodoProducto *ArbolProducto::remove(Producto dato, NodoProducto *r)
{
  NodoProducto *aux;

  if (r == nullptr)
  {
    throw 404;
  }

  if (r->getNombre() == dato.nombre)
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
  else if (r->getNombre() > dato.nombre)
  {
    r->setLeft(remove(dato, r->getLeft()));
  }
  else
  {
    r->setRight(remove(dato, r->getRight()));
  }

  return r;
}



/**
 * Informa si un árbol esta vacío
 * @return
 */
 bool ArbolProducto::esVacio() { 
  return root == nullptr; 
  }

/**
 * Recorre un árbol en preorden
 */

void ArbolProducto::preorder()
{
  preorder(root);
  std::cout << std::endl;
}


void ArbolProducto::preorder(NodoProducto *r)
{
  if (r == nullptr)
  {
    return;
  }

  std::cout << r->getNombre() << " ";
  preorder(r->getLeft());
  preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */

void ArbolProducto::inorder()
{
  inorder(root);
  std::cout << std::endl;
}


void ArbolProducto::inorder(NodoProducto *r)
{
  if (r == nullptr)
  {
    return;
  }

  inorder(r->getLeft());
  std::cout << r->getNombre() << " ";
  inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */

void ArbolProducto::postorder()
{
  postorder(root);
  std::cout << std::endl;
}


void ArbolProducto::postorder(NodoProducto *r)
{
  if (r == nullptr)
  {
    return;
  }

  postorder(r->getLeft());
  postorder(r->getRight());
  std::cout << r->getNombre() << " ";
}

/**
 * Muestra un árbol por consola
 */

void ArbolProducto::print()
{
  if (root != NULL)
    root->printNodo();
}

 
int ArbolProducto::contarPorNivel(int nivel) {
    return contarPorNivel(nivel,0,root);
}

 
int ArbolProducto::contarPorNivel(int n, int nAct, NodoProducto *r) {
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