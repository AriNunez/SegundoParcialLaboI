/*
 * parser.h
 *
 *  Created on: 4 nov. 2021
 *      Author: user
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Controller.h"

int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros);
int parser_EditorialesFromText(FILE* pFile , LinkedList* pArrayListLibros);

#endif /* PARSER_H_ */
