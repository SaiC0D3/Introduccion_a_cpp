//  los PUNTEROS son variables que almacenan direcciones de memoria (apuntan a la dm de alguna variable, estructura, etc.) pero también tienen su propia dm asignada contigua
// una dirección de memoria (RAM, en bytes) es el espacio de la memoria del pc que se destina para una tarea o instrucción (en estos casos para almacenar variables, estrcutras, objetos, etc.)
// como un puntero almacena otra dm, mediante el puntero se puede acceder a la variable dentro de la dm y modificar su valor
// también se puede definir un puntero que guarde la dm de otro puntero (puntero doble), el cual se definie con ** antes del nombre, el resto de asignaciones es igual

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num = 60;
	
	///////// SIN PUNTERO //////////////////////////////////////////////////////////////////
	
	// para ver el valor de la variable
	cout<<"Valor de num: "<<num<<endl;
	
	// para ver dónde está almacenada la variable, no su valor
	cout<<"Dirección de memoria de num: "<<&num<<endl;
	
	///////// CON PUNTERO /////////////////////////////////////////////////////////////////
	
	int *point; // para define un puntero se coloca un asterisco junto al nombre de la variable puntero
	
	point = &num; // asignación de la dm de num a la variable puntero (deben ser del mismo tipo)
	// ahora la variable point apunta a la dm de num (se puede acceder al valor de num como a su dm solo con el puntero)
	
	/*
		Si no se le asigna una dm a un puntero, al igual que con variables, toma una dm basura cualquiera
		-> para evitar esto es bueno ponerle por defecto el valor de nullptr o NULL
	*/
	
	// para ver el valor de la variable mediante el puntero
	cout<<"\nValor de num en el puntero: "<<*point<<endl; // se coloca igual como se define
	
	// para ver dónde está almacenada la variable, no su valor, mediante el puntero
	cout<<"Dirección de memoria de num en el puntero: "<<point<<endl; // el nombre de la variable sin el * ni & porque el 'valor' de la variable point es la dm de num
	
	// para mostrar la dm del puntero
	cout<<"Dirección de memoria del puntero: "<<&point<<endl;
	
	getch();
	return 0;
}
