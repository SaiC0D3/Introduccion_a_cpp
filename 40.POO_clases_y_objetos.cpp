/* PROGRAMACIÓN ORIENTADA A OBJETOS (POO):
	-> la programación orientada a objetos es un paradigma que busca anlaizar y abordar los problemas de computación desde una visión más cercana a la realidad...
	...mediante la creación de clases y la clasificación de objetos, para poder trabajar los datos de manera general más fiel a la realidad, al contrario de la programación estrucutrada...
	...que se enfoca en el desarrollo de programas que incluyen una secuencia, selección y repetición (bucles y condicionales) para dictar estados de un problema
	-> también la POO permite hacer un código más simple y reutilizable para los objetos
	-> básicamente en vez de trabajar con variables sueltas sin realción entre si, y mandarlas a funciones para que con su valor devuelvan un resultado...
	...vamos a agrupar las variables relacionándolas entre si (que su nombre y valor tengan relevancia), mandándo los parámetros necesarios a las funciones que también tengan relación con ellas...
	-> la abstracción de datos (TDA) comienza con los bloques de estructuras en donde agrupamos varios parámetros para un bloque...
	...el cúal se puede usar en métodos (funciones) para trabajar con varios de sus parámetros como Persona.pelo, etc...
	
	1) CLASE: una clase es una agrupación de objetos con características comunes entre sí (abstracción de objetos = representar una clase mediante las carácterísticas más relevantes del objeto)
		Ej: definimos la clase <Producto> con características como: precio-color-durabilidad-etc... y métodos como: ejecutara-actualizar-reproducir-etc... ('clase' con varios campos)
		...cuyos objetos derivados podrian ser: <celular>-<notebook>-<cámara>-ect...
		-> la clase contiene las carácterísticas fundamentales de un objeto y además algunos métodos (acciones = funciones) que estos puedan realizar
		=> resumidamente es una agrupación de variables y funciones de manera global para interrelacionarlas entre si
	
	2) ENCAPSULAMIENTO: es la privatización de atributos y métodos que NO DEBEN SER TOCADOS, que sirven para el funcionamiento global de la clase y sus métodos públicos
		-> las clases van a encapsular sus datos (para mantener los datos seguros y solo permitir el trabajo de las caracterísitcas y métodos necesarios no superfluos)
		-> los métodos públicos de la clase son los únicos que tienen acceso a los atributos privados para poder trabajarlos, modificarlos, asignarles valores, etc.
		Ej: la clase <Pastilla> encapsula y mantiene privado la información que contiene dentro (atributos), dejando a la vista y uso sus funciones (métodos ) como comersela para sanar
	
	3) HERENCIA: la herencia es cuando se crea una clase nueva a partir de otra ya existente, heredando todos sus atributos y métodos pero añadiendo algunos nuevos que la diferencian
		Ej: de la clase <Mamifero> con caracterísitcas: años-peso y métodos: cazar-comer-domir; se crea la sub-clase <Leon> con las mismas características +pelaje y los mismos métodos +jugar
		-> la subclase puede tener acceso total o parcial a los elementos de su clase padre, pero no viceversa
	
	4) OBJETO: un objeto es un conjunto de atributos (carácterísticas esenciales) y métodos (acciones a realizar), el cual deriva de una clase que lo contiene (variables tipo 'clase')
		-> al crear un objeto de la clase, este contiene los atributos y métodos definidos en la clase, no puede tener distintos o nuevos
		Ej: Definimos el objeto <pug> perteneciente a la clase <Perro>, con características de la clase: pelo-edad-tamaño y métodos como: comer-jugar-ladrar
		=> básicamente es una estructura con los campos de la clase <-
		
	5) POLIMORFISMO: es la cualidad que poseen los objetos para responder de distinta manera al mismo mensaje o acción (método)
		Ej: si le mandamos la acción comer() a los objetos <persona>-<perro>-<vaca>, los tres objetos ejecutaran de manera distinta y característica la misma función
		-> para esto las clases deben estar interrelacionadas con el método polimorfo definido en la clase padre, así los objetos creados de las distintas clases pueden realizar la misma función

	Para diferenciar mejor una clase de un objeto ve el ejemplo sgte:
	-> la clase <Persona> con {peso, edad} y (comer, dormir) sale la sub-clase <Alumno> con {peso, edad, curso} y (comer, domrmir, estudiar) y el objeto <persona1> con {67.3, 18} y (comer, dormir)
	-> donde {} son los atributos y () los métodos
*/

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream>

