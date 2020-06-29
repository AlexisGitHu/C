#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio.h"

int main(int argc, char* argv[])
{
	int num_autores = 0;
	int max1 = 10;
	int max2 = 10;
	int num_libros = 0;
	int opcion = 0;
	int bucle = 0;
	char* parsear = NULL;
	FILE* fichero;
	autor_t* autores;
	libro_t* libros;
	
	
	if(argc == 2)
	{
		fichero = fopen(argv[1],"r+");
		if(fichero == NULL)
		{
			printf("No se ha encontrado el archivo\n");
			exit(1);
		}
		else
		{		//leeInfoInicial
				num_autores = leeInfoInicial(fichero);
				num_libros = leeInfoInicial(fichero);
				
				autores = (autor_t*)malloc(sizeof(autor_t)*max1);
				libros = (libro_t*)malloc(sizeof(libro_t)*max2);
				
				leeAutoresFichero(fichero,autores,num_autores);
				leeLibrosFichero(fichero,libros,num_libros);
				emparejarAutores(autores,libros,num_libros,num_autores);
			
			while(bucle==0)
			{
				
				printf("----------------------------\n");
				printf("			Menú			\n");
				printf("----------------------------\n");
				printf("1. Buscar libros\n");
				printf("2. Introducir nuevo autor\n");
				printf("3. Introducir nuevo libro\n");
				printf("4. Salir\n");
				printf("Introduzca una opción: ");
				scanf("%d",&opcion);
				while(getchar()!='\n');
				
				switch(opcion)
				{
					case 1:
						buscarLibros(libros,autores,num_autores,num_libros);
						break;
					case 2:
						if(num_autores>=max1)
						{
							printf("Añadiendo más espacio...\n");
							max1 += INCREMENTO;
							autores=(autor_t*)realloc(autores,sizeof(autor_t)*max1);
						}
						IntroducirAutor(&(autores[num_autores]));
						num_autores++;
						break;
					case 3:
						if(num_libros>=max2)
						{
							printf("Añadiendo más espacio...\n");
							max2 += INCREMENTO;
							libros=(libro_t*)realloc(libros,sizeof(libro_t)*max2);
						}
						IntroducirLibro(&(libros[num_libros]));
						ActualizarLista(autores,&(libros[num_libros]),&(num_autores));
						emparejarAutores(autores,libros,num_libros,num_autores);
						num_libros++;
						
						break;
					case 4:
						GuardarNuevosDatos(fichero,autores,libros,num_autores,num_libros);
						fclose(fichero);
						liberarMemoria(libros,autores,num_autores,num_libros);
						free(libros);
						free(autores);
						bucle = 1;
						break;
					default:
						printf("La opción introducida no es válida\n");
						break;
						
				}
			}
				
				
		}
	}
	else
	{
		printf("Introduzca una sola cadena y que sea válida");
	}
	
	return 0;
}