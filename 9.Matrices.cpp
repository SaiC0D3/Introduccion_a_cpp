// las matrices son arreglos bidimensionales, igual que los arreglos normales pero con m�s grupos de datos en distintas columnas (arriba hacia abajo) y filas (izq a der)

#include<iostream>
#include<locale.h>
#include<conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	
	
	/* DEFINICI�N:
		tipo nombre[n�filas][m�columnas]
		tipo2 nombre2 [n�filas][m�columnas] = {{m elementos separados por coma}, {m elementos}, ...n{m...}}
		
		---al leer datos, primero se llenan las filas, luego las columnas con los elementos (tambi�n empiezan desde 0 hasta n-1)
		---para obtener un elemento se 'llama' a la variable con el n�mero de fila y columna de la posici�n del dato (empieza en 0)
		---hace falta especificar el n�mero de columnas y filas si no queremos que se llenen de basura infinita
	*/
	
	// pos. filas:          0        1
	int numeros[2][3] = {{1,3,5}, {2,4,6}}; // 2 grupos (filas) de 3 elementos cada uno (columnas)
	// pos. columnas:     0,1,2    0,1,2
	
	cout<<"numeros[0][2] = "<<numeros[0][2]<<endl; // muestra 5 que est� en la fila 1 (pos: 0) y columna 3 (pos: 2)
	cout<<"\nMatriz de n�meros: "<<endl;
	
	// para mostrar todos los �ndices usamos un bucle que recorra por cada fila todas las columnas:
	for(int row=0; row<2; row++){ // usamos �ndices para cada dimensi�n
		for(int col=0; col<3; col++){ 
			cout<<numeros[row][col]<<" ";
		}
		cout<<endl;
	}
	
	getch();
	return 0;
}
