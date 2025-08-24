// los bucles o ciclos sirven para repetir una instrucci�n que va cambiando ciertos par�metros en cada iteraci�n

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* DO-WHILE
		do{ 	// se ejecutan las instrucciones al menos 1 vez, luego si se cumple la condici�n se repetir� las veces correspondientes
			instrucciones;
			incremento de conteo para detener el bucle;
		}while(expresi�n l�gica)
		
		---mientras se siga cumpliendo la condici�n, se seguir� ejecut�ndo el c�digo
		---con do-while no hace falta usar la libreria de <conio.h> y su funci�n getch() al disminuir el �ndice
		---se utiliza bastante cuando piden condiciones de rangos de n�meros o letras
	*/
	
	int i = 1;
	// usamos el bucle para imprimir los n�meros impares (12 n�meros)
	while(i <= 24){
		if(i % 2 != 0) // condici�n para que sean impares
			cout<<i<<endl;
		// si no hay else, al no cumplirse el if sigue con la sig. l�nea de c�digo como si fuera el caso contrario
		i++; 
	}
	
	getch();
	return 0;
}
