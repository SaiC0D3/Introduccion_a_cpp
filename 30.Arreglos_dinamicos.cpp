// un arreglo dinámico es un puntero que funciona como arreglo (guarda varias dm en posiciones contiguas) mediante el uso de los indicadores 'new' y 'delete'
// con NEW reservamos uno o varios espacios de memoria, luego con DELETE liberamos dicho espacio de memoria al finalizar el programa (local o global se libera)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

void pedir_datos();
void mostrar();

int total, *arreglo; // variable para el total de elementos del arreglo (necesario para especificar el espacio necesario a reservar con new) 

int main(){
	setlocale(LC_ALL, "Spanish");
	
	pedir_datos();
	mostrar();
	
	delete[] arreglo; // en este caso como es un arreglo el delete va con []
	// de esta forma todas las dm usadas para el arreglo se liberan y desocupamos espacio (siempre se declara al final y después de usar un new)
	
	getch();
	return 0;
}

void pedir_datos(){
	cout<<"Digite cuántos elementos desea ingresar: "; cin>>total;
	
	arreglo = new int[total]; // así se declara el new para reservar espacio, antes del tipo de dato a reservar y entre [] si se trata de un arreglo (en este caso hace falta especificar el total de elementos)
	// con esta asignación, decimos que el puntero arreglo guarda 'total' espacios de memoria, cada uno en una posición específica a los cuales se puede acceder con un índice

	for(int i=0; i<total; i++){
		cout<<"Ingrese elemento: "; cin>>arreglo[i]; // para guardar cada elemento en su dm respectiva se escribe como un arreglo normal con el índice correcpondiente
	}
}

void mostrar(){
	for(int i=0; i<total; i++){
		cout<<"Elemento ["<<i<<"]: "<<arreglo[i]<<endl; // para guardar cada elemento en su dm respectiva se escribe como un arreglo normal con el índice correcpondiente
	}
}
