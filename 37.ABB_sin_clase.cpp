// los �RBOLES son estrcuturas de datos NO-LINEALES, es decir, no tienen una sola direcci�n como las listas que son estrcuturas de datos lineales
// los �rboles se clasifican por su orden (n�mero m�x. de hijos), los �rboles binarios de a lo m�s hijos son los m�s utilizados
// los �RBOLES BINARIOS se caracterizan por presentar una rama izquierda y una rama derecha (2 punteros tipo nodo que apuntan a los nodos hijos) adem�s del campo de informaci�n
// son como listas (una lista es un AB de una sola diracci�n) con dos direcciones, que provienen de un nodo ra�z y finalizan en nodos sin hijos (hojas), por lo que la forma de 'recorrerlos' puede variar
// los arboles binarios se dividen en ORDENADOS (ABO) y DESORDENADOS (AB), a su vez los ABO pueden ser simplemente ABO o AVL
// como cada nodo hijo de la r�iz principal pueden tener hijos, se dice que los AB(O) son estructuras RECURSIVAS en d�nde cada nodo padre es un sub-�rbol (izq. y der.)
// los ABO est�n ordenados de forma que los elementos menores a la ra�z (por cada sub-�rbol) van a la derecha y los mayores a la izquierda

/* PROPIEDADES DE UN �RBOL BINARIO:
	-> el puntero cabeza del �rbol apunta a la ra�z principal
	-> los ABO tambi�n se conocen como ABB (�rbol binario de b�squeda)
	-> el primer nodo ingresado es la ra�z principal
	-> cada nodo padre puede tener a lo m�s 2 hijos
	-> los nodos siguientes a la ra�z o padre se llaman ramas
	-> el nivel de un AB comienza de 0 hasta el �ltimo nodo de la rama m�s larga
	-> los nodos sin hijos se llaman hojas (apountan a NULL)
	-> la altura de un AB se cuenta de abajo (�ltimo nivel) hacia arriba (ra�z)
	-> la altura y nivel de un nodo del AB es desde el comienzo respectivo hasta el nodo
	-> los nodos que est�n en el mismo nivel y compartan un padre son nodos hermanos
	-> la longitud de camino hacia un nodo son la cantidad de nodos desde la ra�z hasta �l
	-> los AVL son �rboles binarios ordenados y equilibrados (ninguna rama es m�s larga que la otra por m�s de 1 nivel), en donde los nodos tienen coef. de equ. y se rotan
	-> en un ABO o ABB no pueden haber nodos repetidos (con igual dato), s� en el caso de un AVL
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
	-> Primero: crear un nodo principal (funci�n aparte)
	-> Segundo: generar el �rbol principal
		-> Caso 1: �rbol vac�o => crear el nuevo nodo con la funci�n anterior y lo asignamos al puntero cabeza del �rbol para definirlo como ra�z
		-> Caso 2: �rbol con alg�n elemento => ingresar el nuevo nodo seg�n el dato que contenga comparado con el de la ra�z
*/
Nodo *crearNodo(int, Nodo *); // los �ltimos par�metros nodos son para refenciar al padre a la hora de crear el �rbol
void insertarNodo(Nodo *&, int, Nodo *); // sin referencia el �ltimo par�metro porque solo es una indicaci�n, no afecta en el orden o creaci�n de nodos

/* MOSTRAR EL �RBOL: se muestra el �rbol en horizontal, no linealmente como una lista, seg�n como se ingresaron en orden
	-> Primero: verificar si el �rbol est� vac�o (si lo est� terminar la funci�n)
	-> Segundo: si no est� vac�o, llamamos a la funci�n por la derecha y la izquierda aumentando en 1 el contador para mostrar cada nivel
*/
void mostrarArbol(Nodo *&, int); // el par�metro entero es para que en la recursividad se de espacio entre un nodo y otro (en la llamada s emanda 0)

/* BUSCAR UN NODO: buscamos comparando por r�iz de cada sub-�rbol movi�ndonos por la izq y der
	-> Primero: si el �rbol est� vac�o no hay nada que buscar as� que retorna false
	-> Segundo: si el dato buscado es el de la ra�z del �rbol actual (cabeza correspondiente en el momento de la recursividad) retorna true
	-> Tercero: moverse al sub-�rbol crrespondiente
		-> si el dato buscado es menor al de la ra�z actual, se manda elsub-�rbol izquierdo
		-> si el dato buscado es mayor al de la ra�z actual, se manda elsub-�rbol derecho
*/
bool busqueda(Nodo *&, int); // retorna true si lo encuentra y false si no

