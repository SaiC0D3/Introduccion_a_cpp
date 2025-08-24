// los ÁRBOLES son estrcuturas de datos NO-LINEALES, es decir, no tienen una sola dirección como las listas que son estrcuturas de datos lineales
// los árboles se clasifican por su orden (número máx. de hijos), los árboles binarios de a lo más hijos son los más utilizados
// los ÁRBOLES BINARIOS se caracterizan por presentar una rama izquierda y una rama derecha (2 punteros tipo nodo que apuntan a los nodos hijos) además del campo de información
// son como listas (una lista es un AB de una sola diracción) con dos direcciones, que provienen de un nodo raíz y finalizan en nodos sin hijos (hojas), por lo que la forma de 'recorrerlos' puede variar
// los arboles binarios se dividen en ORDENADOS (ABO) y DESORDENADOS (AB), a su vez los ABO pueden ser simplemente ABO o AVL
// como cada nodo hijo de la ráiz principal pueden tener hijos, se dice que los AB(O) son estructuras RECURSIVAS en dónde cada nodo padre es un sub-árbol (izq. y der.)
// los ABO están ordenados de forma que los elementos menores a la raíz (por cada sub-árbol) van a la derecha y los mayores a la izquierda

/* PROPIEDADES DE UN ÁRBOL BINARIO:
	-> el puntero cabeza del árbol apunta a la raíz principal
	-> los ABO también se conocen como ABB (árbol binario de búsqueda)
	-> el primer nodo ingresado es la raíz principal
	-> cada nodo padre puede tener a lo más 2 hijos
	-> los nodos siguientes a la raíz o padre se llaman ramas
	-> el nivel de un AB comienza de 0 hasta el último nodo de la rama más larga
	-> los nodos sin hijos se llaman hojas (apountan a NULL)
	-> la altura de un AB se cuenta de abajo (último nivel) hacia arriba (raíz)
	-> la altura y nivel de un nodo del AB es desde el comienzo respectivo hasta el nodo
	-> los nodos que estén en el mismo nivel y compartan un padre son nodos hermanos
	-> la longitud de camino hacia un nodo son la cantidad de nodos desde la raíz hasta él
	-> los AVL son árboles binarios ordenados y equilibrados (ninguna rama es más larga que la otra por más de 1 nivel), en donde los nodos tienen coef. de equ. y se rotan
	-> en un ABO o ABB no pueden haber nodos repetidos (con igual dato), sí en el caso de un AVL
*/

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *izq; // puntero para la rama izquierda
	Nodo *der; // puntero para la rama derecha
	Nodo *padre; // para poder eliminar el nodo
};

/* INGRESAR UN NODO: ingreso ordenado mediante recursividad (ABB)
	-> Primero: crear un nodo principal (función aparte)
	-> Segundo: generar el árbol principal
		-> Caso 1: árbol vacío => crear el nuevo nodo con la función anterior y lo asignamos al puntero cabeza del árbol para definirlo como raíz
		-> Caso 2: árbol con algún elemento => ingresar el nuevo nodo según el dato que contenga comparado con el de la raíz
*/
Nodo *crearNodo(int, Nodo *); // los últimos parámetros nodos son para refenciar al padre a la hora de crear el árbol
void insertarNodo(Nodo *&, int, Nodo *); // sin referencia el último parámetro porque solo es una indicación, no afecta en el orden o creación de nodos

/* MOSTRAR EL ÁRBOL: se muestra el árbol en horizontal, no linealmente como una lista, según como se ingresaron en orden
	-> Primero: verificar si el árbol está vacío (si lo está terminar la función)
	-> Segundo: si no está vacío, llamamos a la función por la derecha y la izquierda aumentando en 1 el contador para mostrar cada nivel
*/
void mostrarArbol(Nodo *&, int); // el parámetro entero es para que en la recursividad se de espacio entre un nodo y otro (en la llamada s emanda 0)

