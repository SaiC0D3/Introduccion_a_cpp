// los valores por referencia se utilizan para pasar la direcci�n de memoria de una variable, as� poder manipular la info contenida en ella de manera m�s f�cil (eso si, se pierden los valores anteriores)
// lo �til es que se pueden mandar como par�metros de funciones a modo de usar un valor en cualquier parte (se trabaja con lo que hay en la dm no con un valor espec�fico de una variable)
// 

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

void cambiar_valores(int&, int&); // se usa '&' junto al tipo para indicar que es la direcci�n de memoria de.. (..en este caso cualquier variable entera)

// las variables globales se definen despu�s de los prototipos de funciones

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num1, num2; // se crean variables en una direcci�n de memoria x
	
	cout<<"Ingrese dos valores enteros: ";
	cin>>num1>>num2;
	
	cambiar_valores(num1, num2); // se le pasa a la funci�n la dm de las variables (es decir d�nde se guardan los valores de las variables num1 y num2)
	
	cout<<endl;
	cout<<"\nNuevo valor 1 = "<<num1<<" DM = "<<&num1; // se muestra el nuevo valor actualizado medieante la dm
	cout<<"\nNuevo valor 2 = "<<num2<<" DM = "<<&num2; // se ve que la dm no cambia pero el valor si
	
	getch();
	return 0;
}

void cambiar_valores(int& xnum, int& ynum){ // aqu� hace falta ponerle nombre a las dm de variables
	// se guarda el valor de la dm en otra variable (al mostrarlas se muestra la dm de las variables recibidas por par�metros al momento de la llamada)
	cout<<"\nValor 1 = "<<xnum<<" DM = "<<&xnum; // al mostrar la variable que guarda la dm de una variable, se muestra el valor ah� contenido, no la dm
	cout<<"\nValor 2 = "<<ynum<<" DM = "<<&ynum; // al mostrar la variable original o la que guarda su dm con & se muestra tal cual la dm
	
	xnum = 22; ynum = 16; // se actualiza el valor de lo que hay en la dm guardada (no es que cambie la dm, solo el valor de la vaiable all� contenida)
}	
