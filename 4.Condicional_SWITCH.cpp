// los condicionales con booleanos permiten ejecutar código específico que requiera de una condición
// el switch se puee utilizar a manera de bucle para pedir una tarea reiteradas veces mientras el usuario quiera (como un do while)
// -> cuando se crea un menu, las opciones deben estar antes del switch dentro de un do-while

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* SWITCH
		switch(expresión){ 	// dentro de expresión va la variable que podría recibir distintos valores, para cada valor hay un caso a ejecutar
			case primer_valor:
				instrucciones 1;
				break; 	// después de cada case, para evitar mostrar más de una opción
		    case segundo_valor:
				instrucciones 2;
				break;
			default: 	// en caso de no tomar ninguno de los valores anteriores 
				instrucciones n;
				break;
		}
		
		---el switch es un condicional múltiple
		---solo se ejecutará el código correspondiente al caso seleccionado
	*/
	
	int mes;
	
	cout<<"\nIngrese un número (entre 1-12): "; cin>>mes;
	
	switch(mes){
			case 1: // en caso de ser un string la variable, los casos serían por ej: 'A', 'a', 'X', etc.
				cout<<"\nRegistró ENERO"<<endl;
				break; 	
			case 2:
				cout<<"\nRegistró FEBRERO"<<endl;
				break;
			case 3:
				cout<<"\nRegistró MARZO"<<endl;
				break;
			case 4:
				cout<<"\nRegistró ABRIL"<<endl;
				break;
			case 5:
				cout<<"\nRegistró MAYO"<<endl;
				break;
			case 6:
				cout<<"\nRegistró JUNIO"<<endl;
				break;
			case 7:
				cout<<"\nRegistró JULIO"<<endl;
				break;
			case 8:
				cout<<"\nRegistró AGOSTO"<<endl;
				break;
			case 9:
				cout<<"\nRegistró SEPTIEMBRE"<<endl;
				break;
			case 10:
				cout<<"\nRegistró OCTUBRE"<<endl;
				break;
			case 11:
				cout<<"\nRegistró NOVIEMBRE"<<endl;
				break;
			case 12:
				cout<<"\nRegistró DICIEMBRE"<<endl;
				break;
			default: cout<<"\nOpción inválida"<<endl; break; // se puede poner todo en 1 sola línea
	}
	
	getch();
	return 0;
}
	
