// las estructuras nos permiten crear variables que almacenen varias características distintas de alguna cosa, todas relacionadas entre sí
// se definen antes de la función principal, al igual que las variables globales, de modo que se puedan utilizar en cualquiér parte del código

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>

using namespace std;

int variable_global; // esta variable se puede usar en función fuera o dentro de la función principal

// definición de una estructura:
struct Producto{ // una variable tipo struct (como un arreglo, pero de varios tipos)
	// aquí dentro van todas las variables de cualquier tipo que queramos relacionadas a la estructura
	char nombre[20]; // cada una de estas variables se llaman CAMPOS
	float precio; // puede contener un campo que sea tipo Producto (struct)
	int stock;
} producto1, producto2; // declaración de variables todas con los mismos campos (1)
// debe declararse al menos una variable del tipo Producto
// si hay más de un campo del mismo tipo, se pueden escribir en una sola línea separados por coma

// para asignarle valores preestablecidos a los campos de cada variable se declara cada variable por separado:
struct Persona{ 
	char nombre[20]; 
	int edad;
} // se pueden declarar en esta sola línea
persona1 = {"Mati", 18}, // se asignas valores al igual que un arreglo, pero con diferentes tipos
persona2 = {"Lucy", 20}; // las variables se separan por comas y la última declarada termina en punto-coma

int main(){
	setlocale(LC_ALL, "Spanish");
	
	/* declaración de variables todas con los mismos campos (2)
		también se pueden declarar variables del mismo tipo estructura dentro del main() en vez de declararlas en la misma estrcutura:
		-> (struct) Producto producto1, producto2,...; // estas variables se dice que son de tipo 'Producto', no hace falta colocar tipo struct
	*/
	
	// para acceder a los valores de cada variable por estructura, se llama así: nombre_variable_estructura.campo (cualquier campo, y la variable estructura las que se hayan declarado)
	cout<<"Datos persona 1:"<<endl;
	cout<<"\nNombre: "<<persona1.nombre;
	cout<<"\nEdad: "<<persona1.edad;
	
	cout<<"\nDatos persona 2:"<<endl;
	cout<<"\nNombre: "<<persona2.nombre;
	cout<<"\nEdad: "<<persona2.edad;
	
	cout<<endl<<endl<<"-------------------------------------------"<<endl;
	
	// de la misma forma para ller por consola los valores de los campos de cada variable, de guardan en la variable.campo correspondiente
	cout<<"\nIngrese nombre del producto: "; 
	cin.getline(producto1.nombre, 20, '\n');
	
	cout<<"Ingrese precio del producto: ";
	cin>>producto1.precio;
	
	producto1.stock = 5;
	
	cout<<"\nProducto: "<<strupr(producto1.nombre)<<" a "<<producto1.precio<<" dólares";
	cout<<"\nCantidad disponible: "<<producto1.stock<<endl;
	
	getch();
	return 0;
}

/* CREAR TDA CON FUNCIONES:
#include <iostream.h>
#define Max 30
struct Agenda{
char nombre[30];
char fono[12];
int mes_c;
};
void llenar(Agenda a[Max],int n);
//Ingresar elementos a la estructura
void Mostrar(Agenda a[Max],int n);
//Muestra elementos a la estructura
void Mostrar(Agenda a[Max],int n, int M);
//Muestra nombres y telefonos de quienes
están de cumpleaños en M
int pide_n();
// Ingresa largo validado
int main()
{ int n,Mes;
Agenda a[Max];
cout <<“Cuantos amigos desea
ingresar”;
n=pide_n();
llenar(a,n);
cout <<“Ingrese mes que desea
chequear cumpleaños”;
cin>>Mes;
cout << “De mis amigos : \n”;
Mostrar(a,n);
cout<<“Los que est{an de
cumpleaños en “<<Mes <<“son:
“;
Mostrar(a,n,Mes);
return 0;
}
void llenar(Agenda a[Max],int n)
{ int i;
for(i=0; i < n; i++)
{ cout <<“Nombre Amigo ” <<
i+1<<“:\t”;
cin >> a[i].nombre;
cout <<“Su telefono: \t”;
cin >> a[i].fono;
cout <<“Mes de nacimiento :\t”;
cin >> a[i].mes_c;
}
}
void Mostrar(Agenda a[Max],int n)
{ int i;
for(i=0; i < n; i++)
cout <<a[i].nombre << “:\t”
<<a[i].fono << “:\t”
<<a[i].mes_c <<endl;
}
void Mostrar(Agenda a[Max],int n, int M)
{ int i;
for(i=0; i < n; i++)
if (a[i].mes_c == M)
cout <<a[i].nombre << “:\t”
<<a[i].fono << endl;
}
int pide_n()
{ int n;
do {
cout <<“Ingrese numero de amigos
(Máximo ”<<Max<<“): “;
cin >> n;
if (n < 1 || n > Max)
cout <<“ERROR, intente de nuevo”;
} while (n < 1 || n > Max);
return n;
}
*/
