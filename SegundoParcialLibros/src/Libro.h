/*
 * Libros.h
 *
 *  Created on: 21 nov. 2021
 *      Author: user
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LEN_CHAR 128

typedef struct
{
	int id;
	char titulo[LEN_CHAR];
	char autor[LEN_CHAR];
	float precio;
	int idEditorial;
}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(int id,char* titulo,char* autor,float precio,int idEditorial);

int libro_MostrarUno(eLibro* this);

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

//void libro_delete(eLibro* this);

#endif /* LIBRO_H_ */
