//Sumatoria de stocks individuales de cada articulo ---> suma recursiva

#include <iostream>
#include "NodoProducto.h"

int total_art(NodoProducto* nodo) {
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
