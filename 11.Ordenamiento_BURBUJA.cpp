// los métodos de ordenamiento se utilizan para ordenar los elementos de listas y/o arreglos, el BURBUJA compara de a dos elementos dejando el menor antes y el mayor después 
#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int numeros[5] = {2,3,1,5,4}; // arreglo desordenado
	int i, j, aux; // índices de los ciclos y auxiliar para intercambiar valores 
	
	/* ALGORITMO:
		coompara la posición actual con la siguiente: 
		-> si es mayor que el sig. se intercambian los valores y avanza al siguiente
		-> si es menor que el sig. avanza al siguiente, coomparando con el subsiguiente
		repite el algoritmo la misma cantidad de elementos del arreglo
	*/
	
	for(i=0; i<5; i++){ // ciclo para repetir el algoritmo
		for(j=0; j<4; j++){ // ciclo para recorrer el arreglo
			if(numeros[j] > numeros[j+1]){ // si el anterior es mayor, se intercambian los valores y avanza al sgte.
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}
	
	// mostramos el arreglo que ahora está ordenado
	cout<<"Orden Ascendente: ";
	for(i=0; i<5; i++){
		cout<<numeros[i]<<" ";
	}
	
	cout<<"\nOrden Descendente: ";
	for(i=4; i>=0; i--){
		cout<<numeros[i]<<" ";
	}
	
	getch();
	return 0;
}
