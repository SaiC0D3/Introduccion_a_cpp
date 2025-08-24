// las FUNCIONES sirven para dividir el programa en distintas y específicas partes, cada funión desarrolla 1 sola tarea
// las funciones son del tipo de valor que retornan (int, char, bool, struct, etc...), al momento de utilizarlas se deben llamar en el main() con los valores por parámetros
// la idea es dejar lo más vacío posible el int main(), solo con las llamadas de las funciones y algunas variables e instrucciones de lectura de datos
// las funciones que retornan un valor, pueden tener varias instrucciones de retornos en condicionales, pero solo 1 valor es el que se llama
// las funciones bool retornan true o false, por lo que la llamada si o si debe estar en un condicional
// el retorno que implica un condicional de 2 opciones se puede resumir en 1 línea de código: return (condición)? true : false; (si se cumple la condición retorna true, si no retorna false)
// las funciones que retornan un puntero lo que hacen es retornar una dirección de memoria, por lo que en su llamada deben igualarse a algún puntero...
// ...además la dm que retornan no es temporal, solo las variables en ella utilizada

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

/* PROTOTIPOS:en esta parte se definen los prototipos de las funiones (declarar que existen para poder llamarlas) de la forma:
	-> tipo nom_funcion(parámetros); // literalmente es solo el tipo, nombre y parámetros, lo mismo que la definición sin {}
	todo lo que pasa dentro de una función es temporal durante el programa se ejecute (si no se trabaja con dm):
	-> los parámetros de una función son variables temporales que usan espacio temporal para cumplir su tarea y que trabajan con copias de los valores recibidos por llamada
	-> del mismo modo, al asignar valores a variables globales mediante la llamada, estos se eliminan al terminar la función quedando con su valor inicial
	-> ya que las variables de los parámetros utilizadas para referenciar los valores obtenidos por llamada son temporales, se pueden reutlizar sus nombres en otras funciones
*/

int encontrar_mayor(int num1, int num2);

int main(){
	setlocale(LC_ALL, "Spanish");
	
	int num1, num2; // pueden o no tener el mismo nombre que los parámetros
	// si una variable nada más se usa para obtener un número distinto repetidas veces (como para llenar una lista) y no se muestra ni se usa dicha variable directamente...
	// ...se puede reutilizar para guardar los distintos valores, de modo que solo es canal para mandarle el dato a la función y que trabaje con el...
	// ...mucho más si se reciben punteros o sea dm del valor mediante la variable, el valor queda guardado en la dm del puntero y no sirve más la varibla, por eso la reutilizamos
	
	cout<<"Digite 2 números: "; cin>>num1>>num2; // se pueden leer más de una variable al mismo tiempo
	
	// LLLAMDA: aquí dentro es donde se llaman a las funciones pasándole los valores a los parámetros para que trabaje con ellos y retorne el resultado
	// en la llamada se puede mandar un dato directamente de parámetro, como un número o letra, sin necesidad de pedirlo
	cout<<"\nEl mayor entre los 2 es: "<<encontrar_mayor(num1, num2)<<endl;
	// se puede llamar directamente ya que guarda un valor como si fuera una constante, o si no se puede guardar en otra variable y mostrar esa
	
	getch();
	return 0;
}

// DEFINICIÓN: aquí al final de todo se definen las instrucciones de cada función

// en funciones que retornan algún valor, se puede leer y mostrar datos con cout y cin igualmente
int encontrar_mayor(int num1, int num2){ // la variable trabaja con las variables en los parámetros y con variables propias
	int mayor_num;
	
	if(num1 > num2)
		mayor_num = num1; // se podría directamente retornar num1
		
	if(num1 < num2)
		mayor_num = num2; // se podría directamente retornar num2
		
	return mayor_num; // en los casos anteriores no habría que definir una variable mayor_num ni retornar al final
}

/* REASIGNACIÓN DE VALORES DENTRO DE UNA FUNCIÓN:

//// CASO 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int numero = 30;
pasoValor(numero);
void pasoValor(int edad){
	edad = 50;
}

-> LAS VARIABLES DEFINIDAS DENTRO DE LA FUNCIÓN SON ESPACIOS DE MEMORIA USADOS DE FORMA TEMPORAL, AL ACABAR EL PRGORAMA SE ELIMINAN
-> LOS VALORES PASADOS POR REFERENCIA SON UNA COPIA DE LAS VARIABLES, COMO SE MUESTRA EN LA FUNCIÓN ANTERIOR, AL FINAL DEL PROGRAMA EDAD DESAPARECE Y EL VALOR DE 50 TAMBIÉN

//// CASO 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pasoReferencia(int &edad){
	edad = 45;
}
int numero = 30;
pasoReferencia(numero);

-> EN ESTE CASO NO SE ENVIA UNA COPIA COMO PARÁMETRO, SI NO QUE SE MANDA LA DM DE NUMERO Y POR LO TANTO AL REASIGNAR VALORES EN LA FUNCIÓN ESTE SI CAMBIA TOTALMENTE

*/
