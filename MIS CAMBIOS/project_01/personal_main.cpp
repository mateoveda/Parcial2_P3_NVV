#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "lista.h"
#include "arbol.h"
#define NOMBRE_ARCHIVO "C:/Users/Usuario/Desktop/Parcial2_P3_NVV/MIS CAMBIOS/project_01/output/datos.csv"
using namespace std;

struct Node {
    ArbolBinario<int> grupos;
    ArbolBinario<string> nombres;
    ArbolBinario<string> ids;
};

Lista<Node> dataList;

void insertData(const string& grupos, const string& nombres, const string& ids) {
    Node newNode;

    newNode.grupos.put(stoi(grupos));  // stoi convierte string a int
    newNode.nombres.put(nombres);
    newNode.ids.put(ids);
    dataList.insertarUltimo(newNode);
}

int main() {
    ifstream file(NOMBRE_ARCHIVO);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }    else{cout<<"Archivo abierto.";}

    string line;
    getline(file, line);  // Leer la primera línea que contiene encabezados (grupos,nombres,id)
    while (getline(file, line)) {
        stringstream ss(line);
        string grupos, nombres, ids;

        getline(ss, grupos, ',');
        getline(ss, nombres, ',');
        getline(ss, ids, ',');

        insertData(grupos, nombres, ids);
    }

    file.close();

    // estan los datos en la lista dataList, cada nodo contiene un árbol para grupos, nombres e IDs
    // ya esta todo preparado para realizar operaciones con estos datos.

    return 0;
}