/* PROGRAMACI�N ORIENTADA A OBJETOS (POO):
	-> la programaci�n orientada a objetos es un paradigma que busca anlaizar y abordar los problemas de computaci�n desde una visi�n m�s cercana a la realidad...
	...mediante la creaci�n de clases y la clasificaci�n de objetos, para poder trabajar los datos de manera general m�s fiel a la realidad, al contrario de la programaci�n estrucutrada...
	...que se enfoca en el desarrollo de programas que incluyen una secuencia, selecci�n y repetici�n (bucles y condicionales) para dictar estados de un problema
	-> tambi�n la POO permite hacer un c�digo m�s simple y reutilizable para los objetos
	-> b�sicamente en vez de trabajar con variables sueltas sin realci�n entre si, y mandarlas a funciones para que con su valor devuelvan un resultado...
	...vamos a agrupar las variables relacion�ndolas entre si (que su nombre y valor tengan relevancia), mand�ndo los par�metros necesarios a las funciones que tambi�n tengan relaci�n con ellas...
	-> la abstracci�n de datos (TDA) comienza con los bloques de estructuras en donde agrupamos varios par�metros para un bloque...
	...el c�al se puede usar en m�todos (funciones) para trabajar con varios de sus par�metros como Persona.pelo, etc...
	
	1) CLASE: una clase es una agrupaci�n de objetos con caracter�sticas comunes entre s� (abstracci�n de objetos = representar una clase mediante las car�cter�sticas m�s relevantes del objeto)
		Ej: definimos la clase <Producto> con caracter�sticas como: precio-color-durabilidad-etc... y m�todos como: ejecutara-actualizar-reproducir-etc... ('clase' con varios campos)
		...cuyos objetos derivados podrian ser: <celular>-<notebook>-<c�mara>-ect...
		-> la clase contiene las car�cter�sticas fundamentales de un objeto y adem�s algunos m�todos (acciones = funciones) que estos puedan realizar
		=> resumidamente es una agrupaci�n de variables y funciones de manera global para interrelacionarlas entre si
	
	2) ENCAPSULAMIENTO: es la privatizaci�n de atributos y m�todos que NO DEBEN SER TOCADOS, que sirven para el funcionamiento global de la clase y sus m�todos p�blicos
		-> las clases van a encapsular sus datos (para mantener los datos seguros y solo permitir el trabajo de las caracter�sitcas y m�todos necesarios no superfluos)
		-> los m�todos p�blicos de la clase son los �nicos que tienen acceso a los atributos privados para poder trabajarlos, modificarlos, asignarles valores, etc.
		Ej: la clase <Pastilla> encapsula y mantiene privado la informaci�n que contiene dentro (atributos), dejando a la vista y uso sus funciones (m�todos ) como comersela para sanar
	
	3) HERENCIA: la herencia es cuando se crea una clase nueva a partir de otra ya existente, heredando todos sus atributos y m�todos pero a�adiendo algunos nuevos que la diferencian
		Ej: de la clase <Mamifero> con caracter�sitcas: a�os-peso y m�todos: cazar-comer-domir; se crea la sub-clase <Leon> con las mismas caracter�sticas +pelaje y los mismos m�todos +jugar
		-> la subclase puede tener acceso total o parcial a los elementos de su clase padre, pero no viceversa
	
	4) OBJETO: un objeto es un conjunto de atributos (car�cter�sticas esenciales) y m�todos (acciones a realizar), el cual deriva de una clase que lo contiene (variables tipo 'clase')
		-> al crear un objeto de la clase, este contiene los atributos y m�todos definidos en la clase, no puede tener distintos o nuevos
		Ej: Definimos el objeto <pug> perteneciente a la clase <Perro>, con caracter�sticas de la clase: pelo-edad-tama�o y m�todos como: comer-jugar-ladrar
		=> b�sicamente es una estructura con los campos de la clase <-
		
	5) POLIMORFISMO: es la cualidad que poseen los objetos para responder de distinta manera al mismo mensaje o acci�n (m�todo)
		Ej: si le mandamos la acci�n comer() a los objetos <persona>-<perro>-<vaca>, los tres objetos ejecutaran de manera distinta y caracter�stica la misma funci�n
		-> para esto las clases deben estar interrelacionadas con el m�todo polimorfo definido en la clase padre, as� los objetos creados de las distintas clases pueden realizar la misma funci�n

	Para diferenciar mejor una clase de un objeto ve el ejemplo sgte:
	-> la clase <Persona> con {peso, edad} y (comer, dormir) sale la sub-clase <Alumno> con {peso, edad, curso} y (comer, domrmir, estudiar) y el objeto <persona1> con {67.3, 18} y (comer, dormir)
	-> donde {} son los atributos y () los m�todos
*/

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream>

using namespace std;

// 1.Creaci�n de una clase: parecido a lo que es un struct en todos los sentidos (los prototipos de funciones se declaran dentro como si fueran globales pero en la clase)
// -> siempre a la hora de decidir los atributos tenemos que abstraer el objeto
class Persona{
	private: // encapsulamiento de los atributos
		int edad; // se le pueden asignar valores directamente (no har�a falta el constructor, y todos los objetos tendr�an el mismo valor com�n del atributo)
		string nombre;
	public: // s�lo se pueden modificar o mostrar los atributos mediante m�todos de la clase
		Persona(int, string); // Persona() si no va a recibir valores -> CONSTRUCTOR: inicializa los atributos (tiene el mismo nombre de la clase) y siempre debe estar creado
		~Persona(); // DESTRUCTOR: sirve para eliminar los objetos creados (si no se crea, el computador genera uno por defecto menos eficiente)
		void leer(); // m�todos o funciones que trabajan con los atributos
		void correr(); // las funciones no polimorfas deben tener distintos nombres por cada clase que haya
};

