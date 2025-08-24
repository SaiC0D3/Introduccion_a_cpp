// las COLAS son listas de nodos de informaci�n caracterizados por tener un frente y un final, los elementos se ingresan por el final y salen por el frente (en orden de 'llegada', FIFO)
// cada nodo (struct) contine 2 campos, uno con el dato (cualquier tipo de info) y otro un puntero del mismo tipo struct que apunta al nodo anterior (el primero y �ltimo apuntan NULL)
// para las colas es importante tener referencia del frente y final, por lo que se requieren 2 punteros m�s para ello
// el 'frente' y 'fin' de la cola (punteros que apuntan al primer y �ltimo nodo) son las cabecillas de la lista, as� como en pilas es la cima (estos cambian su apunte seg�n nodo)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

struct Nodo{
	int dato; // informaci�n, ene este caso una cola de n�meros
	Nodo *siguiente; // puntero que apunta a la dm de otro nodo igual (por eso del mismo tipo)
};

/* INSERTAR ELEMENTO: estos pasos se realizan tantas veces como elementos se ingresen
	-> Primero: inicializar los punterso Nodo fin y frente en NULL y reservar espacio de memoria para un nuevo nodo con 'new'
	-> Segundo: asignar el nuevo nodo al dato ingresado (el dato guardarlo en el nodo actual) e inicializar en NULL al puntero siguiente del nodo para que quede como fin
	-> Tercero: asignar los punteros frente y fin al nuevo nodo creado con la informaci�n, para referenciar la cola
		-> caso 1: cola vac�a => ambos apuntan al nuevo nodo creado pero que est� vac�o (apuntando a NULL)
		-> caso 2: cola con +1 elemento => frente apunta al nuevo nodo creado y fin apunta al nodo siguiente (�ltimo en ser ingresado) que apunta a NULL
*/
void insertarCola(Nodo *&, Nodo *&, int); // dos nodos por referencia, ya que el nodo de frente y fin van cambiando constantemente (trabajamos directamente con la dm del Nodo)
bool cola_vacia(Nodo *); // para los 2 casos del �ltimo paso, no por referencia, ya que solo compara con el puntero

/* QUITAR ELEMENTO: estos pasos se realizan tantas veces como elementos se eliminen
	-> Primero: guardamos en una variable por referencia n el valor del dato del primer o �nico Nodo
	-> Segundo: crear un puntero nodo auxiliar y asignarlo al frente de la cola (para que ambos apunten al nodo a eliminar que est� al frente o �ltima posici�n ingresada) 
	-> Tercero: eliminar con 'delete' al elemento en el frente de la cola (el primero en ingresarse)
		-> caso 1: cola con 1 elemento => tenemos a frente, fin y aux apuntando al mismo nodo, as� que reapuntamos frente y fin a NULL y eliminamos aux con 'delete'
		-> caso 2: cola con +2 elemento => reapuntamos frente al siguiente nodo
*/
void quitarCola(Nodo *&, Nodo *&, int &); // el dato por referencia, ya que el dato a eliminar va ir cambiando constantemente (no recibe un valor si no que lo va sacando de cada nodo)

// para mostrar la cola o lista solo se necesita el puntero que apunta al primer elemento, mostrar la info en �l e ir reapuntando el frente al siguiente hasta que coincida con el fin
void mostrarCola(Nodo *); // sin referencia para no afectar la cola en la memoria al reducir los elementos al ir avanzando

int main(){
	setlocale(LC_ALL, "Spanish");
	
	Nodo *frente = NULL; // punteros para referenciar el comienzo y fin de la cola (primer y �ltimo elemento)
	Nodo *fin = NULL;
	
	int num; // reutilizamos la variable num ya que su valor cambia
	char ans; // para determinar cuando quiera dejar de ingresar elementos
	
	do{
		cout<<"Ingrese un n�mero: "; cin>>num;
		insertarCola(frente, fin, num); // se van ingresando los n�meros en cada dato y se van referenciando el inicio y fin
		
		cout<<"�Desea ingresar otro elemento? (s/n): "; cin>>ans;
	} while(ans == 's' || ans == 'S');
	
	// en caso de las colas s� que se puede 'recorrer' para mostrar sus elementos sin eliminarlos (adem�s solo se muestrar�an el primer y �ltimo sacados)
	cout<<"\nMostrando elementos de la cola: ";
	mostrarCola(frente);
	
	while(frente != NULL){ // mientras el frente no apunte a lo mismo que fin (NULL) o sea hayan elementos en ella...
		quitarCola(frente, fin, num); // ...se elimina el nodo del frente y se muestra
	}
	// ahora se mostrar� vac�a
	//mostrarCola(frente);
	
	getch();
	return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){ 
	Nodo *nuevo_nodo = new Nodo(); // reservamos espacio para el nodo
	nuevo_nodo->dato = n; // le asignamos el valor ingresado al dato del nodo
	nuevo_nodo->siguiente = NULL; // dejamos apuntando a NULL el �ltimo nodo ingresado como fin de la cola
	
	if(cola_vacia(frente)){ // si est� vac�a la cola el inicio y final son nulos (apuntan al mismo nodo vac�o creado)
		frente = nuevo_nodo;
	}
	else{ // si tiene elementos la cola, el primer nodo ingresado queda con frente y el �ltimo nodo queda con fin
		frente->siguiente = nuevo_nodo; 
	}
	fin = nuevo_nodo; // como se debe asignar en ambos ahorramos c�digo pon�endolo fuera
}

bool cola_vacia(Nodo *frente){ // no hace falta que sea por referencia ya que solo verifica, no asigna nada al puntero frente
	/* // si el frente apunta al NULL inicial quiere decir que no hay nodos ingresados
	if(frente == NULL)
		return true;
	else
		return false;
	*/
	return (frente == NULL)? true : false; // el mismo c�digo en comentario pero m�s simple
}

void quitarCola(Nodo *&frente, Nodo *&fin, int &n){
	n = frente->dato; // copiamos el dato del nodo a eliminar
	Nodo *aux = frente; // apuntamos el aux al nodo de frente
	
	if(frente == fin){ // si est� vac�a el inicio y fin apuntan a NUll y se elimina aux
		frente = NULL;
		fin = NULL;
	}
	else{ // si hay elementos, se mueve el frente al siguiente y se elimina al anterior con el aux
		frente = frente->siguiente;
	}
	
	delete aux;
}

void mostrarCola(Nodo *frente){
//	Nodo *aux = frente; en caso de ser par�metro por referencia, para no perder la cola original
    while(frente != NULL){
        cout<<frente->dato<<" ";
        frente = frente->siguiente; // instrucci�n para avanzar el frente hasta que coincida con el fin y mostrar cada dato en el frente temporal
    }
//	frente = aux;
}
