#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"
//REALIZADO POR ALEXIS GÓMEZ CHIMENO
//Función que se encarga de la lectura de cadenas
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


//Función que pide al usuario los atributos del producto y los almacena en su struct correspondiente
void CrearProducto(producto_t* producto, int dia)
{
	
	producto->dia_jacob = dia; //Almaceno el día fijo en el que se introducen los productos
	//Este bucle comprueba que el número de referencia introducido sea válido, es decir, mayor o igual que 0
	do{
		printf("Introduzca el número de referencia: \n");
		scanf("%lld", &(producto->num_ref));
		while(getchar()!='\n'); //Limpieza de búffer de entrada
		
		if(producto->num_ref<0)
		{
			printf("------------------------------------------------\n");
			printf("Error, introduzca un número de referencia válido\n");
			printf("------------------------------------------------\n");
		}
	}while(producto->num_ref < 0);
	
	printf("Introduzca el nombre del producto: \n");
	producto->nombreProd = leeLineaDinamica(); //llama a la función leeLineaDinamica para que el usuario pueda introducir un nombre de producto
	
	printf("Introduzca el nombre del proveedor: \n");
	producto->nombreProv=leeLineaDinamica();//llama a la función leeLineaDinamica para que el usuario pueda introducir un nombre de proveedor
	
	//Este bucle comprueba que el precio de coste del producto no es negativo y lo almacena
	do{
		printf("Introduzca el precio en euros de coste del artículo: \n");
		scanf("%f", &(producto->precioCoste));
		while(getchar()!='\n');//Limpieza de búffer de entrada
		
		if(producto->precioCoste<0)
		{
			printf("----------------------------------\n");
			printf("Error, introduzca un precio válido\n"); //mensaje de error
			printf("----------------------------------\n");
		}
		
	}while(producto->precioCoste < 0);
	
	//Este bucle comprueba que el precio de venta del producto no es negativo y lo almacena
	do{
		printf("Introduzca el precio en euros de venta del artículo: \n");
		scanf("%f", &(producto->precio_venta));
		while(getchar()!='\n'); //Limpieza de búffer de entrada
		
		if(producto->precio_venta<0)
		{
			printf("----------------------------------\n");
			printf("Error, introduzca un precio válido\n"); //mensaje de error
			printf("----------------------------------\n");
		}
		
		
	}while(producto->precio_venta < 0);
	
	//Este bucle comprueba que el número de productos no es negativo y lo almacena
	do{
		printf("Introduzca el número de productos vendidos: \n");
		scanf("%lld", &(producto->prod_vend));
		while(getchar()!='\n'); //Limpieza de búffer de entrada
		
		if(producto->prod_vend<0)
		{
			printf("----------------------------------\n");
			printf("Error, introduzca un número válido\n"); //mensaje de error
			printf("----------------------------------\n");
		}
		
	}while(producto->prod_vend < 0);


}
//Esta función se encarga de modificar los strings de nombre producto de cada struct, añade _ y las 3 primeras letras del nombre del proveedor al nombre del producto
void RetocarProducto(producto_t* producto)
{
	char* cadena_temp;
	int verificar =0;
	cadena_temp = (char*)malloc(sizeof(char)*NUM_CARACTERES);
	verificar = strlen(producto->nombreProd) + 1; //Se invoca a la función strlen para contar el número de caracteres mi string y le sumo uno para tener en cuenta el carácter nulo
	//se pide más memoria de la inicial para asegurar que tengo suficiente para almacenar la antigua cadena y los caracteres de más que se le introducen
	producto->nombreProd = (char*)realloc(producto->nombreProd,sizeof(char)*(verificar + NUM_CARACTERES + 1)); 
	strncpy(cadena_temp, producto->nombreProv, NUM_CARACTERES); //invoco a la función strncpy para copiar los caracteres que quiero introducir a una cadena temporal
	cadena_temp[NUM_CARACTERES]='\0'; //me aseguro que la cadena temporal tenga el caracter nulo al final para evitar errores
	strcat(producto->nombreProd, "_"); //invoco a la función strcat para concatenar el caracter guión bajo con mi string original
	strcat(producto->nombreProd, cadena_temp); //invoco a la función strcat para concatenar mi cadena temporal con el string original al que se le ha añadido el guión bajo
	free(cadena_temp); //libero la memoria de la cadena temporal al finalizar su uso
	
}
//Función que se ocupa de liberar la memoria reservada dinámicamente, tanto de los nombres de las variables de los structs como de los propios structs
void LiberarMemoria(producto_t* producto, int contador)
{
	int del_fori = 0;
	for(del_fori=0; del_fori < contador; del_fori++)
	{
		free(producto[del_fori].nombreProv);
		free(producto[del_fori].nombreProd);
	}
	free(producto);

}
//Función que se encarga de mostrar por la salida estándar los productos introducidos y los beneficios del día
void MostrarProducto_Ganancia(producto_t* producto, int contador)
{
	int del_fori = 0;
	float beneficios = 0.0;
	for(del_fori=0; del_fori<contador; del_fori++)
	{
		printf("-----------------------------------------------\n");
		printf("El nombre del producto es: %s\n", producto[del_fori].nombreProd);
		printf("El nombre del proveedor es: %s\n", producto[del_fori].nombreProv);
		printf("El día en que se registró el producto fue el: %d (2020)\n", producto[del_fori].dia_jacob);
		printf("El número de referencia es: %lld\n", producto[del_fori].num_ref);
		printf("El precio de coste en del producto es: %f€\n", producto[del_fori].precioCoste);
		printf("El precio de venta del producto es: %f€\n", producto[del_fori].precio_venta);
		printf("El número de productos vendidos ha sido: %lld\n", producto[del_fori].prod_vend);
		printf("-----------------------------------------------\n");
	}
	beneficios = gananciaDia(producto,contador); //inovoco a la función gananciaDia para calcular la repercusión económica del día
	
	printf("La ganancia económica del día ha sido: %f€\n",beneficios);
	
	
}
//Función que se encarga de calcular los beneficios obtenidos por los productos vendidos y de devolverlos a donde quiera que se invocara
float gananciaDia(producto_t* producto, int contador) 
{
	float gastos = 0.0;
	float ventas = 0.0;
	float beneficios = 0.0;
	int del_fori = 0;
	for(del_fori = 0; del_fori<contador; del_fori++)
	{
		gastos = gastos + ((producto[del_fori].precioCoste) * (producto[del_fori].prod_vend)); //calcula los gastos que se han tenido al comprar esos productos
		ventas = ventas + ((producto[del_fori].precio_venta)* (producto[del_fori].prod_vend)); //calcula los ingresos que se han tenido al vender esos productos
	}
	
	beneficios = ventas - gastos; //resta los ingresos menos los gastos y saca el beneficio
	
	return beneficios;
}
//Función que se encarga de ordenar los productos por su nombre alfabéticamente
void OrdenarProductos(producto_t* producto, int contador)
{
	int del_fori = 0;
	int del_forj = 0;
	producto_t producto_temp; //incializo un struct temporal
	//Este bucle se encarga de ir ordenando selectivamente los nombres de los productos por orden alfabético sin tener en cuenta mayúsculas o minúsculas, comprueba el producto 0 con el resto, el 1 con el resto y así sucesivamente
	for(del_fori = 0; del_fori<contador-1; ++del_fori)
	{
		for(del_forj = del_fori + 1; del_forj<contador; ++del_forj)
		{
			if(strcasecmp(producto[del_fori].nombreProd, producto[del_forj].nombreProd) > 0 ) //la función strcasecmp me permite saber cuál de los dos productos tendría que ir el primero alfabéticamente
			{
				producto_temp = producto[del_fori];
				producto[del_fori] = producto[del_forj];
				producto[del_forj] = producto_temp;
			}
		}
	}
}
//Función que se encarga de establecer el día en el que se encuentran los productos introducidos por el usuario y devolverlo a la variable que lo invoco
int EstablecerDia()
{
	int dia = 0;
	do
	{
		printf("Introduzca el día en el que se encuentra: \n");
		scanf("%d", &dia);
		while(getchar()!='\n'); //Limpieza de búffer de entrada
		
		if(dia<=0 || dia > 365)
		{
			printf("-------------------------------\n");
			printf("Error, introduzca un día válido\n"); //Mensaje de error
			printf("-------------------------------\n");
		}
	}while(dia <=0 || dia > 365);
	
	return dia;
}