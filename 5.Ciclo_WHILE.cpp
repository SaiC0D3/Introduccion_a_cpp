// los bucles o ciclos sirven para repetir una instrucci�n que va cambiando ciertos par�metros en cada iteraci�n

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* WHILE
		while(expresi�n l�gica){
			instrucciones;
			incremento de conteo para detener el bucle;
		}
		
		---mientras se siga cumpliendo la condici�n, se seguir� ejecut�ndo el c�digo
		---cuando se disminuye el �ndice dentro del while se puede usar la libreria de <conio.h> y su funci�n getch() para evitar un error
	*/
	
	int i = 0; // variable �ndice que va a ir aumentando cada vez que se cumpla la condici�n
	// usamos el bucle para imprimir la tabla del 2 (desde el 0 al 12)
	while(i <= 12){
		cout<<"2 x "<<i<<" = "<<2*i <<endl;
		i++; // n = n + 1 (cuando aumenta o disminuye de 1 en 1)
	}
	
	getch();
	return 0;
}
