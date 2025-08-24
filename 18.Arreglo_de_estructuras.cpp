// los arreglos de estructuras son agrupaciones de strctus en cada posición (llenan mucho el buufer de basura al pedir datos)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

// struct secundario
struct info_artista{ // struct que va a ser campo del struct estudiantes (se declara antes para que sea posible crear una variable de este tipo después)
	char nombre[30];
	char pais[20];
}; 

// struct principal
struct Cancion{
	char name[20];
	int replays;
	struct info_artista artista;
} canciones[2]; // al momento de declarar variables de tipo Cancion se especifica la cantidad de elementos en el arreglo
// el arreglo cacniones tiene 2 elementos que son struct tipo Cancion

int main(){
	setlocale(LC_ALL, "Spanish");
	
	for(int i=0; i<2; i++){ // ciclo para pedir los datos de los campos de cada elemento struct del arreglo
		fflush(stdin); // función para vaciar el buffer luego de pedir el primer elemento (para que no se autocomplete con basura el siguiente)
		cout<<"CANCIÓN N°"<<i+1<<endl;
		cout<<"\nIngrese nombre: "; cin.getline(canciones[i].name, 20, '\n');
		cout<<"Ingrese reproducciones: "; cin>>canciones[i].replays;
		cin.ignore(); // función para eliminar los saltos de linea adicionales generados al ingresar un entero y después un string (en el buffer)
		cout<<"Ingrese artista: "; cin.getline(canciones[i].artista.nombre, 30, '\n');
		cout<<"Ingrese nacionalidad: "; cin.getline(canciones[i].artista.pais, 20, '\n');
		cout<<endl;
	}
	
	/* PROBLEMAS CON EL BUFFER:
		otra forma de leer string cuando no necesita espacios, es con 'std::string cin>>/cout<<'
		-> usando esto no haría falta usar cin.ignore() cuando se piden datos distintos
		otra forma de usar cin.ignore() para que descarte todos los caractéres que encuentre hasta el primer salto de línea '\n' (que también se descartará) es:
		-> 	#include<limits>
			cin.ignore(std::numeric_limits<int>::max(),'\n');
	*/
	
	cout<<"--------------------------------"<<endl;

	// mostramos los datos de forma similar a como fueron ingresados
	for(int i=0; i<2; i++){
		cout<<"\nCANCIÓN N°"<<i+1<<endl;
		cout<<"\nNombre: "<<canciones[i].name<<" ("<<canciones[i].replays<<" reproducciones)";
		cout<<"\nArtista: "<<canciones[i].artista.nombre<<" ("<<canciones[i].artista.pais<<")";
		cout<<endl;
	}
	
	getch();
	return 0;
}
