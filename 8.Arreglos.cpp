// los vectores o arreglos sirven para almacenas una seria de datos del mismo tipo en espacion contiguos de memoria (cada uno con un sub�ndice de posici�n desde 0 hasta n-1)

#include<iostream>
#include<locale.h>
#define n 10 // largo del arreglo constante, el arreglo puede ocupar hasta 10 espacios, no necesariamente todos pero quedan con basura
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* DEFINICI�N
		tipo nombre[tama�o]
		tipo2 nombre2[tama�o] = {datos separados por coma}
		
		---no hace falta definir un tama�o, dejando [] vac�o, o generalmente de define como una constante y se teutiliza en los arreglos
		--para acceder al valor asignado a una posici�n vasta con "llamar" a la variable con la posici�n entre []
	*/
	
	int numeros[] = {1,2,3,4,5}; // numeros[5] = {1,2,3,4,5}
	char letras[n] = {'a','e','i','o','u'};
	
	cout<<"numeros[0] = "<<numeros[0]<<endl; // muestra 1 que est� en la posici�n 0 del array
	cout<<"\nArreglo de letras: ";
	
	// para mostrar todos los �ndices usamos un bucle que recorra cada posici�n:
	for(int i=0; i<n; i++){ // o desde 0 hasta (n-1) 
		cout<<letras[i]<<" ";
	}
	
	cout<<endl;
	getch();
	return 0;
}
