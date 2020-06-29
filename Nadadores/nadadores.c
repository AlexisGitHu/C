#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nadadores.h"

//Función que recoge los array dinámicos de caracteres 
char* leeLineaDinamica()
{
	int maxLength = 10; //máxima longitud inicial del array dinámico
	int incremento = 10; //variable de incremente de la longitud inicial
	char caracter = '\0'; //inicialización de la variable caracter
	int contador = 0; //contador de caracteres introducidos
	char* destino=(char*)malloc(sizeof(char)*maxLength); //declaración del array dinámico de caracteres
	destino[0]='\0'; //inicialización del array dinámico
	caracter=getchar(); //recogida del primer dato introducido
	while(caracter != '\n')
	{
		destino[contador]=caracter;
		contador++;
		//comprobador, si no tiene suficiente espacio la memoria para guardar el string, proporcionará 10 espacios más de tipo char
		if(contador >= maxLength)
		{
			maxLength+=incremento;
			destino=(char*)realloc(destino,sizeof(char)*maxLength);
			
		}
		caracter=getchar();//recogida de los  datos introducidos a partir del primero
	}
	destino[contador] = '\0';//especificación del caracter nulo al final del string
	return destino;
}

//Función que pide y recoge las características de los nadadores
void introducirNadador(nadador_t* nadador)
{
	
	printf("Introduzca el nombre del nadador: \n");
	nadador->nombre=leeLineaDinamica();
	printf("Introduzca la edad del nadador: \n");
	scanf("%d", &(nadador->edad));
	while(getchar()!='\n'); //limpieza de búffer de entrada del scanf
	printf("Introduzca el nombre de la prueba en la que compite: \n");
	nadador->prueba=leeLineaDinamica();
	printf("Introduzca el tiempo que hizo el nadador en la prueba: \n");
	scanf("%f", &(nadador->tiempo));
	while(getchar()!='\n'); //limpieza de búffer de entrada del scanf
	
}
//Función que liberar la memoria de los strings de cada nadador
void liberarMemoriaStrings(nadador_t* nadador)
{
	free(nadador->nombre);
	free(nadador->prueba);
}
//Función que calcula la desviación típica de los tiempos de los nadadores y la devuelve
float calcularDesviacion(int contador_nadadores, float tiempo_total, float cuadrados)
{
	float desviacion = 0.0;
	//calculo los cuadrados de los tiempos entre los nadadores, por un lado y la media al cuadrado por otro y las resto
	desviacion = (cuadrados / contador_nadadores) - pow((tiempo_total/contador_nadadores),2); 
	
	return desviacion;
}
