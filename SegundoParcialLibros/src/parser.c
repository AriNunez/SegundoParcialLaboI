#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pEmpleado;
	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];

	retorno = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
			{
				pEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(pEmpleado != NULL)
				{
					if(ll_add(pArrayListEmployee, pEmpleado)==-1)
					{
						employee_delete(pEmpleado);
					}
				}

			}
		}

		retorno = 1;
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pEmpleado;

	retorno = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			pEmpleado = employee_new();
			if(pEmpleado != NULL)
			{
				fread(pEmpleado,sizeof(Employee),1,pFile);
				if(feof(pFile))
				{
					break;
				}

				if(ll_add(pArrayListEmployee, pEmpleado)==-1)
				{
					employee_delete(pEmpleado);
					break;
				}
			}
		}

		retorno = 1;
	}

    return retorno;
}
