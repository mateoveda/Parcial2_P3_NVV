#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "ArbolProducto.h"
#include "Producto.h"
#define fore(i,a,b) for(int i=a; i<b; i++)
using namespace std;

void printHelp();

void insertRecognitionTree(ArbolProducto& arbol, string nombreArchivo, int& tam);

//void menu(int argc, char** argv);

int main(int argc, char** argv){
    clock_t begin;
    begin = clock();

    cout << "Comenzando a medir Tiempo\n" << endl;
    //INICIO TIMER
    
    /*
    #include <iostream>
#include <ctime>

using namespace std;


int main(){
    clock_t begin;
    begin = clock();

    cout << "Comenzando a medir Tiempo\n" << endl;

    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end-begin) / CLOCKS_PER_SEC;

    cout << "Tiempo transcurrido ---> " << elapsed_secs << " segundos\n" << endl;

    return 0;
}

    */
    ArbolProducto productos;
    string archivo = argv[argc-1];
    int tamanioArchivo=0;

    if(argc<3 || argc>5){

        if(argc==1){
            printHelp();

        }else{cout<<"cantidad de argumentos no valida\n";}

    }else{

        cout<<archivo<<endl;
        insertRecognitionTree(productos, archivo, tamanioArchivo);
        string arg = argv[1];
        string nombre;
        int lim, depo;

        if(arg == "-total_art_dif" || arg == "-total_art"){

            if(argc != 3){

                cout<<"Argumentos no válidos"<<endl;
                
            }else if(arg == "-total_art_dif"){

                cout<<productos.contarnodos()<<endl;

            }else if(arg == "-total_art"){

                cout<<productos.contarProductos()<<endl;

            }

        }else if(arg == "-max_stock"){

            lim = stoi(argv[2]);
            productos.maxStock(lim);

        }else if(arg == "-min_stock"){

            if(argc == 5){

                lim = stoi(argv[2]);
                depo = stoi(argv[3]);

                if(depo<1){

                    cout<<"El numero de deposito ingresado es incorrecto, los depositos empiezan de 1 en adelante\n";

                }else{productos.minStockDeposito(lim,depo-1);}

            }else if(argc == 4){

                lim = stoi(argv[2]);
                productos.minStock(lim);

            }

        }else if(arg == "-stock"){

            if(argc == 5){

                nombre = argv[2];
                depo = stoi(argv[3]);

                if(productos.ObtenerDeposito(nombre,depo)==-1){

                    cout<<"\tNo se encontro el producto: "<<nombre<<"\n";

                }else{

                    cout<<"La cantidad de articulos: "
                    <<nombre<<" en el deposito "
                    <<depo<<" son: "<<productos.ObtenerDeposito(nombre,depo)<<endl;
                    
                    }

            }else if(argc == 4){

                nombre = argv[2];

                if(productos.Stocks(nombre)==-1){

                    cout<<"\tNo se encontro el producto: "<<nombre<<"\n";

                }else{

                    cout<<"La cantidad de articulos: "<<
                    nombre<<" son: "<<productos.Stocks(nombre)<<"\n";

                }
            }
        }else{cout<<"\n\t-- Comando no reconocido --\n\n";}
    }
    
    //FIN TIMER

    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end-begin) / CLOCKS_PER_SEC;

    cout << "Tiempo transcurrido ---> " << elapsed_secs << " segundos\n" << endl;

    return 0;
}

/*
2. filtrar que no den más que 5 o n depositos.
3. verificar sumar depositos

*/

void insertRecognitionTree(ArbolProducto& arbol, string nombreArchivo, int& tam) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {

        cout << "\nNo se pudo abrir el archivo." << endl;
        return;

    }
    string linea;

    //encontrar tamanio maximo del vector

    if (getline(archivo, linea)) {

        istringstream ss(linea);
        string columna;
        vector<string> columnas;

        while (getline(ss, columna, ',')) {

            columnas.push_back(columna);
            
        }

        tam = columnas.size(); //constante
    }


    while (getline(archivo, linea)) {

        istringstream ss(linea);
        string columna;
        vector<string> columnas; // Almacenar todas las columnas de una línea

        while (getline(ss, columna, ',')) {         // Leer todas las columnas de la línea

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

            int roca = columnas.size();

            if(roca < tam){

                nuevoProducto.depositos.encolar(0);

            }
            // Agregamos el artículo al árbol existente
            arbol.put(nuevoProducto);
    }
}

void printHelp(){ //LISTA DE COMANDOS

    cout<<"\n1. *Cantidad de Articulos:*"
<<"\n   - `-total_art_dif`: Cantidad total de articulos diferentes."
<<"\n   - `-total_art`: Cantidad total de articulos.\n"
<<"\n3. *Busqueda por Cotas:*"
<<"\n   - `-min_stock_dep` [n],[deposito]: Listado de articulos con cantidad n o menos de stock segun un deposito."
<<"\n   - `-min_stock` [n]: Listado de articulos con cantidad n o menos de stock."
<<"\n   - `-max_stock` [n]: Listado de aquellos articulos cuyo stock es igual o supera el numero n.\n"
<<"\n4. *Busqueda por Nombres:*"
<<"\n   - `-stock` [nombre_articulo]: El stock total del articulo ingresado como argumento."
<<"\n   - `-stock_dep` [nombre_articulo],[deposito]: El stock del articulo en un deposito.\n"
<<"\n";
}