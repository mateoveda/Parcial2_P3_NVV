#include <iostream>
#include "Cola.h"
using namespace std;

struct Producto{
    string nombre;
    string codigo;
    Cola<int> depositos;
};