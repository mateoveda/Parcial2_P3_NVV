#include <iostream>
using namespace std;

int main(){

}/*
vamos a querer balancearlo desde arriba hacia abajo.
primero buscamos la altura.
Vamos a decir que el nodo está balanceado si el resultado de la formula da -1, 0 o 1.
Si la rotacion es mayor a 1 se necesita una rotacion por el lado izquierdo,
si es menor a -1 se hace una rotacion por el lado derecho.
Hacemos una rotación, que sea cambiar la raiz
se guarda en un nodo auxiliar, en donde se guarda temporalmente la raiz, se posiciona la nueva raiz, 
en donde se cambia de lugar al nodo, hay que cuidar los punteros o simplemente ordenar nuevamente el nodo, 
podemos hacer en todo caso un metodo de ordenamiento que deje el arbol ordenadito, capaz leyendolo nuevamente y
volviendo a ordenarlo, no sé, que leyendo de x manera te lo genera, con un averiguar tamaño tenemos la raiz
en base a eso ordenamos y luego podemos hacer un procedimiento de dicha manera.

el de NodoArbolAVL se cambia el tamaño por 1, por que la verdad le estoy pasando un nodo.
*/