// las LISTAS ENLAZADAS (sin clase) son una serie de nodos con informaci�n que se 'enlazan' mediante punteros y sus dm
// 1-las listas son din�micas, es decir que no tienen un largo de elementos definido, su tama�o n se define en tiempo de ejecuci�n (depende de la memerio disponible)
// 2-en una lista se ingresan, buscan, muestran y eliminan datos de manera din�mica, no se pide ni reserva un espacio espec�fico, se utiliza y libera al ingresar/eliminar alg�n nodo
// cada nodo contienen un campo de informaci�n de cualquier tipo, y otro campo puntero que apunta a la dm del siguiente nodo (el �ltimo apunta a NULL)
// la CABEZA de la lista es un puntero que apunta al primer elemento de la lista, con ella se puede 'recorrer' una lista y se sabe que existe la lista por ella

/* TIPOS DE LISTAS:
	-> simplemente enlazadas: cada nodo apunta al siguiente nada m�s => CABEZA->[d1|*]->[d2|*]->[d3|*]->NULL
	-> doblemente enlazada: cada nodo apunta al siguiente y el siguiente al anterior => CABEZA->[d1|*]<=>[d2|*]<=>[d3|*]->NULL
	-> circular: el �ltimo nodo apunta a la cabeza o primer nodo => *CABEZA->[d1|*]->[d2|*]->[d3|*]->NULL->*CABEZA
	-> doble circular: el �ltimo nodo apunta al primero, el primero al �ltimo y entre si est�n enlazados => *[d3|*]<-*CABEZA->[d1|*]<=>[d2|*]<=>*[d3|*]->NULL->*CABEZA
*/

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
};

/* INGRESAR UN ELEMENTO: conviene programarlo de modo que ingrese los elementos en orden ascendente
	-> Primero: inicializar la cabeza (puntero Nodo) en NULL y crear un nuevo nodo reservando espacio con 'new'
	-> Segundo: asignar elemento a ingresar al dato del nodo
	-> Tercero: crear dos punteros nodos auxiliares y al primero asignarle la cabeza de la lista (ambos apuntan a NULL)
	-> Cuarto: insertar el nodo a la lista
		-> Caso 1: lista vac�a apuntando a NULL (se ingresa nada mas el nodo) => se ingresa al principio
		-> Caso 2: lista con alg�n elemento (ingresar al inicio o al final) => se ingresa en medio o al final
*/
void insertarLista(Nodo *&, int);

/* MOSTRAR UN ELEMENTO: 
	-> Primero: crear un nuevo nodo para el elemento actual
	-> Segundo: asignar al nuevo nodo la cabeza de la lista
	-> Tercero: ir recorriendo la lista mediante el reapunte del nuevo nodo mostrando el dato actual y apuntando al siguiente
*/
void mostrarLista(Nodo *); // no por referencia porque no cambia su valor, solo se usa la cabeza para saber su contenido

/* BUSCAR UN ELEMENTO: 
	-> Primero: crear un nuevo nodo para el elemento actual
	-> Segundo: asignar al nuevo nodo la cabeza de la lista
	-> Tercero: ir recorriendo la lista mediante el reapunte del nuevo nodo al siguiente mientras no se encuentre el elemento buscado
	-> Cuarto: comparar si el dato del nodo actual es igual al elemento buscado 
*/
void buscarLista(Nodo *, int); // no por referencia porque no cambia su valor, solo se usa la cabeza para saber su contenido

/* ELIMINAR UN ELEMENTO: 
	-> Primero: verificar que la lista no est� vac�a
	-> Segundo: crear dos punteros nodos auxiliares (uno para seleccionar el nodo a eliminar y otro para asignarle NULL)
	-> Tercero: asignar al auxiliar para borrar la cabeza de la lista
	-> Cuarto: ir recorriendo la lista mediante el reapunte del auxiliar al siguiente nodo mientras no se encuentre el elemento a borrar
	-> Quinto: eliminar el nodo seleccionado sin alterar la cabeza de la lista
*/
void eliminarNodo(Nodo *&lista, int n);

/* ELIMINAR LA LISTA: esta funci�n elimina el primer elemento de la lista dejando la caneza en el siguiente (al llamarla en un while podemos eliminarla por completo)
	-> Primero: crear un puntero nodo auxiliar e igualarlo a la cabeza de la lista
	-> Segundo: guardar el dato a eliminar en el nodo auxiliar (para mostrarlo antes de eliminarlo)
	-> Tercero: avanzar la cabeza de la lista al siguiente nodo
	-> Cuarto: eliminar el auxiliar cabeza 
*/
void eliminarLista(Nodo *&, int &); // dato por referencia porque el dato del nodo a eliminar se saca del que est� en la cabeza en el momento (ese valor sacado queda global, se puede mostrar fuera de la funci�n)

