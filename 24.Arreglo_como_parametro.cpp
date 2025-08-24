// para enviar arreglos como parámetros en una función, hace falta enviar el tamaño del mismo como parámetro además del nombre del arreglo (para poder recorrerlo dentro de la función)
// RECORDAR: cada función debe realizar una sola tarea; si la función calcula el cuadrado, hacer otra pera pedir y mostrar los datos (los 2 últimos pueden ser en el main())

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

#define TAM 5 // constante para el largo del arreglo

/* FORMAS DE OBTENER EL TAMAÑO DEL ARREGLO:
	-> definir el tamaño maximo como constante y usarlo de parámetro (como en este programa)
	-> definir el arreglo y el tamaño como variables globales y luego en la función asignarle un valor al tamaño
	-> crear una función tamño que retorne un entero que será el tamaño
	-> definir el tamaño maximo como constante, crear una variable para el tamaño pedido y mandarlo por referencia a la función que asigna el valor final (RECOMENDADO)
*/

using namespace std;

void cuadrados(int vec[], int); // es necesario especificar el nombre del arreglo con []
void mostrar_cuadrados(int vec[], int);

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int vec[] = {1,2,3,4,5};
	
	// para la llamada solo basta mandar el nombre del arreglo sin []
	cuadrados(vec, TAM); // se manda la constante TAM para el tamaño
	mostrar_cuadrados(vec, TAM); // se muestra el arreglo ahora con los cuadrados de los valores originales
	
	getch();
	return 0;
}

void cuadrados(int vec[], int tam){
	for(int i=0; i<tam; i++){
		vec[i] *= vec[i]; // se reemplaza cada valor del arreglo por su cuadrado
	}
}

void mostrar_cuadrados(int vec[], int tam){
	for(int i=0; i<tam; i++){
		cout<<vec[i]<<" "; 
	}
	cout<<endl;
}
