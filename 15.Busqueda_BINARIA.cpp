// Los m�todos de b�squeda se utilizan para determinar si un elemento est� guardado en un arreglo o lista, la BINARIA divide el arreglo en b�squeda del dato, comparando si es mayor o menor al medio
// la b�squeda binaria s�lo sirvearreglos ORDENADOS de MENOR a MAYOR (se debe aplicar un m�todo de ordenamiento antes de usarlo)
// este m�todo de b�squeda es el m�s optimo para buscar elementos

#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int A[] = {1,2,3,4,5,6,7,8,9}; 
	int i = 0, dato, inf, sup, mitad; // �ndice para recorrer el arreglo, variable para ver el dato buscado y varables para el l�mite inferior y superior del arreglo y para guardar el dato central
	int band = 0; // 0 para False y 1 para True
	
	dato = 7;
	inf = 0; // primera posici�n
	sup = 10; // largo del arreglo
	
	while(inf <= sup){ // mientras el arreglo todav�a exista se ir� dividiendo y buscando el dato
		mitad = (inf+sup)/2; // divide el tama�o del arreglo (guardando la posici�n del medio) // dentro del while pq va cambiando de mitad cada vez
		
		if(A[mitad] == dato){ // primero verifica si el elemento buscado es el de mitad (en pesici�n del medio)
			band = 1;
			break; // de ser ecnontrado, actualizamos la bandera y salimos del ciclo
		}
		
		if(A[mitad] > dato){ // si el dato es menor al elemento en medio, el largo pasa a ser la mitas-1 (para no contar la mitad de nuevo)
			sup = mitad-1;
		} 
		else{ // if(A[mitad] < dato) // si el dato es mayor al elemento en medio, la posici�n inicial pasa a ser la mitas+1 (para no contar la mitad de nuevo)
			inf = mitad+1;
		}
	}
	
	// despu�s de recorrer el arreglo, verifica si hubo cambio en la bandera o no (se encontr� o no el dato)
	if(band) // (band != 0) � (band == 1)
		cout<<"El dato "<<dato<<" est� en la posici�n "<<mitad<<" del arreglo"<<endl;
	else // (band == 0) � (!band)
		cout<<"El dato "<<dato<<" no pertenece al arreglo"<<endl;
	
	getch();
	return 0;
}
