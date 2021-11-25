#include "Controller.h"
#define LEN_ARCHIVENAME 20


/** \brief Carga los datos de los libros desde el archivo (modo texto).
 * \param pArrayListLibros LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 */
int controller_loadLibrosFromText(LinkedList* pArrayListLibros)
{
	int retorno;
	char nombreArchivo[LEN_ARCHIVENAME];
	FILE* pArchivo;

	retorno = 0;

	if(pArrayListLibros != NULL)
	{
		if(utn_getTexto(nombreArchivo, "\nIngrese el nombre del archivo que quiere leer(RECUERDE INCLUIR LA EXTENSION .csv): \n", "\n¡ERROR!\n", LEN_ARCHIVENAME, 3)==0)
		{

			if(strcmp(nombreArchivo,"libros.csv")==0)
			{
				pArchivo = fopen(nombreArchivo,"r");
				if(pArchivo != NULL)
				{
					parser_LibrosFromText(pArchivo, pArrayListLibros);
					fclose(pArchivo);
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}

/** \brief Carga los datos de las editoriales desde el archivo (modo texto).
 * \param pArrayListEditoriales LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 */
int controller_loadEditorialesFromText(LinkedList* pArrayListEditoriales)
{
	int retorno;
	char nombreArchivo[LEN_ARCHIVENAME];
	FILE* pArchivo;

	retorno = 0;

	if(pArrayListEditoriales != NULL)
	{
		if(utn_getTexto(nombreArchivo, "\nIngrese el nombre del archivo que quiere leer(RECUERDE INCLUIR LA EXTENSION .csv): \n", "\n¡ERROR!\n", LEN_ARCHIVENAME, 3)==0)
		{
			if(strcmp(nombreArchivo,"editoriales.csv")==0)
			{
				pArchivo = fopen(nombreArchivo,"r");
				if(pArchivo != NULL)
				{
					parser_EditorialesFromText(pArchivo, pArrayListEditoriales);
					fclose(pArchivo);
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}

/** \brief Listar libros con los datos de las editoriales
 * \param pArrayListLibros LinkedList* Puntero a la lista de libros
 * \param pArrayListEditoriales LinkedList* Puntero a la lista de editoriales
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 */
int controller_ListLibrosConRelacion(LinkedList* pArrayListLibros,LinkedList* pArrayListEditoriales)
{
	int retorno;
	int len;
	int i;
	int idEditorial;
	int indexEditorial;
	eLibro* pLibro;
	eEditorial* pEditorial;
	retorno = 0;

	if(pArrayListLibros != NULL && pArrayListEditoriales != NULL)
	{
		len = ll_len(pArrayListLibros);

		puts("\n\t>>Listado Libros con Editoriales");
		printf("|%-10s|%-50s|%-25s|%-11s|%-25s|\n","ID","TITULO","AUTOR","PRECIO","NOMBRE DE LA EDITORIAL");

		for(i=0;i<len;i++)
		{
			pLibro = (eLibro*) ll_get(pArrayListLibros, i);
			libro_getIdEditorial(pLibro, &idEditorial);
			indexEditorial = editorial_BuscarIndexById(pArrayListEditoriales, idEditorial);
			if(indexEditorial != -1)
			{
				pEditorial = (eEditorial*) ll_get(pArrayListEditoriales, indexEditorial);
				if(libro_MostrarUnoConRelacion(pLibro, pEditorial)==1)
				{
					retorno = 1;
				}
			}
		}

	}
    return retorno;
}

/** \brief Ordenar libros
 * \param pArrayListLibros LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 */
int controller_sortLibros(LinkedList* pArrayListLibros)
{
	int retorno;
	int criterio;
	int orden;

	retorno = 0;

	if(pArrayListLibros != NULL)
	{
		puts("\n\t>>Listado Criterios");
		puts("1. ID\n2. TITULO\n3. AUTOR\n4. PRECIO\n5. ID EDITORIAL\n");
		if(utn_getInt(&criterio, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 5, 3)==0)
		{
			puts("\n\t>>Listado Orden");
			puts("1. ASCENDENTE\n2. DESCENDENTE\n");
			if(utn_getInt(&orden, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 2, 3)==0)
			{
				if(orden==2)
				{
					orden=0;
				}

				switch(criterio)
				{
					case 1:
						ll_sort(pArrayListLibros, libro_CompareById, orden);
						break;

					case 2:
						ll_sort(pArrayListLibros, libro_CompareByTitulo, orden);
						break;

					case 3:
						ll_sort(pArrayListLibros, libro_CompareByAutor, orden);
						break;

					case 4:
						ll_sort(pArrayListLibros, libro_CompareByPrecio, orden);
						break;

					case 5:
						ll_sort(pArrayListLibros, libro_CompareByIdEditorial, orden);
						break;
				}
				retorno = 1;
			}
		}
	}

    return retorno;
}

/// \brief Filtra los libros por la editorial que se elija
/// \param pArrayListLibros LinkedList* Puntero a la lista
/// \return LinkedList* Retorna NULL en caso de error - en caso de exito retorna el puntero a la lista nueva filtrada
LinkedList* controller_FiltrarLibrosPorEditorial(LinkedList* pArrayListLibros)
{
	LinkedList* pFilterList = NULL;
	int criterio;

	if(pArrayListLibros != NULL)
	{
		puts("\n\t>>Listado de Editoriales");
		puts("1. PLANETA\n2. SIGLO XXI EDITORES\n3. PEARSON\n4. MINOTAURO\n5. SALAMANDRA\n6. PENGUIN BOOKS\n");
		if(utn_getInt(&criterio, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 6, 3)==0)
		{
				switch(criterio)
				{
					case 1:
						pFilterList = (LinkedList*) ll_filter(pArrayListLibros, libro_FiltrarEditPlaneta);
						break;

					case 2:
						pFilterList = (LinkedList*) ll_filter(pArrayListLibros, libro_FiltrarEditSigloXXI);
						break;

					case 3:
						pFilterList = (LinkedList*) ll_filter(pArrayListLibros, libro_FiltrarEditPearson);
						break;

					case 4:
						pFilterList = (LinkedList*) ll_filter(pArrayListLibros, libro_FiltrarEditMinotauro);
						break;

					case 5:
						pFilterList = (LinkedList*) ll_filter(pArrayListLibros, libro_FiltrarEditSalamandra);
						break;

					case 6:
						pFilterList = (LinkedList*) ll_filter(pArrayListLibros, libro_FiltrarEditPenguinBooks);
						break;
				}
		}

	}

    return pFilterList;
}

/** \brief Guarda los libros filtrados por la editorial Minotauro en un archivo (modo texto).
 * \param path char* Puntero al nombre del archivo
 * \param pArrayListFilterMinotauro LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 */
int controller_saveListFilterMinotauroAsText(char* path , LinkedList* pArrayListFilterMinotauro)
{
	int retorno;
	FILE* pArchivo;
	eLibro* pLibro;
	int len;
	int i;
	int id;
	char titulo[LEN_CHAR];
	char autor[LEN_CHAR];
	float precio;
	int idEditorial;

	retorno = 0;

	if(path != NULL && pArrayListFilterMinotauro != NULL && ll_isEmpty(pArrayListFilterMinotauro) == 0)
	{
		pArchivo = fopen(path,"w");

		if(pArchivo != NULL)
		{
			len = ll_len(pArrayListFilterMinotauro);

			fprintf(pArchivo,"id,titulo,autor,precio,idEditorial\n");

			for(i=0;i<len;i++)
			{
				pLibro = (eLibro*) ll_get(pArrayListFilterMinotauro, i);
				if(pLibro == NULL)
				{
					break;
				}

				libro_getId(pLibro, &id);
				libro_getTitulo(pLibro, titulo);
				libro_getAutor(pLibro, autor);
				libro_getPrecio(pLibro, &precio);
				libro_getIdEditorial(pLibro, &idEditorial);

				fprintf(pArchivo,"%d,%s,%s,%.2f,%d\n",id,titulo,autor,precio,idEditorial);
			}

			fclose(pArchivo);

			if(len==i)
			{
				retorno = 1;
			}
		}

	}

    return retorno;
}
