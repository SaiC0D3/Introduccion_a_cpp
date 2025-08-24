// para pasar elementos de un arreglo como par�metros hacia un puntero que guarde el arreglo se necesita mandar la dm de la primera posici�n y el total de datos (para solo avanzar en las dm)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

int hallarMax(int *, int); // un par�metro para la dm del primer elemento y otro para el total de elementos
void mostrar(int *, int);

int main(){
	setlocale(LC_ALL, "Spanish");
	
	const int total = 6;
	int numeros[total] = {12,-3,5,-16,0,8};
	int max;
	
	max = hallarMax(numeros, total); // se le manda el arreglo al puntero pero solo recibe la dm del primer elemento
	
	mostrar(numeros, total);
	cout<<"\nEl mayor elemento del arreglo es: "<<max<<endl;
	
	getch();
	return 0;
}

int hallarMax(int *dir, int n){ // el par�metro puntero 'p' recibe la dm del arreglo (de la primera posici�n)
	int mayor = 0;
	
	for(int i=0; i<n; i++){
		if(*(dir+i) > mayor) // *(dir+i) == "*dir++" == dir[i] == lo que est� dentro (*) de la direcci�n del primer elemento m�s el �ndice para avanzar en las dm al sumar
			mayor = *(dir+i); // si se quiere ver una posici�n espec�fica ser�a: *(dir+pos)
	}
	
	return mayor;
}

void mostrar(int *dir, int n){
	cout<<"Mostrando elementos: "<<endl<<endl;
	
	for(int i=0; i<n;i++){
		cout<<"Elemento ["<<i<<"]: "<<*(dir+i)<<endl;
	}
}
