#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nadadores.h"

//EJERCICIO REALIZADO POR ALEXIS GÓMEZ CHIMENO

//Función principal
int main(int argc, char* argv[])
{
	int contador_nadadores = 0; //variable para contar el número de nadadores introducido
	int del_for = 0; //variable auxiliar para los bucles de tipo for
	nadador_t* nadadores = NULL; //variable para el array dinámico
	float tiempo_total = 0.0; //tiempo total de los nadadores
	float cuadrados_de_tiempos = 0.0; //tiempo al cuadrado de cada nadador
	float desviacion = 0.0; //variable donde se guardará la desviación típica
	
	nadadores = (nadador_t*)malloc(sizeof(nadador_t)*NADADORES_TOTALES);//declaración del array dinámico
	printf("A continuación debe introducir la información relativa a los nadadores \n\n");
	//Bucle para introducir las características de los nadadores
	for(del_for = 0; del_for < NADADORES_TOTALES; ++del_for)
	{
		printf("------------------------\n");
		printf("        Nadador %d:     \n", del_for+1);
		printf("------------------------\n");
		introducirNadador(&(nadadores[del_for])); //llamada a la función introducirNadador
		tiempo_total = tiempo_total + (nadadores[del_for].tiempo); //Voy sumando los tiempos de todos los nadadores
		cuadrados_de_tiempos = cuadrados_de_tiempos + (pow(nadadores[del_for].tiempo, 2)); //calculo los tiempos de cada nadador al cuadrado
		contador_nadadores++; //incremento los nadadores en 1 cada vez que introduzco uno nuevo
	}
	
	
	desviacion = calcularDesviacion(contador_nadadores, tiempo_total, cuadrados_de_tiempos); //llamada a la función calcularDesviacion
	printf("La desviacion es: %f\n", desviacion);
	//bucle para liberar la memoria ocupada por los strings de cada nadador
	for(del_for = 0; del_for < NADADORES_TOTALES; ++del_for)
	{
		liberarMemoriaStrings(&(nadadores[del_for]));
	}
	//liberación del array dinámico de los nadadores
	free(nadadores);
	
	return 0;
}