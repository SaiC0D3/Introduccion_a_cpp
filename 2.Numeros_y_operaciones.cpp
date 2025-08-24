// los numeros (sean del tipo que sean) se pueden operar con signos denominados OPERADORES ARITM�TICOS y comparar con OPERADORES L�GICOS (no entre n�mero y caracter o string)
// cuando se le asigna un valor de distinto tipo a una variable, obtiene solo la parte correspondiente del tipo (ej: 12.5 (float) -> int num = 12)
// si lo anterior no es significativo el cambio se hace tal cual (ej: 1234502 (long) -> int num = 1234502) siempre y cuando soporte la cantidad de bytes

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	float n1, n2; // se puede operar con valores predefinidos de la forma: int n1 = 12;
	float add, subs, mult, div; // si la divisi�n es entre enteros arroja 0 como resultado si hay residuo
	// los 'double' se muestran en notaci�n cientifica
	// con long se guardan enteros o reales largos
	add = subs = mult = 0; // como valor por defecto para no tener basura
	int a, b;
	int mod = 0; // el m�dulo debe ser entero al ser una operaci�n binaria
	// dos n�meros son divisibles si el m�dulo (resto) es cero
	// con: valor / (alg�n n�mero), podemos obtener cu�ntas veces cabe ese valor en el n�mero (para sacar cantidades al descomponer el n�mero)
	// con: valor % (alg�n n�mero), podemos restarle al valor las veces que cabe en el n�mero y quedarnos solo con lo que esta por debajo del n�mero (cambia el valor)
	// con m�dulo 10 se puede obtener el �ltimo d�gito de un n�mero (al ser enteros el resto es igual al �ltimo d�gito: 12/10 -> resto 2)
	// dividiendo por 10 se puede eliminar el �ltimo d�gito de un n�meo (al ser enteros el resultado deja el �ltimo d�gito en decimal, el cual es truncado)
	
	/* CADENAS A N�MEROS (con la librer�a para strings)
	string numero = "2024";
	atoi(numero) // para transformar n�meros enteros de cadena a enteros operables
	cout<<"String a n�mero: "<<numero<<endl;
	*/
	 
	cout<<"Ingrese el primer n�mero: "; cin>>n1;
	cout<<"Ingrese el segundo n�mero: "; cin>>n2;
	cout<<"Ingrese el tercer n�mero: "; cin>>a;
	cout<<"Ingrese el cuerto n�mero: "; cin>>b;
	
	cout.precision(3); // funci�n para redondear el (n) decimal y dejar solo n-1 decimal (todo lo que venga despu�s se le aplica el redondeo)
	
	// las operaciones se pueden mostrar sencillamente as�: cout << x + y;
	add = n1 + n2; cout<<"\nLa suma es: "<<add<<endl;
	subs = n1 - n2; cout<<"\nLa resta es: "<<subs<<endl;
	mult = n1 * n2; cout<<"\nEl producto es: "<<mult<<endl;
	div = n1 / n2; cout<<"\nLa divisi�n es: "<<div<<endl;
	mod = a % b; cout<<"\nEl resto de la divisi�n es: "<<mod<<endl;
	// la asignaci�n de valores (copiar o dar un valor) se hace desde la variable vac�a hac�a la con informaci�n: x = 1 -> y = x (y = 1)
	
	// para calcular el mayor de alg�n arreglo, se compara una variable mayor = 0 con los elementos, si alguno es mayor entonces se actualiza el valor de mayor por ese
	// para calcular el menos de alg�n arreglo, se compara una variable menor = (primer elemento � n�mero muy grande), si alguno es menorentonces se actualiza el valor de menor por ese
	
	// POTENCIAS DE 10 como valores:
	// si se pone la letra 'e' entre dos n�meros se entiende que es el primero por la potencia de 10 elevada al segundo
	// ej: int diez_mil = 1e4; -> 1 * 10^4 => 1*10,000 => 10,000
	
	// DIVISORES de un n�mero
	// OBS: divisores de 50 -> 1,2,5,10,25,_50
	// OBS: divisores de 12 -> 1,2,3,4,6,_12
	// NO EXISTEN DIVISORES DE UN N�MERO MAYORES A LA MITAD DEL N�MERO (ADEM�S TODO N�MERO ES DIV POR 1 Y SI MISMO)
	// para sacar los divisores se usa un for que compruebe si el n�mero es divisible por los n�meros del 1 al numero (si el resto entre dos n�meros divididos es 0 es que es divisible el primero en el segundo9)
	// -> si usamos la l�gica anterior, solo vemos de 2 hasta numero/2 pero el contador de divs empieza en 2 (por el 1 y si mimso)
	
	getch();
	return 0;
}
