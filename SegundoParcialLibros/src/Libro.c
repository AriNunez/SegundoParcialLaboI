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

void libro_delete(eLibro* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int libro_MostrarUno(eLibro* this)
{
	int retorno;
	int id;
	char titulo[LEN_CHAR];
	char autor[LEN_CHAR];
	float precio;
	int idEditorial;

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;

		libro_getId(this, &id);
		libro_getTitulo(this, titulo);
		libro_getAutor(this, autor);
		libro_getPrecio(this, &precio);
		libro_getIdEditorial(this, &idEditorial);

		printf("|%-10d|%-30s|%-30s|%-10.2f|%-10d|\n",id,titulo,autor,precio,idEditorial);
	}

	return retorno;
}

int libro_MostrarUnoConRelacion(eLibro* this,eEditorial* thisEditorial)
{
	int retorno;
	int id;
	char titulo[LEN_CHAR];
	char autor[LEN_CHAR];
	float precio;
	char nombreEditorial[LEN_CHAR];

	retorno = 0;

	if(this != NULL && thisEditorial != NULL)
	{
		retorno = 1;

		libro_getId(this, &id);
		libro_getTitulo(this, titulo);
		libro_getAutor(this, autor);
		libro_getPrecio(this, &precio);
		editorial_getNombre(thisEditorial, nombreEditorial);

		printf("|%-10d|%-50s|%-25s|%-10.2f|%-20s|\n",id,titulo,autor,precio,nombreEditorial);
	}

	return retorno;
}

int libro_setId(eLibro* this,int id)
{
	int retorno;

	retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}
int libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno;

	retorno = 0;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo,titulo);
		retorno = 1;
	}

	return retorno;
}
int libro_setAutor(eLibro* this,char* autor)
{
	int retorno;

	retorno = 0;

	if(this != NULL && autor != NULL)
	{
		strcpy(this->autor,autor);
		retorno = 1;
	}

	return retorno;
}
int libro_setPrecio(eLibro* this,float precio)
{
	int retorno;

	retorno = 0;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}
int libro_setIdEditorial(eLibro* this,int idEditorial)
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

int libro_getId(eLibro* this,int* id)
{
	int retorno;

	retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}
int libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno;

	retorno = 0;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 1;
	}

	return retorno;
}
int libro_getAutor(eLibro* this,char* autor)
{
	int retorno;

	retorno = 0;

	if(this != NULL && autor != NULL)
	{
		strcpy(autor,this->autor);
		retorno = 1;
	}

	return retorno;
}
int libro_getPrecio(eLibro* this,float* precio)
{
	int retorno;

	retorno = 0;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}
int libro_getIdEditorial(eLibro* this,int* idEditorial)
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

int libro_CompareById(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	int idPrimerLibro;
	int idSegundoLibro;

	if(pFirstLibro != NULL && pSecondLibro)
	{
		pPrimerLibro = (eLibro*) pFirstLibro;
		pSegundoLibro = (eLibro*) pSecondLibro;
		libro_getId(pPrimerLibro, &idPrimerLibro);
		libro_getId(pSegundoLibro, &idSegundoLibro);
		retorno = 0;

		if(idPrimerLibro > idSegundoLibro)
		{
			retorno = 1;
		}
		else
		{
			if(idPrimerLibro < idSegundoLibro)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int libro_CompareByTitulo(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	char tituloPrimerLibro[LEN_CHAR];
	char tituloSegundoLibro[LEN_CHAR];

	if(pFirstLibro != NULL && pSecondLibro != NULL)
	{
		pPrimerLibro = (eLibro*) pFirstLibro;
		pSegundoLibro = (eLibro*) pSecondLibro;
		libro_getTitulo(pPrimerLibro, tituloPrimerLibro);
		libro_getTitulo(pSegundoLibro, tituloSegundoLibro);

		retorno = strcmp(tituloPrimerLibro,tituloSegundoLibro);
	}

	return retorno;
}
int libro_CompareByAutor(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	char autorPrimerLibro[LEN_CHAR];
	char autorSegundoLibro[LEN_CHAR];

	if(pFirstLibro != NULL && pSecondLibro != NULL)
	{
		pPrimerLibro = (eLibro*) pFirstLibro;
		pSegundoLibro = (eLibro*) pSecondLibro;
		libro_getAutor(pPrimerLibro, autorPrimerLibro);
		libro_getAutor(pSegundoLibro, autorSegundoLibro);

		retorno = strcmp(autorPrimerLibro,autorSegundoLibro);
	}

	return retorno;
}
int libro_CompareByPrecio(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	float precioPrimerLibro;
	float precioSegundoLibro;

	if(pFirstLibro != NULL && pSecondLibro)
	{
		pPrimerLibro = (eLibro*) pFirstLibro;
		pSegundoLibro = (eLibro*) pSecondLibro;
		libro_getPrecio(pPrimerLibro, &precioPrimerLibro);
		libro_getPrecio(pSegundoLibro, &precioSegundoLibro);
		retorno = 0;

		if(precioPrimerLibro > precioSegundoLibro)
		{
			retorno = 1;
		}
		else
		{
			if(precioPrimerLibro < precioSegundoLibro)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int libro_CompareByIdEditorial(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	int idEditorialPrimerLibro;
	int idEditorialSegundoLibro;

	if(pFirstLibro != NULL && pSecondLibro)
	{
		pPrimerLibro = (eLibro*) pFirstLibro;
		pSegundoLibro = (eLibro*) pSecondLibro;
		libro_getIdEditorial(pPrimerLibro, &idEditorialPrimerLibro);
		libro_getIdEditorial(pSegundoLibro, &idEditorialSegundoLibro);
		retorno = 0;

		if(idEditorialPrimerLibro > idEditorialSegundoLibro)
		{
			retorno = 1;
		}
		else
		{
			if(idEditorialPrimerLibro < idEditorialSegundoLibro)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}


