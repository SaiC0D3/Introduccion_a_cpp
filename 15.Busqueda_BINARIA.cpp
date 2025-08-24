// Los métodos de búsqueda se utilizan para determinar si un elemento está guardado en un arreglo o lista, la BINARIA divide el arreglo en búsqueda del dato, comparando si es mayor o menor al medio
// la búsqueda binaria sólo sirvearreglos ORDENADOS de MENOR a MAYOR (se debe aplicar un método de ordenamiento antes de usarlo)
// este método de búsqueda es el más optimo para buscar elementos

#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int A[] = {1,2,3,4,5,6,7,8,9}; 
	int i = 0, dato, inf, sup, mitad; // índice para recorrer el arreglo, variable para ver el dato buscado y varables para el límite inferior y superior del arreglo y para guardar el dato central
	int band = 0; // 0 para False y 1 para True
	
	dato = 7;
	inf = 0; // primera posición
	sup = 10; // largo del arreglo
	
	while(inf <= sup){ // mientras el arreglo todavía exista se irá dividiendo y buscando el dato
		mitad = (inf+sup)/2; // divide el tamaño del arreglo (guardando la posición del medio) // dentro del while pq va cambiando de mitad cada vez
		
		if(A[mitad] == dato){ // primero verifica si el elemento buscado es el de mitad (en pesición del medio)
			band = 1;
			break; // de ser ecnontrado, actualizamos la bandera y salimos del ciclo
		}
		
		if(A[mitad] > dato){ // si el dato es menor al elemento en medio, el largo pasa a ser la mitas-1 (para no contar la mitad de nuevo)
			sup = mitad-1;
		} 
		else{ // if(A[mitad] < dato) // si el dato es mayor al elemento en medio, la posición inicial pasa a ser la mitas+1 (para no contar la mitad de nuevo)
			inf = mitad+1;
		}
	}
	
	// después de recorrer el arreglo, verifica si hubo cambio en la bandera o no (se encontró o no el dato)
	if(band) // (band != 0) ó (band == 1)
		cout<<"El dato "<<dato<<" está en la posición "<<mitad<<" del arreglo"<<endl;
	else // (band == 0) ó (!band)
		cout<<"El dato "<<dato<<" no pertenece al arreglo"<<endl;
	
	getch();
	return 0;
}
