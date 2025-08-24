// las SUB-CLASES son clases que tienen acceso limitado o total a los atributos y métodos de otra clase padre, además de poseer sus propios atributos y métodos
// los método heredados le permiten trabajar con los atributos de la clase padre como si fueran suyos, pero NO MODIFICARLOS... (en private, en protected SI PUEDEN)
// ...mientras que sus propios métodos funcionan sólo con sus propios atributos, no con los de la clase padre
// la idea de las sub-clases no es tener 2 clases diferentes y cada uno con sus elementos y con algunos compartidos...
// ...la idea es que existen 2 clases con elementos en común pero que están relacionadas entre sí, auqnue los atributos y métodos se trabajen como si fueran clases separadas...
// ...es decir, para cada clase, sea una sub-clase de la otra, al asignar valores a los atributos y ussar métodos se codifican como si fueran 2 clases separadas
// es importante saber que la clase padre no tiene control sobre los elementos de la clase hija, no le pertenecen a diferencia del caso viceversa
// se pueden crear tantas sub-clases como se desee (a su vez pueden crearse sub-clases hermanas, etc...) -> herencia múltiple o JERARQUÍA
// -> cuando una clase deriva de una sub-clase de la clase padre, la clase última hereda todos los atributos de sus predecesores (de la sub-clase que a su vez contiene los de la clase padre)
// -> al momento de asignar los atributos de la clase última se indica que el constructor de SU clase padre ya asignó a los atributos suyos y de la clase padre heredados, no el constructor de cada uno

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream>

using namespace std;

// Definimos la clase padre
class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string, int); // en este caso vamos a inicializar las variables desde la constructora para ver claro el ejemplo de valores heredados
		~Persona(); // destructora
		void mostrarPersona();
};

// Definimos la sub-clase: nombre de la sub-clase : public NombreClasePadre (de esta manera indicamos que la clase estudiante tiene acceso a todo lo público de la clase padre)
// -> si en lugar de 'private' en la clase padre, se usa 'protected' entonces todas las sub-clases (y solo ellas) de ella podrían acceder a los atributos privados
// -> aunque no pueda modificar los valores de los atributos, si que puede trabajar con ellos en la medida que las funciones HEREDADAS lo hagan, no mediante las suyas propias
class Estudiante : public Persona{
	private:
		// string nombre (heredado)
		// int edad (heredado)
		string curso; // podría ser el RUT
		float notaFinal; // en total tiene 4 atributos
	public: // en este caso vamos a inicializar las variables desde la constructora para ver claro el ejemplo de valores heredados
		Estudiante(string, int, string, float); // constructora (de parámetros SIEMPRE van primero los atributos heredados y después los propios, en orden, sea constructora o setter)
		~Estudiante(); // destructora
		// la constructora (y los valores inicializados) y destructora de la clase padre también se heredan
		// void mostrarPersona() (heredado) 
		void mostrarDatos(); // no puede tener el mismo nombre que la mostrar heredada a menos que sea polimorfismo
};

Persona::Persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
} // inicializamos los atributos de la clase padre

Persona::~Persona(){
} // después de las contructoras y destructoras de la clase padre van los de la clase hija y después las funciones de cada una en la misma jerarquía

// después de los 4 parámetros de la sub-clase se indican los parámetros ya inicializados desde la constructora de la clase padre (especificando cuáles de los 4 ya se inicializaron)
Estudiante::Estudiante(string _nombre, int _edad, string _curso, float _nota) : Persona(_nombre, _edad){ // <- para HEREDAR los valores inicializados
	// ahora procedemos a pedir los valores de los atributos porpios o los que faltan
	curso = _curso;
	notaFinal = _nota;
}

Estudiante::~Estudiante(){
}

void Persona::mostrarPersona(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Estudiante::mostrarDatos(){ // como tiene acceso a ella al ser sub-clase, se pueden llamar cualquier método de la clase padre
	mostrarPersona(); // aprovechamos de usar la función heredada, pero la clase por si sola podría mostrar los atributos heredados en su propia función (con protected)
	cout<<"Nivel: "<<curso<<endl; // ahora mostramos el resto de atributos que faltan de la sub-clase
	cout<<"Nota Final: "<<notaFinal<<endl;
}

int main(){
	setlocale(LC_ALL, "Spanish");
	
	Estudiante student("Matías", 18, "2do Año", 6.6); // creamos el objeto de la sub-clase con atributos de la sub-clase que tiene los de ambas clases creadas
	// los objetos creados solo reciben los atributos y usan los métodos, por lo que se crean del tipo de clase que se necesite trabajar
	
	// el objeto estudiante puede llamar a cualquier función de ambas clases, ya que pertenece a la sub-clase
	student.mostrarDatos();
	
	getch();
	return 0;
}
