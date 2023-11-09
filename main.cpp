#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "ArbolProducto.h"
#include "Producto.h"
#define fore(i,a,b) for(int i=a; i<b; i++)
#define NOMBRE_ARCHIVO "C:/Users/Usuario/Desktop/Parcial2_P3_NVV/PARA SUBIR A MAIN (TRABAJAR ACÁ)/output/Inventariado Fisico.csv"
using namespace std;

/*
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

Comentarios:

Analisis de la 1:
funcion contar, que recorra toda la lista, y que cuente todos la cantidad de todos los nodos.

Analisis de la 2:
pida los datos del articulo y en base a eso devuelva la cantidad de articulos totales (trampa del profe)
Tiene que recorrer todo, no es un while.

Analisis de la 3:
ver cual es el minimo
void, que literalmente saca el listado (recorre todo)
hay que tener cuidado en sumar articulos que estan agregados dos veces.

analisis de la 4:
funcion entera, que simplemente retorne una suma;

analisis de la 5:
funcion 

CONSIDERACIONES:
1. Puede ser que haya dos articulos repetidos, para ese caso hay que crear una función que los unifique
respetando las cantidades de cada uno (sume por deposito).
2. Hay que tener un protocolo por si es un error, el articulo. (Mismo comportamiento que busqueda de articulos)
3. hay que ver como hacemos el indice.
4. hay que armar el algoritmo para que se ordene solito el arbol.

*/ 
void menu(ArbolProducto& arbol);

void minimoStock(ArbolProducto& arbol);

void minimoStockPorDeposito(ArbolProducto& arbol){
    cout<<"a\n";
};

int Stockindividual(ArbolProducto& arbol);

int StockindividualporDeposito(ArbolProducto& arbol);

void buscarPorMinimoStock(ArbolProducto& arbol);

void insertRecognitionTree(ArbolProducto& arbol);

int main(){
    ArbolProducto productos;
    insertRecognitionTree(productos);
    menu(productos);
    
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


void menu(ArbolProducto& arbol){
    char opcion = '0';
    cout<<"\t\t* * * * * * * * M E N U * * * * * * * *\n";
    cout<<"1. Ver la cantidad total de articulos diferentes.\n"
    <<"2. Ver la cantidad total de articulos. \n"
    <<"3. Ver el listado de articulos que estan en el minimo de stock.\n"
    <<"4. Listado de articulos que estan en el minimo de stock y por deposito.\n"
    <<"5. Stock individual de cada articulo.\n"
    <<"6. Stock individual de cada articulo segun deposito.\n"
    <<"7. Los articulos que igualan o superen determinada cantidad en stock\n"
    <<"8. Salir \n";
    cin>>opcion;
    switch (opcion)
    {
    case '1'://Ver la cantidad total de articulos diferentes.
        cout<<"La cantidad total de articulos diferentes es: "<<arbol.contarProductos()<<"\n";
        break;

    case '2'://Ver la cantidad total de articulos.
        cout<<"Cantidad total de articulos"<<arbol.contarnodos()<<"\n";
        break;
        
    case '3'://Ver el listado de articulos que estan en el minimo de stock.
        int n = 0;
        cout<<"Introducir el mínimo de stock que desea consultar: ";
        cin>>n;
        cout<<"Listado de articulos que están en el minimo de stock:\n";
        arbol.minStock(n);
        break;

    case '4'://Listado de articulos que estan en el minimo de stock y por deposito.
        cout<<"Listado de articulos que estan en el minimo de stock y por deposito:\n";
        //minimoStockPorDeposito(arbol);
        break;

    case '5'://Stock individual de cada articulo.
        string nombr =" ";
        cout<<"Dar el nombre del producto\n";
        cin>>nombr;
        cout<<"Stock individual de cada articulo\n";
        arbol.Stocks(nombr);
        break;

    case '6'://Stock individual de cada articulo segun deposito.
        string nombr;
        int deposito = 0;
        cout<<"Introducir el nombre del deposito:\n";
        cin>>nombr;
        cout<<"Introducir el numero de deposito\n";
        cin>>deposito;
        cout<<"Stock individual de cada articulo segun deposito es: "<< arbol.ObtenerDeposito(nombr, deposito);
        break; 

    case '7'://Los articulos que igualan o superen determinada cantidad en stock.
        int n;
        cout<<"Introducir el valor de la cantidad de stock que busca que los articulos superen: ";
        cin>>n;
        cout<<"Los articulos que igualan o superen determinada cantidad de stock\n";
        arbol.maxStock(n);
        break;

    case '8'://Salir.
        cout<<"Salir\n";
        break;  
    default:
    cout<<"Error. El valor ingresado es incorrecto, intente nuevamente\n";
        break;
    } 
}


//