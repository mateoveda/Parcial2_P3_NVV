#ifndef ARTICULO_H
#define ARTICULO_H

#include <iostream>
#include "cola.h"
using namespace std;

struct Producto{
    string nombre;
    string codigo;
    Cola<int> depositos; // Usamos una cola para almacenar los depósitos
};

#endif