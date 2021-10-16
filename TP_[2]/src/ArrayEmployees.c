/*
 * ArrayEmployees.c
 *
 *  Created on: 4 oct 2021
 *      Author: Mermin
 */
#include "ArrayEmployees.h"

int Menu(void)
{
	int option;

	printf("\n1. Altas. \n");
	printf("2. Modificar. \n");
	printf("3. Baja. \n");
	printf("4. Informar. \n");
	printf("5. Salir. \n");
	Utn_GetInt(&option, "Elija una opción : ", ERROR_MESSAGE, MIN_OPTION, MAX_OPTION, ATTEMPTS);

	return option;
}

int InitEmployees(Employee* list, int len)
{
	int retorno = ERROR;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
	        list[i].isEmpty = AVAILABLE;
	        retorno = FUNCIONO;
	    }
	}

return retorno;

}

int GetEmployee(int* refId, Employee* refEmployee)
{
	Employee auxEmployee;
	int retorno = ERROR;

	if(refId != NULL && refEmployee != NULL)
	{
		if(Utn_GetString(auxEmployee.name, TAM_STRING, "Ingrese su nombre: ", ERROR_MESSAGE, ATTEMPTS) == FUNCIONO &&
		   Utn_GetString(auxEmployee.lastName, TAM_STRING, "Ingrese su apellido: ", ERROR_MESSAGE, ATTEMPTS) == FUNCIONO &&
		   Utn_GetFloat(&auxEmployee.salary, "Ingrese su sueldo: ", ERROR_MESSAGE, MIN_SALARY, MAX_SALARY, ATTEMPTS) == FUNCIONO &&
		   Utn_GetInt(&auxEmployee.sector, "Ingrese a que sector pertenece ( 1 - 200): ", ERROR_MESSAGE, MIN_SECTOR, MAX_SECTOR, ATTEMPTS) == FUNCIONO)
		{
			auxEmployee.id = *refId;
			*refId =auxEmployee.id + 1;
			*refEmployee = auxEmployee;
			retorno = FUNCIONO;
		}
	}

	return retorno;
}

int IsEmpty(Employee* list, int len, int* refIndex)
{
	int i;
	int index;
	int retorno = ERROR;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == AVAILABLE)
			{
				index = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}

	*refIndex = index;

	return retorno;
}

int AddEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int index;
	int retorno = ERROR;

	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
	{
		if(IsEmpty(list, len, &index) == FUNCIONO)
		{
			strcpy(list[index].name,name);
			strcpy(list[index].lastName,lastName);
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty = OCCUPIED;
			list[index].id = id;
			retorno = FUNCIONO;
		}
	}

	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int index = ERROR;
	int i;

	for(i=0;i<len;i++)
	{
		if(list[i].id == id && list[i].isEmpty == OCCUPIED)
		{
			index = i;
		}
	}

	return index;
}

int ModifyEmployee(Employee* list, int len)
{
	int retorno = ERROR;
	int option;
	int auxId;
	int index;

	printEmployees(list, len);

	Utn_GetInt(&auxId, "Ingrese id del empleado a modificar: ", ERROR_MESSAGE, MIN_ID, MAX_ID, ATTEMPTS);
	index = findEmployeeById(list, len, auxId);
	if(index != ERROR)
	{
		Utn_GetInt(&option, "Que desea modificar? ( 1-Nombre, 2-Apellido, 3-Salario o 4-Sector ) : ", ERROR_MESSAGE, MIN_MODIFY, MAX_MODIFY, ATTEMPTS);
		if(ModifyEmployeeByOption(list, len, index, option)==FUNCIONO)
		{
			retorno = FUNCIONO;
		}
	}

	return retorno;
}

int ModifyEmployeeByOption(Employee* list, int len, int auxIndex, int auxOption)
{
	int retorno = ERROR;
	char auxName[TAM_STRING];
	char auxLastName[TAM_STRING];
	float auxSalary;
	int auxSector;

	switch(auxOption)
	{
		case NAME:
			Utn_GetString(auxName, TAM_STRING, "Ingrese nuevo nombre: ", ERROR_MESSAGE, ATTEMPTS);
			strcpy(list[auxIndex].name, auxName);
			retorno = FUNCIONO;
		break;

		case LAST_NAME:
			Utn_GetString(auxLastName, TAM_STRING, "Ingrese nuevo apellido: ", ERROR_MESSAGE, ATTEMPTS);
			strcpy(list[auxIndex].lastName, auxLastName);
			retorno = FUNCIONO;
		break;

		case SALARY:
			Utn_GetFloat(&auxSalary, "Ingrese nuevo sueldo: ", ERROR_MESSAGE, MIN_SALARY, MAX_SALARY, ATTEMPTS);
			list[auxIndex].salary = auxSalary;
			retorno = FUNCIONO;
		break;

		case SECTOR:
			Utn_GetInt(&auxSector, "Ingrese nuevo sector: ", ERROR_MESSAGE, MIN_SECTOR, MAX_SECTOR, ATTEMPTS);
			list[auxIndex].sector = auxSector;
			retorno = FUNCIONO;
		break;

	}

	return retorno;
}

