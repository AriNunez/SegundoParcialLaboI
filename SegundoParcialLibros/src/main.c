/*
 ============================================================================
 Name        : SegundoParcialLibros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"

int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	LinkedList* pListaLibros;
	LinkedList* pListaEditoriales;

	pListaLibros = ll_newLinkedList();
	pListaEditoriales = ll_newLinkedList();

    do
    {
		puts("\n==========LIBROS Y EDITORIALES==========\n");
		puts("1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro"
				"\n2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial."
				"\n3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente."
				"\n4. Imprimir por pantalla todos los datos de los libros. "
				"\n5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList. Guardar el listado en un archivo csv."
				"\n6. Salir.\n");
    	if(utn_getInt(&opciones, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 6, 3)==0)
		{
			switch(opciones)
			{
				case 1:
					if(controller_loadLibrosFromText(pListaLibros)==1)
					{
						puts("CARGA EXITOSA");
					}
					break;
				case 2:
					if(controller_loadEditorialesFromText(pListaEditoriales)==1)
					{
						puts("CARGA EXITOSA");
					}
					break;
				case 3:
					break;
				case 4:
					controller_ListLibrosConRelacion(pListaLibros, pListaEditoriales);
					break;
				case 5:
					break;
				case 6:
					puts("SALIMOOOOOOS");
					break;

			}

		}
    }while(opciones != 6);

	return EXIT_SUCCESS;
}
