#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
#include "Defines.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagLoadText = 0;
    int flagLoadBinary = 0;
    int flagAddEmployee = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	option = Menu();

            switch(option)
            {
                case 1:
                	if(flagLoadText || flagLoadBinary)
                	{
                		printf("Los datos ya han sido cargados anteriormente, no es posible volver a cargarlos!\n");
                	}
                	else
                	{
                		if(controller_loadFromText(PATH_TEXTO, listaEmpleados) == FUNCIONO)
                		{
                			printf("Los empleados se cargaron satisfactoriamente!\n");
                			flagLoadText = 1;
                		}
                		else
                		{
                			printf("Hubo un error al cargar los empleados!\n");
                		}
                	}
                    break;
                case 2:
                	if(flagLoadText || flagLoadBinary)
                	{
                		printf("Los datos ya han sido cargados anteriormente, no es posible volver a cargarlos!\n");
                	}
                	else
                	{
                		if(controller_loadFromBinary(PATH_BINARIO, listaEmpleados) == FUNCIONO)
                		{
                			printf("Los empleados se cargaron satisfactoriamente!\n");
                			flagLoadBinary = 1;
                		}
                		else
                		{
                			printf("Hubo un error al cargar los empleados!\n");
                		}
                	}
                	break;
                case 3:
                		if(controller_addEmployee(listaEmpleados) == FUNCIONO)
                		{
                			printf("El empleado se dio de alta satisfactoriamente!\n");
                			flagAddEmployee = 1;
                		}
                		else
                		{
                			printf("Hubo un error al dar de alta el empleado!\n");
                		}
                    break;
                case 4:
                	if(flagLoadText || flagLoadBinary || flagAddEmployee)
                	{
                		if(controller_editEmployee(listaEmpleados) == FUNCIONO)
                		{
                			printf("El empleado fue modificado satisfactoriamente!\n");
                		}
                		else
                		{
                			printf("Hubo un error al modificar el empleado!");
                		}
                	}
                	else
                	{
                		printf("Tiene que existir un empleado antes de poder modificarlo!\n");
                		printf("Intenta cargando mediante archivos o dando de alta...\n");
                	}
                	break;
                case 5:
                	if(flagLoadText || flagLoadBinary || flagAddEmployee)
                	{
                		if(controller_removeEmployee(listaEmpleados) == FUNCIONO)
                		{
                			printf("El empleado fue eliminado satisfactoriamente!\n");
                		}
                		else
                		{
                			printf("Hubo un error al eliminar el empleado!");
                		}
                	}
                	else
                	{
                		printf("Tiene que existir un empleado antes de poder darlo de baja!\n");
                		printf("Intenta cargando mediante archivos o dando de alta...\n");
                	}
                	break;
                case 6:
                	if(flagLoadText || flagLoadBinary || flagAddEmployee)
                	{
                		if(controller_ListEmployee(listaEmpleados) == ERROR)
                		{
                			printf("Hubo un error al mostrar la lista de empleados!\n");
                		}
                	}
                	else
                	{
                		printf("Tiene que existir un empleado antes de poder listarlo!\n");
                		printf("Intenta cargando mediante archivos o dando de alta...\n");
                	}
                	break;
                case 7:
                	if(flagLoadText || flagLoadBinary || flagAddEmployee)
                	{
                		if(controller_sortEmployee(listaEmpleados) == FUNCIONO)
                		{
                			printf("Lista de empleados ordenados satisfactoriamente!\n");
                			controller_ListEmployee(listaEmpleados);
                		}
                		else
                		{
                			printf("Hubo un error al ordenar la lista de empleados!\n");
                		}
                	}
                	else
                	{
                		printf("Tienen que existir dos empleados antes de poder ordenarlos!\n");
                		printf("Intenta cargando mediante archivos o dando de alta...\n");
                	}
                	break;
                case 8:
                	if(flagLoadText || flagLoadBinary)
                	{
                		if(controller_saveAsText(PATH_TEXTO, listaEmpleados) == FUNCIONO &&
                		   controller_saveAsBinary(PATH_BINARIO,listaEmpleados) == FUNCIONO)
                		{
                			printf("Los empleados se guardaron satisfactoriamente!\n");
                		}
                		else
                		{
                			printf("Hubo un error al guardar los empleados!\n");
                		}
                	}
                	else
                	{
                		printf("Se tienen que cargar los datos de los empleados antes de guardarlos!\n");
                	}
                	break;
                case 9:
                	if(flagLoadText || flagLoadBinary)
                	{
                		if(controller_saveAsBinary(PATH_BINARIO,listaEmpleados) == FUNCIONO &&
                		   controller_saveAsText(PATH_TEXTO, listaEmpleados) == FUNCIONO)
                		{
                			printf("Los empleados se guardaron satisfactoriamente!\n");
                		}
                		else
                		{
                			printf("Hubo un error al guardar los empleados!\n");
                		}
                	}
                	else
                	{
                		printf("Se tienen que cargar los datos de los empleados antes de guardarlos!\n");
                	}
                	break;
                case 10:
                	ll_deleteLinkedList(listaEmpleados);
                	printf("\nchauuuuuuuuuuuuuuuuuuuuuuuuuuu");
                	break;
            }
        }while(option != 10);
}
