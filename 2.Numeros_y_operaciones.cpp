// los numeros (sean del tipo que sean) se pueden operar con signos denominados OPERADORES ARITMÉTICOS y comparar con OPERADORES LÓGICOS (no entre número y caracter o string)
// cuando se le asigna un valor de distinto tipo a una variable, obtiene solo la parte correspondiente del tipo (ej: 12.5 (float) -> int num = 12)
// si lo anterior no es significativo el cambio se hace tal cual (ej: 1234502 (long) -> int num = 1234502) siempre y cuando soporte la cantidad de bytes

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	float n1, n2; // se puede operar con valores predefinidos de la forma: int n1 = 12;
	float add, subs, mult, div; // si la división es entre enteros arroja 0 como resultado si hay residuo
	// los 'double' se muestran en notación cientifica
	// con long se guardan enteros o reales largos
	add = subs = mult = 0; // como valor por defecto para no tener basura
	int a, b;
	int mod = 0; // el módulo debe ser entero al ser una operación binaria
	// dos números son divisibles si el módulo (resto) es cero
	// con: valor / (algún número), podemos obtener cuántas veces cabe ese valor en el número (para sacar cantidades al descomponer el número)
	// con: valor % (algún número), podemos restarle al valor las veces que cabe en el número y quedarnos solo con lo que esta por debajo del número (cambia el valor)
	// con módulo 10 se puede obtener el último dígito de un número (al ser enteros el resto es igual al último dígito: 12/10 -> resto 2)
	// dividiendo por 10 se puede eliminar el último dígito de un númeo (al ser enteros el resultado deja el último dígito en decimal, el cual es truncado)
	
	/* CADENAS A NÚMEROS (con la librería para strings)
	string numero = "2024";
	atoi(numero) // para transformar números enteros de cadena a enteros operables
	cout<<"String a número: "<<numero<<endl;
	*/
	 
	cout<<"Ingrese el primer número: "; cin>>n1;
	cout<<"Ingrese el segundo número: "; cin>>n2;
	cout<<"Ingrese el tercer número: "; cin>>a;
	cout<<"Ingrese el cuerto número: "; cin>>b;
	
	cout.precision(3); // función para redondear el (n) decimal y dejar solo n-1 decimal (todo lo que venga después se le aplica el redondeo)
	
	// las operaciones se pueden mostrar sencillamente así: cout << x + y;
	add = n1 + n2; cout<<"\nLa suma es: "<<add<<endl;
	subs = n1 - n2; cout<<"\nLa resta es: "<<subs<<endl;
	mult = n1 * n2; cout<<"\nEl producto es: "<<mult<<endl;
	div = n1 / n2; cout<<"\nLa división es: "<<div<<endl;
	mod = a % b; cout<<"\nEl resto de la división es: "<<mod<<endl;
	// la asignación de valores (copiar o dar un valor) se hace desde la variable vacía hacía la con información: x = 1 -> y = x (y = 1)
	
	// para calcular el mayor de algún arreglo, se compara una variable mayor = 0 con los elementos, si alguno es mayor entonces se actualiza el valor de mayor por ese
	// para calcular el menos de algún arreglo, se compara una variable menor = (primer elemento ó número muy grande), si alguno es menorentonces se actualiza el valor de menor por ese
	
	// POTENCIAS DE 10 como valores:
	// si se pone la letra 'e' entre dos números se entiende que es el primero por la potencia de 10 elevada al segundo
	// ej: int diez_mil = 1e4; -> 1 * 10^4 => 1*10,000 => 10,000
	
	// DIVISORES de un número
	// OBS: divisores de 50 -> 1,2,5,10,25,_50
	// OBS: divisores de 12 -> 1,2,3,4,6,_12
	// NO EXISTEN DIVISORES DE UN NÚMERO MAYORES A LA MITAD DEL NÚMERO (ADEMÁS TODO NÚMERO ES DIV POR 1 Y SI MISMO)
	// para sacar los divisores se usa un for que compruebe si el número es divisible por los números del 1 al numero (si el resto entre dos números divididos es 0 es que es divisible el primero en el segundo9)
	// -> si usamos la lógica anterior, solo vemos de 2 hasta numero/2 pero el contador de divs empieza en 2 (por el 1 y si mimso)
	
	getch();
	return 0;
}
