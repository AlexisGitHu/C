#include <stdio.h>
#include <stdlib.h>
#include "simetrica.h"

//EJERCICIO REALIZADO POR ALEXIS GÓMEZ CHIMENO

//función para generar una matriz de números aleatorios
void generarMatrizSimetrica(int** matriz, int dimension)
{
	int filas = 0;//filas de las matriz
	int columnas = 0;//columnas de la matriz
	//bucle para ir insertando los elementos de la matriz uno a uno
	for(filas = 0; filas<dimension; ++filas)
	{
		for(columnas=0; columnas<dimension; ++columnas)
		{
	
			matriz[filas][columnas] = (rand()%RANDOM_MAX)+RANDOM_MIN; //genera números aleatorios comprendidos entre 1 y 19
			printf("El numero introducido es: %d\n", matriz[filas][columnas]);
			
		}
	}
}
//función para comprobar la simetría de los elementos de la matriz
void comprobarMatrizSimetrica(int** matriz, int dimension)
{
	int comprobador = (dimension * dimension); //variable que determina el número de elementos de la matriz, para luego hacer comprobaciones
	int contador = 0; //variable auxiliar para determinar si es simétrica o no
	
	int filas = 0; //filas de las matriz
	int columnas = 0; //columnas de la matriz
	//Comprueba si se ha dado el número necesario de comprobaciones tal que los elementos Aij = Aji, para todo i,j pertenecientes a los naturales
	for(filas = 0; filas<dimension; ++filas)
	{
		for(columnas=0; columnas<dimension; ++columnas)
		{
			if(matriz[filas][columnas] == matriz[columnas][filas])
			{
				contador++;
			}
		}
	}
	//Determina en base a las comprobaciones anteriores si se ha dado el número necesario de casos para que sea simétrica
	if(comprobador==contador)
	{
		printf("Enhorabuena, es una matriz simétrica\n");
	}
	else
	{
		printf("Lo siento, no es una matriz simétrica\n");
	}
}