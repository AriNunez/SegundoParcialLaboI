#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Puntero al nombre del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;

	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_EmployeeFromText(pArchivo, pArrayListEmployee);
			fclose(pArchivo);
			retorno = 1;
		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int len;
	int i;
	Employee* pEmployee;

	retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		puts("\n\t>>Listado Empleados");
		printf("\n|%-10s|%-25s|%-25s|%-25s|\n\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");

		for(i=0;i<len;i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if(employee_MostrarUno(pEmployee)==1)
			{
				retorno = 1;
			}
		}

	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int criterio;
	int orden;

	retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		puts("\n\t>>Listado Criterios");
		puts("1. ID\n2. NOMBRE\n3. HORAS TRABAJADAS\n4. SUELDO\n");
		if(utn_getInt(&criterio, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 4, 3)==0)
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
						ll_sort(pArrayListEmployee, employee_CompareById, orden);
						break;

					case 2:
						ll_sort(pArrayListEmployee, employee_CompareByName, orden);
						break;

					case 3:
						ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, orden);
						break;

					case 4:
						ll_sort(pArrayListEmployee, employee_CompareBySueldo, orden);
						break;
				}
				retorno = 1;
			}
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Puntero al nombre del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int Retorna (0) en caso de error - (1) en caso de exito
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;
	Employee* pEmpleado;
	int len;
	int i;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		pArchivo = fopen(path,"w");

		if(pArchivo != NULL)
		{
			len = ll_len(pArrayListEmployee);

			fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

			for(i=0;i<len;i++)
			{
				pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				if(pEmpleado == NULL)
				{
					break;
				}

				employee_getId(pEmpleado, &id);
				employee_getNombre(pEmpleado, nombre);
				employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);
				employee_getSueldo(pEmpleado, &sueldo);

				fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
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
