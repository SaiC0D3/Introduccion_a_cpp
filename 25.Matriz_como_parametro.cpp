// para enviar matrices como parámetros en una función, hace falta enviar el número de columnas y filad del mismo como parámetro además del nombre del arreglo

#include<iostream>
#include<conio.h>
#include<locale.h>
#include<string.h>
#define MAXCOL 3

using namespace std;

// en la definción de la función es OBLIGATORIO especificar el máximo número de columnas, no así con las filas (y dos enteros para filas y columnas)
void mostrar_matriz(int m[][MAXCOL], int, int); // una pura función, ya que se actualizan los valores la matriz con los cuadrados, no se genera una nueva
void calcular_cuadrados(int m[][MAXCOL], int, int); // incluso se podría crear una función llamada mostrar_cuadrados que muestre directamente cada posición al cuadrado

int main(){
	setlocale(LC_ALL, "Spanish");
	
	const int nfilas = 2; // constantes igual que el tamaño de un arreglo, cuando se define por defecto
	const int ncolum = 3;
	int matriz[nfilas][ncolum] = {{1,2,3},{4,5,6}};
	
	mostrar_matriz(matriz, nfilas, ncolum);
	calcular_cuadrados(matriz, nfilas, ncolum);
	// en este punto la matriz ya tiene los cuadrados como valores, asi que se llama a la misma tal cual
	cout<<"\nMostrando elementos de la matriz al cuadrado:\n"<<endl;
	mostrar_matriz(matriz, nfilas, ncolum);
	
	getch();
	return 0;
}

void mostrar_matriz(int m[][MAXCOL], int nfil, int ncol){
	for(int i=0; i<nfil; i++){
		for(int j=0; j<ncol; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}

void calcular_cuadrados(int m[][MAXCOL], int nfil, int ncol){
	for(int i=0; i<nfil; i++){
		for(int j=0; j<ncol; j++){
			m[i][j] *= m[i][j]; 
		}
	}
}
