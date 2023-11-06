#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>
#include <queue>

struct Articulo {
    string codigo;
    string nombre;
    queue<int> depositos; // Usamos una cola para almacenar los depósitos
};

#endif
