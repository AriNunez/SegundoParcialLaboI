#include "parser.h"

/** \brief Parsea los datos de los libros desde el archivo (modo texto).
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayListLibros LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 *
 */
int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno;
	eLibro* pLibro;
	char idStr[LEN_CHAR];
	char titulo[LEN_CHAR];
	char autor[LEN_CHAR];
	char precioStr[LEN_CHAR];
	char idEditorialStr[LEN_CHAR];
	int id;
	float precio;
	int idEditorial;

	retorno = 0;

	if(pFile != NULL && pArrayListLibros != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,titulo,autor,precioStr,idEditorialStr);
		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,titulo,autor,precioStr,idEditorialStr)==5)
			{
				id = atoi(idStr);
				precio = atof(precioStr);
				idEditorial = atoi(idEditorialStr);
				pLibro = libro_newParametros(id, titulo, autor, precio, idEditorial);

				if(pLibro != NULL)
				{
					if(ll_add(pArrayListLibros, pLibro)==-1)
					{
						libro_delete(pLibro);
					}
				}

			}
		}
		retorno = 1;
	}

    return retorno;
}

/** \brief Parsea los datos de las editoriales desde el archivo (modo texto).
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayListEditoriales LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 */
int parser_EditorialesFromText(FILE* pFile , LinkedList* pArrayListEditoriales)
{
	int retorno;
	eEditorial* pEditorial;
	char idEditorialStr[LEN_CHAR];
	char nombre[LEN_CHAR];
	int idEditorial;

	retorno = 0;
	if(pFile != NULL && pArrayListEditoriales != NULL)
	{
		fscanf(pFile,"%[^,],%[^\n]\n",idEditorialStr,nombre);
		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^\n]\n",idEditorialStr,nombre)==2)
			{
				idEditorial = atoi(idEditorialStr);
				pEditorial = editorial_newParametros(idEditorial, nombre);

				if(pEditorial != NULL)
				{

					if(ll_add(pArrayListEditoriales, pEditorial)==-1)
					{
						editorial_delete(pEditorial);
					}
				}

			}
		}

		retorno = 1;
	}

    return retorno;
}
