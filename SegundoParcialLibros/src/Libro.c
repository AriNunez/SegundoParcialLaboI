/*
 * Libros.c
 *
 *  Created on: 21 nov. 2021
 *      Author: user
 */

#include "Libro.h"

eLibro* libro_new()
{
	eLibro* pNewLibro = NULL;

	pNewLibro = (eLibro*) malloc(sizeof(eLibro));

	if(pNewLibro != NULL)
	{
		pNewLibro->id = 0;
		strcpy(pNewLibro->titulo,"0");
		strcpy(pNewLibro->autor,"0");
		pNewLibro->precio = 0;
		pNewLibro->idEditorial = 0;
	}

	return pNewLibro;
}
eLibro* libro_newParametros(int id,char* titulo,char* autor,float precio,int idEditorial)
{
	eLibro* pNewLibro = NULL;

	if(titulo != NULL && autor != NULL)
	{
		pNewLibro = libro_new();

		if(pNewLibro != NULL)
		{
			libro_setId(pNewLibro, id);
			libro_setTitulo(pNewLibro, titulo);
			libro_setAutor(pNewLibro, autor);
			libro_setPrecio(pNewLibro, precio);
			libro_setIdEditorial(pNewLibro, idEditorial);
		}
	}

	return pNewLibro;
}

int libro_MostrarUno(eLibro* this)
{
	int retorno;

	retorno = 0;

	if(this != NULL)
	{

	}

	return retorno;
}

int libro_setId(eLibro* this,int id);
int libro_setTitulo(eLibro* this,char* titulo);
int libro_setAutor(eLibro* this,char* autor);
int libro_setPrecio(eLibro* this,float precio);
int libro_setIdEditorial(eLibro* this,int idEditorial);

int libro_getId(eLibro* this,int* id);
int libro_getTitulo(eLibro* this,char* titulo);
int libro_getAutor(eLibro* this,char* autor);
int libro_getPrecio(eLibro* this,float* precio);
int libro_getIdEditorial(eLibro* this,int* idEditorial);

int employee_CompareById(void* pFirstEmployee,void* pSecondEmployee);
int employee_CompareByTitulo(void* pFirstEmployee,void* pSecondEmployee);
int employee_CompareByAutor(void* pFirstEmployee,void* pSecondEmployee);
int employee_CompareByPrecio(void* pFirstEmployee,void* pSecondEmployee);
int employee_CompareByIdEditorial(void* pFirstEmployee,void* pSecondEmployee);