using namespace std;

// 1.Creación de una clase: parecido a lo que es un struct en todos los sentidos (los prototipos de funciones se declaran dentro como si fueran globales pero en la clase)
// -> siempre a la hora de decidir los atributos tenemos que abstraer el objeto
class Persona{
	private: // encapsulamiento de los atributos
		int edad; // se le pueden asignar valores directamente (no haría falta el constructor, y todos los objetos tendrían el mismo valor común del atributo)
		string nombre;
	public: // sólo se pueden modificar o mostrar los atributos mediante métodos de la clase
		Persona(int, string); // Persona() si no va a recibir valores -> CONSTRUCTOR: inicializa los atributos (tiene el mismo nombre de la clase) y siempre debe estar creado
		~Persona(); // DESTRUCTOR: sirve para eliminar los objetos creados (si no se crea, el computador genera uno por defecto menos eficiente)
		void leer(); // métodos o funciones que trabajan con los atributos
		void correr(); // las funciones no polimorfas deben tener distintos nombres por cada clase que haya
};

// 2.Inicialización de variables (atributos): el constructor permite asignarle valores a los atributos privados desde la función main()
Persona::Persona(int _edad, string _nombre){ // Persona::Persona() si no va a recibir valores y los vas a asignar tu, por ejemplo: edad = 16 / nombre = Denji
	edad = _edad; // asignación de valores por parámetros
	nombre = _nombre;
} // los valores que se asignan a los atributos mediante constructora varian según el objeto (no es la clase la que se queda con los valores, si no el objeto creado)

// 2.1.Liberación de objetos: el destructor se encarga se eliminar los objetos creados en el programa, eliminando así sus valores asignados en el constructor (NO elimina la clase)
Persona::~Persona(){ // tiene el mismo nombre del constructor con el '~' antes
	// instrucciones para vaciar las variables (si son variables normales (sin memoria reservada con 'new') no hace falta escribir nada: el programa los elimina solo)
} // en casos donde se asigna memoria con 'new', la destructora debe especificar el 'delete' de esa variable

// 3.Definición de funciones (métodos): tipo de la función - clase a la que pertenece - nombre de la función - parámetros
// -> las funciones de la clase se definen antes del main, las que no, después del main
void Persona::leer(){ // como al función es parte de la clase, no necesita recibir de parámetros las variables a usar (los saca de la clase directamente)
	cout<<"Ahora "<<nombre<<" está leyendo, con "<<edad<<" años"<<endl;
}
// -> es importante declarar la clase a la que pertenece, ya que varias clases pueden tener los mismos métodos (con igual nombre y todo)
void Persona::correr(){
	cout<<"Ahora "<<nombre<<" está corriendo en una maratón "<<endl;
}

int main(){
	setlocale(LC_ALL, "Spanish");
	
	// 4.Creación de objetos de la clase: nombre de la clase - nombre de la variable (y si el constructor existe y recibe parámetros, se le asigna al objeto)
	// -> se pueden declarar directamente al final de la clase antes del ';' como en los structs
	Persona p1 = Persona(18, "Matías"); // se mandan los valores para el objeto mediante el constructor o de la sig. forma:
	Persona p2(18, "Belén"); // ...se le mandan los parámetros del constructor al mismo nombre del objeto
	Persona p3(19, "Delian");
	//  también se pueden pedir al usuario (accediendo a los datos privados), más adelante sabremos como...
	// se pueden crear arreglos de objetos de la forma: Persona p[cantidad de objetos], y se trabajan igual que los arreglos de estructuras
	
	// 5.Declaramos la acción que ejecuta cada objeto: de la misma forma que con las estructuras (nombre objeto.función a realizar)
	// -> las funciones al ser públicas si se pueden llamar mediante el objeto y poder usar o mostrar sus atributos (no podemos hacer por ej: p1.nombre)
	p1.leer();
	p2.correr();
	cout<<"\nDelian está haciendo 2 acciones:"<<endl; // OBS: no se puede mandar a llamar un atributo PRIVADO, ej: p3.nombre <- NO si los valores son asignados en el constructor 
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
{ cout <<"Ingrese un número
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
cout<<endl<<" El Número "<<n
<<" No esta en la lista"<<endl;
}
}
}
int main()
{
lista L;
int n;
do
{ cout <<"Ingrese un número
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
