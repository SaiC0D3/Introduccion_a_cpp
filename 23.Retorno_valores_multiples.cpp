// las funciones void se pueden aprovechar para hacer funciones que devuelvan valores múltiples (más de un resultado) mediante el uso de valores por referencia en lugar de mostrarlo dentro de si misma
// en realidad la función no está retornando valores múltiples, si no que está actualizando los registros de memoria de variables que ya se habían declarado,
// ...para devolver verdaderamente múltiples valores en C++ (con "return") se deben emplear arrays o structs
// ya sean múltiples valores o solo uno, el enviar parámetros por referencia sirve para definir una variable en el main(),
// darle un valor desde la función con la llamada y poder usar ese valor en otras funciones o partes del main()

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

void calcular(int, int, int&, int&); // variables enteras para los números leidos y ambos resultados a devolver

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num1, num2, suma = 0, producto = 0; // se definen las variables sumas y producto en el main() con valor inicial de 0
	
	cout<<"Ingrese dos números: "<<endl; 
	cin>>num1>>num2;
	
	// se llama a la función mandándoles como parámetros las variables para obtener su valor verdadero final desde la función
	calcular(num1, num2, suma, producto);
	
	// ahora ambos valores se actualizaron de su valor inicial y se pueden mostrar en el main()
	cout<<"\nLa suma es: "<<suma;
	cout<<"\nEl producto es: "<<producto<<endl;
	
	getch();
	return 0;
}

void calcular(int x, int y, int& suma, int& producto){
	// los valores asignados a las variables de los parámetros por referencia se traspasan a los de la llamada para poder mostrarlos en el int main
	suma = x + y;
	producto = x * y;
}
