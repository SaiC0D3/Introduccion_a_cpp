// las FUNCIONES sirven para dividir el programa en distintas y específicas partes, cada funión dessarrolla 1 sola tarea
// las funciones que no retornar un valor son de tipo VOID (al momento de llamarse se ejecuta el código de la función y al terminar sigue con el main)
// las funciones void generalmente se usan para mostrar o desplegar resultados, no solo un valor, o para dejar vacío el main y todo hacerlo en la función
// al momento de llamarlas va únicamente el nombre con los parámetros (no se puede asignar a una variable ni mostrar en cout)
// los parámetros pueden ir vacíos si es que no reciben ningua variable externa
// las funciones void pueden llamar a otras funciones dentro de ellas

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

// PROTOTIPO:
void menu();

// las variables globales que se definen aquí sirven para todas las funciones

int main(){
	setlocale(LC_ALL, "Spanish");
	
	// LLAMADA:
	menu();
	
	system("pause");
	return 0;
}

//DEFINICIÓN:
void menu(){
	int op; // esta variable local solo se puede usar en esta función
	
	do{
		cout<<"  .:MENÚ:.\n";
		cout<<"\n1. 50 Números Pares";
		cout<<"\n2. 50 Números Impares";
		cout<<"\n3. Salir";
		cout<<"\n\nOpción elegida: "; cin>>op;
	
		switch(op){
			case 1:
				cout<<"\nNúmeros Pares--------------------------------------------------------\n"<<endl;
				for(int i=0; i<50; i++){
					if(!(i % 2)) // (i % 2) == 0
						cout<<i<<" ";
				}
				break;
			case 2:
				cout<<"\nNúmeros Impares--------------------------------------------------------\n"<<endl;
				for(int i=0; i<50; i++){
					if(i % 2) // (i % 2) != 0
						cout<<i<<" ";
				}
				break;
			case 3: break;
			default:
				cout<<"\nOpción inválida...\n"<<endl;
				break;
		}
	} while(op != 3);
	
	cout<<endl;
}
