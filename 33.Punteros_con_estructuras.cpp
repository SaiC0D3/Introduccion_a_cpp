// la forma de almacenar estructuras en punteros tiene la especialidad de utlizar el operador '->' para señalar a un campo de la estructura específico
// el puntero almacena la dm del struct, la cual contiene toda la info de sus campos, para acceder a estos se apunta a la región específica de la dm con -> campo
// cuando son arreglos de estructura, es lo mismo que los arreglos en cuanto a mandar la dm del primer elemento para obtener los demás avanzando el índice...
// ...lo que si cambia es al momento de guardar o mostrar los elementos: videojuegos[3] // (dir+i)->campo que es lo mismo que dir[i].campo sin punteros

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

struct Videojuego{
	char nombre[30];
	int anio;
} videojuego, *dir = &videojuego; // se necesita una variable tipo struct para rellenar los campos y el puntero del mismo tipo struct para trabajarlos (le asignamos de una la dm)

void pedir_datos();
void mostrar(Videojuego *); // puntero struct de parámetro

int main(){
	setlocale(LC_ALL, "Spanish");
	
	pedir_datos();
	mostrar(dir); // mandamos el puntero struct para que reciba su dm (o se puede mandar '&videojuego' directamente)
	
	getch();
	return 0;
}

void pedir_datos(){
	cout<<"Ingrese nombre: ";
	cin.getline(dir->nombre, 30, '\n'); // lo mismo que poner 'dir.nombre' sin punteros
	
	cout<<"Ingrese año de lanzamiento: "; cin>>dir->anio;
}

void mostrar(Videojuego *dir){
	cout<<"\n .:VIDEOGAME:. \n";
	cout<<"\nName: "<<dir->nombre;
	cout<<"\nRelease: "<<dir->anio;
	cout<<endl;
}
