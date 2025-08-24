// las funciones POLIMORFAS son aquellas que, dependiendo del objeto de cierta clase, se ejecutan de una manera espec�fica
// la funci�n padre declara la funci�n polimorfa con 'virtual' y las clases hijas y subclases de las hijas simplemente heredan la funci�n...
// ...luego los objetos del tipo de clase que se creen pueden llamar a la funci�n pero dependiendedo de la clase a la que pertenecen la ejecutar�n de otra manera
// cada clase le a�ade algo a la funci�n polimorfa y las hijas al llamarlas incluyen lo de las clases padres
// Ej: la funci�n mostrar() com�n de todas las clases tendr� diferente c�digo, se difenrencia especificando la clase a la que pertenece la funci�n
// -> de todas formar una funci�n polimorfa puede incluir a las otras versiones de otras clases PADRES como una funci�n normal de una subclase
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
		void mostrar(); // ahora si que el m�todo se debe definir (se hereda el polimorfismo) y con el MISMO NOMBRE que en la clase padre
		// aunque al momento de llamarlas si se tiene que especificar a cu�l clase pertenece para incluir lo que cada clase agrega a la funci�n
		// la funci�n MOSTRAR es la que va a variar seg�n el objeto de cierta clase que lo llame...en el main es donde se clarifica el polimorfismo
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

void Persona::mostrar(){ // funci�n polimorfa desde la clase Persona
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Alumno::mostrar(){ // funci�n polimorfa desde la clase Alumno
	// para incluir lo de la clase persona no se puede simplemente llamar como mostrar(), ya que ser�a una recursividad
	Persona::mostrar(); // NO ES NECESARIO INCLUIRLA, en este caso conviene para conectar los atributos a mostrar)
	cout<<"Nota: "<<nota<<endl;
}

void Profesor::mostrar(){ // funci�n polimorfa desde la clase Persona
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;;
}

// funci�n polimorfa (ya no hace falta poner el 'virual')
int main(){
	setlocale(LC_ALL, "Spanish");
	
	Persona *vector[3]; // arreglo de objetos tipo puntero (un struct con los campos que guarda dm con los valores asignados)
	
	// se debe asignr espacio de memoria para cada elemento del arreglo
	vector[0] = new Alumno("Mat�as", 18, 6.8); // al momento de asignar el 'tipo' de memoria se especifica la clase que difiere el objeto
	// si bien vector es tipo persona, se pueden guardar par�metros extra a sus atributos, que dependiendo qu� funci�n llame usar� los datos de solo su clase o se incluir� en una subclase
	// la variable es persona pero con los datos extra para una variable alumno (se est� guardando como Persona y Alumno)
	// si bien se est� llamando a la funci�n polimorfa por su nombre com�n 'mostrar', ejecutar� la funci�n perteneciente a la clase del espacio reservado antes
	vector[0] -> mostrar(); // lo mismo que vector[0].mostrar() pero con punteros
	
	cout<<endl;
	vector[1] = new Profesor("Alejandro", 20, "Programaci�n");
	vector[1] -> mostrar(); 
	// aqu� se ve que a pesar de llamar a la misma funci�n para una variable persona, se ejecuta de distinta manera la funci�n seg�n la subclase incluida
	
	getch();
	return 0;
}
