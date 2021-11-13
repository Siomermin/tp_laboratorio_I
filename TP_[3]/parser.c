#include "Parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	char auxId[LEN_AUX];
	char auxNombre[LEN_AUX];
	char auxHorasTrabajadas[LEN_AUX];
	char auxSueldo[LEN_AUX];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId, auxNombre, auxHorasTrabajadas, auxSueldo) == 4)
			{
				Employee* empleadoAux;
				empleadoAux = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				if(ll_add(pArrayListEmployee, empleadoAux) == FUNCIONO)
				{
					retorno = FUNCIONO;
				}
			}
		}while(!feof(pFile));
	}
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	Employee* empleadoAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			empleadoAux = employee_new();
			if(fread(empleadoAux, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, empleadoAux);
				retorno = FUNCIONO;
			}
		}while(!feof(pFile));
	}
    return retorno;
}

int parser_SaveEmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int len;
	int i;
	int auxId;
	char auxNombre[LEN_NOMBRE];
	int auxHorasTrabajadas;
	int auxSalario;

	Employee* empleadoAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		fprintf(pFile, "%s, %s, %s, %s\n", "Id", "Nombre", "HorasTrabajadas", "Sueldo");
		for(i=0;i<len;i++)
		{
			empleadoAux = (Employee*)ll_get(pArrayListEmployee, i);

			if(employee_getId(empleadoAux, &auxId) == FUNCIONO &&
			   employee_getName(empleadoAux, auxNombre) == FUNCIONO &&
			   employee_getWorkHours(empleadoAux, &auxHorasTrabajadas) == FUNCIONO &&
			   employee_getSalary(empleadoAux, &auxSalario) == FUNCIONO)
			{
				fprintf(pFile, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSalario);
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}

int parser_SaveEmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int len;
	int i;

	Employee* empleadoAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			empleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
			if(fwrite(empleadoAux, sizeof(Employee), 1, pFile) == 1)
			{
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}