/* RECORRER EL �RBOL: por cada m�todo de repiten los pasos recursivamente por ra�z del sub-�rbol actual
	-> PREORDEN (RID): mostrar la r�iz, atravesar el sub-�rbol izquierdo y despu�s el derecho
	-> POSTORDEN (IDR): atraviesa elsub-�rbol izquierdo, despu�s atraviesa el sub-�rbol derecho y muestra la ra�z
	-> INORDEN (IRD): atraviesa elsub-�rbol izquierdo, muestra la ra�z y despu�s atraviesa el sub-�rbol derecho
	
	(!) estos recorridos se pusan para mostrar o para trabajar el �rbol, para funciones que deban recorrer el �rbol en busca de alg�n par�metro (el m�s usado es postOrden)
*/
// sin referencia porque no altera ning�n valor, solo muestra
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

/* ELIMINAR UN NODO: 
	(!) para eliminar un nodo hace falta conocer su nodo padre a la hora de eliminarlo para modificar ambos nodos
	-> Primero: recorrer el �rbol en busca del nodo a eliminar
	-> Segundo: cuando se llege al nodo ra�z a eliminar, se manda a elimnar con otra funci�n espec�fica
	-> Tercero: la funci�n para eliminar el nodo actuar� seg�n el tipo de nodo encontrado (porque al eliminar un nodo padre perder�amos sus hijos y el orden si no se mueven los nodos en cada caso)
		-> Caso 1: tiene ambos hijos
			=> primero va al hijo derecho, y de ese nodo, va al �ltimo nodo de la izquierda (seleccionado)
			=> copia el valor del nodo seleccionado al nodo ra�z que va a eliminar
			=> elimina el nodo seleccionado (en este momento el nodo seleccionado pasa por el mimso proceso de eliminaci�n, viendo que caso se cumple antes de ser eliminado)
			OBS: en una ABO o ABB el m�nimo valor est� a lo m�s izquierda y el mayor a lo m�s derecha (con una funci�n que recorra hasta cada lado hasta que sea null se obtiene)
		-> Caso 2: tiene solo un hijo 
			=> hacemos que el padre del nodo a eliminar apunte al hijo del nodo a eliminar y viceversa (mediante otra funci�n)
			=> eliminamos el nodo a eliminar que sigue se�alando a su hijo pero su padre ya no lo se�ala a �l (mediante otra funci�n)
		-> Caso 3: es hoja => reemplazamos el nodo a eliminar por NULL (para que su nodo padre quede con un hijo NULL como se debe) y lo eliminamos
*/
void eliminar(Nodo *, int); // sin referencia para que al terminar el programa el �rbol vuelva a estar normal (la eliminaci�n es temporal en lo que se ejecuta el programa)
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *); // retorna el puntero nodo m�s a la izquierda posible
// Nodo *maximo(Nodo *); // retorna el puntero nodo m�s a la derecha posible
void reemplazar(Nodo *, Nodo *); // toma un nodo padre y reemplaza su posici�n por su hijo (tanto para hijo izq como der) // simplemente reemplaza un nodo con otro que se especifique
void destruirNodo(Nodo *); // elimina un nodo espec�fico desligandolo de sus hijos primero


void menu(); // menu de opciones para reiterar el ingreso de elementods sin bucle, entre otras cosas
Nodo *arbol = NULL; // cabeza del �rbol (apunta a la ra�z principal: primer nodo ingresado)

int main(){
	setlocale(LC_ALL, "Spanish");
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	int dato, opcion;
	
	do{
		cout<<"\t.:MEN�:."<<endl;
		cout<<"1. Ingresar nuevo elemento"<<endl;
		cout<<"2. Mostrar �rbol creado"<<endl;
		cout<<"3. Buscar un elemento en el �rbol"<<endl;
		cout<<"4. Recorrer �rbol en PREORDEN"<<endl;
		cout<<"5. Recorrer �rbol en INTORDEN"<<endl;
		cout<<"6. Recorrer �rbol en POSTORDEN"<<endl;
		cout<<"7. Eliminar un elemento del �rbol"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"Opci�n escogida: "; cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\nDigite un n�mero: "; cin>>dato;
				insertarNodo(arbol, dato, NULL); // padre NULL por defecto
				cout<<endl;
				break;
			case 2: 
				cout<<"\nMostrando elementos del �rbol en orden: "<<endl;
				mostrarArbol(arbol, 0);
				system("pause"); // para que no omita la impresi�n de la funci�n
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
				cout<<"\nDigite el n�mero a eliminar: "; cin>>dato;
				eliminar(arbol, dato);
				cout<<endl<<endl;
				system("pause");
				break;
			case 8: break;
			default: cout<<"\nOpci�n inv�lida"<<endl;
		}
		system("cls"); // para limpiar la pantalla cada vez que se muestre el men� (requiere un system pause en cada case para que se muestren)
	}while(opcion != 8);
}

