// con el modo de escritura no solo podemos crear un nuevo archivo o reescribirlo, tambi�n se puede a�adir m�s texto al archivo
// para esto lo fundamental que cambia es la forma de abrir el archivo (indicando el modo para texto especial para escribir -> a�adir texto o encriptar texto)
// el texto a�adido en el programa se queda en el archivo de texto de la carpeta (no desaparece al terminar ni cerrar la carpeta)...
// ...si se ejecuta muchas veces se seguir� agregando la misma l�ne de texto desde donde qued� el cursor

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream> // librer�a para poder usar las funciones para archivos

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
	
	archivo<<" Leche, Pan, Carne, Fruta, Cereal, "; // escribimos la nueva l�nea de texto
	// OBS: el texto escrito se a�ade justo donde qued� el indicador en el archivo de texto (no en cualquier parte ni una l�nea despu�s)
	
	archivo.close(); // crramos el archivo creado para guardar lo extra escrito
}
