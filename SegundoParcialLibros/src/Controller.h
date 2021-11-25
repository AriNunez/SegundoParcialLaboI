#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

#include "LinkedList.h"
#include "Libro.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int controller_loadLibrosFromText(LinkedList* pArrayListEmployee);
int controller_loadEditorialesFromText(LinkedList* pArrayListEditoriales);
int controller_ListLibrosConRelacion(LinkedList* pArrayListLibros,LinkedList* pArrayListEditoriales);
int controller_sortLibros(LinkedList* pArrayListLibros);
LinkedList* controller_FiltrarLibrosPorEditorial(LinkedList* pArrayListLibros);
int controller_saveListFilterMinotauroAsText(char* path , LinkedList* pArrayListFilterMinotauro);

LinkedList* controller_MapearLibros(LinkedList* pArrayListLibros);
int controller_saveListMapText(char* path , LinkedList* pArrayListMap);

#endif // controller_H_INCLUDED