Nodo *crearNodo(int n, Nodo *padre){ // funci�n para crear el nodo ra�z, se retorna el puntero nodo con el primer dato para el ingreso de la funci�n
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre; // para poder eliminarlo
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
	if(arbol == NULL){ // si est� vac�o creamos el primer nodo con la funci�n mand�ndole el dato ingresado
		Nodo *nuevo_nodo = crearNodo(n, padre); // creamos un puntero que obtiene la dm del nodo creado
		arbol = nuevo_nodo; // apuntamos la cabeza del �rbol al nuevo nodo creado
	}
	else{ // si ya hay un elemento en el �rbol
		int valorRaiz = arbol->dato; // guardamos el dato de la ra�z para comparar a la hora de ingresar el nodo hijo en orden
		if(n < valorRaiz) // si el dato a ingresar es menor al de la ra�z, se ingresa a la izquierda
			insertarNodo(arbol->izq, n, arbol); // se indica el padre del siguiente nodo a ingresar el la ra�z actual
		else // si el dato a ingresar es mayor al de la ra�z, se ingresa a la derecha
			insertarNodo(arbol->der, n, arbol);
	} // OBS: como es recursiva la funci�n, al env�ar arbol->izq o der en cada llamada se trabaja la ra�z del sub-�rbol correspondiente y no la cabeza principal
}

void mostrarArbol(Nodo *&arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, cont+1); // vamos hacia el �rbol derecho dejando los espacios correspondientes para los siguientes
		for(int i=0; i<cont; i++){ // bucle para mostrar los espacion entre nodos y niveles
			cout<<"    "; 
		}
		cout<<arbol->dato<<endl; // mostramos la ra�z actual
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
	if(arbol->izq){ // si el nodo en el que estamos tiene hijo izq verificamos si tiene m�s hijos izq
		return minimo(arbol->izq); // recorre la rama izquierda hasta que la ra�z actual no tenga m�s hijo izq (apunte a NULL) y pasa al �ltimo else para retornar esa ra�z o �ltimo nodo izq
	}
	else{ // cuando el nodo en que estamos no tiene m�s hijos izq porque apunta a null
		return arbol;
	}
}

void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){ // si el nodo a eliminar tiene padre...
		// al padre del nodo actual le asignamos su nuevo hijo (hijo del actual)
		if(arbol->dato == arbol->padre->izq->dato){ // si el hijo del nodo a elimiar es el derecho, o sea el nodo a eliminar el el �nico izquierdo desde el padre...(en el condicional pregunta si el nodo actual es igual al hijo izquierdo de su padre)
			arbol->padre->izq = nuevoNodo; // reemplazamos su valor (mediante indicaciones del hijo izquierdo del padre) por el nuevo hijo
		}
		else if(arbol->dato == arbol->padre->der->dato){ // lo mismo pero en caso de que el nodo a eliminar sea al �nico derecho desde el padre y su hijo sea izquierdo
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
		Nodo *menor = minimo(nodoEliminar->der); // le mandamos el hijo derecho del nodo a eliminar para que busque el m�s a la izquierda de �l (en zig-zag)
		nodoEliminar->dato = menor->dato; // cambiamos el dato del nodo a eliminar por el del nodo seleccionado menor
		eliminarNodo(menor); // mandamos a eliminar el seleccionado viendo que condici�n cumple antes, para pas�rle sus hijos al anterior antes de eliminarlos
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
		reemplazar(nodoEliminar, NULL); // lo igualamos a NULL (su padre apunta a NULL en su posici�n) y lo borramos
		destruirNodo(nodoEliminar);
	}	
}

void eliminar(Nodo *arbol, int n){
	if(arbol == NULL)
		return;
	else if(n < arbol->dato){ // en caso de que no est� vac�o vamos a recorrer el �rbol en b�scqueda del elemento a eliminar segpun el orden
		eliminar(arbol->izq, n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->der, n);
	}
	else{ // si ya se encontr� el elemento a eliminar (quedamos en una ra�z determinada apuntada por la cabeza actual)
		eliminarNodo(arbol); // eliminamos el nodo actual
	}
}
