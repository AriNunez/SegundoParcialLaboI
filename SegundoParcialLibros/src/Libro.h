#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Editorial.h"

#define LEN_CHAR 128

typedef struct
{
	int id;
	char titulo[LEN_CHAR];
	char autor[LEN_CHAR];
	float precio;
	int idEditorial;
}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(int id,char* titulo,char* autor,float precio,int idEditorial);
void libro_delete(eLibro* this);

int libro_MostrarUno(eLibro* this);
int libro_MostrarUnoConRelacion(eLibro* this,eEditorial* thisEditorial);

int libro_setId(eLibro* this,int id);
int libro_setTitulo(eLibro* this,char* titulo);
int libro_setAutor(eLibro* this,char* autor);
int libro_setPrecio(eLibro* this,float precio);
int libro_setIdEditorial(eLibro* this,int idEditorial);

int libro_getId(eLibro* this,int* id);
int libro_getTitulo(eLibro* this,char* titulo);
int libro_getAutor(eLibro* this,char* autor);
int libro_getPrecio(eLibro* this,float* precio);
int libro_getIdEditorial(eLibro* this,int* idEditorial);

int libro_CompareById(void* pFirstLibro,void* pSecondLibro);
int libro_CompareByTitulo(void* pFirstLibro,void* pSecondLibro);
int libro_CompareByAutor(void* pFirstLibro,void* pSecondLibro);
int libro_CompareByPrecio(void* pFirstLibro,void* pSecondLibro);
int libro_CompareByIdEditorial(void* pFirstLibro,void* pSecondLibro);

int libro_FiltrarEditPlaneta(void* pElement);
int libro_FiltrarEditSigloXXI(void* pElement);
int libro_FiltrarEditPearson(void* pElement);
int libro_FiltrarEditMinotauro(void* pElement);
int libro_FiltrarEditSalamandra(void* pElement);
int libro_FiltrarEditPenguinBooks(void* pElement);


#endif /* LIBRO_H_ */
