// los condicionales con booleanos permiten ejecutar c�digo espec�fico que requiera de una condici�n

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* IF-ELSE
		if(condici�n){
			instrucciones 1;
		}
		else if(caso contrario){
			instrucciones 2;
		}
		else{						// no es necesario poner condici�n en else
			instrucciones 3;
		}
		
		---los operadores comparativos son <,>,==,!=
		---los operadores l�gicos son || (o: cualquiera cumple), && (y: todos cumplen)
		---se puede escribir la condici�n opuesta como !(condici�n)
		por ejemplo: !(true) == false
		-> si dentro de un condicional se pone el nombre de una variable o funci�n sola, quiere decir que es true y se cumple la condici�n o que es distinto de 0, NULL o false
	*/
	
	int edad;
	
	cout<<"\t--- Para acceder debe tener +18 a�os---"<<endl;
	cout<<"\nIngrese su edad: "; cin>>edad;
	
	if(edad >= 18) // (edad > 18 || edad == 18)
		cout<<"\n\tAcceso permitido"<<endl; // cuando es 1 pura instrucci�n no hace falta usar {}
	else // (edad < 18)
		cout<<"\n\tAcceso denegado"<<endl;
	
	getch();
	return 0;
}
