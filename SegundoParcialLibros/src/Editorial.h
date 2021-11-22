/*
 * Editorial.h
 *
 *  Created on: 21 nov. 2021
 *      Author: user
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

#define LEN_CHAR 128

typedef struct
{
	int idEditorial;
	char nombre[LEN_CHAR];
}eEditorial;

eEditorial* editorial_new();
eEditorial* editorial_newParametros(int idEditorial,char* nombre);

void editorial_delete(eEditorial* this);

int editorial_MostrarUno(eEditorial* this);

int editorial_setIdEditorial(eEditorial* this,int idEditorial);
int editorial_setNombre(eEditorial* this,char* nombre);

int editorial_getIdEditorial(eEditorial* this,int* idEditorial);
int editorial_getNombre(eEditorial* this,char* nombre);

int editorial_CompareByIdEditorial(void* pFirstEditorial,void* pSecondEditorial);
int editorial_CompareByNombre(void* pFirstEditorial,void* pSecondEditorial);

int editorial_BuscarIndexById(LinkedList* pArrayListEditoriales,int idEditorial);

#endif /* EDITORIAL_H_ */
