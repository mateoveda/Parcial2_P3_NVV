#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "ArbolProducto.h"
#include "Producto.h"
#define fore(i,a,b) for(int i=a; i<b; i++)
using namespace std;

//ARTÍCULO NO IDENTIFICADO EN BASE DE DATOS

void printHelp();

void insertRecognitionTree(ArbolProducto& arbol, string nombreArchivo);

int main(int argc, char** argv){
    ArbolProducto productos;
    string archivo = argv[argc-1];
    if(argc<3 || argc>5){
        if(argc==1){
            printHelp();
        }else{
        cout<<"cantidad de argumentos no valida0\n";
        }
    }else{
        cout<<archivo<<endl;
        insertRecognitionTree(productos, archivo);
        string arg = argv[1];
        string nombre;
        int lim, depo;
        if(arg == "-total_art_dif" || arg == "-total_art"){
            if(argc != 3){
                cout<<"Argumentos no válidos"<<endl;
            }else if(arg == "-total_art_dif"){
                cout<<productos.contarProductos()<<endl;
            }else if(arg == "-total_art"){
                cout<<productos.contarnodos()<<endl;
            }
        }else if(arg == "-max_stock"){
            lim = stoi(argv[2]);
            productos.maxStock(lim);
        }else if(arg == "-min_stock"){
            if(argc == 5){
                lim = stoi(argv[2]);
                depo = stoi(argv[3]);
                productos.minStockDeposito(lim, depo);
            }else if(argc == 4){
                lim = stoi(argv[2]);
                productos.minStock(lim);
            }
        }else if(arg == "-stock"){
            if(argc == 5){
                nombre = argv[2];
                depo = stoi(argv[3]);
                productos.ObtenerDeposito(nombre,depo);
            }else if(argc == 4){
                nombre = argv[2];
                productos.Stocks(nombre);
            }
        }
    }    
}

void insertRecognitionTree(ArbolProducto& arbol, string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "\nNo se pudo abrir el archivo." << endl;
        return;
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
                int deposito = columnas[i].empty() ? 0 : stoi(columnas[i]); //antes era stoi
                nuevoProducto.depositos.encolar(deposito);
            }
            // Agregamos el artículo al árbol existente
            arbol.put(nuevoProducto);
        
    }
}

void printHelp(){
    cout << "help\n";
    cout<<"1. *Cantidad de Articulos:*"
<<"\n   - `-total_art_dif`: Cantidad total de articulos diferentes."
<<"\n   - `-total_art`: Cantidad total de articulos.\n"
<<"\n3. *Busqueda por Cotas:*"
<<"\n   - `-min_stock_dep` [n],[deposito]: Listado de articulos con cantidad n o menos de stock segun un deposito."
<<"\n   - `-min_stock` [n]: Listado de articulos con cantidad n o menos de stock."
<<"\n   - `-max_stock` [n]: Listado de aquellos articulos cuyo stock es igual o supera el numero n.\n"
<<"\n4. *Busqueda por Nombres:*"
<<"\n   - `-stock` [nombre_articulo]: El stock total del articulo ingresado como argumento."
<<"\n   - `-stock_dep` [nombre_articulo],[deposito]: El stock del articulo en un deposito.\n";
}