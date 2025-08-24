// las FUNCIONES sirven para dividir el programa en distintas y espec�ficas partes, cada funi�n dessarrolla 1 sola tarea
// las funciones que no retornar un valor son de tipo VOID (al momento de llamarse se ejecuta el c�digo de la funci�n y al terminar sigue con el main)
// las funciones void generalmente se usan para mostrar o desplegar resultados, no solo un valor, o para dejar vac�o el main y todo hacerlo en la funci�n
// al momento de llamarlas va �nicamente el nombre con los par�metros (no se puede asignar a una variable ni mostrar en cout)
// los par�metros pueden ir vac�os si es que no reciben ningua variable externa
// las funciones void pueden llamar a otras funciones dentro de ellas

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

// PROTOTIPO:
void menu();

// las variables globales que se definen aqu� sirven para todas las funciones

int main(){
	setlocale(LC_ALL, "Spanish");
	
	// LLAMADA:
	menu();
	
	system("pause");
	return 0;
}

//DEFINICI�N:
void menu(){
	int op; // esta variable local solo se puede usar en esta funci�n
	
	do{
		cout<<"  .:MEN�:.\n";
		cout<<"\n1. 50 N�meros Pares";
		cout<<"\n2. 50 N�meros Impares";
		cout<<"\n3. Salir";
		cout<<"\n\nOpci�n elegida: "; cin>>op;
	
		switch(op){
			case 1:
				cout<<"\nN�meros Pares--------------------------------------------------------\n"<<endl;
				for(int i=0; i<50; i++){
					if(!(i % 2)) // (i % 2) == 0
						cout<<i<<" ";
				}
				break;
			case 2:
				cout<<"\nN�meros Impares--------------------------------------------------------\n"<<endl;
				for(int i=0; i<50; i++){
					if(i % 2) // (i % 2) != 0
						cout<<i<<" ";
				}
				break;
			case 3: break;
			default:
				cout<<"\nOpci�n inv�lida...\n"<<endl;
				break;
		}
	} while(op != 3);
	
	cout<<endl;
}
