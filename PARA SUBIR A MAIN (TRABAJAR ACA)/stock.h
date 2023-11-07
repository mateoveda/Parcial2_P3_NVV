#include "NodoProducto.h"

int stock(NodoProducto* raiz, const std::string& nombreProducto) {
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
