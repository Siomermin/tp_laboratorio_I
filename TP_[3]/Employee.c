#include "Employee.h"

Employee* employee_new()
{
	Employee* empleadoAux;

	empleadoAux = (Employee*)malloc(sizeof(Employee));

	if(empleadoAux == NULL)
	{
        printf("Error de memoria al crear un empleado!\n");
        exit(EXIT_FAILURE);
	}
	return empleadoAux;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleadoAux;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
	{
		empleadoAux = employee_new();

		if(employee_setId(empleadoAux, atoi(idStr)) == ERROR ||
		   employee_setName(empleadoAux, nombreStr) == ERROR ||
		   employee_setWorkHours(empleadoAux, atoi(horasTrabajadasStr)) == ERROR ||
		   employee_setSalary(empleadoAux, atoi(sueldoStr)) == ERROR)
		{
			printf("Error al cargar el empleado! \n");
			employee_delete(empleadoAux);
		}
	}
	return empleadoAux;
}

void employee_delete(Employee* auxEmpleado)
{
	free(auxEmpleado);
	auxEmpleado = NULL;
}

int employee_setId(Employee* this,int id)
{
	int retorno = ERROR;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = ERROR;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_setName(Employee* this,char* nombre)
{
	int retorno = ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_getName(Employee* this,char* nombre)
{
	int retorno = ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_setWorkHours(Employee* this,int horasTrabajadas)
{
	int retorno = ERROR;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_getWorkHours(Employee* this,int* horasTrabajadas)
{
	int retorno = ERROR;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_setSalary(Employee* this,int sueldo)
{
	int retorno = ERROR;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_getSalary(Employee* this,int* sueldo)
{
	int retorno = ERROR;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_getInfo(char* refNombre, int* refHorasTrabajadas, int* refSueldo)
{
	int retorno = ERROR;
	char auxNombre[LEN_NOMBRE];
	int auxHorasTrabajadas;
	int sueldoAux;

	if(refNombre != NULL && refHorasTrabajadas != NULL && refSueldo != NULL)
	{
		if(Utn_GetString(auxNombre, LEN_NOMBRE, "Ingrese el nombre: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO &&
		   Utn_GetInt(&auxHorasTrabajadas, "Ingrese la cantidad de horas trabajadas ( mínimo : 60hs y máximo : 325hs) : ", MENSAJE_ERROR, MIN_HORAS_TRABAJADAS, MAX_HORAS_TRABAJADAS, REINTENTOS) == FUNCIONO &&
		   Utn_GetInt(&sueldoAux, "Ingrese el sueldo ( Sueldo mínimo : $10000 , Sueldo máximo : $50000 ) : ", MENSAJE_ERROR, MIN_SALARIO, MAX_SALARIO, REINTENTOS) == FUNCIONO)
		{
			if(ValidateName(auxNombre) == FUNCIONO)
			{
				strcpy(refNombre,auxNombre);
				*refHorasTrabajadas = auxHorasTrabajadas;
				*refSueldo = sueldoAux;
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}

int employee_searchById(LinkedList* this, int id)
{
	int retorno = ERROR;
	int i;
	int len;
	int idAux;
	Employee* empleadoAux;

	if(this != NULL && id > 0)
	{
		len = ll_len(this);

		for(i=0;i<len;i++)
		{
			empleadoAux = ll_get(this, i);

			if(employee_getId(empleadoAux, &idAux) == FUNCIONO && idAux == id)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}

int employee_editByOption(Employee* auxEmpleado, int opcion)
{
	int retorno = ERROR;
	char auxNombre[LEN_NOMBRE];
	int auxHorasTrabajadas;
	int auxSueldo;

	switch(opcion)
	{
	case 1:
		if(Utn_GetString(auxNombre, LEN_NOMBRE, "Ingrese el nombre: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO &&
		   ValidateName(auxNombre) == FUNCIONO)
		{
			if(employee_setName(auxEmpleado, auxNombre) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		break;
	case 2:
		if(Utn_GetInt(&auxHorasTrabajadas, "Ingrese la cantidad de horas trabajadas ( mínimo : 60hs y máximo : 325hs) : ", MENSAJE_ERROR, MIN_HORAS_TRABAJADAS, MAX_HORAS_TRABAJADAS, REINTENTOS) == FUNCIONO &&
				employee_setWorkHours(auxEmpleado, auxHorasTrabajadas) == FUNCIONO)
		{
			retorno = FUNCIONO;
		}
		break;
	case 3:
		if(Utn_GetInt(&auxSueldo, "Ingrese el sueldo ( Sueldo mínimo : $10000 , Sueldo máximo : $50000 ) : ", MENSAJE_ERROR, MIN_SALARIO, MAX_SALARIO, REINTENTOS) == FUNCIONO &&
		   employee_setSalary(auxEmpleado, auxSueldo) == FUNCIONO)
		{
			retorno = FUNCIONO;
		}
		break;
	case 4:
		if(employee_getInfo(auxNombre, &auxHorasTrabajadas, &auxSueldo) == FUNCIONO)
		{
			if(employee_setName(auxEmpleado, auxNombre) == FUNCIONO &&
			   employee_setWorkHours(auxEmpleado, auxHorasTrabajadas) == FUNCIONO &&
			   employee_setSalary(auxEmpleado, auxSueldo) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		break;
	}
	return retorno;
}

int employee_printAEmployee(Employee* auxEmpleado)
{
	int retorno = ERROR;
	int auxId;
	char auxNombre[LEN_NOMBRE];
	int auxHorasTrabajadas;
	int auxSueldo;

	if(employee_getId(auxEmpleado, &auxId) == FUNCIONO &&
	   employee_getName(auxEmpleado, auxNombre) == FUNCIONO &&
	   employee_getWorkHours(auxEmpleado, &auxHorasTrabajadas) == FUNCIONO &&
	   employee_getSalary(auxEmpleado, &auxSueldo) == FUNCIONO)
	{
		printf("%5d    %10s    %10d    %10d\n", auxId,
												auxNombre,
												auxHorasTrabajadas,
												auxSueldo);
		retorno = FUNCIONO;
	}
	return retorno;
}

int employee_compareByName(void* empleadoUno, void* empleadoDos)
{
	int retorno = 0;
	char auxNombreUno[LEN_NOMBRE];
	char auxNombreDos[LEN_NOMBRE];
	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		unEmpleado = (Employee*) empleadoUno; // unboxing
		otroEmpleado = (Employee*) empleadoDos; // unboxing

		if(employee_getName(unEmpleado, auxNombreUno) == FUNCIONO &&
		   employee_getName(otroEmpleado, auxNombreDos) == FUNCIONO)
		  {
				retorno = strcmp(auxNombreUno,auxNombreDos); // 0 si son iguales, -1 si el primero es menor que el segundo alfabeticamente,1 si el primero es mayor.
		  }
	}
	return retorno;
}

int employee_compareById(void* empleadoUno, void* empleadoDos)
{
	int retorno = 0;
	int auxIdUno;
	int auxIdDos;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		unEmpleado = (Employee*) empleadoUno; // unboxing
		otroEmpleado = (Employee*) empleadoDos; // unboxing

		if(employee_getId(unEmpleado, &auxIdUno) == FUNCIONO &&
		   employee_getId(otroEmpleado, &auxIdDos) == FUNCIONO)
		{
			if(auxIdUno > auxIdDos)
			{
				retorno = 1;
			}
			else
			{
				if(auxIdUno < auxIdDos)
				{
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}

int employee_compareByWorkHours(void* empleadoUno, void* empleadoDos)
{
	int retorno = 0;
	int auxHorasTrabajadasUno;
	int auxHorasTrabajadasDos;

	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		unEmpleado = (Employee*) empleadoUno; // unboxing
		otroEmpleado = (Employee*) empleadoDos; // unboxing

		if(employee_getWorkHours(unEmpleado, &auxHorasTrabajadasUno) == FUNCIONO &&
		   employee_getWorkHours(otroEmpleado, &auxHorasTrabajadasDos) == FUNCIONO)
		{
			if(auxHorasTrabajadasUno > auxHorasTrabajadasDos)
			{
				retorno = 1;
			}
			else
			{
				if(auxHorasTrabajadasUno < auxHorasTrabajadasDos)
				{
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}

int employee_compareBySalary(void* empleadoUno, void* empleadoDos)
{
	int retorno = 0;
	int auxSalarioUno;
	int auxSalarioDos;

	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		unEmpleado = (Employee*) empleadoUno; // unboxing
		otroEmpleado = (Employee*) empleadoDos; // unboxing

		if(employee_getSalary(unEmpleado, &auxSalarioUno) == FUNCIONO &&
		   employee_getSalary(otroEmpleado, &auxSalarioDos) == FUNCIONO)
		{
			if(auxSalarioUno > auxSalarioDos)
			{
				retorno = 1;
			}
			else
			{
				if(auxSalarioUno < auxSalarioDos)
				{
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}

int employee_getLastId(char* path , int* id)
{
	int retorno = ERROR;
	int auxId;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL && id != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			do
			{
				if(fscanf(pFile, "%d\n", &auxId) == 1)
				{
						*id = auxId;
						retorno = FUNCIONO;
				}
			}while(!feof(pFile));
		}
	}
	return retorno;
}

int employee_SaveIdAsText(char* path , int auxId)
{
	int retorno = ERROR;
	FILE* pFile;

	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%d\n", auxId);
		retorno = FUNCIONO;
	}
	fclose(pFile);
	return retorno;
}
