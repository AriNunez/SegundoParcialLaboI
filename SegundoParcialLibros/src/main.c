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
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;

			}

		}
    }while(opciones != 6);

	return EXIT_SUCCESS;
}
