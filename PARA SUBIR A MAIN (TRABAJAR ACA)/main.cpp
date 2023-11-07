#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "ArbolProducto.h"
#include "Producto.h"
//INCLUIR LAS FUNCIONES

#define NOMBRE_ARCHIVO "C:/Users/Usuario/Desktop/Parcial2_P3_NVV/PARA SUBIR A MAIN (TRABAJAR ACÁ)/output/Inventariado Fisico.csv"
//ACTUALIZAR UBICACION CUANDO SE PASE A MAIN
using namespace std;


//Declaracion de funciones
void insertRecognitionTree(ArbolProducto& arbol);


int main() {

    // INCLUIR EL MENU

    return 0;
}

void insertRecognitionTree(ArbolProducto& arbol) {
    ifstream archivo(NOMBRE_ARCHIVO);

    if (!archivo.is_open()) {
        cerr << "\nNo se pudo abrir el archivo." << endl;
        return;
    } else {
        cout << "\nArchivo abierto." << endl;
    }

    string linea;
    getline(archivo, linea); // Ignorar la primera línea que contiene los encabezados

    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string columna;
        vector<string> columnas; // Almacenar todas las columnas de una línea

        // Leer todas las columnas de la línea
        while (getline(ss, columna, ',')) {
            columnas.push_back(columna);
        }

        // Las primeras columnas son strings
        string columna2 = columnas[1];
        string columna3 = columnas[2];

        // Creamos un objeto de tipo Producto
        Producto nuevoProducto;
        nuevoProducto.codigo = columna2;
        nuevoProducto.nombre = columna3;

        // Almacenamos los depósitos en la cola
        for (size_t i = 3; i < columnas.size(); ++i) {
            int deposito = columnas[i].empty() ? 0 : stoi(columnas[i]);
            nuevoProducto.depositos.encolar(deposito);
        }


            // Agregamos el artículo al árbol existente
            arbol.put(nuevoProducto);
        
    }
}