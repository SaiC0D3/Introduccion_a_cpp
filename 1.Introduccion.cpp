// aqu� arriba se definen las librerias para poder usar funciones en el c�digo y macros
#include<iostream> // libreria para usar funciones de salida y entrada de datos 
#include<locale.h> // libreria para usar caracteres en espa�ol
#include<conio.h> // libreria para usar la funci�n getch() y evitar que se cierre la consola
// las librer�as incluyen funciones hechas para usar o extensiones a otras funciones del programa (generalmente se llaman con un . despu�s de la funci�n b�sica ej: f.open())

using namespace std; // para poder usar instrucciones de salida (cout) y entrada (cin)
// de no ponerlo, en el main() se declaran: std::cin>> std::cout<<

// aqu� en medio se definen los prototipos de funciones, varialbes globales, constantes, entre otros
// las variables globales sirven para todas las funciones (sin tener que pasarlas por par�metros) y tienen el �ltimo valor que se le haya asignado en cualquier funci�n

int main(){ // funci�n principal que lee la consola 

	// dentro del main() se escriben las instrucciones principales del programa: llamado de funciones, operaciones simples, def. de variables, etc.
	setlocale(LC_ALL, "Spanish"); // llamado de una funci�n de la libreria para usar espa�ol
	
	// las variables de definen mediante un identificador (nombre) y un valor si lo requiere (se puede cambiar, a menos que se defina en una constante)
	// el identificador de una vairable es la llave para acceder a un valor guardado en un espacio de memoria
	// la memoria RAM del pc se identifica mediante direcciones de memoria a las que se puede acceder
	const int largo = 10; // la otra forma de definir constantes
	char letra = 'a';
	char palabra[30]; // se puede usar el tipo 'string' que guarda palabras o frases completas
	// para guardar una frase usando char conviene usar la funci�n cin.getline(...,...,...);
	// para guardar una frase usando string conviene usar la funci�n getline(cin,...);
	int numero = 16; 
	float decimal = 6.99; // def. de variables de distintos tipos 
	int x;
	
	cout<<"\tHELLO WORLD"<<endl; // cout: imprime un texto (string), coloca margen y salta una l�nea
	
	cout<<"\nIngrese una palabra: ";
	cin>>palabra;
	
	cout<<"\nIngrese un n�mero: ";
	cin>>x; // cin: guarda un valor obtenido por consola en una variable
	
	/* COMENTARIO M�LTIPLE
		-> [ctrl] + [.] para convertir lo seleccionado a comentario
		-> con la funci�n system("pause") de la librer�a <stdlib.h> permite detener la ejecuci�n hasta que se presione una tecla en consola
	*/
	
	getch();
	return 0; // retorno final de la funci�n (al ser tipo entero retorna un entero)
}

// el resto de funciones reutilizables van escritas debajo del main()
