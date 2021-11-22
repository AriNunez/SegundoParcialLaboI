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
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);



#endif // controller_H_INCLUDED
