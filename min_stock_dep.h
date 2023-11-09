#include <iostream>
#include <string>
#include <vector>
#include "NodoProducto.h"

void min_stock_dep(NodoProducto* nodo, int deposit_number, int n, std::vector<std::pair<std::string, std::string>>& productos) {
    if (nodo == nullptr) {
        return;
    }

    // Verificar si el número de depósito actual coincide con el número proporcionado
    if (nodo->getDato().numeroDeposito == deposit_number) {
        // Si el depósito actual coincide, verificar si tiene una cantidad menor o igual a 'n'
        while (!nodo->getDato().depositos.esVacia()) {
            int cantidad = nodo->getDato().depositos.desencolar();
            if (cantidad <= n) {
                productos.push_back(std::make_pair(nodo->getDato().nombre, nodo->getDato().codigo));
                break;  // Solo se agrega una vez si cumple la condición
            }
        }
    }

    // Continuar la búsqueda en subárboles izquierdo y derecho
    min_stock_dep(nodo->getLeft(), deposit_number, n, productos);
    min_stock_dep(nodo->getRight(), deposit_number, n, productos);
}