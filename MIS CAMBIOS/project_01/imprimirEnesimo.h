#ifndef IMPRIMIR_ENESIMO_H
#define IMPRIMIR_ENESIMO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "articulo.h"

void imprimirEnesimo(const std::string& nombreArchivo, int n) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "\nNo se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    } else {
        std::cout << "\nArchivo abierto." << std::endl;
    }

    std::string linea;
    std::getline(archivo, linea); // Ignorar la primera línea que contiene los encabezados

    int contadorArticulos = 0;

    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string columna;
        std::vector<std::string> columnas;

        while (std::getline(ss, columna, ',')) {
            columnas.push_back(columna);
        }

        if (columnas.size() >= 5) {
            contadorArticulos++;

            if (contadorArticulos == n) {
                std::cout << "Enésimo artículo (" << n << "):" << std::endl;
                std::cout << "Código: " << columnas[1] << std::endl;
                std::cout << "Nombre: " << columnas[2] << std::endl;

                // Imprimir los depósitos, reemplazando cadenas vacías por 0
                std::cout << "Depósitos:" << std::endl;
                for (size_t i = 3; i < columnas.size(); ++i) {
                    std::string deposito = columnas[i];
                    if (deposito.empty()) {
                        deposito = "0";
                    }
                    std::cout << "Depósito " << i - 2 << ": " << deposito << std::endl;
                }

                break;
            }
        }
    }
}

#endif // IMPRIMIR_ENESIMO_H