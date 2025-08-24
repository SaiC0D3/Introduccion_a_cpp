// las FUNCIONES recursivas se usan cuando la funci�n necesita llamarse a s� misma para completar la tarea inicial (pueden ser de cualquier tipo que RETORNA)
// el proceso inicial se ejecuta hasta que se vuelve a llamar a la misma funci�n, entonces queda en reposo y abre un segundo proceso...
// ...hasta que ese segundo proceso termina y arroja un resultado, entonces la funci�n incial vuelve a ejecutarse ahora con el resultado obtenido para usarlo
// este proceso se hace una ifinidad de veces, a menos que se especifique un caso base, en donde termina el �ltimo proceso y luego van terminando en cadena los anteriores
// (la recursividad puede ser una instrucci�n de la funci�n o estar en el retorno)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

int factorial(int);

/* FACTORIAL:
	-> el factorial de un n�mero n se calcula como el producto de el y todos sus antecesores hasta el 0! (o el n�mero por el factorial anterior)
	-> el 0! por definici�n es 1 (caso base: determina el �ltimo proceso de la recursividad) -> cuando n = 0
	
	As� por ej: 3! = 3*2*1 = 3*2!
	-> caso general: n! = n*(n-1) -> cuando n > 0
*/

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num;
	
	cout<<"Ingrese un n�mero: "; cin>>num;
	cout<<"\n"<<num<<"! = "<<factorial(num)<<endl;
	
	getch();
	return 0;
}

int factorial(int n){ // en este caso es la misma variable n la que se reactualiza con los valores de los procesos (desde el �ltimo hacia el primero)
	if(n == 0)
		n = 1; // caso base
	else
		n = n*factorial(n-1); // caso general
	// con n = 2 entrar� en el caso general y se detendr� en n = 2*factorial(1) <--- lo mismo que antes, finalmente retorna 2*1=2 que es el resultado de 2!
	// ahora con n = 1 entrar� en el caso general de nuevo y se detendr� en n = 1*factorial(0) <--- se reanuda y n = 1*1=1, termina el proceso y retorna 2 <------}
	// finalmente con n = 0 entrar� en el caso base y retornar� 1 este proceso -----------------> factorial(0) = 1 ---------------------------------------------->}
		
	return n; // en este caso se reescribe el valor de n, pero se podr�a retornar directamente n*factorial(n-1) y dejar el caso base
}
