// los bucles o ciclos sirven para repetir una instrucci�n que va cambiando ciertos par�metros en cada iteraci�n

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* FOR
		for(def. e inicializaci�n del �ndice; expresi�n l�gica a cumplir; aumento del �ndice){
			instrucciones;
		}
		
		---mientras se siga cumpliendo la condici�n, se seguir� ejecut�ndo el c�digo
		---la definici�n del �ndice puede o no ir dentro de los par�metros del for
		---lo malo del ciclo for() es que solo admite 1 condici�n
	*/
	
	// usamos el bucle para imprimir las letras del abecedario a partir de su c�digo ASCII
	for(char letter = 'a'; letter <= 122; letter++) // en ASCII la 'a' min�scula empieza en 97 y la 'z' en 122
		cout<<letter<<endl;
	// al ser una s�la instrucci�n, se pueden omitir los {}
	// (i=0; i <= n; i++) � (i=1; i < n; i++)
	
	getch();
	return 0;
}
