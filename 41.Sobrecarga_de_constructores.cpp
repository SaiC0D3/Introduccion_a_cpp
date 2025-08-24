// una clase puede tener varios CONSTRUCTORES, de modo que el usuario pueda inicializar los atributos de los objetos de la forma que desee 
// la computadora sabr� que constructor usar por el tipo y cantidad de par�metros recibidos (inicializar� el que concidan sus par�metros con los valores ingresado)
// una vez inicializados los valores de los atributos, las funciones trabajar�n con esos valores hasta que se le den unos distintos al mismo objeto, o se cree otro objeto con distintos valores

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<fstream>

using namespace std;

class Fecha{
	private:
		int dia, mes, anio;
	public:
		// los constructores tambi�n son funciones, por lo que trabajan con cualquier tipo de par�metros (ya sean temporales o no)
		Fecha(int, int, int); // constructor1 -> por si se ingresan los 3 par�metros de la fecha en orden corriente
		Fecha(long); // constructor2 -> por si se ingresan la fecha como �n solo par�metro (ej:20170323)
		void mostrarFecha(); // funci�n para poder mostrar los atributos
};

// todos los constructores se llaman igual, pero difieren en sus par�metros
Fecha::Fecha(int _dia, int _mes, int _anio){
	dia = _dia;
	mes = _mes;
	anio = _anio;
}

Fecha::Fecha(long date){
	// para descomponer la fecha ingresada como un s�lo n�mero (formato fecha-mes-dia pegados) sacamos cada parte de la fecha y la guardamos en los atributos:
	// Ej: 20170323
	
//	(!) ESTE M�TODO NO FUNCIONA POR ALGUNA RAZ�N:
//	anio = int(date/10000); // con la funci�n 'int' convertimos a tipo entero el n�mero recibido, en este caso para sacar el a�o tenemos que eliminar los 4 d�gitos sgtes.
//	// 20170323/10000 = 2017 (pero 2017 sigue siendo long, por eso con la funci�n int lo cambiamos a int para que pueda guardarse en el atributo de tipo int)
//	mes = int((date-anio*1000)/100);
//	// 20170323-20170000 = 0323/100 = 03 (en este caso solo se guarda 3 como entero)
//	dia = int(date-anio*10000-mes*100);
//	// 20170323-20170000 = 323-300 = 23 

	anio = date / 1e4; // 20170323/10000 = 2017 (el resultado no es de tipo long, si no del tipo de la variable que se le asigne)
	mes = (date / 100) % 100; // 20170323/100 = 201703%100 = 03 = 3 (eliminamos los d�gitos del d�a y sacamos los �ltimos que son del mes)
	dia = date % 100; // 20170323%100 = 23 (sacamos los �ltimos d�gitos que son del d�a)
}

void Fecha::mostrarFecha(){ // mostramos la fecha en orden corriente, se como sea que se hayan inicializado los atributos
	cout<<"La fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
	setlocale(LC_ALL, "Spanish");
	
	Fecha hoy(26,2,2022);
	Fecha ayer(20220225);
	
	hoy.mostrarFecha();
	ayer.mostrarFecha();
	
	getch();
	return 0;
}

