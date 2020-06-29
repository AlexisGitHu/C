#ifndef _SUPERMERCADO_H
#define _SUPERMERCADO_H

#define NUM_CARACTERES 3 //Número de caracteres que se quieren añadir al final del nombre del producto
//Estructura producto que almacena las variables de cada producto
typedef struct producto
{
	int dia_jacob;
	long long int num_ref;
	char* nombreProd;
	char* nombreProv;
	float precioCoste;
	float precio_venta;
	long long int prod_vend;
	
}producto_t;

//Prototipado de funciones
char* leeLineaDinamica();
void CrearProducto(producto_t* producto, int dia);
void RetocarProducto(producto_t* producto);
void MostrarProducto_Ganancia(producto_t* producto, int contador);
void LiberarMemoria(producto_t* producto, int contador);
float gananciaDia(producto_t* producto, int contador);
void OrdenarProductos(producto_t* producto, int contador);
int EstablecerDia();

#endif