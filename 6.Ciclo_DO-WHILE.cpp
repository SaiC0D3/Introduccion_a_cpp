// los bucles o ciclos sirven para repetir una instrucción que va cambiando ciertos parámetros en cada iteración

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* DO-WHILE
		do{ 	// se ejecutan las instrucciones al menos 1 vez, luego si se cumple la condición se repetirá las veces correspondientes
			instrucciones;
			incremento de conteo para detener el bucle;
		}while(expresión lógica)
		
		---mientras se siga cumpliendo la condición, se seguirá ejecutándo el código
		---con do-while no hace falta usar la libreria de <conio.h> y su función getch() al disminuir el índice
		---se utiliza bastante cuando piden condiciones de rangos de números o letras
	*/
	
	int i = 1;
	// usamos el bucle para imprimir los números impares (12 números)
	while(i <= 24){
		if(i % 2 != 0) // condición para que sean impares
			cout<<i<<endl;
		// si no hay else, al no cumplirse el if sigue con la sig. línea de código como si fuera el caso contrario
		i++; 
	}
	
	getch();
	return 0;
}
