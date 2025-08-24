// las FUNCIONES sirven para dividir el programa en distintas y espec�ficas partes, cada funi�n desarrolla 1 sola tarea
// las funciones son del tipo de valor que retornan (int, char, bool, struct, etc...), al momento de utilizarlas se deben llamar en el main() con los valores por par�metros
// la idea es dejar lo m�s vac�o posible el int main(), solo con las llamadas de las funciones y algunas variables e instrucciones de lectura de datos
// las funciones que retornan un valor, pueden tener varias instrucciones de retornos en condicionales, pero solo 1 valor es el que se llama
// las funciones bool retornan true o false, por lo que la llamada si o si debe estar en un condicional
// el retorno que implica un condicional de 2 opciones se puede resumir en 1 l�nea de c�digo: return (condici�n)? true : false; (si se cumple la condici�n retorna true, si no retorna false)
// las funciones que retornan un puntero lo que hacen es retornar una direcci�n de memoria, por lo que en su llamada deben igualarse a alg�n puntero...
// ...adem�s la dm que retornan no es temporal, solo las variables en ella utilizada

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

/* PROTOTIPOS:en esta parte se definen los prototipos de las funiones (declarar que existen para poder llamarlas) de la forma:
	-> tipo nom_funcion(par�metros); // literalmente es solo el tipo, nombre y par�metros, lo mismo que la definici�n sin {}
	todo lo que pasa dentro de una funci�n es temporal durante el programa se ejecute (si no se trabaja con dm):
	-> los par�metros de una funci�n son variables temporales que usan espacio temporal para cumplir su tarea y que trabajan con copias de los valores recibidos por llamada
	-> del mismo modo, al asignar valores a variables globales mediante la llamada, estos se eliminan al terminar la funci�n quedando con su valor inicial
	-> ya que las variables de los par�metros utilizadas para referenciar los valores obtenidos por llamada son temporales, se pueden reutlizar sus nombres en otras funciones
*/

int encontrar_mayor(int num1, int num2);

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num1, num2; // pueden o no tener el mismo nombre que los par�metros
	// si una variable nada m�s se usa para obtener un n�mero distinto repetidas veces (como para llenar una lista) y no se muestra ni se usa dicha variable directamente...
	// ...se puede reutilizar para guardar los distintos valores, de modo que solo es canal para mandarle el dato a la funci�n y que trabaje con el...
	// ...mucho m�s si se reciben punteros o sea dm del valor mediante la variable, el valor queda guardado en la dm del puntero y no sirve m�s la varibla, por eso la reutilizamos
	
	cout<<"Digite 2 n�meros: "; cin>>num1>>num2; // se pueden leer m�s de una variable al mismo tiempo
	
	// LLLAMDA: aqu� dentro es donde se llaman a las funciones pas�ndole los valores a los par�metros para que trabaje con ellos y retorne el resultado
	// en la llamada se puede mandar un dato directamente de par�metro, como un n�mero o letra, sin necesidad de pedirlo
	cout<<"\nEl mayor entre los 2 es: "<<encontrar_mayor(num1, num2)<<endl;
	// se puede llamar directamente ya que guarda un valor como si fuera una constante, o si no se puede guardar en otra variable y mostrar esa
	
	getch();
	return 0;
}

// DEFINICI�N: aqu� al final de todo se definen las instrucciones de cada funci�n

// en funciones que retornan alg�n valor, se puede leer y mostrar datos con cout y cin igualmente
int encontrar_mayor(int num1, int num2){ // la variable trabaja con las variables en los par�metros y con variables propias
	int mayor_num;
	
	if(num1 > num2)
		mayor_num = num1; // se podr�a directamente retornar num1
		
	if(num1 < num2)
		mayor_num = num2; // se podr�a directamente retornar num2
		
	return mayor_num; // en los casos anteriores no habr�a que definir una variable mayor_num ni retornar al final
}

/* REASIGNACI�N DE VALORES DENTRO DE UNA FUNCI�N:

//// CASO 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int numero = 30;
pasoValor(numero);
void pasoValor(int edad){
	edad = 50;
}

-> LAS VARIABLES DEFINIDAS DENTRO DE LA FUNCI�N SON ESPACIOS DE MEMORIA USADOS DE FORMA TEMPORAL, AL ACABAR EL PRGORAMA SE ELIMINAN
-> LOS VALORES PASADOS POR REFERENCIA SON UNA COPIA DE LAS VARIABLES, COMO SE MUESTRA EN LA FUNCI�N ANTERIOR, AL FINAL DEL PROGRAMA EDAD DESAPARECE Y EL VALOR DE 50 TAMBI�N

//// CASO 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pasoReferencia(int &edad){
	edad = 45;
}
int numero = 30;
pasoReferencia(numero);

-> EN ESTE CASO NO SE ENVIA UNA COPIA COMO PAR�METRO, SI NO QUE SE MANDA LA DM DE NUMERO Y POR LO TANTO AL REASIGNAR VALORES EN LA FUNCI�N ESTE SI CAMBIA TOTALMENTE

*/
