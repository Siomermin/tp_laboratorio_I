/*
 ============================================================================
 Name        : TP 2 .c
 Author      : Fermin Gonzalez.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"
#include "Defines.h"

int main(void) {
	setbuf(stdout, NULL);

Employee employeeList[LEN];
Employee employee;
int option;
int optionCase4;
int order;
int auxId = 1;
int idRemove;
int flagCase1;

InitEmployees(employeeList, LEN);

do
{

	option = Menu();

	switch(option)
	{
		case 1:
			flagCase1 = FUNCIONO;

			if(GetEmployee(&auxId, &employee)==ERROR ||
			   AddEmployee(employeeList, LEN, employee.id, employee.name, employee.lastName,
						   employee.salary, employee.sector)==ERROR)
			{
				flagCase1 = ERROR;
				printf("Hubo un error al dar de alta el empleado! \n");
			}
			else
			{
				printf("El empleado se dio de alta satisfactoriamente con el ID %d.\n",employee.id);
			}

		break;

		case 2:
			if(flagCase1==FUNCIONO)
			{
				if(ModifyEmployee(employeeList, LEN)==ERROR)
				{
					printf("Hubo un error al modificar el empleado! \n");
				}
				else
				{
					printf("El empleado se modifico satisfactoriamente!\n");
				}
			}
			else
			{
				printf("Necesitas dar de alta un empleado antes de poder modificarlo.");
			}
		break;

		case 3:
			if(flagCase1==FUNCIONO)
			{
				if(GetIdToRemove(employeeList, LEN, &idRemove)==ERROR || removeEmployee(employeeList, LEN, idRemove)==ERROR)
				{
					printf("Hubo un error al dar de baja el empleado! \n");
				}
				else
				{
					printf("El empleado se dio de baja satisfactoriamente! \n");
				}
			}
			else
			{
				printf("Necesitas dar de alta un empleado antes de poder darlo de baja.");
			}
		break;

		case 4:
			if(flagCase1==FUNCIONO)
			{
				optionCase4 = MenuCase4();

				switch(optionCase4)
				{
					case SORT_EMPLOYEES:
						if(Utn_GetInt(&order,"De que manera quiere ordenar a los empleados? ( 1-Ascendente o 0-Descendente ): ",
																	ERROR_MESSAGE, DECREASING, INCREASING, ATTEMPTS)==FUNCIONO)
						{
							if(sortEmployees(employeeList, LEN, order)==ERROR)
							{
								printf("Hubo un error al ordenar a los empleados!\n");
							}
							else
							{
								printf("Empleados ordenados satisfactoriamente!\n");
								printEmployees(employeeList, LEN);
							}
						}

					break;

					case AVERAGE_SALARY:
						if(TotalAndAverageSalary(employeeList, LEN)==ERROR)
						{
							printf("Hubo un error al calcular el total y promedio de los salarios!\n");
						}

					break;
				}
			}
			else
			{
				printf("Necesitas dar de alta un empleado antes de poder informar.");
			}
		break;

		case 5:
		break;
	}

}while(option != 5);

}
