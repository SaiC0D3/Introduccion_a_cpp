// Los métodos de búsqueda se utilizan para determinar si un elemento está guardado en un arreglo o lista, la SECUENCIAL recorre el arreglo comparando cada elemento con el buscado
// la búsqueda secuencial sirve para todo tipo de arreglos, desordenados u ordenados

#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int A[] = {1,4,3,5,2}; 
	int i = 0, dato; // variable para recorrer las posiciones del arreglo y para ver el dato buscado
	char band = 'F'; // bandera para validar una condición (puede ser con 1 y 0 también)
	
	dato = 3;
	
	// es enste caso usamos WHILE ya que necesitamos más de una condición (no hace falta seguir recorriendo el arreglo si ya se encontró)
	while((band == 'F') && (i < 5)){ // recorrer el arreglo mientras no se cumpla condición y no se termine el arreglo
		if(A[i] == dato) // si el dato del arreglo coincide con el buscado, actualizamos la bandera
			band = 'V';
		i++; // siguiente elemento del arreglo (aunque encuentre el elemento avanza 1 posición más y sale del while)
	}
	
	// después de recorrer el arreglo, verifica si hubo cambio en la bandera o no (se encontró o no el dato)
	if(band == 'V')
		cout<<"El dato "<<dato<<" se encuentra en la posición: "<<i-1<<endl; // posición i-1 dado que igual se suma una posición cuando lo encuentra
	else
		cout<<"EL dato "<<dato<<" no se encuentra en el arreglo"<<endl;
	
	getch();
	return 0;
}