/* BUSCAR UN NODO: buscamos comparando por ráiz de cada sub-árbol moviéndonos por la izq y der
	-> Primero: si el árbol está vacío no hay nada que buscar así que retorna false
	-> Segundo: si el dato buscado es el de la raíz del árbol actual (cabeza correspondiente en el momento de la recursividad) retorna true
	-> Tercero: moverse al sub-árbol crrespondiente
		-> si el dato buscado es menor al de la raíz actual, se manda elsub-árbol izquierdo
		-> si el dato buscado es mayor al de la raíz actual, se manda elsub-árbol derecho
*/
bool busqueda(Nodo *&, int); // retorna true si lo encuentra y false si no

/* RECORRER EL ÁRBOL: por cada método de repiten los pasos recursivamente por raíz del sub-árbol actual
	-> PREORDEN (RID): mostrar la ráiz, atravesar el sub-árbol izquierdo y después el derecho
	-> POSTORDEN (IDR): atraviesa elsub-árbol izquierdo, después atraviesa el sub-árbol derecho y muestra la raíz
	-> INORDEN (IRD): atraviesa elsub-árbol izquierdo, muestra la raíz y después atraviesa el sub-árbol derecho
	
	(!) estos recorridos se pusan para mostrar o para trabajar el árbol, para funciones que deban recorrer el árbol en busca de algún parámetro (el más usado es postOrden)
*/
// sin referencia porque no altera ningún valor, solo muestra
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

/* ELIMINAR UN NODO: 
	(!) para eliminar un nodo hace falta conocer su nodo padre a la hora de eliminarlo para modificar ambos nodos
	-> Primero: recorrer el árbol en busca del nodo a eliminar
	-> Segundo: cuando se llege al nodo raíz a eliminar, se manda a elimnar con otra función específica
	-> Tercero: la función para eliminar el nodo actuará según el tipo de nodo encontrado (porque al eliminar un nodo padre perderíamos sus hijos y el orden si no se mueven los nodos en cada caso)
		-> Caso 1: tiene ambos hijos
			=> primero va al hijo derecho, y de ese nodo, va al último nodo de la izquierda (seleccionado)
			=> copia el valor del nodo seleccionado al nodo raíz que va a eliminar
			=> elimina el nodo seleccionado (en este momento el nodo seleccionado pasa por el mimso proceso de eliminación, viendo que caso se cumple antes de ser eliminado)
			OBS: en una ABO o ABB el mínimo valor está a lo más izquierda y el mayor a lo más derecha (con una función que recorra hasta cada lado hasta que sea null se obtiene)
		-> Caso 2: tiene solo un hijo 
			=> hacemos que el padre del nodo a eliminar apunte al hijo del nodo a eliminar y viceversa (mediante otra función)
			=> eliminamos el nodo a eliminar que sigue señalando a su hijo pero su padre ya no lo señala a él (mediante otra función)
		-> Caso 3: es hoja => reemplazamos el nodo a eliminar por NULL (para que su nodo padre quede con un hijo NULL como se debe) y lo eliminamos
*/
void eliminar(Nodo *, int); // sin referencia para que al terminar el programa el árbol vuelva a estar normal (la eliminación es temporal en lo que se ejecuta el programa)
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *); // retorna el puntero nodo más a la izquierda posible
// Nodo *maximo(Nodo *); // retorna el puntero nodo más a la derecha posible
void reemplazar(Nodo *, Nodo *); // toma un nodo padre y reemplaza su posición por su hijo (tanto para hijo izq como der) // simplemente reemplaza un nodo con otro que se especifique
void destruirNodo(Nodo *); // elimina un nodo específico desligandolo de sus hijos primero


void menu(); // menu de opciones para reiterar el ingreso de elementods sin bucle, entre otras cosas
Nodo *arbol = NULL; // cabeza del árbol (apunta a la raíz principal: primer nodo ingresado)