// 2.Inicializaci�n de variables (atributos): el constructor permite asignarle valores a los atributos privados desde la funci�n main()
Persona::Persona(int _edad, string _nombre){ // Persona::Persona() si no va a recibir valores y los vas a asignar tu, por ejemplo: edad = 16 / nombre = Denji
	edad = _edad; // asignaci�n de valores por par�metros
	nombre = _nombre;
} // los valores que se asignan a los atributos mediante constructora varian seg�n el objeto (no es la clase la que se queda con los valores, si no el objeto creado)

// 2.1.Liberaci�n de objetos: el destructor se encarga se eliminar los objetos creados en el programa, eliminando as� sus valores asignados en el constructor (NO elimina la clase)
Persona::~Persona(){ // tiene el mismo nombre del constructor con el '~' antes
	// instrucciones para vaciar las variables (si son variables normales (sin memoria reservada con 'new') no hace falta escribir nada: el programa los elimina solo)
} // en casos donde se asigna memoria con 'new', la destructora debe especificar el 'delete' de esa variable

// 3.Definici�n de funciones (m�todos): tipo de la funci�n - clase a la que pertenece - nombre de la funci�n - par�metros
// -> las funciones de la clase se definen antes del main, las que no, despu�s del main
void Persona::leer(){ // como al funci�n es parte de la clase, no necesita recibir de par�metros las variables a usar (los saca de la clase directamente)
	cout<<"Ahora "<<nombre<<" est� leyendo, con "<<edad<<" a�os"<<endl;
}
// -> es importante declarar la clase a la que pertenece, ya que varias clases pueden tener los mismos m�todos (con igual nombre y todo)
void Persona::correr(){
	cout<<"Ahora "<<nombre<<" est� corriendo en una marat�n "<<endl;
}

int main(){
	setlocale(LC_ALL, "Spanish");
	
	// 4.Creaci�n de objetos de la clase: nombre de la clase - nombre de la variable (y si el constructor existe y recibe par�metros, se le asigna al objeto)
	// -> se pueden declarar directamente al final de la clase antes del ';' como en los structs
	Persona p1 = Persona(18, "Mat�as"); // se mandan los valores para el objeto mediante el constructor o de la sig. forma:
	Persona p2(18, "Bel�n"); // ...se le mandan los par�metros del constructor al mismo nombre del objeto
	Persona p3(19, "Delian");
	//  tambi�n se pueden pedir al usuario (accediendo a los datos privados), m�s adelante sabremos como...
	// se pueden crear arreglos de objetos de la forma: Persona p[cantidad de objetos], y se trabajan igual que los arreglos de estructuras
	
	// 5.Declaramos la acci�n que ejecuta cada objeto: de la misma forma que con las estructuras (nombre objeto.funci�n a realizar)
	// -> las funciones al ser p�blicas si se pueden llamar mediante el objeto y poder usar o mostrar sus atributos (no podemos hacer por ej: p1.nombre)
	p1.leer();
	p2.correr();
	cout<<"\nDelian est� haciendo 2 acciones:"<<endl; // OBS: no se puede mandar a llamar un atributo PRIVADO, ej: p3.nombre <- NO si los valores son asignados en el constructor 
	p3.leer(); 
	p3.correr();
	
	// para eliminar un objeto manualmente se llama al destructor: p3.~Persona() (no hace falta porque con colo declarar el destructor el programa sabe que debe eliminar TODOS los objetos)
	
	getch();
	return 0;
}

/* LISTA CON CLASE:
void lista::ingreso( int n) {
nodo *q, *r;
q = new nodo;
if (!q)
{ cout <<"NO HAY Espacio de
Memoria suficiente";
}
else {
q -> info = n;
q -> sig = p;
if ( !p || q -> info <= p -> info )
p = q;
else {
r = p -> sig;
while ( r && r -> info < q -> info )
{
q -> sig = r;
r = r -> sig;
}
q -> sig -> sig = q;
q -> sig = r;
}
}
}
int main()
{
lista L;
int n;
do
{ cout <<"Ingrese un n�mero
(0 para terminar)";
cin>> n;
if(n)
L.ingreso(n);
}while(n);
L.mostrar();
cout <<"Ingrese elemento
a eliminar: ";
cin >> n;
L.elimina(n);
L.mostrar();
return 0;
}
void lista::elimina( int n )
{ nodo *r, *q;
if ( p == NULL ) // eq. if (!p)
cout<<"LISTA VACIA"<<endl;
else
{ q = p;
if ( p -> info == n )
{
p = p -> sig;
delete q ;
}
else
{
do
{ r = q;
q = q -> sig;
} while ( q && q -> info != n );
if ( q )
{ r -> sig = q -> sig;
delete q;
}
else
cout<<endl<<" El N�mero "<<n
<<" No esta en la lista"<<endl;
}
}
}
int main()
{
lista L;
int n;
do
{ cout <<"Ingrese un n�mero
(0 para terminar)";
cin>> n;
if(n)
L.ingreso(n);
}while(n);
L.mostrar();
cout <<"Ingrese elemento
a eliminar: ";
cin >> n;
L.elimina(n);
L.mostrar();
return 0;
}
void lista::mostrar()
{ nodo *q;
q=p;
while(q)
{ cout<<q->info<<"\t";
q=q->sig;
}
}
lista::lista()
{
p=NULL;
}
lista::~lista()
{ nodo *q;
while (p) {
q=p;
p=p->sig;
delete q;
}
}

*/
