// las FUNCIONES sirven para dividir el programa en distintas y específicas partes, cada funión dessarrolla 1 sola tarea
// las plantillas de funciones, entre otras cosas, sirven para crear funciones con parámetros de variable general (aplican para cualquier tipo)
// se definen como funciones void, pero con la declaración de un PREFIJO donde se especifica la modificación, por lo que NO RETORNAN ningún valor

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

// PROTOTIPO: siempre va arriba antes de la función que lo usa como parámetro
template <class TIPOD> // PREFIJO: declara el tipo global de dato para los parámetros (TIPOD o cualquier nombre)
void valor_absoluto(TIPOD numero); // de esta forma indicamos que cualquier tipo de dato numérico va a ser aceptado

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num1; float num2; double num3;
	
	cout<<"Ingrese un entero: "; cin>>num1;
	cout<<"Ingrese un flotante: "; cin>>num2;
	cout<<"Ingrese un double: "; cin>>num3;
	
	// LLAMADA:
	valor_absoluto(num1);
	valor_absoluto(num2);
	valor_absoluto(num3);
	
	getch();
	return 0;
}

// DEFINICIÓN:
template <class TIPOD> // siempre va arriba antes de la función que lo usa como parámetro
void valor_absoluto(TIPOD numero){ // para calcular el valor absoluto de enteros, flotantes, etc
	
	if(numero < 0)
		numero = numero * (-1);
	
	cout<<"\nEl valor absoluto es: "<<numero<<endl;
}
