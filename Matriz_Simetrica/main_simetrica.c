#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simetrica.h"

//EJERCICIO REALIZADO POR ALEXIS GÓMEZ CHIMENO

//Bucle principal
int main(int argc, char* argv[])
{
	srand(time(NULL)); //modifica la semilla que toma la función rand() para que se produzcan distintos números
	int** matriz = NULL; //declaración de la matriz
	int del_for = 0;//variable auxiliar para los bucles
	int dimension = 0;
	printf("Introduzca la dimensión de su matriz: ");
	scanf("%d", &dimension);
	fflush(stdin);
	matriz = (int**)malloc(sizeof(int*)*dimension);//declaro el número de filas de la matriz
	for(del_for = 0; del_for<dimension; ++del_for)
	{
		matriz[del_for] = (int*)malloc(sizeof(int)*dimension);//declaro el número de columnas de la matriz
		
		
	}
	generarMatrizSimetrica(matriz, dimension);//llamada a la función de generar matrices aleatorias
	
	comprobarMatrizSimetrica(matriz, dimension); //llamada a la función de comprobación
	//bucle encargado de liberar las columnas de la matriz
	for(del_for = 0; del_for<dimension; ++del_for)
	{
		free(matriz[del_for]);
		
	}
	free(matriz);//elimina las filas de la matriz
	return 0;
}