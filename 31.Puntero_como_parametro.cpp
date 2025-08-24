// los punteros como parámetros se usan para modificar el valor de alguna variable a través de su dm, por lo que el valor cambiado no es temporal (no se elimina al terminar el programa)
// para esto se declara una variable temporal tipo puntero de parámetro en la cual se le debe mandar una dm en la llamada para que funcione
// también se pueden mandar punteros por referencia con *& en forma de parámetros al trabajar con punteros dobles

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

void intercambiar(float *, float *); // los parámetros son punteros, reciben dm de variables y trabajan con el valor ORIGINAL, no una copia

int main(){
	setlocale(LC_ALL, "Spanish");
	
	float x = 12.55, y = 60.21;
	
	cout<<"Valor inicial x = "<<x<<endl;
	cout<<"Valor inicial y = "<<y<<endl;
	
	intercambiar(&x, &y); // como debe recibir dm los parámetros punteros, se mandan las variables con &
	
	cout<<"\nNuevo valor x = "<<x<<endl;
	cout<<"Nuevo valor y = "<<y<<endl;
	
	getch();
	return 0;
}

void intercambiar(float *num1, float *num2){
	float aux;
	// intercambio genérico de valores
	aux = *num1;
	*num1 = *num2; // lo que está dentro de la variable en la dm num1 es lo que se cambia
	*num2 = aux; 
}

/* PASAR PUNTEROS POR LLAMADA DE FUNCIONES:

///// CASO 1 //////////////////////////////////////////////////////////////////////////////

int numero = 30; // dirección de memoria: 0x024
int *puntero = &numero;
pasoPuntero(puntero); // pasoPuntero(0x024)
void pasoPuntero(int *direccion){ // *direccion = 0x022
	// Instrucciones
}

EN ESTE CASO LA FUNCIÓN QUE RECIBE UNA DM POR PARÁMETRO, AL MANDARLE EL VALOR DEL PUNTERO, DIRECCION PASA A APUNTAR A LA DM DE NUMERO, DE MANERA TEMPORAL
...ES DECIR QUE AMBAS VARIABLES (DIRECCION Y PUNTERO) APUNTAN A LA MISMA DM PERO UNA ES TEMPORAL Y LA OTRA NO, DESDE DISTINTAS DM

///// CASO 2 //////////////////////////////////////////////////////////////////////////////

int numero = 30;
int *punt_numero = &numero;
void pasoPuntero(punt_numero);
void pasoPuntero(int *&direccion){
	// Instrucciones
}

AHORA, CON EL OPERADOR *& INDICAMOS EN EL PARÁMETRO QUE SE VA A RECIBIR LA DM DEL PUNTERO QUE SE ENVÍE POR LLAMADA, POR LO QUE SE LE HAGA A DIRECCION SE LE APLICA A PUNT_NUMERO
...ES DECIR AMBAS VARIABLES, LA TEMPORAL DEL PARAMETRO (DIRECCION) Y EL PUNTERO (PUNTERO) APUNTAN A LA MISMA DM DE NUMERO DESDE LA MISMA DM COMPARTIDA

*/
