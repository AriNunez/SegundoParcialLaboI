/*
 * Editorial.c
 *
 *  Created on: 21 nov. 2021
 *      Author: user
 */

#include "Editorial.h"

eEditorial* editorial_new()
{
	eEditorial* pNewEditorial = NULL;

	pNewEditorial = (eEditorial*) malloc(sizeof(eEditorial));

	if(pNewEditorial != NULL)
	{
		pNewEditorial->idEditorial = 0;
		strcpy(pNewEditorial->nombre,"0");
	}

	return pNewEditorial;
}
eEditorial* editorial_newParametros(int idEditorial,char* nombre)
{
	eEditorial* pNewEditorial = NULL;

	if(nombre != NULL)
	{
		pNewEditorial = editorial_new();

		if(pNewEditorial != NULL)
		{
			editorial_setIdEditorial(pNewEditorial, idEditorial);
			editorial_setNombre(pNewEditorial, nombre);
		}
	}

	return pNewEditorial;
}

void editorial_delete(eEditorial* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int editorial_MostrarUno(eEditorial* this)
{
	int retorno;
	int idEditorial;
	char nombre[LEN_CHAR];

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;

		editorial_getIdEditorial(this, &idEditorial);
		editorial_getNombre(this, nombre);

		printf("|%-10d|%-30s|\n",idEditorial,nombre);
	}

	return retorno;
}

int editorial_setIdEditorial(eEditorial* this,int idEditorial)
{
	int retorno;

	retorno = 0;

	if(this != NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		retorno = 1;
	}

	return retorno;
}
int editorial_setNombre(eEditorial* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}

	return retorno;
}

int editorial_getIdEditorial(eEditorial* this,int* idEditorial)
{
	int retorno;

	retorno = 0;

	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 1;
	}

	return retorno;
}
int editorial_getNombre(eEditorial* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}

	return retorno;
}

int editorial_CompareByIdEditorial(void* pFirstEditorial,void* pSecondEditorial)
{
	int retorno;
	eEditorial* pPrimeraEditorial;
	eEditorial* pSegundaEditorial;
	int idPrimeraEditorial;
	int idSegundaEditorial;

	if(pFirstEditorial != NULL && pSecondEditorial != NULL)
	{
		pPrimeraEditorial = (eEditorial*) pFirstEditorial;
		pSegundaEditorial = (eEditorial*) pSecondEditorial;
		editorial_getIdEditorial(pPrimeraEditorial, &idPrimeraEditorial);
		editorial_getIdEditorial(pSegundaEditorial, &idSegundaEditorial);
		retorno = 0;

		if(idPrimeraEditorial > idSegundaEditorial)
		{
			retorno = 1;
		}
		else
		{
			if(idPrimeraEditorial < idSegundaEditorial)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int editorial_CompareByNombre(void* pFirstEditorial,void* pSecondEditorial)
{
	int retorno;
	eEditorial* pPrimeraEditorial;
	eEditorial* pSegundaEditorial;
	char nombrePrimeraEditorial[LEN_CHAR];
	char nombreSegundaEditorial[LEN_CHAR];

	if(pFirstEditorial != NULL && pSecondEditorial != NULL)
	{
		pPrimeraEditorial = (eEditorial*) pFirstEditorial;
		pSegundaEditorial = (eEditorial*) pSecondEditorial;
		editorial_getNombre(pPrimeraEditorial, nombrePrimeraEditorial);
		editorial_getNombre(pSegundaEditorial, nombreSegundaEditorial);
		retorno = strcmp(nombrePrimeraEditorial,nombreSegundaEditorial);
	}

	return retorno;
}

int editorial_BuscarIndexById(LinkedList* pArrayListEditoriales,int idEditorial)
{
	int retorno;
	int i;
	eEditorial* pEditorial;
	int idEditorialAux;

	retorno = -1;

	if(pArrayListEditoriales != NULL && idEditorial >= 0)
	{
		for(i=0;i<ll_len(pArrayListEditoriales);i++)
		{
			pEditorial = ll_get(pArrayListEditoriales, i);
			editorial_getIdEditorial(pEditorial, &idEditorialAux);
			if(idEditorialAux == idEditorial)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
