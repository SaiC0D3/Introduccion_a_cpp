// Los m�todos de b�squeda se utilizan para determinar si un elemento est� guardado en un arreglo o lista, la SECUENCIAL recorre el arreglo comparando cada elemento con el buscado
// la b�squeda secuencial sirve para todo tipo de arreglos, desordenados u ordenados

#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int A[] = {1,4,3,5,2}; 
	int i = 0, dato; // variable para recorrer las posiciones del arreglo y para ver el dato buscado
	char band = 'F'; // bandera para validar una condici�n (puede ser con 1 y 0 tambi�n)
	
	dato = 3;
	
	// es enste caso usamos WHILE ya que necesitamos m�s de una condici�n (no hace falta seguir recorriendo el arreglo si ya se encontr�)
	while((band == 'F') && (i < 5)){ // recorrer el arreglo mientras no se cumpla condici�n y no se termine el arreglo
		if(A[i] == dato) // si el dato del arreglo coincide con el buscado, actualizamos la bandera
			band = 'V';
		i++; // siguiente elemento del arreglo (aunque encuentre el elemento avanza 1 posici�n m�s y sale del while)
	}
	
	// despu�s de recorrer el arreglo, verifica si hubo cambio en la bandera o no (se encontr� o no el dato)
	if(band == 'V')
		cout<<"El dato "<<dato<<" se encuentra en la posici�n: "<<i-1<<endl; // posici�n i-1 dado que igual se suma una posici�n cuando lo encuentra
	else
		cout<<"EL dato "<<dato<<" no se encuentra en el arreglo"<<endl;
	
	getch();
	return 0;
}


