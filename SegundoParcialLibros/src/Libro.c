#include "Libro.h"

/// \brief Crea un nuevo eLibro en memoria de manera dinamica y lo inicializa con valores iniciales
/// \return eLibro* Retorna NULL en caso de no conseguir espacio en memoria o el puntero al espacio reservado
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

/// \brief Asigna valores a un eLibro que se encuentra en memoria dinamica
/// \param id int Entero
/// \param titulo char* Puntero a string
/// \param autor char* Puntero a string
/// \param precio float Flotante
/// \param idEditorial int Entero
/// \return eLibro* Retorna NULL en caso de error - en caso de exito retorna el puntero al espacio reservado con valores asignados
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

/// \brief Elimina un eLibro que se encuentra en memoria dinamica
/// \param this eLibro* Puntero a libro
void libro_delete(eLibro* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/// \brief Mustra los valores de un eLibro
/// \param this eLibro* Puntero a libro
/// \return int Retorna 0 en caso de error - 1 en caso de exito
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

/// \brief Muestra los valores de un eLibro con la relacion correspondiente a su eEditorial
/// \param this eLibro* Puntero a libro
/// \param thisEditorial eEditorial* Puntero a editorial
/// \return int Retorna 0 en caso de error - 1 en caso de exito
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

		printf("|%-10d|%-50s|%-25s|$%-10.2f|%-25s|\n",id,titulo,autor,precio,nombreEditorial);
	}

	return retorno;
}

