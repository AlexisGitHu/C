#ifndef _NADADORES_H
#define _NADADORES_H

#define NADADORES_TOTALES 16 //declaración del número máximo de nadadores

//estructura que recoge las características de los nadadores
typedef struct
{
	char* nombre;
	int edad;
	char* prueba;
	float tiempo;
	
}nadador_t;

//Prototipado de funciones
void introducirNadador(nadador_t* nadador);
void liberarMemoriaStrings(nadador_t* nadador);
float calcularDesviacion(int contador_nadadores, float tiempo_total, float cuadrados);

#endif 