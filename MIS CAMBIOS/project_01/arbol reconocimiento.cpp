#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "lista.h"
#include "arbol.h"
#include "articulo.h"
#include "imprimirEnesimo.h"
#define NOMBRE_ARCHIVO "C:/Users/Usuario/Desktop/Parcial2_P3_NVV/MIS CAMBIOS/project_01/output/Inventariado Fisico.csv"
using namespace std;


//Declaracion de funciones
void insertRecognitionTree(ArbolBinario<string>& arbol);


int main() {
    int n;
    cout<<"imprimir n-esimo ---> ";
    cin>>n;
    imprimirEnesimo(NOMBRE_ARCHIVO, n);
    return 0;
}

void insertRecognitionTree(ArbolBinario<string>& arbol) {
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

        // Verificar si hay al menos 5 columnas
        if (columnas.size() >= 5) {
            // Las primeras dos columnas son strings
            string columna2 = columnas[1];
            string columna3 = columnas[2];

            // Creamos un objeto de tipo Articulo
            Articulo nuevoArticulo;
            nuevoArticulo.codigo = columna2;
            nuevoArticulo.nombre = columna3;

            // Almacenamos los depósitos en la cola
            for (size_t i = 3; i < columnas.size(); ++i) {
                int deposito = columnas[i].empty() ? 0 : stoi(columnas[i]);
                nuevoArticulo.depositos.push(deposito);
            }


            // Agregamos el artículo al árbol existente
            //arbol.put(nuevoArticulo.);
        }
    }
}