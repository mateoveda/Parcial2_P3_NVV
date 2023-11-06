#include "NodoProducto.h"

class ArbolProducto{
protected:
  NodoProducto *root;
private:
  Producto search(Producto dato, NodoProducto *r);
  bool searchB(Producto dato, NodoProducto *r);
  NodoProducto *put(Producto dato, NodoProducto *r);
  NodoProducto *remove(Producto dato, NodoProducto *r);
  NodoProducto *findMaxAndRemove(NodoProducto *r, bool *found);
  void preorder(NodoProducto *r);
  void inorder(NodoProducto *r);
  void postorder(NodoProducto *r);
  NodoProducto *espejito(NodoProducto *r);
  int contarPorNivel(int n, int nAct, NodoProducto *r);

public:
  ArbolProducto();

  void put(Producto dato);

  void putt(Producto dato, NodoProducto*r);

  Producto search(Producto dato);

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