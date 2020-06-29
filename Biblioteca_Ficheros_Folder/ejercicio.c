#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio.h"


void buscarLibros(libro_t* libros, autor_t* autores, int num_autores, int num_libros)
{
	int opcion = 0;
	printf("----------------------------\n");
	printf("            Menú			\n");
	printf("----------------------------\n");
	printf("1. Buscar por autor\n");
	printf("2. Buscar por título\n");
	printf("3. Buscar por género\n");
	printf("Introduzca una opción: ");
	scanf("%d",&opcion);
	while(getchar()!='\n');
	
	switch(opcion)
	{
		case 1:
			buscarAutor(autores, num_autores);
			break;
		case 2:
			buscarTitulo(libros,num_libros);
			break;
		case 3:
			buscarGenero(libros,num_libros);
			break;
		default:
			printf("La opción seleccionada no es válida\n");
			break;
	}
}

void buscarAutor(autor_t* autores, int num_autores)
{
	char* nombre = NULL;
	int i = 0;
	printf("Introduzca su autor: ");
	nombre=leeLineaDinamica();
	for(i=0; i<num_autores;i++)
	{
		if(strstr(autores[i].nombre,nombre)!=NULL)
		{
			if(autores[i].lista!=NULL && autores[i].lista[0]!='\0')
			{
				printf("%s\n",autores[i].lista);
			}
			
		}
	}
	free(nombre);
	
}
void buscarTitulo(libro_t* libros, int num_libros)
{
	char* titulo = NULL;
	int i = 0;
	printf("Introduzca el título: ");
	titulo=leeLineaDinamica();
	for(i=0; i<num_libros;i++)
	{
		if(strstr(libros[i].titulo,titulo)!=NULL)
		{
			printf("%s\n",libros[i].titulo);
		}
	}
	free(titulo);
	
}
void buscarGenero(libro_t* libros, int num_libros)
{
	char* genero = NULL;
	int i = 0;
	printf("Introduzca el género: ");
	genero=leeLineaDinamica();
	for(i=0; i<num_libros;i++)
	{
		if(strstr(libros[i].genero,genero)!=NULL)
		{
			printf("%s\n",libros[i].titulo);
		}
	}
	free(genero);
	
}
char* leeLineaFichero(FILE* fichero)
{
	int max = 10;
	char* destino = NULL;
	char letra = '\0';
	int contador = 0;
	
	destino = (char*)malloc(sizeof(char)*max);
	letra = getc(fichero);
	
	while((letra!='\n') && (!feof(fichero)))
	{
		destino[contador]=letra;
		contador++;
		letra = getc(fichero);
		if(contador>=max)
		{
			max += INCREMENTO;
			destino = (char*)realloc(destino,sizeof(char)*max);
		}
		
	}
	destino[contador]='\0';
	return destino;
	
}
char* leeLineaDinamica()
{
	int max = 10;
	char* destino = NULL;
	char letra = '\0';
	int contador = 0;
	
	destino = (char*)malloc(sizeof(char)*max);
	destino[0] = '\0';
	letra = getc(stdin);
	
	while(letra!='\n')
	{
		destino[contador]=letra;
		contador++;
		if(contador>=max)
		{
			max += INCREMENTO;
			destino = (char*)realloc(destino,sizeof(char)*max);
		}
		letra = getc(stdin);
	}
	destino[contador]='\0';

	return destino;
	
}
int leeInfoInicial(FILE* fichero)
{
	int numero = 0;
	char* parsear = NULL;
	parsear = leeLineaFichero(fichero);
	numero = atoi(parsear);
	free(parsear);
	
	return numero;
}

void leeAutoresFichero(FILE* fichero, autor_t* autores,int num_autores)
{
	int i = 0;
	char* auxiliar = NULL;
	for(i=0;i<num_autores;i++)
	{
		autores[i].nombre=leeLineaFichero(fichero);
		auxiliar = leeLineaFichero(fichero);
		autores[i].num_libros=atoi(auxiliar);
		autores[i].lista = leeLineaFichero(fichero);
		free(auxiliar);
	}
	
}
void leeLibrosFichero(FILE* fichero, libro_t* libros, int num_libros)
{
	int i = 0;
	int j = 0;
	for(i=0; i<num_libros; i++)
	{
		libros[i].titulo=leeLineaFichero(fichero);
		libros[i].autor.nombre=leeLineaFichero(fichero);
		libros[i].genero=leeLineaFichero(fichero);
	}
}
void emparejarAutores(autor_t* autores,libro_t* libros,int num_libros, int num_autores)
{
	int i = 0;
	int j = 0;
	for(i=0;i<num_autores;i++)
	{
		for(j=0;j<num_libros;j++)
		{
			if(strcmp(libros[j].autor.nombre,autores[i].nombre)==0)
			{
				libros[j].autor=autores[i];
			}
		}
	}
}
void liberarMemoria(libro_t* libros, autor_t* autores,int num_autores,int num_libros)
{
	int i = 0;
	for(i=0; i<num_libros; i++)
	{
		free(libros[i].titulo);
		free(libros[i].genero);

	}
	for(i=0; i<num_autores; i++)
	{
		free(autores[i].nombre);
		free(autores[i].lista);
	}
	
}
void IntroducirAutor(autor_t* autor)
{
	printf("Introduzca un nombre: ");
	autor->nombre=leeLineaDinamica();
	autor->num_libros=0;
	autor->lista=NULL;
}

