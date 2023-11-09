#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "ArbolProducto.h"
#include "Producto.h"
//#include "min_stock_dep.h"
#define fore(i,a,b) for(int i=a; i<b; i++)
#define NOMBRE_ARCHIVO "C:/Users/Mateo/OneDrive/Escritorio/Parcial2_P3_NVV/Inventariado Fisico.csv"
using namespace std;

/*
//INCLUIR LAS FUNCIONES

#define NOMBRE_ARCHIVO "C:/Users/Usuario/Desktop/Parcial2_P3_NVV/PARA SUBIR A MAIN (TRABAJAR ACÁ)/output/Inventariado Fisico.csv"
//ACTUALIZAR UBICACION CUANDO SE PASE A MAIN
using namespace std;


//Declaracion de funciones
void insertRecognitionTree(ArbolProducto& arbol);


*/ 

void insertRecognitionTree(ArbolProducto& arbol);

int main(int argc, char** argv){
    string archivo= argv[argc-1];
    cout<<"ARCHIVO: "<<archivo<<endl;
    if(argc<3 || argc>5){
        cout<<"cantidad de argumentos no valida0\n";
    }else{
        ArbolProducto productos;
        insertRecognitionTree(productos);
        string arg = argv[1];
        cout<<arg<<endl;
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


    /*
    limite minimo de argumentos: 3
    lim max: 5
    si cumple, abris archivo, inicializas variables, llamas lo que necesites
    
    CASES ->arg 1
    -total_art_dif -> funcion propia
    -total_art -> funcion propia
    
    -max_stock -> necestias que el arg 2 no sea el archivo y sea siosi un entero (piso)
    -min_stock tiene dos opciones
        arg 2 es entero y arg 3 tiene que ser archivo -> prodcutos cuyo stock total es >= arg 2
        arg 2 sea entero, el 3 tambien, y el 4 sea el atchivo -> ahi el arg 3 es el deposito
    
    -stock
        arg 2 sea producto y el arg 3 sea el archivo -> stock total del producto
        arg 2 es prod y arg 3 es esntero y arg 4 es archivo -> stock del prod en el depo
    
    argc-> cantidad de arg
    argc-1 es la pos del archivo (o deberia)
    argv[] es el array de los argumentos
    archivo-> argv[argc-1]
    main-> argv[0]
    stoi(argv[2])

    if(3==argc-1)
    */
    
}
/*ArbolProducto productos;
    insertRecognitionTree(productos);
    
    interprete*/

void insertRecognitionTree(ArbolProducto& arbol) {
    ifstream archivo(NOMBRE_ARCHIVO);

    if (!archivo.is_open()) {
        cerr << "\nNo se pudo abrir el archivo." << endl;
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
            int deposito = columnas[i].empty() ? 0 : stoi(columnas[i]);
            nuevoProducto.depositos.encolar(deposito);
        }


            // Agregamos el artículo al árbol existente
            arbol.put(nuevoProducto);
        
    }
}
