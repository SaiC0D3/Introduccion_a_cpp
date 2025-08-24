// los bucles o ciclos sirven para repetir una instrucción que va cambiando ciertos parámetros en cada iteración

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* FOR
		for(def. e inicialización del índice; expresión lógica a cumplir; aumento del índice){
			instrucciones;
		}
		
		---mientras se siga cumpliendo la condición, se seguirá ejecutándo el código
		---la definición del índice puede o no ir dentro de los parámetros del for
		---lo malo del ciclo for() es que solo admite 1 condición
	*/
	
	// usamos el bucle para imprimir las letras del abecedario a partir de su código ASCII
	for(char letter = 'a'; letter <= 122; letter++) // en ASCII la 'a' minúscula empieza en 97 y la 'z' en 122
		cout<<letter<<endl;
	// al ser una sóla instrucción, se pueden omitir los {}
	// (i=0; i <= n; i++) ó (i=1; i < n; i++)
	
	getch();
	return 0;
}
