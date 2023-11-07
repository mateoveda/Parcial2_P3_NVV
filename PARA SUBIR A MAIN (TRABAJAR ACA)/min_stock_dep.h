#include <iostream>
#include <string>
#include <vector>
#include "NodoProducto.h"

void min_stock_dep(NodoProducto* nodo, int n, std::vector<std::pair<std::string, std::string>>& productos) {
    if (nodo == nullptr) {
        return;
    }

    // Verificar si el depósito seleccionado tiene una cantidad menor o igual a 'n'
    while (!nodo->getDato().depositos.esVacia()) {
        int cantidad = nodo->getDato().depositos.desencolar();
        if (cantidad <= n) {
            productos.push_back(std::make_pair(nodo->getNombre(), nodo->getCodigo()));
            break;  // Solo se agrega una vez si cumple la condición
        }
    }

    // Recorrer los subárboles
    min_stock_dep(nodo->getLeft(), n, productos);
    min_stock_dep(nodo->getRight(), n, productos);
}