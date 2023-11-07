#include "NodoProducto.h"
#include "cola.h"

int obtenerDeposito(NodoProducto* nodo, const std::string& nombreProducto, int numDeposito) {
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
