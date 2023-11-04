#include <iostream>
#include "Lista.h"
#include "ArbolBinario.h"
#define fore(i,a,b) for(int i=a; i<b; i++)
using namespace std;

/*


Comentarios:

Analisis de la 1:
funcion contar, que recorra toda la lista, y que cuente todos la cantidad de todos los nodos.

Analisis de la 2:
pida los datos del articulo y en base a eso devuelva la cantidad de articulos totales (trampa del profe)
Tiene que recorrer todo, no es un while.

Analisi de la 3:
ver cual es el minimo
void, que literalmente saca el listado (recorre todo)
hay que tener cuidado en sumar articulos que estan agregados dos veces.

analisis de la 4:
funcion entera, que simplemente retorne una suma;

analisis de la 5:
funcion 


*/ 

void menu();

int totalArticulos();

int totalArticulosdiferentes();

void minimoStock();

void minimoStockPorDeposito();

int Stockindividual();

int StockindividualporDeposito();

void buscarPorMinimoStock();

int main(){
    Lista<ArbolBinario<int>> lista;
    menu();
}

void menu(){
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
        cout<<"La cantidad total de articulos diferentes es: "<<totalArticulosdiferentes()<<"\n";
        break;

    case '2'://Ver la cantidad total de articulos.
        cout<<"Cantidad total de articulos"<<totalArticulos()<<"\n";
        break;
        
    case '3'://Ver el listado de articulos que estan en el minimo de stock.
        cout<<"Listado de articulos que están en el miimo de stock:\n";
        minimoStock();
        break;

    case '4'://Listado de articulos que estan en el minimo de stock y por deposito.
        cout<<"Listado de articulos que estan en el minimo de stock y por deposito:\n";
        minimoStockPorDeposito();
        break;

    case '5'://Stock individual de cada articulo.
        cout<<"Stock individual de cada articulo\n";
        break;

    case '6'://Stock individual de cada articulo segun deposito.
        cout<<"Stock individual de cada articulo segun deposito\n";
        break; 

    case '7'://Los articulos que igualan o superen determinada cantidad en stock.
        cout<<"Los articulos que igualan o superen determinada cantidad de stock\n";
        break;

    case '8'://Salir.
        cout<<"Salir\n";
        break;  
    default:
    cout<<"Error. El valor ingresado es incorrecto, intente nuevamente\n";
        break;
    } 
}