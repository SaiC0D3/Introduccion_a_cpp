// las funciones POLIMORFAS son aquellas que, dependiendo del objeto de cierta clase, se ejecutan de una manera específica
// la función padre declara la función polimorfa con 'virtual' y las clases hijas y subclases de las hijas simplemente heredan la función...
// ...luego los objetos del tipo de clase que se creen pueden llamar a la función pero dependiendedo de la clase a la que pertenecen la ejecutarán de otra manera
// cada clase le añade algo a la función polimorfa y las hijas al llamarlas incluyen lo de las clases padres
// Ej: la función mostrar() común de todas las clases tendrá diferente código, se difenrencia especificando la clase a la que pertenece la función
// -> de todas formar una función polimorfa puede incluir a las otras versiones de otras clases PADRES como una función normal de una subclase
// un objeto puede ser de la clase padre y ser incluido en sus subclases para ejecutar de distinta forma las funciones polimorfas

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream>

using namespace std;

class Persona{ // Super-Clase o clase padre
	private:
		string nombre;
		int edad;
	public:
		Persona(string, int);
		virtual void mostrar(); // polimorfismo: se declara el prototipo con VIRTUAL antes del tipo (cualquiera)
};

class Alumno : public Persona{
	private:
		float nota;
	public:
		Alumno(string, int, float); // constructora con atributos heredados
		void mostrar(); // ahora si que el método se debe definir (se hereda el polimorfismo) y con el MISMO NOMBRE que en la clase padre
		// aunque al momento de llamarlas si se tiene que especificar a cuál clase pertenece para incluir lo que cada clase agrega a la función
		// la función MOSTRAR es la que va a variar según el objeto de cierta clase que lo llame...en el main es donde se clarifica el polimorfismo
};

class Profesor : public Persona{
	private:
		string materia;
	public:
		Profesor(string, int, string);
		void mostrar();
};

Persona::Persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
}

Alumno::Alumno(string _nombre, int _edad, float _nota) : Persona(_nombre, _edad){ // constructor de sub-clase, heredando los de la constructora de la clase padre
	nota = _nota;
}

Profesor::Profesor(string _nombre, int _edad, string _materia) : Persona(_nombre, _edad){ // constructor de sub-clase, heredando los de la constructora de la clase padre
	materia = _materia;
}

void Persona::mostrar(){ // función polimorfa desde la clase Persona
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Alumno::mostrar(){ // función polimorfa desde la clase Alumno
	// para incluir lo de la clase persona no se puede simplemente llamar como mostrar(), ya que sería una recursividad
	Persona::mostrar(); // NO ES NECESARIO INCLUIRLA, en este caso conviene para conectar los atributos a mostrar)
	cout<<"Nota: "<<nota<<endl;
}

void Profesor::mostrar(){ // función polimorfa desde la clase Persona
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;;
}

// función polimorfa (ya no hace falta poner el 'virual')
int main(){
	setlocale(LC_ALL, "Spanish");
	
	Persona *vector[3]; // arreglo de objetos tipo puntero (un struct con los campos que guarda dm con los valores asignados)
	
	// se debe asignr espacio de memoria para cada elemento del arreglo
	vector[0] = new Alumno("Matías", 18, 6.8); // al momento de asignar el 'tipo' de memoria se especifica la clase que difiere el objeto
	// si bien vector es tipo persona, se pueden guardar parámetros extra a sus atributos, que dependiendo qué función llame usará los datos de solo su clase o se incluirá en una subclase
	// la variable es persona pero con los datos extra para una variable alumno (se está guardando como Persona y Alumno)
	// si bien se está llamando a la función polimorfa por su nombre común 'mostrar', ejecutará la función perteneciente a la clase del espacio reservado antes
	vector[0] -> mostrar(); // lo mismo que vector[0].mostrar() pero con punteros
	
	cout<<endl;
	vector[1] = new Profesor("Alejandro", 20, "Programación");
	vector[1] -> mostrar(); 
	// aquí se ve que a pesar de llamar a la misma función para una variable persona, se ejecuta de distinta manera la función según la subclase incluida
	
	getch();
	return 0;
}
