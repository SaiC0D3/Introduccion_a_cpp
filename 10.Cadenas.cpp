// las cadenas (strings) son arreglos de �nicamente caracteres, para guardar palabras, oraciones, etc.

#include<iostream>
#include<locale.h>
#include<string.h> // libre�a para usar funi�nes preestablecidas para trabajar con strings
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	// hay 3 formas de definir cadenas (de peor a mejor):
	char palabra1[] = "Matias"; // para acceder a caracteres de la cadena basta con 'llamar' a la variable con la posici�n del caracter: palabra1[0] = 'M' (para recorrer una cadena se usa un bucle)
	char palabra2[] = {'M','a','t','i','a','s'}; // si la palabra es menor al largo se puede especificar que termina a�adiendio '\n' al arreglo (para que no guarde pasura despu�s)
	char nombre[20]; // es ideal especificar el largo de la cadena cuando no sabemos cuantos caract�res va a tener (pedir por consola)
	
	// se pueden operar los valores directamente desde el nombre de la variable y la posici�n
	// ej: a[3] = a[2] + 3 (donde a es un arreglo de enteros)
	
	// se pueden unir cadenas con el operador de +
	// ej: A[] = "Hola", B[] = "Mundo" -> C[] = A[] + B[] =  "HolaMundo" 
	
	cout<<"Ingrese su nombre: ";
	
	/* Hay 4 formas de guardar cadenas (de peor a mejor):
	
		// guarda caracteres juntos hasta que haya un espacio (aunque sobre espacio)
		char letra[10];
		cout<<"Ingrese una frase: "; => [...hola tu...]
		cin>>letra; // solo guarda 'hola' y lo dem�s se llena de basura
		
		// guarda todo los caracteres que se ingresen, supere o no el largo estabelcido
		char word[2];
		cout<<"Ingrese una frase: "; => [...hola...]
		gets(word); // guarda 'hola' ocupando espacio extra
		
		// guarda todas las palabras escritas hasta que haya un salto de l�nea
		string frase;
		cout<<"Ingrese una frase: ";
		getline(cin, frase);
		cout<<"��"<<frase<<"��"<<endl;
		-> para asingar valores, comparar, etc. no hace falta de las funciones de <string.h> se hacen como variables normales
		
		// guarda todo lo escrito hasta que uno presione un caracter para temrinar
		char texto[30];
		cout<<"Ingrese un texto: ";
		cin.getline(variable (texto), largo (30), caracter para terminar (ej:'\n'))
		-> para acceder a cada caracter se recorre el arreglo
		
	*/
	
	cin.getline(nombre, 20, '\n'); // guardar en nombr, m�ximo 20 caract�res, hasta que se presione un salto de l�nea (enter: '\n')
	
	cout<<"\nBienvenido, "<<nombre<<endl;
	
	// FUNCIONES STRING.H:
	// la comparaci�n (a>b, etc.) y asignaci�n (a=b) de cadenas se deben hacer con las funciones (strcmp y strcpy)
	int largo;
	largo = strlen(nombre); // funici�n que retorna la cantidad de caract�res de una cadena (retorna un n�mero entero)
	
	char word[]= "Hola ", word_copy[10]; // cualquier largo por defecto a la copia
	strcpy(word_copy, word); // -> word_copy = "Hola " (a la vac�a se le asigna la variable con la info. a compiar)
	
	char uno[] = "Mati", dos[] = "mati"; // como son distintos no se muestra el if()
	if(strcmp(uno, dos) == 0) cout<<"Son iguales";
	/* strcmp(a, b) compara si son iguales las cadenas o si son diferentes:
		-> strcmp(a, b) == 0 si son iguales las cadenas
		-> strcmp(a, b) > 0 si a va despu�s alfab�ticmente que b  // strcmp(a, b) != 0
		-> strcmp(a, b) < 0 si a va antes alfab�ticmente que b   // si son diferentes las cadenas
	*/
	
	strcat(word_copy, uno); cout<<"\n"<<word_copy; 
	// strcat(a, b) concatena (une) dos cadenas, lo de b justo al final de lo de a (es recomendable unir una copia de la primera cadena para no perser su valor original)
	
	strrev(uno); // invierte la cadena -> uno = "itaM"
	 
	strupr(uno); // trasnforma a may�sculas toda la cadena -> uno = ITAM
	strlwr(uno); // trasnforma a min�sculas toda la cadena -> uno = itam
	// si invirti�ramos la cadena uno ahora ser�a igual a la cadena dos
	
	cout<<"\n"<<uno<<endl; // conviene hacer una copia para no perder el valor original
	
	// memccpy(a,b,c,n) -> copia el contenido del strring b en a hasta que encuentre el caracter c � haya copiado n caracteres
	
	/* STDLIB.H
		atoi(variable) -> transforma n�meros enteros escritos como caract�res a enteros operables
		atof(variable) -> transforma n�meros flotantes escritos como caract�res a flotantes operables
	*/
	
	getch();
	return 0;
}
