#include <iostream>
#include <string>
using namespace std;

void printHelp();

int main() {
    // Crear un string con el carácter '"'
    std::string miString = "Este es un string con comillas dobles (\") dentro.";
    
    // Imprimir el string
    std::cout << miString << std::endl;

    return 0;
}

void printHelp(){
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