// los constructores o modificadores (GETTERS y SETTERS) son m�todos de la clase que nos permiten establecer y obtener los valores de los atributos de un objeto desde fuera de la clase
// la constructora s�lo se utiliza para inicializar ciertos atributos especificados en los par�metros, por lo que si queremos agregar m�s o generar uno m�s general no conviene...
// ...para esto se utiliza el SETTER: par�metro que funciona exactamente igual que el constructor (para establecer con mayor alcanze los valores desde el main sin usar varios constructores)
// por otro lado...el GETTER: se utiliza para obtener el valor de SOLO 1 atributo de la clase (son del mismo tipo del atributo que retornar) para poder usarlo en el main con la llamada
// la idea es dejar a la constructora los atributos m�s importantes o que requieran inicializar en un valor por defecto que usan los m�todos para operar (ej: puntero = NULL, cont = 0)
// los getters y setters sirven para poder manipular los valores de los atributos desde otras funciones fuera de la clase o desde otras clases o sub-clases

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream>

using namespace std;

class Punto{
	private:
		int x, y; // coordenadas del punto
	public:
		Punto(); // Constructora: para inicializar las variables atributos
		~Punto(); // Destructora: para eliminar los objetos
		void setPunto(int, int); // Setter: para asignarle los valores a los atributos
		int getPuntoX(); // Getter: para obtener el valor del atributo x en el main()
		int getPuntoY(); // Getter: para obtener el valor del atributo y en el main()
};

Punto::Punto(){ // aunque se deje vac�o SIEMPRE debe estar creado para que los atributos puedan optar a tomar valores en un futuro
} // en este caso no inicializamos ning�n atributo

Punto::~Punto(){
} // de momento no hace falta especificar nada

// asignaci�n de atributos por llamada: es de tipo void la funci�n y puede tener cualquier nombre en verdad
void Punto::setPunto(int _x, int _y){
	x = _x;
	y = _y;
	// tambi�n sirven para, en esta misma funci�n, establecer varias opciones para asignar (condicionales, etc) y ahorrarse la sobrecarga de constructores
}

// retorno del valor de un atributo: es de tipo del atributo que retorna y puede tener cualquier nombre en verdad
int Punto::getPuntoX(){ // no lleva par�metros porque no recibe nada para modificar, s�lo reotrna el valor a usar
	return x; // retorna el valor del atributo antes asignado con el setter
}
// -> lo que hacen es retornar el valor del atributo, no el atributo, por lo que no se modifica en la clase
int Punto::getPuntoY(){
	return y; // el valor retornado se puede asignar a variables del main o donde se llame para poder trabajarlo sin necesidad de llamar a la funci�n cada vez
}

int main(){
	setlocale(LC_ALL, "Spanish");
	
	Punto punto1; // creaci�n de objeto
	// no se le pueden asignar valores de la forma: punto1(...,...), ya que eso es cuando se inicializan con el constructor
	int coordX; // esta variable es del main, no hace falta que sea de la clase para copiar el valor del atributo con el getter
	int x; // variable para pedir una coordenada y asignarla al atributo
	
	// NO OLVIDAR: como son funciones de la clase primero se nombra al objeto seguido de .funci�n, ya si despu�s se copian a una variable no hace falta
	
	cout<<"Digite la coordenada x del punto: "; cin>>x;
	punto1.setPunto(x, -4); // asignamos los valores directamente y trav�s de una variable ingresado por el usuario)
	
	// obtenemos y mostramos los valores de los atributos
	coordX = punto1.getPuntoX(); // copiamos el valor a una variable y la mostramos
	cout<<"\nCoordenadas del punto: ("<<coordX<<", "<<punto1.getPuntoY()<<")"<<endl; // mostramos directamente desde el llamado de la funci�n
	
	getch();
	return 0;
}

