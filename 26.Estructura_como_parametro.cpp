// para enviar estructuras como parámetros en una función se define el struct, se crea una variable de ese tipo y en la función de declara una variable del tipo estructura creado
// ...después en la llamada se manda la variable creada en la def. del struct

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#define MAX 50

using namespace std;

// el struct se define antes de los prototipos de funciones
struct Persona{
	char nombre[MAX];
	int edad;
} p1; // p1 es la variable a usar en las funciones, para pedir dartos, mostrar, etc.
	// ...p1 funciona como una variable global; su valor se puede usar y actualizar en cualquier función

void pedirDatos();
void mostrarDatos(Persona); // basta con especificar el tipo de variable (en este caso el nombre del struct)

int main(){
	setlocale(LC_ALL, "Spanish");
	
	pedirDatos();
	mostrarDatos(p1); // se le envía p1 para mostrar sus datos recién ingresados
	
	getch();
	return 0;
}


void pedirDatos(){
	cout<<"Ingrese su nombre: "; cin.getline(p1.nombre, MAX,  '\n');
	cout<<"Ingrese su edad: "; cin>>p1.edad;
}

void mostrarDatos(Persona p){ // función para mostrar en general cualquier struct del tipo Persona
	cout<<"\nREGISTRADO\n";
	cout<<"\nPersona 1: "<<p.nombre<<" ("<<p.edad<<" años)"<<endl;
}
