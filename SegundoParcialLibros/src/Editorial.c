#include "Editorial.h"

/// \brief Crea un nuevo eEditorial en memoria de manera dinamica y lo inicializa con valores iniciales
/// \return eEditorial* Retorna (NULL) en caso de no conseguir espacio en memoria o el puntero al espacio reservado
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

/// \brief Asigna valores a un eEditorial que se encuentra en memoria dinamica
/// \param idEditorial int
/// \param nombre char* Puntero a string
/// \return eEditorial* Retorna (NULL) en caso de error - en caso de exito retorna el puntero al espacio reservado con valores asignados
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

/// \brief Elimina un eEditorial que se encuentra en memoria dinamica
/// \param this eEditorial* Puntero a editorial
void editorial_delete(eEditorial* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/// \brief Muestra los valores de un eEditorial
/// \param this eEditorial* Puntero a editorial
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el eEditorial recibido por paramentro
/// \param this eEditorial* Puntero a editorial
/// \param idEditorial int
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el eEditorial recibido por paramentro
/// \param this eEditorial* Puntero a editorial
/// \param nombre char* Puntero a string
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del eEditorial recibido por parametro y lo devuelve
/// \param this eEditorial* Puntero a editorial
/// \param idEditorial int* Puntero a int donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del eEditorial recibido por parametro y lo devuelve
/// \param this eEditorial* Puntero a editorial
/// \param nombre char* Puntero a string donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstEditorial void* Puntero al primer elemento a comparar
/// \param pSecondEditorial void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (1) en caso de que el primero sea mayor - (-1) en caso de que el segundo sea mayor
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstEditorial void* Puntero al primer elemento a comparar
/// \param pSecondEditorial void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (>=1) en caso de que el primero sea mayor - (<=-1) en caso de que el segundo sea mayor
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

/// \brief Busca en la lista de eEditorial el idEditorial recibido por parametro y lo retorna
/// \param pArrayListEditoriales LinkedList* Puntero a la lista de editoriales
/// \param idEditorial int
/// \return int Retorna -1 en caso de no encontrar el idEditorial en la lista - >=0 en caso de encontrarlo en la lista
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
