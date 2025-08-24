// los métodos de ordenamiento se utilizan para ordenar los elementos de listas y/o arreglos, el SELECCIÓN determina el menor elemento cada vez para moverlo al inicio

#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int numeros[] = {3,4,5,2,1}; // arreglo desordenado
	int i, j, aux, min; // indices para los bucles, auxiliar para intercambiar valores y variable para guardar la posición del menor
	
	/* ALGORITMO:
		determina el menor valor general del arreglo: 
		-> lo coloca al inicio del arreglo
		-> determina el menor valor del arreglo desde la siguiente posición (arreglo menos el inicial)
		-> lo coloca al inicio del arreglo chico (arreglo menos el inicial)
		repite el algoritmo hasta que el útlimo elemento coincida con el largo y se el menor del arreglo chico donde solo es el
	*/
	
	for(i=0; i<5; i++){ // ciclo para recorrer el arreglo
		min = i; // asumimos que la posición inical es el menor
		for(j=i+1; j<5; j++){ // recorremos desde la siguiente posición
			if(numeros[j] < numeros[min]){ // si el valor actual es menor al valor con la posición asumida como menor
				min = j; 				  // se intercambia la posición para el menor (no el valor)
			}
		} // al final del ciclo ya se recorrieron todas las posiciones y se tiene el valor menor temporal del arreglo 
		aux = numeros[i]; // se intercambia el valor actual con el menor temporal
		numeros[i] = numeros[min];
		numeros[min] = aux;
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
