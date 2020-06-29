#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"
//REALIZADO POR ALEXIS GÓMEZ CHIMENO
int main(int argc, char* argv[])
{
	int bucle = 0; //variable que mantiene la ejecución del prograama
	long int amplitud = 0; //variable que guardará el número de productos a introducir
	int contador = 0; //variable que lleve la cuenta de cuántos productos se han introducido
	int del_fori = 0;
	int dia = 0;
	producto_t* producto = NULL;
	if(argc<=1) //Condicional que asegura que el usuario ha introducido el número de productos por parámetros
	{
		printf("Error, introduzca cuántos productos quiere\n"); //mensaje de error
		
	}else
	{
		amplitud = strtol(argv[1], NULL, 10); //Parseo del dato introducido por parámetro a formato integer
		
		
		if(amplitud > 0) //Condicional que se asegura que el número de productos introducidos no es negativo 0
		{
			producto =(producto_t*)malloc(sizeof(producto_t)*amplitud);
			
			do{
				
				if(contador == amplitud) //Condicional que se encarga de mostrar el resumen de la introducción de datos una vez que se ha llegado al número máximo de productos que introdujo el usuario
				{	
					OrdenarProductos(producto, contador); //llamada a la función OrdenarProductos
					MostrarProducto_Ganancia(producto,contador); //llamada a la función MostrarProducto_Ganancia
					LiberarMemoria(producto, contador); //llamada a la función LiberarMemoria
					bucle = 1; //salida del bucle principal del programa

				}
				else
				{
					printf("----------------------------------------\n");
					printf("Introduzca los datos del producto %d\n", contador+1);
					printf("----------------------------------------\n");
					if(contador == 0) //Condicional que asegura la introducción de un único día de introducción de productos
					{
						dia = EstablecerDia();
					}
						 
					CrearProducto(&(producto[contador]), dia); //llamada a la función CrearProducto
					RetocarProducto(&(producto[contador])); //llamada a la función RetocarProducto
					contador++; //cada vez que se almacena un producto, se incrementa el número de productos introducidos
				}
			}while(bucle == 0);
		}
		else
		{
			printf("Error, no puede querer introducir 0 o menos productos\n"); //mensaje de error
		}
	}
	return 0;
}