int main(){
	setlocale(LC_ALL, "Spanish");
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	int dato, opcion;
	
	do{
		cout<<"\t.:MENÚ:."<<endl;
		cout<<"1. Ingresar nuevo elemento"<<endl;
		cout<<"2. Mostrar árbol creado"<<endl;
		cout<<"3. Buscar un elemento en el árbol"<<endl;
		cout<<"4. Recorrer árbol en PREORDEN"<<endl;
		cout<<"5. Recorrer árbol en INTORDEN"<<endl;
		cout<<"6. Recorrer árbol en POSTORDEN"<<endl;
		cout<<"7. Eliminar un elemento del árbol"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"Opción escogida: "; cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\nDigite un número: "; cin>>dato;
				insertarNodo(arbol, dato, NULL); // padre NULL por defecto
				cout<<endl;
				break;
			case 2: 
				cout<<"\nMostrando elementos del árbol en orden: "<<endl;
				mostrarArbol(arbol, 0);
				system("pause"); // para que no omita la impresión de la función
				break;
			case 3:
				cout<<"\nDigite elemento a buscar: "; cin>>dato;
				if(busqueda(arbol, dato) == true)
					cout<<"\nEl elemento ha sido encontrado"<<endl;
				else
					cout<<"\nEl elemento NO ha sido encontrado"<<endl;
				cout<<endl<<endl;
				system("pause");
				break;
			case 4: 
				cout<<"\nRecorrido en PREORDEN: ";
				preOrden(arbol);
				cout<<endl<<endl;
				system("pause");
				break;
			case 5:
				cout<<"\nRecorrido en INORDEN: ";
				inOrden(arbol);
				cout<<endl<<endl;
				system("pause");
				break;
			case 6: 
				cout<<"\nRecorrido en POSTORDEN: ";
				postOrden(arbol);
				cout<<endl<<endl;
				system("pause");
				break;
			case 7: 
				cout<<"\nDigite el número a eliminar: "; cin>>dato;
				eliminar(arbol, dato);
				cout<<endl<<endl;
				system("pause");
				break;
			case 8: break;
			default: cout<<"\nOpción inválida"<<endl;
		}
		system("cls"); // para limpiar la pantalla cada vez que se muestre el menú (requiere un system pause en cada case para que se muestren)
	}while(opcion != 8);
}

Nodo *crearNodo(int n, Nodo *padre){ // función para crear el nodo raíz, se retorna el puntero nodo con el primer dato para el ingreso de la función
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre; // para poder eliminarlo
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
	if(arbol == NULL){ // si está vacío creamos el primer nodo con la función mandándole el dato ingresado
		Nodo *nuevo_nodo = crearNodo(n, padre); // creamos un puntero que obtiene la dm del nodo creado
		arbol = nuevo_nodo; // apuntamos la cabeza del árbol al nuevo nodo creado
	}
	else{ // si ya hay un elemento en el árbol
		int valorRaiz = arbol->dato; // guardamos el dato de la raíz para comparar a la hora de ingresar el nodo hijo en orden
		if(n < valorRaiz) // si el dato a ingresar es menor al de la raíz, se ingresa a la izquierda
			insertarNodo(arbol->izq, n, arbol); // se indica el padre del siguiente nodo a ingresar el la raíz actual
		else // si el dato a ingresar es mayor al de la raíz, se ingresa a la derecha
			insertarNodo(arbol->der, n, arbol);
	} // OBS: como es recursiva la función, al envíar arbol->izq o der en cada llamada se trabaja la raíz del sub-árbol correspondiente y no la cabeza principal
}

void mostrarArbol(Nodo *&arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, cont+1); // vamos hacia el árbol derecho dejando los espacios correspondientes para los siguientes
		for(int i=0; i<cont; i++){ // bucle para mostrar los espacion entre nodos y niveles
			cout<<"    "; 
		}
		cout<<arbol->dato<<endl; // mostramos la raíz actual
		mostrarArbol(arbol->izq, cont+1); // hacemos lo mismo ahora con la rama izquierda
	}
}

