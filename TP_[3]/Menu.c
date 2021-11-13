/*
 * Menu.c
 *
 *  Created on: 29 oct 2021
 *      Author: Mermin
 */
#include "Menu.h"

int Menu(void)
{
	int opcion;

	printf("\n/****************************************************");
	printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
	printf("3. Alta de empleado. \n");
	printf("4. Modificar datos de empleado. \n");
	printf("5. Baja de empleado. \n");
	printf("6. Listar empleados. \n");
	printf("7. Ordenar empleados. \n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario). \n");
	printf("10. Salir. \n");
	printf("*****************************************************/");
	if(Utn_GetInt(&opcion, "\nElija una opción : ", MENSAJE_ERROR, 1, 10, 5) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}

int MenuModify(void)
{
	 int opcion;

	 printf("\n/****************************************************");
	 printf("\nQue desea modificar?\n");
	 printf("1. Nombre.\n");
	 printf("2. Horas trabajadas.\n");
	 printf("3. Sueldo.\n");
	 printf("4. Todas las anteriores.\n");
	 printf("5. Salir.\n");
	 printf("*****************************************************/");
	 if(Utn_GetInt(&opcion, "\nElija una opción : ", MENSAJE_ERROR, 1, 5, 5) == ERROR)
	 {
		 opcion = ERROR;
	 }
	 return opcion;
}

int MenuSort(void)
{
	int opcion;

	printf("\n/****************************************************");
	printf("\nComo desea ordenar?\n");
	printf("1. ID.\n");
	printf("2. Nombre.\n");
	printf("3. Horas trabajadas.\n");
	printf("4. Sueldo.\n");
	printf("5. Salir.\n");
	printf("*****************************************************/");
	if(Utn_GetInt(&opcion, "\nElija una opción : ", MENSAJE_ERROR, 1, 5, 5) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}

int SubMenuOrder(void)
{
	int opcion;

	printf("\n/****************************************************");
	printf("\nEn que orden desea ordenar?\n");
	printf("0. Descendente.\n");
	printf("1. Ascendente.\n");
	printf("*****************************************************/");
	if(Utn_GetInt(&opcion, "\nElija una opción : ", MENSAJE_ERROR, DESCENDENTE, ASCENDENTE, 5) == ERROR)
	{
		opcion = ERROR;
	}
	printf("Esto puede demorar unos segundos, aguarde porfavor...\n");
	return opcion;
}

int SubMenuRemove(void)
{
	int opcion;

	printf("\n/****************************************************");
	printf("\nEsta seguro de eliminar el cliente?\n");
	printf("1. Sí.\n");
	printf("2. No.\n");
	printf("*****************************************************/");
	if(Utn_GetInt(&opcion, "\nElija una opción : ", MENSAJE_ERROR, SI, NO, 5) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}
