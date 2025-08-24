// los condicionales con booleanos permiten ejecutar código específico que requiera de una condición

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* IF-ELSE
		if(condición){
			instrucciones 1;
		}
		else if(caso contrario){
			instrucciones 2;
		}
		else{						// no es necesario poner condición en else
			instrucciones 3;
		}
		
		---los operadores comparativos son <,>,==,!=
		---los operadores lógicos son || (o: cualquiera cumple), && (y: todos cumplen)
		---se puede escribir la condición opuesta como !(condición)
		por ejemplo: !(true) == false
		-> si dentro de un condicional se pone el nombre de una variable o función sola, quiere decir que es true y se cumple la condición o que es distinto de 0, NULL o false
	*/
	
	int edad;
	
	cout<<"\t--- Para acceder debe tener +18 años---"<<endl;
	cout<<"\nIngrese su edad: "; cin>>edad;
	
	if(edad >= 18) // (edad > 18 || edad == 18)
		cout<<"\n\tAcceso permitido"<<endl; // cuando es 1 pura instrucción no hace falta usar {}
	else // (edad < 18)
		cout<<"\n\tAcceso denegado"<<endl;
	
	getch();
	return 0;
}
