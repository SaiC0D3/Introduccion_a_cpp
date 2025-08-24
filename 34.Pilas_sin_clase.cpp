// las PILAS son recipientes con nodos de información, los cuales se sacan en orden inverso a como se ingresaron (LIFO)...
// ...es decir, el primer elemento que sacamos es el último que se ingresó a la pila (como una pila de platos, se ingresan uno sobre otro)
// cada nodo (struct) contine 2 campos, uno con el dato (cualquier tipo de info) y otro un puntero del mismo tipo struct que apunta al nodo anterior (el primero apunta NULL)
// es como un arreglo de estructuras pero que cada elemento contiene un campo que apunta a la dm donde se halla el siguiente elemento (están enlazados)
// la 'cima' de la pila (puntero pila apuntando al último nodo) es la cabeza de la lista, con ella es que existe la pila y podemos trbajarla (esta cambia su apunte según nodo)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

struct Nodo{
	int dato; // información, ene este caso una pila de números
	Nodo *siguiente; // puntero que apunta a la dm de otro nodo igual (por eso del mismo tipo)
};

/* INSERTAR ELEMENTO: estos pasos se realizan tantas veces como elementos se ingresen
	-> Primero: inicializar un puntero tipo Nodo (pila) en NULL (como los contadores en 0) y reservar la memoria para almacenar un nuevo nodo (crear variable puntero Nodo) con 'new'
	-> Segundo: asginar o rellenar el valor para dato en el Nodo
	-> Tercero: asignar al campo siguiente el puntero pila inicializado en NULL
	-> Cuarto: asignar al puntero pila al puntero Nodo con el dato lleno y que apunta a NULL (así el siguiente nodo ingresado queda delante del anterior o 'sobre')
	Así: pila->[dato|*sig]->NULL
*/
void insertarPila(Nodo *&, int); // un nodo por referencia, ya que los nodos enlazados van a estar cambiando constantemente (trabajamos directamente con la dm del Nodo)

/* QUITAR ELEMENTO: estos pasos se realizan tantas veces como elementos se eliminen
	-> Primero: crear un puntero Nodo auxiliar que apunte a pila (al nodo en la cima)
	-> Segundo: guardamos en una variable por referencia n el valor del dato del Nodo auxiliar
	-> Tercero: apuntar a pila (la cima) al Nodo siguiente del auxiliar
	-> Cuarto: eliminar el Nodo auxiliar con 'delete' (de esta forma la cima queda como el elemento siguiente o debajo y se elimina el nodo anterior como aux sin dejar a pila apuntando a nada)
*/
void quitarPila(Nodo *&, int &); // el dato por referencia, ya que el dato a eliminar va ir cambiando constantemente (no recibe un valor si no que lo va sacando de cada nodo)

int main(){
	setlocale(LC_ALL, "Spanish");
	
	Nodo *pila = NULL; // un puntero nodo vacío que luego va a servir para asignárselo al primer nodo creado y luego apuntar al nodo recién ingresado (finaliza apuntando a la cima)
	
	int num, total; // reutilizamos la variable num ya que su valor cambia
	
	cout<<"Digite cuántos números desea ingresar: "; cin>>total;
	
	for(int i=0; i<total; i++){
		cout<<"\nIngrese un número: "; cin>>num;
		insertarPila(pila, num); // se van ingresando los números en cada dato y se van enlazando los nodos
	}
	
	// la única forma de mostrar los elementos de la pila es al momento de ir eliminándolos, ya que no se puede 'recorrer'
	
	cout<<"\nSacando elementos de la pila: ";
	while(pila != NULL){ // al ir quitando nodos, pila va a terminar apuntando a NULL (así que minetras hayan nodos por quitar...)
		quitarPila(pila, num); //...quitamos el elemento en la cima
		cout<<num<<" "; // mostramos el dato del nodo eliminado para corroborar el LIFO
	}
	
	getch();
	return 0;
}

void insertarPila(Nodo *&pila, int n){ // por cada elemento recibe un nodo y un dato
	Nodo *nuevo_nodo = new Nodo(); // reserva de espacio para el nodo
	nuevo_nodo->dato = n; // asignación del dato al nodo
	nuevo_nodo->siguiente = pila; // no a NULL directamente proque debe enlazarse al anterior cada vez
	pila = nuevo_nodo; // pila al principio apunta NULL, después apunta al nodo recién ingresado
}

void quitarPila(Nodo *&pila, int &n){
	Nodo *aux = pila; // creamos un puntero nodo que apunte al último nodo de la pila (cima)
	n = aux->dato; // copiamos el dato de la cima en el nodo aux (por eso n es por referencia, porque toma el valor del dato actual)
	pila = aux->siguiente; // movemos la 'cima' de la pila al siguiente nodo
	delete aux; // eliminamos el nodo aux que contiene la info de la anterior cima
}
