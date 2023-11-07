#include <iostream>
#include "NodoProducto.h"

void min_stock(NodoProducto* nodo, int n) {
    if (nodo == nullptr) {
        return;
    }

    if (nodo->getStocktotal() <= n) {
        cout << "Nombre: " << nodo->getNombre() << ", Código: " << nodo->getCodigo() << endl;
    }

    min_stock(nodo->getLeft(), n);
    min_stock(nodo->getRight(), n);
}