#include "NodoProducto.h"

class ArbolProducto{
protected:
  NodoProducto *root;
private:
  string search(Producto dato, NodoProducto *r);
  bool searchB(Producto dato, NodoProducto *r);
  NodoProducto *Put(Producto& dato, NodoProducto *r);
  void preorder(NodoProducto *r);
  void inorder(NodoProducto *r);
  void postorder(NodoProducto *r);
  int total_art(NodoProducto* r);
  int contarNodos(NodoProducto* r);
  void min_stock(NodoProducto* r, int n);
  int stock(NodoProducto* r, const std::string& nombreProducto);
  int obtenerDeposito(NodoProducto* r, const std::string& nombreProducto, int numDeposito);
  void max_stock(NodoProducto* r, int n);
  void minStockDepo(NodoProducto* r, int n, int depo);

public:
  ArbolProducto();

  void put(Producto& dato);

  string search(Producto dato);

  bool searchB(Producto dato);

  void preorder();

  void inorder();

  void postorder();

  ~ArbolProducto();

  bool esVacio();

  void print();

  int contarProductos();

  int contarnodos();

  void minStock(int n);

  int Stocks(const std::string& nombreProducto);

  int ObtenerDeposito(const std::string& nombreProducto, int numDeposito);

  void maxStock(int n);

  void minStockDeposito(int n, int depo);

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
 void ArbolProducto::put(Producto& dato) {
  root=Put(dato, root);
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */


NodoProducto *ArbolProducto::Put(Producto& dato, NodoProducto *r)
{
  if (r == nullptr)
  {
    return new NodoProducto(dato);
  }  
  if (r->getNombre() == dato.nombre)
  {
    return r;//despues sumar
  }

  if (r->getNombre() > dato.nombre)
  {
    r->setLeft(Put(dato, r->getLeft()));
  }
  else
  {
    r->setRight(Put(dato, r->getRight()));
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

  r -> printNodo();
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
  r -> printNodo();
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
  r-> printNodo();
}

/**
 * cuenta la cantidad total de artículos del arbol
 */
int ArbolProducto::contarProductos(){
  return total_art(root);
}


/**
 * Cuenta la cantidad total de artículos del nodo y sus hijos
 */
int ArbolProducto::total_art(NodoProducto* r) {
    if (r == nullptr) {
        return 0;
    }

    // Suma los depósitos del nodo actual
    int sumaActual = r->getStocktotal();

    // Suma los depósitos de los nodos izquierdo y derecho recursivamente
    int sumaIzquierda = total_art(r->getLeft());
    int sumaDerecha = total_art(r->getRight());

    // Devuelve la suma total
    return sumaActual + sumaIzquierda + sumaDerecha;
}

int ArbolProducto::contarnodos(){
  return contarNodos(root);
}

int ArbolProducto::contarNodos(NodoProducto* r) {
    if (r == nullptr) {
        return 0;
    }
    return 1 + contarNodos(r->getLeft()) + contarNodos(r->getRight());
}

void ArbolProducto::minStock(int n){
    min_stock(root, n);
}

void ArbolProducto::min_stock(NodoProducto* r, int n) {
    if (r == nullptr) {
        return;
    }

    if (r->getStocktotal() <= n) {
        r->printNodo();
    }

    min_stock(r->getLeft(), n);
    min_stock(r->getRight(), n);
}

int ArbolProducto::Stocks(const std::string& nombreProducto){
  return stock(root, nombreProducto);
}

int ArbolProducto::stock(NodoProducto* r, const std::string& nombreProducto) {
    if (r == nullptr) {
        return -1;  // Si el árbol está vacío, retorna -1
    }

    // Realiza un recorrido en el árbol para encontrar el nodo con el nombre de producto especificado
    while (r != nullptr) {
        if (nombreProducto == r->getNombre()) {
          int aux = r->getStocktotal();
            // Si se encuentra el producto, se suma el valor de sus depósitos
            return aux;
        } else if (nombreProducto < r->getNombre()) {
            r = r->getLeft();  // Se mueve hacia el subárbol izquierdo
        } else {
            r = r->getRight();  // Se mueve hacia el subárbol derecho
        }
    }

    // Si no se encuentra el producto, se retorna -1
    return -1;
}


int ArbolProducto::ObtenerDeposito(const std::string& nombreProducto, int numDeposito){
  return obtenerDeposito(root, nombreProducto, numDeposito);
}


int ArbolProducto::obtenerDeposito(NodoProducto* r, const std::string& nombreProducto, int numDeposito) {
    if (r == nullptr) {
        return -1; // Retorna -1 si no se encontró el producto
    }

    while(r != nullptr){
      if (r->getNombre() == nombreProducto) {
        return r->getStockdeposito(numDeposito-1);
      }else if (nombreProducto < r->getNombre()) {
          r = r->getLeft();  // Se mueve hacia el subárbol izquierdo
      } else {
          r = r->getRight();  // Se mueve hacia el subárbol derecho
      }
    }
    
    return -1;
}

void ArbolProducto::maxStock(int n){
  return max_stock(root, n);
}

void ArbolProducto::max_stock(NodoProducto* r, int n) {
    if (r == nullptr) {
        return;
    }

    if (r->getStocktotal() >= n) {
        r->printNodo();
    }

    max_stock(r->getLeft(), n);
    max_stock(r->getRight(), n);
}

void ArbolProducto::minStockDeposito(int n, int depo){
  minStockDepo(root,n,depo);
}

void ArbolProducto::minStockDepo(NodoProducto* r, int n, int depo){
  
  if (r == nullptr){
    return;
  }
  if(r->getStockdeposito(depo)<n+1){
    r->printNodoDepo(depo);
  }
  minStockDepo(r->getLeft(),n,depo);
  minStockDepo(r->getRight(),n,depo);
}
