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
	int flagCargaDeLibros;
	int flagCargaDeEditoriales;
	LinkedList* pListaLibros;
	LinkedList* pListaEditoriales;
	LinkedList* pListFilterMinotauro;

	pListaLibros = ll_newLinkedList();
	pListaEditoriales = ll_newLinkedList();

	flagCargaDeLibros = 0;
	flagCargaDeEditoriales = 0;

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
					if(flagCargaDeLibros == 0)
					{
						if(controller_loadLibrosFromText(pListaLibros)==1)
						{
							puts("CARGA EXITOSA");
							flagCargaDeLibros = 1;
						}
						else
						{
							puts("\n¡ERROR! NO FUE POSIBLE ENCONTRAR EL NOMBRE DEL ARCHIVO INGRESADO\n");
							puts("SE RECOMIENDA INGRESAR EL SIGUIENTE NOMBRE DE ARCHIVO: libros.csv\n");
						}
					}
					else
					{
						puts("\n¡YA SE HA CARGADO LA LISTA DE LIBROS!\n");
					}

					break;

				case 2:
					if(flagCargaDeEditoriales == 0)
					{
						if(controller_loadEditorialesFromText(pListaEditoriales)==1)
						{
							puts("CARGA EXITOSA");
							flagCargaDeEditoriales = 1;
						}
						else
						{
							puts("\n¡ERROR! NO FUE POSIBLE ENCONTRAR EL NOMBRE DEL ARCHIVO INGRESADO\n");
							puts("SE RECOMIENDA INGRESAR EL SIGUIENTE NOMBRE DE ARCHIVO: editoriales.csv\n");
						}
					}
					else
					{
						puts("\n¡YA SE HA CARGADO LA LISTA DE EDITORIALES!\n");
					}
					break;

				case 3:
					if(flagCargaDeLibros == 1 && flagCargaDeEditoriales == 1)
					{
						controller_sortLibros(pListaLibros);
					}
					else
					{
						puts("\n¡ES NECESARIO CARGAR LA LISTA DE LIBROS Y EDITORIALES PARA ACCEDER A ESTA OPCION!\n");
					}

					break;

				case 4:
					if(flagCargaDeLibros == 1 && flagCargaDeEditoriales == 1)
					{
						controller_ListLibrosConRelacion(pListaLibros, pListaEditoriales);
					}
					else
					{
						puts("\n¡ES NECESARIO CARGAR LA LISTA DE LIBROS Y EDITORIALES PARA ACCEDER A ESTA OPCION!\n");
					}
					break;

				case 5:
					if(flagCargaDeLibros == 1 && flagCargaDeEditoriales == 1)
					{
						pListFilterMinotauro =  controller_FiltrarLibrosPorEditorial(pListaLibros);
						if(pListFilterMinotauro != NULL)
						{
							if(controller_saveListFilterMinotauroAsText("ListaFiltradaMinotauro.csv", pListFilterMinotauro)==1)
							{
								puts("\n¡GUARDADO DE LISTA FILTRADA POR EDITORIAL MINOTAURO EXITOSA EN ARCHIVO ListaFiltradaMinotauro.csv!\n");
								if(utn_getInt(&opciones, "\n¿DESEA MOSTRAR LA LISTA FILTRADA?\n1. SI\n2. NO\n", "\n¡ERROR!\n", 1, 2, 0)==0 && opciones == 1)
								{
									controller_ListLibrosConRelacion(pListFilterMinotauro, pListaEditoriales);
								}
							}

						}
						else
						{
							puts("\n¡ERROR! NO FUE POSIBLE FILTRAR LA LISTA POR EDITORIAL MINOTAURO");
						}
					}
					else
					{
						puts("\n¡ES NECESARIO CARGAR LA LISTA DE LIBROS Y EDITORIALES PARA ACCEDER A ESTA OPCION!\n");
					}
					break;

				case 6:
					puts("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!\n");
					break;

			}

		}
    }while(opciones != 6);

	return EXIT_SUCCESS;
}
