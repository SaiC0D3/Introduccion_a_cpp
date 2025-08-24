//  los arreglos asignan valores a posiciones contiguas de memoria (sus valores de cada posición están en dm seguidas una de otra)
// para asignar todas las dm y valores de un arreglo a un puntero SÓLO se le pasa la dm del primer valor (ya que a partir de esa de puede acceder a las siguientes)...
// ...por lo anterior, un puntero solo guarda 1 dm, si es un arreglo guarda la dm del piemer elemento (para acceder a los demás se usa un bucle)...
// ...aunque en verdad solo se hace una igualdad entre arreglo y puntero, ya que ambos guardan varias dm en posiciones contiguas (el puntero se puede recorrer con las posiciones)
// cada tipo de variable se almacena en bytes de información que vienen señalados en la dm; por ejemplo una variable tipo int reserva 4 bytes de memoria

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int arreglo[] = {2,1,4,6,9,3};
	
	// asignación de la dm del arreglo al puntero
	int *p = &arreglo[0]; // más corto: int *p = arreglo; (más abaja el por qué)
	
	for(int i=0; i<6; i++){ // ciclo para recorrer las direcciones de memoria del arreglo desde la priemra guardada en el puntero
		cout<<"Valor posición ["<<i<<"]: "<<*p++<<endl; // se agrega ++ al puntero para que a la dm guardada en él se le sumen los bytes del tipo de variable que almacena
		// de esta manera se muestran los valores del arreglo que están dentro de la dm del arreglo almacenada en el puntero
	}
	
	// ya más fácil es poner simplemente p[i] (el puntero como arreglo directamente)
	// como los arreglos ya son agrupaciones de dm, al crear un puntero y asignarle valores como un arreglo, se puede trabajar de la misma forma
	// -> arreglos[i] para cin, cout y asiganciones con otro arreglo, ya sea 'arreglos' definido como puntero o como arreglo
	// si se manda un char a un parámetro puntero char, no hace falta asignar el valor del primer elemento ni enviarle la dm con & ya que son lo mismo
	
	cout<<"\nPosiciones de memoria de los elementos del arreglo\n"<<endl; /////////////////////////////////////////////////////77
	
	for(int i=0; i<6; i++){ // de la misma forma para, en vez de mostrar el valor de la posición del arreglo, mostrar su dm asignada
		cout<<"Dirección de memoria posición ["<<i<<"]: "<<p++<<endl; // sin asterisco, mostrando el valor del puntero que es la dm con ++ para avanzar a la siguiente
	}
	
	getch();
	return 0;
}
