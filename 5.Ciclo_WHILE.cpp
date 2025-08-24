// los bucles o ciclos sirven para repetir una instrucción que va cambiando ciertos parámetros en cada iteración

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* WHILE
		while(expresión lógica){
			instrucciones;
			incremento de conteo para detener el bucle;
		}
		
		---mientras se siga cumpliendo la condición, se seguirá ejecutándo el código
		---cuando se disminuye el índice dentro del while se puede usar la libreria de <conio.h> y su función getch() para evitar un error
	*/
	
	int i = 0; // variable índice que va a ir aumentando cada vez que se cumpla la condición
	// usamos el bucle para imprimir la tabla del 2 (desde el 0 al 12)
	while(i <= 12){
		cout<<"2 x "<<i<<" = "<<2*i <<endl;
		i++; // n = n + 1 (cuando aumenta o disminuye de 1 en 1)
	}
	
	getch();
	return 0;
}