/// \brief Asigna un valor en el eLibro recibido por paramentro
/// \param this eLibro* Puntero a libro
/// \param id int
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el eLibro recibido por paramentro
/// \param this eLibro* Puntero a libro
/// \param titulo char* Puntero a string
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el eLibro recibido por paramentro
/// \param this eLibro* Puntero a libro
/// \param autor char* Puntero a string
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el eLibro recibido por paramentro
/// \param this eLibro* Puntero a libro
/// \param precio float
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el eLibro recibido por paramentro
/// \param this eLibro* Puntero a libro
/// \param idEditorial int
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del eLibro recibido por parametro y lo devuelve
/// \param this eLibro* Puntero a libro
/// \param id int* Puntero a int donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del eLibro recibido por parametro y lo devuelve
/// \param this eLibro* Puntero a libro
/// \param titulo char* Puntero a char donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del eLibro recibido por parametro y lo devuelve
/// \param this eLibro* Puntero a libro
/// \param autor char* Puntero a char donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del eLibro recibido por parametro y lo devuelve
/// \param this eLibro* Puntero a libro
/// \param precio float* Puntero a float donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del eLibro recibido por parametro y lo devuelve
/// \param this eLibro* Puntero a libro
/// \param idEditorial int* Puntero a int donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstLibro void* Puntero al primer elemento a comparar
/// \param pSecondLibro void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (1) en caso de que el primero sea mayor - (-1) en caso de que el segundo sea mayor
int libro_CompareById(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	int idPrimerLibro;
	int idSegundoLibro;

	if(pFirstLibro != NULL && pSecondLibro != NULL)
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstLibro void* Puntero al primer elemento a comparar
/// \param pSecondLibro void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (>=1) en caso de que el primero sea mayor - (<=-1) en caso de que el segundo sea mayor
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstLibro void* Puntero al primer elemento a comparar
/// \param pSecondLibro void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (>=1) en caso de que el primero sea mayor - (<=-1) en caso de que el segundo sea mayor
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstLibro void* Puntero al primer elemento a comparar
/// \param pSecondLibro void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (1) en caso de que el primero sea mayor - (-1) en caso de que el segundo sea mayor
int libro_CompareByPrecio(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	float precioPrimerLibro;
	float precioSegundoLibro;

	if(pFirstLibro != NULL && pSecondLibro != NULL)
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstLibro void* Puntero al primer elemento a comparar
/// \param pSecondLibro void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (1) en caso de que el primero sea mayor - (-1) en caso de que el segundo sea mayor
int libro_CompareByIdEditorial(void* pFirstLibro,void* pSecondLibro)
{
	int retorno;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	int idEditorialPrimerLibro;
	int idEditorialSegundoLibro;

	if(pFirstLibro != NULL && pSecondLibro != NULL)
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

/// \brief Compara que el idEditorial del elemento sea igual a un valor determinado para poder filtrar
/// \param pElement void* Puntero al elemento a filtrar o no
/// \return int Retorna 0 si no se debe filtrar el elemento - 1 en caso de que se deba filtrar el elemento
int libro_FiltrarEditPlaneta(void* pElement)
{
	int retorno;
	eLibro* pLibro;
	int idEditorial;

	if(pElement != NULL)
	{
		retorno = 0;
		pLibro = (eLibro*) pElement;
		libro_getIdEditorial(pLibro, &idEditorial);

		if(idEditorial == 1)
		{
			retorno =  1;
		}
	}

	return retorno;
}

/// \brief Compara que el idEditorial del elemento sea igual a un valor determinado para poder filtrar
/// \param pElement void* Puntero al elemento a filtrar o no
/// \return int Retorna 0 si no se debe filtrar el elemento - 1 en caso de que se deba filtrar el elemento
int libro_FiltrarEditSigloXXI(void* pElement)
{
	int retorno;
	eLibro* pLibro;
	int idEditorial;

	if(pElement != NULL)
	{
		retorno = 0;
		pLibro = (eLibro*) pElement;
		libro_getIdEditorial(pLibro, &idEditorial);

		if(idEditorial == 2)
		{
			retorno =  1;
		}
	}

	return retorno;
}

/// \brief Compara que el idEditorial del elemento sea igual a un valor determinado para poder filtrar
/// \param pElement void* Puntero al elemento a filtrar o no
/// \return int Retorna 0 si no se debe filtrar el elemento - 1 en caso de que se deba filtrar el elemento
int libro_FiltrarEditPearson(void* pElement)
{
	int retorno;
	eLibro* pLibro;
	int idEditorial;

	if(pElement != NULL)
	{
		retorno = 0;
		pLibro = (eLibro*) pElement;
		libro_getIdEditorial(pLibro, &idEditorial);

		if(idEditorial == 3)
		{
			retorno =  1;
		}
	}

	return retorno;
}

/// \brief Compara que el idEditorial del elemento sea igual a un valor determinado para poder filtrar
/// \param pElement void* Puntero al elemento a filtrar o no
/// \return int Retorna 0 si no se debe filtrar el elemento - 1 en caso de que se deba filtrar el elemento
int libro_FiltrarEditMinotauro(void* pElement)
{
	int retorno;
	eLibro* pLibro;
	int idEditorial;

	if(pElement != NULL)
	{
		retorno = 0;
		pLibro = (eLibro*) pElement;
		libro_getIdEditorial(pLibro, &idEditorial);

		if(idEditorial == 4)
		{
			retorno =  1;
		}
	}

	return retorno;

}

/// \brief Compara que el idEditorial del elemento sea igual a un valor determinado para poder filtrar
/// \param pElement void* Puntero al elemento a filtrar o no
/// \return int Retorna 0 si no se debe filtrar el elemento - 1 en caso de que se deba filtrar el elemento
int libro_FiltrarEditSalamandra(void* pElement)
{
	int retorno;
	eLibro* pLibro;
	int idEditorial;

	if(pElement != NULL)
	{
		retorno = 0;
		pLibro = (eLibro*) pElement;
		libro_getIdEditorial(pLibro, &idEditorial);

		if(idEditorial == 5)
		{
			retorno =  1;
		}
	}

	return retorno;
}

/// \brief Compara que el idEditorial del elemento sea igual a un valor determinado para poder filtrar
/// \param pElement void* Puntero al elemento a filtrar o no
/// \return int Retorna 0 si no se debe filtrar el elemento - 1 en caso de que se deba filtrar el elemento
int libro_FiltrarEditPenguinBooks(void* pElement)
{
	int retorno;
	eLibro* pLibro;
	int idEditorial;

	if(pElement != NULL)
	{
		retorno = 0;
		pLibro = (eLibro*) pElement;
		libro_getIdEditorial(pLibro, &idEditorial);

		if(idEditorial == 6)
		{
			retorno =  1;
		}
	}

	return retorno;
}

void* libro_mapearLibros(void* element)
{
	eLibro* pLibro;
	eLibro* pCloneLibro;
	int idEditorial;
	float precio;
	float descuento;
	float precioConDescuento;

	if(element != NULL)
	{
		pLibro = (eLibro*) element;
		pCloneLibro = libro_clonarLibro(pLibro);
		libro_getIdEditorial(pLibro, &idEditorial);
		libro_getPrecio(pLibro, &precio);

		if(idEditorial == 1 && precio >= 300)
		{
			descuento = (precio * 20) / 100;
			precioConDescuento = precio - descuento;
			libro_setPrecio(pCloneLibro, precioConDescuento);

		}
		else
		{
			if(idEditorial == 2 && precio <= 200)
			{
				descuento = (precio * 10) / 100;
				precioConDescuento = precio - descuento;
				libro_setPrecio(pCloneLibro, precioConDescuento);
			}
		}
	}

	return pCloneLibro;
}

eLibro* libro_clonarLibro(eLibro* this)
{
	eLibro* pCloneLibro = NULL;
	int id;
	char titulo[LEN_CHAR];
	char autor[LEN_CHAR];
	float precio;
	int idEditorial;

	if(this != NULL)
	{
		libro_getId(this, &id);
		libro_getTitulo(this, titulo);
		libro_getAutor(this, autor);
		libro_getPrecio(this, &precio);
		libro_getIdEditorial(this, &idEditorial);

		pCloneLibro = libro_newParametros(id, titulo, autor, precio, idEditorial);
	}

	return pCloneLibro;
}
