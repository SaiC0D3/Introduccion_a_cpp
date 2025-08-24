// los ARCHIVOS o FICHEROS nos permiten guardar los datos que el programa ma a utilizar al momento de ejecutar para no perderlos una vez terminados
// son notas de texto en la que anotamos los valores a usar en el programa (números, palabras, letras, etc.) 
// el programa puede crear, abrir, llenar, leer y cerrar un archivo de texto (siempre se debe abrir para llenar y leer los datos, después se debe cerrar al terminar las instrucciones)
// para que el programa lea e archivo una vez creado, se debe especificar la dirección del archivo (en caso de que no esté en la misma carpeta del ejecutable)
// se puede abrir el archivo de texto en varias partes de la función siempre y cuando se cierre cada vez
// si no se desea crear el archivo en el programa se puede crear un block de notas fuera en la misma carpeta y mandar a leer el archivo al abrirlo...
// ...con modo escritura se crea un nuevo o reescribe el que haya con mismo nombre; y en modo lectura solo se lee un archivo ya creado (no se puede crear un archivo en modo lectura)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream> // librería para poder usar las funciones para archivos

using namespace std;

void crear(); // para llenar el archivo de texto creado
void lectura(); // para leer un archivo de texto

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int opcion;
	
	do{
		cout<<"\t.:MENÚ:."<<endl;
		cout<<"1. Escribir en el archivo:"<<endl;
		cout<<"2. Leer un archivo"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"\nOpción escogida: "; cin>>opcion;
		
		switch(opcion){
			case 1:
				crear();
				cout<<"\nArchivo creado correctamente\n"<<endl;
				system("pause");
				break;
			case 2: 
				cout<<"\nMostrando texto del archivo:"<<endl;
				lectura();
				cout<<endl;
				system("pause");
				break;
			case 3: break;
			default: cout<<"\nOpción inválida"<<endl;
		}
		system("cls"); // para limpiar la pantalla cada vez que se muestre el menú (requiere un system pause en cada case para que se muestren)
	}while(opcion != 3);
	
	getch();
	return 0;
}

void crear(){
	// 0) Creamos la variable del tipo de archuvo a trabajar (indicar modo de salida (input/ouput)):
	ofstream archivo; // o(uput)stram es como el 'tipo' de dato de la variable 'archivo', esta variable se usará para las funciones del archivo de SÓLO ESCRITURA
	
	// 1) Abrir un archivo:
	// archivo.open("nombre.txt"); // dentro va el nombre o dirección del archivo a abrir (en este caso va a buscar un .txt llamado nombre)
	// archivo.open("C:\Carpeta\ejemplo.txt") -> en este caso la nota de texto se crea en la dirección específicada (unidad disco, en la carpeta donde se encuentra el block de notas (debe existir la carpeta))
	
	/* 	se puede pedir el nombre con una variable y mandarla en el parámetro:
		srting nombreArchivo; // el tipo strig es para guardar una frase entera, se guardan con la función getline y en sus parámetros se especifica para dónde se guarda (cin por defecto u otra variable) y la variable que contendrá el string
		cout<<"Ingrese nombre del archivo: "; // debe terminar en.txt y no tener espacios
		getline(cin, nombreArchivo); // se abre después de pedir el nombre
		archivo.open(nombreArchivo.c_str()); -> en este caso para leer el nombre ingresado se le aplica una función de la nueva librería al nombre de la variable
		(!) se puede hacer con los string convencionales (char) y cin o cin.getline() de todas formas (y ahorrarse funciones como lo de .c_str())
	*/
	
	// 1.2) Crear y abrir un archivo:
	archivo.open("prueba.txt", ios::out); // con ios::('out' indicamos que es modo escritura, se manda el nombre en el parámetro (si ya exite reemplaza lo que tenga con lo que escriba ahora))
	// no hace falta poner el modo del archivo (ios::etc) para crear o leer un archivo si se guarda el nombre con un char
	
	// 2) Verificar que el archivo se haya creado correctamente (o exista para abrirlo):
	if(archivo.fail()){ // archivo.fail != fail -> la función .fail booleana retorna true por defecto, si se cumple es que no existe el archivo en la carpeta
		cout<<"\nNo se ha encontrado el archivo"<<endl;
		exit(1); // indicamos que no existe y terminamos el programa
	}
	
	// 3) Escribir en el archivo:
	archivo<<"Texto copiado exitosamente en el archivo :D "; // de esta manera escribimos un texto en la nota de texto: el nombre d ela variable archivo y las << del cout (como mostrando qué imprimir)
	/*	se puede pedir el nombre con una variable y mandarla en el parámetro:
		srting frase; // el tipo strig es para guardar una frase entera
		cout<<"Ingrese el texto del archivo: ";
		getline(cin, frase); 
		
		archivo<<frase; // se 'muestra' la variable con el texto guardado
		
		-> para escribir números o letras simples se usa el tipo de variable correspondiente (arch<<letra / arch<<num)
	*/
	
	// 4) Cerrar el archivo:
	archivo.close(); // crramos el archivo creado para guardar lo nuevo escrito
}

void lectura(){
	ifstream archivo; // i(nput)stram es como el 'tipo' de dato de la variable 'archivo', esta variable se usará para las funciones del archivo de SÓLO LECTURA 
	string texto; // para leer necesita un avariable en la que guardar cada frase (terminan en un salto de línea) para mostrarla
	
	// ABRIMOS ARCHIVO:
	archivo.open("prueba.txt", ios::in); // con ios::(con 'in' indicamos que es modo lectura...)
	// en modo lectura no crea ni reescribe un archivo, solo lee el nombre indicado en parámetros (ya sea preescrito, una dirección o ingresado por el usuario)
	// en este caso el único archivo creado es 'prueba' (podemos crear un archivo y leerlo acto seguido)
	
	// VERIFICAMOS ARCHIVO:
	if(archivo.fail()){ // si el archivo falla es porque no existe
		cout<<"\nNo se ha encontrado el archivo"<<endl;
		exit(1);
	}
	
	// LEEMOS EL ARCHIVO:
	while(!archivo.eof()){ // archivo.eof() == false -> la función booleana .e(nd)o(f)f(ile) nos indica si la línea que se está leyendo es la última del archivo (retorna true por defecto)
		getline(archivo, texto); // sacamos la frase del texto (saca toda la primera frase hasta el salto de línea y sigue con la siguiente hasta que sea la última línea)
		cout<<"´´"<<texto<<"´´"<<'\n'; // mostramos la frase sacada del texto
		// la otra forma de obtener palabras (pero solo letras, palabras o números) es con: el nombre de la variable archivo y las >> del cin (indicando que se lee un número, caracter o palabra)
		// archivo>>letra (siendo letra una variavle 'char') -> en este caso lee hasta un espacio
		// y al mostrar se debe mandar 'letra', no 'archivo' (en caso de char se muestra letra por letra , no guarda la frase o palabra entera)
	}
	
	// CERRAMOS EL ARCHIVO:
	archivo.close();
}