Nodo *lista = NULL; // cabeza de lista (como se usa en varias funciones la hacemos global)

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int dato, num;
	char ans;
	
	do{ // ingresando elementos a la lista
		cout<<"Digite un n�mero: "; cin>>dato;
		insertarLista(lista, dato);
		
		cout<<"\n�Desea ingresar otro elemento? (s/n): "; cin>>ans;
		cout<<endl;
	} while(ans == 's' || ans == 'S');
	
	// mostrando elementos ingresados a la lista
	cout<<"\nMostrando elementos de la lista: ";
	mostrarLista(lista);
	
	// buscando un nodo de la lista
	cout<<"\nIngrese un elemento a buscar en la lista: "; cin>>num;
	buscarLista(lista, num);
	
	// eliminando un nodo de la lista
	cout<<"\nIngrese un elemento a eliminar de la lista: "; cin>>num;
	eliminarNodo(lista, num);
	
	// mostrando la lista ctualizada, sin los nodos eliminados
	cout<<"\nMostrando elementos de la lista: ";
	mostrarLista(lista);
	
	// eliminando toda la lista
	cout<<"\nVaciando la lista: "<<endl;
	while(lista != NULL){
		eliminarLista(lista, num);	
		cout<<num<<" eliminado"<<endl;
	}
	
	getch();
	return 0;
}

void insertarLista(Nodo *&lista, int n){
	// nuevo_nodo y los auxiliares son locales, al terminar la funci�n y que los datos estpen ingresados, se eliminan
	
	Nodo *nuevo_nodo = new Nodo(); // creamos espacio para el nodo
	nuevo_nodo->dato = n; // le asignsamos el valor al nodo
	
	Nodo *aux1 = lista; // la cabeza y el auxiliar1 apuntan a NULL
	Nodo *aux2; // para ordenar la lista nada m�s
	
	// ayuda para insertar al medio
	while((aux1 != NULL) && (aux1->dato < n)){ // while para insertar en orden (despu�s de haberse ingresado al menos 1 elemento)
		aux2 = aux1; // ambos auxiliares apuntan al primer elemento con la cabeza
		aux1 = aux1->sig; // se mueve al siguiente elemento el aux1 (as� mientras sea distinto de NULL o fin de lista)
		// si el dato ingresado es mayor al primero, se mueven los auxiliares para referencial el ingreso al medio del primero y el �ltimo o el final
	}
	// insertar al inicio o final
	if(lista == aux1){ // si el elemento ingresado es el primero de la lista
		lista = nuevo_nodo; // la cabeza apunta al nodo creado y deja de apuntar a NULL
	}
	else{ // entr� al while y ya hay elementos en la lista
		aux2->sig = nuevo_nodo; // aux1 ya no apunta a la cabeza, as� que el aux2 apuntando a nada pasa a apuntar al nodo creado
		nuevo_nodo->sig = aux1; // el nodo creado pasa a apuntar al siguiente nodo o NULL si es el �ltimo
		// si el dato ingrsado es menor al primero, se ingresa el dato antes del primero con ayuda de los auxiliares movido en el while
		// si el dato ingresado es mayor al primero, no entr� al while, por lo tanto se ingresa despu�s del primero o al final
	}
	
	nuevo_nodo->sig = aux1; // el nodo creado pasa a apuntar NULL (para esto sirve el aux1)
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo(); // creamos el nuevo nodo
	actual = lista; // apuntamos el nuevo nodo al primer elemento de la lista
	
	while(actual != NULL){ // vamos a ir moviendo actual por la lista hasta que sea el �ltimo que apunta NULL
		cout<<actual->dato<<" "; // se muestra el dato del nodo actual
		actual = actual->sig; // se avanza el puntero al siguiente
	}
	cout<<endl;
}

