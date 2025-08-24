// las estructuras anidadas son structs donde uno o más campos son otros structs

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

// struct secundario
struct info_direccion{ // struct que va a ser campo del struct estudiantes (se declara antes para que sea posible crear una variable de este tipo después)
	char region[30];
	char ciudad[30];
	char calle[30];
}; 

// struct principal
struct Estudiante{
	char nombre[20];
	char universidad[40];
	struct info_direccion direccion; // el campo 'direccion' del struct estudiante es de tipo 'info_direccion' (otro struct)
};

int main(){
	setlocale(LC_ALL, "Spanish");
	
	Estudiante estudiante;
	
	cout<<"Ingrese su nombre: "; cin.getline(estudiante.nombre, 20, '\n');
	cout<<"Ingrese universidad: "; cin.getline(estudiante.universidad, 40, '\n');
	cout<<"\nIngrese su dirección:"<<endl; // primero se llama al campo del struct principal y después al campo del struct secundario (no al nombre del struct)
	cout<<"Ingrese región: "; cin.getline(estudiante.direccion.region, 30, '\n');
	cout<<"Ingrese ciudad: "; cin.getline(estudiante.direccion.ciudad, 30, '\n');
	cout<<"Ingrese calle: "; cin.getline(estudiante.direccion.calle, 30, '\n');
	
	// mostramos los datos de forma similar a como fueron ingresados
	cout<<"\n\nEstudiante Registrado!"<<endl;
	cout<<"\nNombre: "<<estudiante.nombre;
	cout<<"\nUniversidad: "<<estudiante.universidad;
	cout<<"\nDirección: calle "<<estudiante.direccion.calle<<", "<<estudiante.direccion.ciudad<<", "<<estudiante.direccion.region<<endl;
	
	getch();
	return 0;
}
