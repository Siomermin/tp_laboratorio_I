#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		if(parser_EmployeeFromText(pFile, pArrayListEmployee) == FUNCIONO)
		{
			retorno = FUNCIONO;
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL &&
	   parser_EmployeeFromBinary(pFile, pArrayListEmployee) == FUNCIONO)
	{
		retorno = FUNCIONO;
	}
	fclose(pFile);
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	char auxNombre[LEN_NOMBRE];
	int auxHorasTrabajadas;
	int auxSueldo;
	int refId;
	int nuevoId;

	Employee* empleadoAux = employee_new();

	if(pArrayListEmployee != NULL && empleadoAux != NULL)
	{
		if(employee_getInfo(auxNombre, &auxHorasTrabajadas, &auxSueldo) == FUNCIONO &&
			employee_getLastId(PATH_ID, &refId) == FUNCIONO)
		{
			nuevoId = refId + 1;
			if(employee_setId(empleadoAux, nuevoId) == FUNCIONO &&
			   employee_setName(empleadoAux, auxNombre) == FUNCIONO &&
			   employee_setWorkHours(empleadoAux, auxHorasTrabajadas) == FUNCIONO &&
			   employee_setSalary(empleadoAux, auxSueldo) == FUNCIONO)
			{
				if(employee_SaveIdAsText(PATH_ID, nuevoId) == FUNCIONO)
				{
					ll_add(pArrayListEmployee, empleadoAux);
					retorno = FUNCIONO;
				}
				else
				{
					employee_delete(empleadoAux); // CAPAZ LO SAQUE TENGOQUE VER QUE ONDA
				}
			}
		}

	}
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int auxId;
	int index;
	int opcion;
	Employee* empleadoAux;

	if(controller_ListEmployee(pArrayListEmployee) == FUNCIONO &&
	   Utn_GetInt(&auxId, "Ingrese la ID del cliente a modificar: ", MENSAJE_ERROR, MIN_ID, MAX_ID, REINTENTOS) == FUNCIONO)
	{
		index = employee_searchById(pArrayListEmployee, auxId);
		empleadoAux = (Employee*)ll_get(pArrayListEmployee, index);
		if(empleadoAux != NULL)
		{
			opcion = MenuModify();
			if(employee_editByOption(empleadoAux, opcion) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int auxId;
	int index;
	int opcion;
	Employee* empleadoAux;

	if(controller_ListEmployee(pArrayListEmployee) == FUNCIONO &&
	   Utn_GetInt(&auxId, "Ingrese la ID del cliente a eliminar: ", MENSAJE_ERROR, MIN_ID, MAX_ID, REINTENTOS) == FUNCIONO)
    {
		index = employee_searchById(pArrayListEmployee, auxId);
		if(index != ERROR)
		{
		   opcion = SubMenuRemove();
		   if(opcion == SI)
		   {
			   empleadoAux = (Employee*)ll_get(pArrayListEmployee, index);
			   if(ll_remove(pArrayListEmployee, index) == FUNCIONO)
			   {
				   employee_delete(empleadoAux);
				   retorno = FUNCIONO;
			   }
		   }
		}
    }

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int i;
	int len;
	Employee* empleadoAux;

	len = ll_len(pArrayListEmployee);

		if(pArrayListEmployee != NULL)
		{
			printf("\n/****************************************************");
			printf("\n                  LISTA DE EMPLEADOS                 \n");
			printf("\n    ID       Nombre     Horas Trabajadas  Sueldo\n\n");
			for(i=0;i<len;i++)
			{
				empleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
				if(employee_printAEmployee(empleadoAux) == FUNCIONO)
				{
					retorno = FUNCIONO;
				}
			}
			printf("*****************************************************/\n");
		}
		return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int orden;
	int opcion;

	if(pArrayListEmployee != NULL)
	   opcion = MenuSort();
	{
		switch(opcion)
		{
		case 1:
			   orden = SubMenuOrder();
			   if(ll_sort(pArrayListEmployee, employee_compareById, orden) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
			break;
		case 2:
				orden = SubMenuOrder();
			   if(ll_sort(pArrayListEmployee, employee_compareByName, orden) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
			break;
		case 3:
				orden = SubMenuOrder();
			   if(ll_sort(pArrayListEmployee, employee_compareByWorkHours, orden) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
			break;
		case 4:
				orden = SubMenuOrder();
	           if(ll_sort(pArrayListEmployee, employee_compareBySalary, orden) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
			break;
		}
	}
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			if(parser_SaveEmployeeToText(pFile, pArrayListEmployee) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		fclose(pFile);
	}
    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			if(parser_SaveEmployeeToBinary(pFile, pArrayListEmployee) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		fclose(pFile);
	}
    return retorno;
}

