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
  void min_stock(NodoProducto* nodo, int n);
  int stock(NodoProducto* raiz, const std::string& nombreProducto);
  int obtenerDeposito(NodoProducto* nodo, const std::string& nombreProducto, int numDeposito);
  void max_stock(NodoProducto* nodo, int n);
  void minStockDepo(NodoProducto* nodo, int n, int depo);

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
  //std::cout<<"-------------"<<std::endl;
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
  std::cout<<"debug 5";
  
  if (r->getNombre() == dato.nombre)
  {
    std::cout<<"debug 6";
    return r;//despues sumar
  }
  std::cout<<"debug 7";

  if (r->getNombre() > dato.nombre)
  {
    std::cout<<"debug 10";
    r->setLeft(Put(dato, r->getLeft()));
  }
  else
  {
    std::cout<<"debug 11";
    r->setRight(Put(dato, r->getRight()));
    std::cout<<"debug 13";
  }
  std::cout<<"debug 14";

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
 * Muestra un árbol por consola
 */

void ArbolProducto::print()
{
  if (root != nullptr) //ANTES ERA NULL
  {
    root->printNodo();
  }
    
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
int ArbolProducto::total_art(NodoProducto* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    // Suma los depósitos del nodo actual
    int sumaActual = nodo->getStocktotal();

    // Suma los depósitos de los nodos izquierdo y derecho recursivamente
    int sumaIzquierda = total_art(nodo->getLeft());
    int sumaDerecha = total_art(nodo->getRight());

    // Devuelve la suma total
    return sumaActual + sumaIzquierda + sumaDerecha;
}

int ArbolProducto::contarnodos(){
  return contarNodos(root);
}

int ArbolProducto::contarNodos(NodoProducto* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return 1 + contarNodos(nodo->getLeft()) + contarNodos(nodo->getRight());
}

void ArbolProducto::minStock(int n){
    min_stock(root, n);
}

void ArbolProducto::min_stock(NodoProducto* nodo, int n) {
    if (nodo == nullptr) {
        return;
    }

    if (nodo->getStocktotal() <= n) {
        nodo->printNodo();
    }

    min_stock(nodo->getLeft(), n);
    min_stock(nodo->getRight(), n);
}

int ArbolProducto::Stocks(const std::string& nombreProducto){
  return stock(root, nombreProducto);
}

int ArbolProducto::stock(NodoProducto* raiz, const std::string& nombreProducto) {
    if (raiz == nullptr) {
        return 0;  // Si el árbol está vacío, retorna 0
    }

    // Realiza un recorrido en el árbol para encontrar el nodo con el nombre de producto especificado
    while (raiz != nullptr) {
        if (nombreProducto == raiz->getNombre()) {
            // Si se encuentra el producto, se suma el valor de sus depósitos
            return raiz->getStocktotal();
        } else if (nombreProducto < raiz->getNombre()) {
            raiz = raiz->getLeft();  // Se mueve hacia el subárbol izquierdo
        } else {
            raiz = raiz->getRight();  // Se mueve hacia el subárbol derecho
        }
    }

    // Si no se encuentra el producto, se retorna 0
    return 0;
}


int ArbolProducto::ObtenerDeposito(const std::string& nombreProducto, int numDeposito){
  return obtenerDeposito(root, nombreProducto, numDeposito);
}


int ArbolProducto::obtenerDeposito(NodoProducto* nodo, const std::string& nombreProducto, int numDeposito) {
    if (nodo == nullptr) {
        return -1; // Retorna -1 si no se encontró el producto
    }

    if (nodo->getNombre() == nombreProducto) {
        Producto producto = nodo->getDato();
        Cola<int> depositos = producto.depositos;
        int tamaño = 0;

        // Recorremos la cola para encontrar el depósito deseado
        int depSeleccionado = -1;
        bool encontrado = false;

        while (!depositos.esVacia() && tamaño < numDeposito) {
            depSeleccionado = depositos.desencolar();
            depositos.encolar(depSeleccionado);
            tamaño++;
            encontrado = true;
        }

        if (encontrado && tamaño == numDeposito) {
            return depSeleccionado;
        } else {
            return -1; // El número de depósito excede la cantidad de depósitos del producto
        }
    }

    // Búsqueda en los subárboles izquierdo y derecho
    int resultadoIzquierdo = obtenerDeposito(nodo->getLeft(), nombreProducto, numDeposito);
    if (resultadoIzquierdo != -1) {
        return resultadoIzquierdo;
    }

    int resultadoDerecho = obtenerDeposito(nodo->getRight(), nombreProducto, numDeposito);
    return resultadoDerecho;
}

void ArbolProducto::maxStock(int n){
  return max_stock(root, n);
}

void ArbolProducto::max_stock(NodoProducto* nodo, int n) {
    if (nodo == nullptr) {
        return;
    }

    if (nodo->getStocktotal() >= n) {
        nodo->printNodo();
    }

    max_stock(nodo->getLeft(), n);
    max_stock(nodo->getRight(), n);
}

void ArbolProducto::minStockDeposito(int n, int depo){
  minStockDepo(root,n,depo);
}

void ArbolProducto::minStockDepo(NodoProducto* nodo, int n, int depo){
  if (nodo == nullptr)
  {
    return;
  }

  inorder(nodo->getLeft());
  if(nodo->getStockdeposito(depo)<n+1){
    nodo -> printNodo();
  }
  inorder(nodo->getRight());
}
