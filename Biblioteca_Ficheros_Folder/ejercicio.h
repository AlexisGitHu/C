#ifndef _BIBLIOT_H
#define _BIBLIOT_H
#define INCREMENTO 10
#define INFO_AUTOR 3

typedef enum 
{
	Novelas,
	Didacticos,
	Cronicas
}genero_e;

typedef struct autor
{
	char* nombre;
	int num_libros;
	char* lista;
	
}autor_t;

typedef struct libro
{
	char* titulo;
	autor_t autor;
	char* genero;
	
}libro_t;

//PROTOTIPADO
char* leeLineaFichero(FILE* fichero);
char* leeLineaDinamica();
int leeInfoInicial(FILE* fichero);
void leeAutoresFichero(FILE* fichero, autor_t* autores,int num_autores);
void leeLibrosFichero(FILE* fichero, libro_t* libros, int num_libros);
void emparejarAutores(autor_t* autores,libro_t* libros,int num_libros,int num_autores);
void buscarLibros(libro_t* libros, autor_t* autores, int num_autores, int num_libros);
void buscarAutor(autor_t* autores, int num_autores);
void buscarTitulo(libro_t* libros, int num_libros);
void buscarGenero(libro_t* libros, int num_libros);
void liberarMemoria(libro_t* libros, autor_t* autores,int num_autores,int num_libros);
void IntroducirAutor(autor_t* autor);
void IntroducirLibro(libro_t* libro);
void ActualizarLista(autor_t* autor,libro_t* libro,int* num_autores);
void GuardarNuevosDatos(FILE* fichero,autor_t* autores,libro_t* libros, int num_autores,int num_libros);
void CrearAutor(libro_t* libro,autor_t* autor,int* num_autores);

#endif