bool busqueda(Nodo *&arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == n)
			return true;
	else if(arbol->dato > n)
			return busqueda(arbol->izq, n);
	else if(arbol->dato < n)
			return busqueda(arbol->der, n);
}

void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" ";  // R
		preOrden(arbol->izq);    // I
		preOrden(arbol->der);    // D
	}
}


void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izq);     // I
		cout<<arbol->dato<<" ";  // R
		inOrden(arbol->der);     // D
	}
}


void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izq);   // I
		postOrden(arbol->der);   // D
		cout<<arbol->dato<<" ";  // R
	}
}

Nodo *minimo(Nodo *arbol){
	if(arbol == NULL)
		return NULL; // retorna que no hay hijo izq
	if(arbol->izq){ // si el nodo en el que estamos tiene hijo izq verificamos si tiene más hijos izq
		return minimo(arbol->izq); // recorre la rama izquierda hasta que la raíz actual no tenga más hijo izq (apunte a NULL) y pasa al último else para retornar esa raíz o último nodo izq
	}
	else{ // cuando el nodo en que estamos no tiene más hijos izq porque apunta a null
		return arbol;
	}
}

void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){ // si el nodo a eliminar tiene padre...
		// al padre del nodo actual le asignamos su nuevo hijo (hijo del actual)
		if(arbol->dato == arbol->padre->izq->dato){ // si el hijo del nodo a elimiar es el derecho, o sea el nodo a eliminar el el único izquierdo desde el padre...(en el condicional pregunta si el nodo actual es igual al hijo izquierdo de su padre)
			arbol->padre->izq = nuevoNodo; // reemplazamos su valor (mediante indicaciones del hijo izquierdo del padre) por el nuevo hijo
		}
		else if(arbol->dato == arbol->padre->der->dato){ // lo mismo pero en caso de que el nodo a eliminar sea al único derecho desde el padre y su hijo sea izquierdo
		    arbol->padre->der = nuevoNodo;	
		}		
	}
	if(nuevoNodo){ // si el nodo a eliminar tiene hijo...
		// al hijo del nodo actual le asignamos su padre (padre del actual)
		nuevoNodo->padre = arbol->padre;
	}
}

void destruirNodo(Nodo *nodo){ // le quitamos sus hijos y lo eliminamos
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}

void eliminarNodo(Nodo *nodoEliminar){
	// caso 1:
	if(nodoEliminar->izq && nodoEliminar->der){ // resumidamente pregunta si el nodo a eliminar tiene hijos distintos de 0 o NULL (no es hoja y tiene ambos hijos)
		Nodo *menor = minimo(nodoEliminar->der); // le mandamos el hijo derecho del nodo a eliminar para que busque el más a la izquierda de él (en zig-zag)
		nodoEliminar->dato = menor->dato; // cambiamos el dato del nodo a eliminar por el del nodo seleccionado menor
		eliminarNodo(menor); // mandamos a eliminar el seleccionado viendo que condición cumple antes, para pasárle sus hijos al anterior antes de eliminarlos
	} // caso 2:
	else if(nodoEliminar->izq){ // si tiene hijo izquierdo el nodo a eliminar
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar); // eliminamos el nodo con hijo pero sin padre
	}
	else if(nodoEliminar->der){ // si tiene hijo derecho el nodo a eliminar
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	} // caso 3:
	else{
		reemplazar(nodoEliminar, NULL); // lo igualamos a NULL (su padre apunta a NULL en su posición) y lo borramos
		destruirNodo(nodoEliminar);
	}	
}

void eliminar(Nodo *arbol, int n){
	if(arbol == NULL)
		return;
	else if(n < arbol->dato){ // en caso de que no esté vacío vamos a recorrer el árbol en búscqueda del elemento a eliminar segpun el orden
		eliminar(arbol->izq, n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->der, n);
	}
	else{ // si ya se encontró el elemento a eliminar (quedamos en una raíz determinada apuntada por la cabeza actual)
		eliminarNodo(arbol); // eliminamos el nodo actual
	}
}
