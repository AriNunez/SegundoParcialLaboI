/*
 * Editorial.h
 *
 *  Created on: 21 nov. 2021
 *      Author: user
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LEN_CHAR 128

typedef struct
{
	int idEditorial;
	char nombre[LEN_CHAR];
}eEditorial;

#endif /* EDITORIAL_H_ */