void buscarLista(Nodo *lista, int n){
	Nodo *actual = new Nodo(); // creamos el nuevo nodo
	actual = lista; // apuntamos el nuevo nodo al primer elemento de la lista
	
	bool band = false; // asumimos que no se encuentra en la lista
	
	while((actual != NULL) && (actual->dato <= n)){ // vamos a ir moviendo actual por la lista hasta que sea el �ltimo que apunta NULL (como la lista est� ordenada, si el dato buscado es mayor se avanza en la b�squeda sin comparar)
		if(actual->dato == n){ 
			band = true; // si el dato del nodo actual coincide con el buscado, cambiamos la bandera a verdadero para indicar que s� se encuentra 
		}
		actual = actual->sig; // se avanza el puntero al siguiente
	}
	
	if(band == true){
		cout<<"\nElemento ha sido econtrado en la lista"<<endl;
	}
	else{
		cout<<"\nElemento NO ha sido econtrado en la lista"<<endl;
	}
}

void eliminarNodo(Nodo *&lista, int n){
	if(lista != NULL){ // mientras exista la lista se verificar�
		Nodo *aux_borrar; // cabeza auxiliar
		Nodo *anterior = NULL;
		
		aux_borrar = lista; // ambos apuntan al primer nodo para poder recorrerla sin alterar la cabeza
		
		// while para cuando el elemento a eliminar es diferente del primero
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){ // mientras hayan elementos por recorrer y el elemento a eliminar no se encuentre...
			anterior = aux_borrar; // auxiliar para el aux cabeza, ambos se van moviendo al siguiente recorriendo la lista
			aux_borrar = aux_borrar->sig; //...vamos moviendo el aux cabeza al siguiente hasta que sea NULL
		}
	
		if(aux_borrar == NULL){ // si tras recorrer la lista en el while termina la cabeza auxiliar en NULL por no encontrar el elemento
			cout<<"\nElemento NO ha sido econtrado en la lista"<<endl;
		}
		else if(anterior == NULL){ // eliminar el primer elemento de la lista
			lista = lista->sig; // movemos la cabeza real al segundo elemento para no eliminarla
			delete aux_borrar; // eliminamos el primer nodo que era la cabeza antes mediante la cabeza auxiliar
		}
		else{// eliminar cualquier otro elemento despu�s del primero (entra al while al menos 1 vez)
			anterior->sig = aux_borrar->sig; // anterior como cabeza auxiliar hace que el elemento apunte al siguiente del siguiente o al �ltimo (por esto se trabaja con *& para modificar la dm de los punteros desde la funci�n y no temporalmente)
			delete aux_borrar; // borramos el elemento del medio o el �ltimo
		}	
	} // si la cabeza es NULL es porque no hay eleentos por lo que no hay nada que borrar
}

void eliminarLista(Nodo *&lista, int &n){ // elimina el primer elemento de la lista
	Nodo *aux = lista; // creamos la cabeza auxiliar
	n = aux->dato; // guardamos el dato del nodo por eliminar
	lista = aux->sig; // avanzamos la cabeza real de la lista
	delete aux; // borramos el nodo que anter era la cabeza con aux
}

/* RETORNO DE LA LISTA CREADA CON PUNTEROS:
int main()
{ lista *p;
int n;
p = NULL;
cout<<"\n\t\tIngrese n�meros, presione 0 para terminar.";
do{ cout<<"\n\tIngrese un n�mero: ";
cin>>n;
if(n)
p=IngresoLista(n,p);
}while(n);
mostrar(p);
cout<<"\n\t\tIngrese um n�mero que desee eliminar: ";
cin>>n;
p=EliminaLista(n,p); //Como no esta en un Ciclo lo realiza
una �nica vez
mostrar(p);
while(p)
p=EliminaLista(p->num,p);
return 0;
}
struct lista
{ int num;
lista *prox;
};
lista* IngresoLista(int n, lista *p)
{ lista *q,*r;
q=new lista;
if (!q)
{ cout <<"NO HAY Espacio de Memoria suficiente";
return p;
}
q->num=n;
q->prox=p;
if((!p)||(q->num <= p->num))
p=q;
else
{ r=p->prox;
while(r && r->num < q->num )
{ q->prox=r;
r=r->prox;
}
q-> prox -> prox=q;
q-> prox=r;
}
return p;
}
lista* EliminaLista(int n, lista *p)
{ lista *r,*q;
if(p == NULL)
cout<<"\n\t Lista Vac�a.";
else
{ q=p;
if(p->num == n)
{ p=p->prox;
delete q;
}
else
{ do{ r=q;
q=q->prox;
}while(q && (q->num != n));
if(q)
{ r->prox=q->prox;
delete q;
}
else
cout<<"\n\t El n�mero "<<n<<" no est� en la Lista.";
}
}
return p;
}
void mostrar(lista *p)
{ lista *q;
q=p;
while(q)
{ cout<<(q->num)<<"\t";
q=q->prox;
}
}
*/
