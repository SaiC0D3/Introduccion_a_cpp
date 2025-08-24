// para enviar arreglos como par�metros en una funci�n, hace falta enviar el tama�o del mismo como par�metro adem�s del nombre del arreglo (para poder recorrerlo dentro de la funci�n)
// RECORDAR: cada funci�n debe realizar una sola tarea; si la funci�n calcula el cuadrado, hacer otra pera pedir y mostrar los datos (los 2 �ltimos pueden ser en el main())

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

#define TAM 5 // constante para el largo del arreglo

/* FORMAS DE OBTENER EL TAMA�O DEL ARREGLO:
	-> definir el tama�o maximo como constante y usarlo de par�metro (como en este programa)
	-> definir el arreglo y el tama�o como variables globales y luego en la funci�n asignarle un valor al tama�o
	-> crear una funci�n tam�o que retorne un entero que ser� el tama�o
	-> definir el tama�o maximo como constante, crear una variable para el tama�o pedido y mandarlo por referencia a la funci�n que asigna el valor final (RECOMENDADO)
*/

using namespace std;

void cuadrados(int vec[], int); // es necesario especificar el nombre del arreglo con []
void mostrar_cuadrados(int vec[], int);

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int vec[] = {1,2,3,4,5};
	
	// para la llamada solo basta mandar el nombre del arreglo sin []
	cuadrados(vec, TAM); // se manda la constante TAM para el tama�o
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
