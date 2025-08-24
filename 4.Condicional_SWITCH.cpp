// los condicionales con booleanos permiten ejecutar c�digo espec�fico que requiera de una condici�n
// el switch se puee utilizar a manera de bucle para pedir una tarea reiteradas veces mientras el usuario quiera (como un do while)
// -> cuando se crea un menu, las opciones deben estar antes del switch dentro de un do-while

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* SWITCH
		switch(expresi�n){ 	// dentro de expresi�n va la variable que podr�a recibir distintos valores, para cada valor hay un caso a ejecutar
			case primer_valor:
				instrucciones 1;
				break; 	// despu�s de cada case, para evitar mostrar m�s de una opci�n
		    case segundo_valor:
				instrucciones 2;
				break;
			default: 	// en caso de no tomar ninguno de los valores anteriores 
				instrucciones n;
				break;
		}
		
		---el switch es un condicional m�ltiple
		---solo se ejecutar� el c�digo correspondiente al caso seleccionado
	*/
	
	int mes;
	
	cout<<"\nIngrese un n�mero (entre 1-12): "; cin>>mes;
	
	switch(mes){
			case 1: // en caso de ser un string la variable, los casos ser�an por ej: 'A', 'a', 'X', etc.
				cout<<"\nRegistr� ENERO"<<endl;
				break; 	
			case 2:
				cout<<"\nRegistr� FEBRERO"<<endl;
				break;
			case 3:
				cout<<"\nRegistr� MARZO"<<endl;
				break;
			case 4:
				cout<<"\nRegistr� ABRIL"<<endl;
				break;
			case 5:
				cout<<"\nRegistr� MAYO"<<endl;
				break;
			case 6:
				cout<<"\nRegistr� JUNIO"<<endl;
				break;
			case 7:
				cout<<"\nRegistr� JULIO"<<endl;
				break;
			case 8:
				cout<<"\nRegistr� AGOSTO"<<endl;
				break;
			case 9:
				cout<<"\nRegistr� SEPTIEMBRE"<<endl;
				break;
			case 10:
				cout<<"\nRegistr� OCTUBRE"<<endl;
				break;
			case 11:
				cout<<"\nRegistr� NOVIEMBRE"<<endl;
				break;
			case 12:
				cout<<"\nRegistr� DICIEMBRE"<<endl;
				break;
			default: cout<<"\nOpci�n inv�lida"<<endl; break; // se puede poner todo en 1 sola l�nea
	}
	
	getch();
	return 0;
}
	