void IntroducirLibro(libro_t* libro)
{
	
	printf("Introduzca el título del libro: \n");
	libro->titulo=leeLineaDinamica();
	printf("Introduzca el nombre del autor: \n");
	libro->autor.nombre=leeLineaDinamica();
	printf("Introduzca el género: \n");
	libro->genero=leeLineaDinamica();
	
}
void ActualizarLista(autor_t* autor,libro_t* libro,int* num_autores)
{
	int i = 0;
	int j = 0;
	int tope = strlen(libro->autor.nombre);
	int titulo = 0;
	int extra = 0;
	int almacen = (*num_autores);
	int aux = 0;
	int contador = 0;
	int total = strlen(libro->titulo);
	
	for(i=0; i<(*num_autores); i++)
	{
		contador=0;
		for(j=0;j<tope;j++)
		{
			if(libro->autor.nombre[j]==autor[i].nombre[j])
			{
				contador++;
			}
		}
		if(contador==tope)
		{
			printf("Se concatena\n");
			if(autor[i].lista!=NULL && autor[i].lista[0]!='\0')
			{
				aux=strlen(autor[i].lista);
				titulo=strlen(libro->titulo);

				total=aux+titulo;
				printf("%d\n",total);
				autor[i].lista=(char*)realloc(autor[i].lista,sizeof(char)*total+10);
				for(j=(aux-1);j<total;j++)
				{	
					autor[i].lista[j] = libro->titulo[j-(aux-1)];
				}
				autor[i].lista[j-1]=';';
				autor[i].lista[j]=';';
				autor[i].lista[j+1]='\0';
				printf("%s\n",autor[i].lista);
				autor[i].num_libros += 1;
				extra = 1;
			}
			else
			{
				aux=0;
				titulo=strlen(libro->titulo);
				total=aux+titulo;
				autor[i].lista=(char*)realloc(autor[i].lista,sizeof(char)*total+10);
				for(j=aux;j<total;j++)
				{	
					autor[i].lista[j] = libro->titulo[j];
				}
				autor[i].lista[j]=';';
				autor[i].lista[j+1]=';';
				autor[i].lista[j+2]='\0';
				printf("%s\n",autor[i].lista);
				autor[i].num_libros += 1;
				extra = 1;
				
			}
			

			
		}

	}
	if(extra!=1)
	{
		autor[almacen].nombre=libro->autor.nombre;
		printf("%s\n",autor[almacen].nombre);
		autor[almacen].num_libros += 1;
		autor[almacen].lista=libro->titulo;
		(*num_autores)++;
	}
}

void GuardarNuevosDatos(FILE* fichero,autor_t* autores,libro_t* libros, int num_autores,int num_libros)
{

	int i = 0;
	int n = 0;
	char car_auto[10];
	char car_libro[10];
	char auto_libros[10];
	n=sprintf(car_auto,"%d",num_autores);
	n=sprintf(car_libro,"%d",num_libros);
	fseek(fichero,0,SEEK_SET);
		fwrite(car_auto,sizeof(char)*strlen(car_auto),1,fichero);
		fwrite("\n",sizeof(char),1,fichero);
		fwrite(car_libro,sizeof(char)*strlen(car_libro),1,fichero);
		fwrite("\n",sizeof(char),1,fichero);
	for(i=0;i<(num_autores);i++)
	{
		fwrite(autores[i].nombre,sizeof(char)*strlen(autores[i].nombre),1,fichero);
		fwrite("\n",sizeof(char),1,fichero);
		n=sprintf(auto_libros,"%d",autores[i].num_libros);
		fwrite(auto_libros,sizeof(char)*strlen(auto_libros),1,fichero);
		fwrite("\n",sizeof(char),1,fichero);
		if(autores[i].lista!=NULL)
		{
			fwrite(autores[i].lista,sizeof(char)*strlen(autores[i].lista),1,fichero);
			
		}
		fwrite("\n",sizeof(char),1,fichero);
		
	}
	for(i=0;i<(num_libros);i++)
	{
		fwrite(libros[i].titulo,sizeof(char)*strlen(libros[i].titulo),1,fichero);
		fwrite("\n",sizeof(char),1,fichero);
		fwrite(libros[i].autor.nombre,sizeof(char)*strlen(libros[i].autor.nombre),1,fichero);
		fwrite("\n",sizeof(char),1,fichero);
		fwrite(libros[i].genero,sizeof(char)*strlen(libros[i].genero),1,fichero);
		fwrite("\n",sizeof(char),1,fichero);
		
	}

	
}