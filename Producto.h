#pragma once
#include <iostream>
#include "Cola.h"
using namespace std;

struct Producto{
    string grupo; //COMENTARIO
    string nombre;
    string codigo;
    Cola<int> depositos;
};