int GetIdToRemove(Employee* list, int len, int* refId)
{
	int retorno = ERROR;
	int auxId;

	if(list != NULL && len > 0)
	{
		printEmployees(list, len);
		Utn_GetInt(&auxId, "Ingrese id del empleado a dar de baja: ", ERROR_MESSAGE, MIN_ID, MAX_ID, ATTEMPTS);
		retorno = FUNCIONO;
	}

	*refId = auxId;

	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = ERROR;
	int option;
	int index;

	index = findEmployeeById(list, len, id);

	if(index != ERROR)
	{
		Utn_GetInt(&option, "Esta seguro de dar de baja al empleado? ( 1-Sí o 2-No ): ", ERROR_MESSAGE, MIN_REMOVE, MAX_REMOVE, ATTEMPTS);
		if(option == YES)
		{
			list[index].isEmpty = AVAILABLE;
			retorno = FUNCIONO;
		}
	}

	return retorno;

}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno = ERROR;
	Employee auxEmployee;
	int i;
	int j;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len-1;i++)
		{
			if(list[i].isEmpty == OCCUPIED)
			{
				for(j=i+1;j<len;j++)
				{
						if(order == INCREASING)
						{
							if((strcmp(list[i].lastName,list[j].lastName) < 0) ||
							   (strcmp(list[i].lastName,list[j].lastName) == 0 &&
									    list[i].sector > list[j].sector))
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
								retorno = FUNCIONO;
							}
						}
						else
						{
							if((strcmp(list[i].lastName,list[j].lastName) > 0) ||
							   (strcmp(list[i].lastName,list[j].lastName) == 0 &&
							            list[i].sector < list[j].sector))
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
								retorno = FUNCIONO;
							}
						}
					}
				}
			}
		}

	return retorno;
}


int printEmployees(Employee* list, int length)
{
	int retorno = ERROR;
	int i;


    printf("ID           Nombre         Apellido      Salario       Sector \n");
    printf("---------------------------------------------------------------------\n\n");
	for(i=0;i<length;i++)
	{
		if(list != NULL && length > 0 && list[i].isEmpty == OCCUPIED)
		{
			if(printAEmployee(list[i], length)==FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
	}

	return retorno;
}

int printAEmployee(Employee employee, int length)
{
	int retorno = ERROR;
	int i;

	for(i=0;i<length;i++)
	{
		printf("%3d %15s %15s    %9.2f    %6d \n",
													employee.id,
													employee.name,
													employee.lastName,
													employee.salary,
													employee.sector);
		retorno = FUNCIONO;
		break;
	}

	return retorno;
}

int MenuCase4()
{
	int option;

	printf("\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
	printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
	Utn_GetInt(&option, "Elija una opción: ", ERROR_MESSAGE, SORT_EMPLOYEES, AVERAGE_SALARY, ATTEMPTS);

	return option;
}

int TotalAndAverageSalary(Employee* list, int len)
{
	int retorno = ERROR;
	float acumSalary = 0;
	int employeeCounter = 0;
	float averageSalary;
	int i;

	for(i=0;i<len;i++)
	{
		if(list != NULL && len > 0 && list[i].isEmpty == OCCUPIED)
		{
			acumSalary += list[i].salary;
			employeeCounter++;
			retorno = FUNCIONO;
		}
	}

	averageSalary = acumSalary / employeeCounter;

	printf("El total de los salarios es: $%.2f \n", acumSalary);
	printf("El promedio de los salarios es: $%.2f \n", averageSalary);

	if(EmployeesAboveAvSalary(list, len, averageSalary)==ERROR)
	{
		printf("No fue posible mostrar a los empleados que superan el salario promedio!\n");
	}

	return retorno;
}

int EmployeesAboveAvSalary(Employee* list, int len, float averageSalary)
{
	int retorno = ERROR;
	int i;

	printf("Lista de empleados que superan el salario promedio. \n");
	printf("ID           Nombre         Apellido      Salario       Sector \n");
	printf("-------------------------------------------------------------------\n\n");
	if(list != NULL && len > 0 && averageSalary > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCCUPIED && list[i].salary > averageSalary)
			{
				printAEmployee(list[i], len);
				retorno = FUNCIONO;
			}
		}
	}

	return retorno;
}

/*
 * int sortEmployees(Employee* list, int len, int order)
{
	int retorno = ERROR;
	Employee auxEmployee;
	int i;
	int j;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len-1;i++)
		{
			if(list[i].isEmpty == OCCUPIED)
			{
				for(j=i+1;j<len;j++)
				{
					if(list[j].isEmpty == OCCUPIED)
					{
						if(order == INCREASING)
						{
							if((strcmp(list[i].lastName,list[j].lastName) < 0) ||
							   (strcmp(list[i].lastName,list[j].lastName) == 0 &&
									    list[i].sector > list[j].sector))
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
								retorno = FUNCIONO;
							}
						}
						else
						{
							if((strcmp(list[i].lastName,list[j].lastName) > 0) ||
							   (strcmp(list[i].lastName,list[j].lastName) == 0 &&
							            list[i].sector < list[j].sector))
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
								retorno = FUNCIONO;
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}
 * */

