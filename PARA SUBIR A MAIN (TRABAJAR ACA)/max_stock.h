#include <iostream>
#include "NodoProducto.h"

void max_stock(NodoProducto* nodo, int n) {
    if (nodo == nullptr) {
        return;
    }

    if (nodo->getStocktotal() >= n) {
        cout << "Nombre: " << nodo->getNombre() << ", Código: " << nodo->getCodigo() << std::endl;
    }

    max_stock(nodo->getLeft(), n);
    max_stock(nodo->getRight(), n);
}
