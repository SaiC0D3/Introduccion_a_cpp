// las funciones void se pueden aprovechar para hacer funciones que devuelvan valores m�ltiples (m�s de un resultado) mediante el uso de valores por referencia en lugar de mostrarlo dentro de si misma
// en realidad la funci�n no est� retornando valores m�ltiples, si no que est� actualizando los registros de memoria de variables que ya se hab�an declarado,
// ...para devolver verdaderamente m�ltiples valores en C++ (con "return") se deben emplear arrays o structs
// ya sean m�ltiples valores o solo uno, el enviar par�metros por referencia sirve para definir una variable en el main(),
// darle un valor desde la funci�n con la llamada y poder usar ese valor en otras funciones o partes del main()

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

void calcular(int, int, int&, int&); // variables enteras para los n�meros leidos y ambos resultados a devolver

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num1, num2, suma = 0, producto = 0; // se definen las variables sumas y producto en el main() con valor inicial de 0
	
	cout<<"Ingrese dos n�meros: "<<endl; 
	cin>>num1>>num2;
	
	// se llama a la funci�n mand�ndoles como par�metros las variables para obtener su valor verdadero final desde la funci�n
	calcular(num1, num2, suma, producto);
	
	// ahora ambos valores se actualizaron de su valor inicial y se pueden mostrar en el main()
	cout<<"\nLa suma es: "<<suma;
	cout<<"\nEl producto es: "<<producto<<endl;
	
	getch();
	return 0;
}

void calcular(int x, int y, int& suma, int& producto){
	// los valores asignados a las variables de los par�metros por referencia se traspasan a los de la llamada para poder mostrarlos en el int main
	suma = x + y;
	producto = x * y;
}
