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

int main(int argc, char** argv){
    clock_t begin;
    begin = clock();

    cout << "Comenzando a medir Tiempo\n" << "\n";

    ArbolProducto productos;
    string archivo = argv[argc-1];
    int tamanioArchivo=0;

    if(argc<3 || argc>5){

        if(argc==1){
            printHelp();

        }else{cout<<"cantidad de argumentos no valida\n";}

    }else{

        cout<<"Se abrio el archivo: "<<archivo<<"\n";
        insertRecognitionTree(productos, archivo, tamanioArchivo);
        string arg = argv[1];
        string nombre;
        int lim, depo;

        if(arg == "-total_art_dif" || arg == "-total_art"){

            if(argc != 3){

                cout<<"Argumentos no válidos"<<"\n";
                
            }else if(arg == "-total_art_dif"){

                cout<<"La cantidad total de articulos diferentes es: "<<productos.contarnodos()<<"\n";

            }else if(arg == "-total_art"){

                cout<<"La cantidad total de articulos es: "<<productos.contarProductos()<<"\n";

            }

        }else if(arg == "-max_stock"){

            lim = stoi(argv[2]);
            cout<<"Los productos cuyo stock es igual o supera los "<<lim<<" articulos son: "<<"\n";
            productos.maxStock(lim);

        }else if(arg == "-min_stock"){

            if(argc == 5){

                lim = stoi(argv[2]);
                depo = stoi(argv[3]);

                if(depo<1 || tamanioArchivo-3 < depo){

                    cout<<"El numero de deposito ingresado es incorrecto, los depositos empiezan de 1 hasta "<<tamanioArchivo-3<<"\n";

                }else{
                    cout<<"Los productos cuyo stock es igual o supera los "<<lim<<" articulos en el deposito "<<depo<<" son: "<<"\n";
                    productos.minStockDeposito(lim,depo-1);
                }

            }else if(argc == 4){

                lim = stoi(argv[2]);
                cout<<"Los productos cuyo stock es menor o igual a "<<lim<<" articulos son: "<<"\n";
                productos.minStock(lim);

            }

        }else if(arg == "-stock"){

            if(argc == 5){

                nombre = argv[2];
                depo = stoi(argv[3]);
                
                if(depo<1 || tamanioArchivo-3 < depo){
                    cout<<"El numero de deposito ingresado es incorrecto, los depositos empiezan de 1 hasta "<<tamanioArchivo-3<<"\n";
                }else{
                    if(productos.ObtenerDeposito(nombre,depo)==-1){

                        cout<<"\tNo se encontro el producto: "<<nombre<<"\n";

                    }else{

                        cout<<"La cantidad de articulos: "
                        <<nombre<<" en el deposito "
                        <<depo<<" son: "<<productos.ObtenerDeposito(nombre,depo)<<"\n";
                    
                    }
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

    cout << "\nTiempo transcurrido ---> " << elapsed_secs << " segundos\n" << "\n";

    return 0;
}

void insertRecognitionTree(ArbolProducto& arbol, string nombreArchivo, int& tam) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {

        cout << "\nNo se pudo abrir el archivo." << "\n";
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

    string grupoAux;
    string columna1;
    string columna2;
    string columna3;
    while (getline(archivo, linea)) {

        istringstream ss(linea);
        string columna;
        vector<string> columnas; // Almacenar todas las columnas de una línea


        while (getline(ss, columna, ',')) {         // Leer todas las columnas de la línea

            columnas.push_back(columna);

        }


        // Las primeras columnas son strings

        if(columnas[0] != ""){

            columna1 = columnas[0];
            grupoAux = columna1;

        }else{columna1 = grupoAux;}

        columna2 = columnas[1];
        columna3 = columnas[2];

        // Creamos un objeto de tipo Producto
        Producto nuevoProducto;
        
        nuevoProducto.grupo = columna1; //SIN USO ACTUALMENTE / COMENTARIO
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
