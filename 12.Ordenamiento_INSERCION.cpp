// los m�todos de ordenamiento se utilizan para ordenar los elementos de listas y/o arreglos, el INSERCI�N compara de a 2 con el anterior y el siguiente,
//																							  para ir moviendo el menor al incio siempre

#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int numeros[] = {3,4,2,1,5}; // srreglo desordenado
	int i, pos, aux; // indice del bucle, variable para ver la posici�n espec�fica y axuiliar para intercambiar valores
	
	
	/* ALGORITMO:
		coompara la posici�n actual con la anterior: 
		-> si el anterior es mayor, se intercambian los valores
			-> si todav�a hay un elemento anterior, se repite lo anterior
		-> si el anterior es menor, avanza con el siguiente
		repite el algoritmo hasta que no hayan elementos anteriores mayores en cada posici�n
	*/
	
	for(i=0; i<5; i++){ // ciclo para recorrer el arreglo
		pos = i; // guardamos la posici�n actual
		aux = numeros[i]; // guardamos el valor de la posici�n actual
		
		// ciclo para ir comparando con el anterior y el siguiente valor e ir moviendo hacia el inicio el valor actual (si es menor que el anterior)
		while((pos > 0) && (numeros[pos-1] > aux)){ // intercambia valores con el anterior mientras no sea la posic�n inicial (disminuya la posici�n),
			numeros[pos] = numeros[pos-1]; 			// y si el anterior es mayor que el valor actual
			pos--;
		}
		numeros[pos] = aux; // se mantiene el valor en caso de que ya est� ordenado o se cambia por el valor guardado que se fue moviendo
	}
	
	// mostramos el arreglo que ahora est� ordenado
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
