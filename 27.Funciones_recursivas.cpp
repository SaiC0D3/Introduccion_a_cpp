// las FUNCIONES recursivas se usan cuando la función necesita llamarse a sí misma para completar la tarea inicial (pueden ser de cualquier tipo que RETORNA)
// el proceso inicial se ejecuta hasta que se vuelve a llamar a la misma función, entonces queda en reposo y abre un segundo proceso...
// ...hasta que ese segundo proceso termina y arroja un resultado, entonces la función incial vuelve a ejecutarse ahora con el resultado obtenido para usarlo
// este proceso se hace una ifinidad de veces, a menos que se especifique un caso base, en donde termina el último proceso y luego van terminando en cadena los anteriores
// (la recursividad puede ser una instrucción de la función o estar en el retorno)

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

int factorial(int);

/* FACTORIAL:
	-> el factorial de un número n se calcula como el producto de el y todos sus antecesores hasta el 0! (o el número por el factorial anterior)
	-> el 0! por definición es 1 (caso base: determina el último proceso de la recursividad) -> cuando n = 0
	
	Así por ej: 3! = 3*2*1 = 3*2!
	-> caso general: n! = n*(n-1) -> cuando n > 0
*/

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num;
	
	cout<<"Ingrese un número: "; cin>>num;
	cout<<"\n"<<num<<"! = "<<factorial(num)<<endl;
	
	getch();
	return 0;
}

int factorial(int n){ // en este caso es la misma variable n la que se reactualiza con los valores de los procesos (desde el último hacia el primero)
	if(n == 0)
		n = 1; // caso base
	else
		n = n*factorial(n-1); // caso general
	// con n = 2 entrará en el caso general y se detendrá en n = 2*factorial(1) <--- lo mismo que antes, finalmente retorna 2*1=2 que es el resultado de 2!
	// ahora con n = 1 entrará en el caso general de nuevo y se detendrá en n = 1*factorial(0) <--- se reanuda y n = 1*1=1, termina el proceso y retorna 2 <------}
	// finalmente con n = 0 entrará en el caso base y retornará 1 este proceso -----------------> factorial(0) = 1 ---------------------------------------------->}
		
	return n; // en este caso se reescribe el valor de n, pero se podría retornar directamente n*factorial(n-1) y dejar el caso base
}
