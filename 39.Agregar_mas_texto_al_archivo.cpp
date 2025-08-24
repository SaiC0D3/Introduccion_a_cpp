// con el modo de escritura no solo podemos crear un nuevo archivo o reescribirlo, también se puede añadir más texto al archivo
// para esto lo fundamental que cambia es la forma de abrir el archivo (indicando el modo para texto especial para escribir -> añadir texto o encriptar texto)
// el texto añadido en el programa se queda en el archivo de texto de la carpeta (no desaparece al terminar ni cerrar la carpeta)...
// ...si se ejecuta muchas veces se seguirá agregando la misma líne de texto desde donde quedó el cursor

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream> // librería para poder usar las funciones para archivos

using namespace std;

void agregar(); 

int main(){
	setlocale(LC_ALL, "Spanish");
	
	agregar();
	
	getch();
	return 0;
}

void agregar(){
	ofstream archivo; // como escribimos texto nuevo se sigue usando el tipo de archivo para ESCRITURA
	
	archivo.open("lista.txt", ios::app); // abrimos el archivo en modo especial
	
	if(archivo.fail()){ // verificamos que el archivo exista
		cout<<"\nNo se ha podido abrir el archivo"<<endl;
		exit(1);
	}
	
	archivo<<" Leche, Pan, Carne, Fruta, Cereal, "; // escribimos la nueva línea de texto
	// OBS: el texto escrito se añade justo donde quedó el indicador en el archivo de texto (no en cualquier parte ni una línea después)
	
	archivo.close(); // crramos el archivo creado para guardar lo extra escrito
}
