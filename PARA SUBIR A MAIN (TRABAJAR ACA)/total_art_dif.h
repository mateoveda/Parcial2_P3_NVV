//contador de productos ---> contar nodos

#include "NodoProducto.h"

int contarNodos(NodoProducto* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return 1 + contarNodos(nodo->getLeft()) + contarNodos(nodo->getRight());
}